#include "aimbot.hpp"

#include <algorithm>
#include <cfloat>
#include <cmath>

#include <framework/entities/entities.hpp>
#include <framework/roblox/visual_engine.hpp>
#include <overlay/overlay.hpp>
#include <utilities/structs.hpp>

#undef max
#undef min

namespace
{
    bool game_focused( )
    {
        const HWND foreground = GetForegroundWindow( );
        if ( !foreground || foreground == g_overlay.hwnd )
            return false;

        DWORD pid = 0;
        GetWindowThreadProcessId( foreground, &pid );

        return pid != 0 && pid == static_cast< DWORD >( g_memory.pid );
    }

    void move_mouse( int dx, int dy )
    {
        INPUT input{};
        input.type = INPUT_MOUSE;
        input.mi.dx = dx;
        input.mi.dy = dy;
        input.mi.dwFlags = MOUSEEVENTF_MOVE;

        SendInput( 1, &input, sizeof( INPUT ) );
    }

    bool read_aim_part( const entity_t& entity, primitive_t& out )
    {
        static const char* const preferred[] = { "Head", "HumanoidRootPart" };

        for ( const char* name : preferred )
        {
            for ( const auto& bone : entity.bones )
            {
                if ( bone.key != name || !bone.primitive )
                    continue;

                out = g_memory.read< primitive_t >( bone.primitive + Offsets::Primitive::Rotation );
                return true;
            }
        }

        return false;
    }
}  // namespace

void aimbot_t::poll_key( )
{
    const bool down = ( GetAsyncKeyState( key ) & 0x8000 ) != 0;

    if ( toggle_mode )
    {
        if ( down && !key_was_down )
            toggle_state = !toggle_state;
    }
    else
    {
        toggle_state = down;
    }

    key_was_down = down;
}

void aimbot_t::acquire( visual_engine_t& engine, const vector2& center )
{
    const float radius = fov;

    auto snapshot = cache::get_snapshot( );

    float locked_dist = FLT_MAX;

    for ( const auto& entity : snapshot )
    {
        if ( !entity.humanoid || entity.humanoid != current_target )
            continue;

        primitive_t prim;
        if ( !read_aim_part( entity, prim ) )
            break;

        vector2 screen;
        if ( !engine.world_to_screen( prim.position, screen ) )
            break;

        locked_dist = ( screen - center ).length( );
        break;
    }

    const bool lock_valid = locked_dist <= radius * sticky_multiplier;

    float best_dist = FLT_MAX;
    std::uint64_t best_humanoid = 0;
    vector3 best_point{};
    vector3 best_velocity{};
    float best_range = 0.f;

    const auto workspace = g_memory.read< std::uint64_t >( game->datamodel.address + Offsets::DataModel::Workspace );
    const auto camera = workspace ? g_memory.read< std::uint64_t >( workspace + Offsets::Workspace::CurrentCamera ) : 0;
    const vector3 camera_pos = camera ? g_memory.read< vector3 >( camera + Offsets::Camera::Position ) : vector3( );

    for ( const auto& entity : snapshot )
    {
        if ( entity.self || !entity.humanoid )
            continue;

        if ( g_memory.read< float >( entity.humanoid + Offsets::Humanoid::Health ) <= 0.f )
            continue;

        primitive_t prim;
        if ( !read_aim_part( entity, prim ) )
            continue;

        vector2 screen;
        if ( !engine.world_to_screen( prim.position, screen ) )
            continue;

        const float dist = ( screen - center ).length( );
        if ( dist > radius )
            continue;

        if ( sticky && lock_valid && entity.humanoid != current_target && dist >= locked_dist * ( 1.f - sticky_bias ) )
            continue;

        if ( dist >= best_dist )
            continue;

        best_dist = dist;
        best_humanoid = entity.humanoid;
        best_point = prim.position;
        best_velocity = prim.linear_velocity;
        best_range = ( prim.position - camera_pos ).length( );
    }

    current_target = best_humanoid;
    target_point = best_point;
    target_velocity = best_velocity;
    target_range = best_range;
}

void aimbot_t::draw_fov( )
{
    if ( !show_fov )
        return;

    auto draw = ImGui::GetBackgroundDrawList( );
    const ImVec2 center( game->dimensions.x / 2.f, game->dimensions.y / 2.f );

    const ImU32 fill = IM_COL32( 255, 255, 255, static_cast< int >( std::clamp( fov_fill_alpha, 0.f, 1.f ) * 255.f ) );

    if ( fov_style != 0 )
        draw->AddCircleFilled( center, fov, fill, 96 );

    if ( fov_style != 1 )
        draw->AddCircle( center, fov, fov_outline_color, 96, 1.5f );
}

void aimbot_t::tick( )
{
    poll_key( );

    if ( !enabled )
        return;

    auto engine = visual_engine_t::get( );
    if ( !engine.address )
        return;

    game->dimensions = engine.get_member< vector2 >( Offsets::VisualEngine::Dimensions );
    game->view_matrix = engine.get_member< matrix4 >( Offsets::VisualEngine::ViewMatrix );

    if ( game->dimensions.x < 1.f || game->dimensions.y < 1.f )
        return;

    draw_fov( );

    if ( !toggle_state || g_overlay.menu_open || !game_focused( ) )
        return;

    const vector2 center{ game->dimensions.x / 2.f, game->dimensions.y / 2.f };

    acquire( engine, center );

    if ( !current_target )
    {
        remainder = vector2( );
        return;
    }

    vector3 aim_world = target_point;
    if ( prediction > 0.f )
        aim_world += target_velocity * prediction;

    vector2 aim_screen;
    if ( !engine.world_to_screen( aim_world, aim_screen ) )
        return;

    const vector2 delta = aim_screen - center;
    if ( delta.length_squared( ) < 0.25f )
        return;

    float speed = smooth;
    if ( distance_sensitivity > 0.f && target_range > 0.f )
        speed /= 1.f + target_range * distance_sensitivity * 0.02f;

    speed = std::clamp( speed, 0.5f, 120.f );

    const float step = 1.f - std::exp( -speed * ImGui::GetIO( ).DeltaTime );
    remainder += delta * step;

    const int dx = static_cast< int >( std::lround( remainder.x ) );
    const int dy = static_cast< int >( std::lround( remainder.y ) );

    if ( dx || dy )
    {
        remainder.x -= static_cast< float >( dx );
        remainder.y -= static_cast< float >( dy );
        move_mouse( dx, dy );
    }
}
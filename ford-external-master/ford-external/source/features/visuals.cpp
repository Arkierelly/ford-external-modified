#include "visuals.hpp"

#include <imgui.h>

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <framework/entities/entities.hpp>
#include <framework/roblox/visual_engine.hpp>
#include <string>
#include <string_view>
#include <unordered_map>

#undef max
#undef min

namespace
{
    // Only real body parts contribute to the box. Accessories, hair, layered
    // clothing and tool handles are ignored, which is what kept the box up
    // above the head at distance.
    constexpr std::string_view k_body_parts[] = { "Head",     "UpperTorso",    "LowerTorso",    "Torso",     "LeftUpperArm",    "LeftLowerArm",
                                                  "LeftHand", "RightUpperArm", "RightLowerArm", "RightHand", "LeftUpperLeg",    "LeftLowerLeg",
                                                  "LeftFoot", "RightUpperLeg", "RightLowerLeg", "RightFoot", "HumanoidRootPart" };

    bool is_body_part( std::string_view name )
    {
        for ( auto part : k_body_parts )
        {
            if ( name == part )
                return true;
        }
        return false;
    }

    struct bone_link_t
    {
        const char* from;
        const char* to;
    };

    // R15 / Rthro
    constexpr bone_link_t k_r15_links[] = {
        { "Head", "UpperTorso" },          { "UpperTorso", "LowerTorso" },       { "LowerTorso", "HumanoidRootPart" },
        { "UpperTorso", "LeftUpperArm" },  { "LeftUpperArm", "LeftLowerArm" },   { "LeftLowerArm", "LeftHand" },
        { "UpperTorso", "RightUpperArm" }, { "RightUpperArm", "RightLowerArm" }, { "RightLowerArm", "RightHand" },
        { "LowerTorso", "LeftUpperLeg" },  { "LeftUpperLeg", "LeftLowerLeg" },   { "LeftLowerLeg", "LeftFoot" },
        { "LowerTorso", "RightUpperLeg" }, { "RightUpperLeg", "RightLowerLeg" }, { "RightLowerLeg", "RightFoot" },
    };

    // R6
    constexpr bone_link_t k_r6_links[] = {
        { "Head", "Torso" }, { "Torso", "Left Arm" }, { "Torso", "Right Arm" }, { "Torso", "Left Leg" }, { "Torso", "Right Leg" },
    };
}  // namespace

bool visuals_t::calculate_bounds( visual_engine_t& engine, entity_t& entity, ImRect& bb )
{
    vector2 points[ std::size( k_body_parts ) ];
    int count = 0;

    for ( const auto& bone : entity.bones )
    {
        if ( !bone.primitive || !is_body_part( bone.key ) )
            continue;

        const auto prim = g_memory.read< primitive_t >( bone.primitive + Offsets::Primitive::Rotation );

        vector2 screen;
        if ( !engine.world_to_screen( prim.position, screen ) )
            continue;

        points[ count++ ] = screen;

        if ( count >= static_cast< int >( std::size( k_body_parts ) ) )
            break;
    }

    if ( count < 3 )
        return false;

    float min_x = FLT_MAX, max_x = -FLT_MAX;
    float min_y = FLT_MAX, max_y = -FLT_MAX;

    for ( int i = 0; i < count; i++ )
    {
        min_x = std::min( min_x, points[ i ].x );
        max_x = std::max( max_x, points[ i ].x );
        min_y = std::min( min_y, points[ i ].y );
        max_y = std::max( max_y, points[ i ].y );
    }

    const float height = max_y - min_y;
    if ( height < 1.f )
        return false;

    const float pad_x = height * 0.10f;
    const float pad_top = height * 0.08f;

    bb.Min = ImVec2( min_x - pad_x, min_y - pad_top );
    bb.Max = ImVec2( max_x + pad_x, max_y );

    return bb.Max.x > bb.Min.x && bb.Max.y > bb.Min.y;
}

void visuals_t::draw_skeleton( visual_engine_t& engine, const entity_t& entity, ImDrawList* draw )
{
    std::unordered_map< std::string, vector2 > bones;
    bones.reserve( entity.bones.size( ) );

    for ( const auto& bone : entity.bones )
    {
        if ( !bone.primitive )
            continue;

        const auto prim = g_memory.read< primitive_t >( bone.primitive + Offsets::Primitive::Rotation );

        vector2 screen;
        if ( !engine.world_to_screen( prim.position, screen ) )
            continue;

        bones[ bone.key ] = screen;
    }

    const auto links = [ & ]( const auto& table )
    {
        for ( const auto& link : table )
        {
            const auto from = bones.find( link.from );
            const auto to = bones.find( link.to );

            if ( from == bones.end( ) || to == bones.end( ) )
                continue;

            const ImVec2 a( from->second.x, from->second.y );
            const ImVec2 b( to->second.x, to->second.y );

            draw->AddLine( a, b, IM_COL32( 0, 0, 0, 255 ), 3.f );
            draw->AddLine( a, b, skeleton_color, 1.5f );
        }
    };

    links( k_r15_links );
    links( k_r6_links );
}

void visuals_t::render( )
{
    if ( !visuals->boxes && !visuals->health_bar && !visuals->skeleton )
        return;

    auto engine = visual_engine_t::get( );
    if ( !engine.address )
        return;

    game->dimensions = engine.get_member< vector2 >( Offsets::VisualEngine::Dimensions );
    game->view_matrix = engine.get_member< matrix4 >( Offsets::VisualEngine::ViewMatrix );

    if ( game->dimensions.x < 1.f || game->dimensions.y < 1.f )
        return;

    auto draw = ImGui::GetBackgroundDrawList( );

    for ( auto& entity : cache::get_snapshot( ) )
    {
        if ( !visuals->self && entity.self )
            continue;

        float health = 0.f;
        float max_health = 0.f;

        if ( entity.humanoid )
        {
            health = g_memory.read< float >( entity.humanoid + Offsets::Humanoid::Health );
            max_health = g_memory.read< float >( entity.humanoid + Offsets::Humanoid::MaxHealth );

            if ( health <= 0.f )
                continue;
        }

        if ( visuals->skeleton )
            draw_skeleton( engine, entity, draw );

        if ( !visuals->boxes && !visuals->health_bar )
            continue;

        ImRect bb{ FLT_MAX, FLT_MAX, -FLT_MAX, -FLT_MAX };

        if ( !calculate_bounds( engine, entity, bb ) )
            continue;

        bb.Min.x = std::floorf( bb.Min.x );
        bb.Min.y = std::floorf( bb.Min.y );

        bb.Max.x = std::floorf( bb.Max.x );
        bb.Max.y = std::floorf( bb.Max.y );

        if ( visuals->boxes )
        {
            draw->AddRect( bb.Min, bb.Max, IM_COL32( 0, 0, 0, 255 ), 0.f, 0, 3.f );
            draw->AddRect( bb.Min, bb.Max, IM_COL32( 255, 255, 255, 255 ), 0.f, 0, 1.f );
        }

        if ( visuals->health_bar && entity.humanoid && max_health > 0.f )
        {
            const float ratio = std::clamp( health / max_health, 0.f, 1.f );
            const float filled = std::floor( ( bb.Max.y - bb.Min.y ) * ratio );

            draw->AddRect( ImVec2( bb.Min.x - 5.f, bb.Min.y - 1.f ), ImVec2( bb.Min.x - 2.f, bb.Max.y + 1.f ), IM_COL32( 0, 0, 0, 255 ) );

            if ( filled >= 1.f )
            {
                draw->AddRectFilled(
                    ImVec2( bb.Min.x - 4.f, bb.Max.y - filled ), ImVec2( bb.Min.x - 3.f, bb.Max.y ), IM_COL32( 255, 255, 255, 255 ) );
            }
        }
    }
}
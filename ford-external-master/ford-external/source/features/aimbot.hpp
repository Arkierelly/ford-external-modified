#ifndef aimbot_hpp
#define aimbot_hpp

#include <Windows.h>

#include <cstdint>
#include <memory>

#include <imgui.h>

#include <framework/math.hpp>
#include <framework/roblox/visual_engine.hpp>

struct aimbot_t
{
    bool enabled = false;
    int key = VK_RBUTTON;
    bool toggle_mode = false;

    bool show_fov = true;
    float fov = 120.f;
    int fov_style = 0;  // 0 = outline, 1 = filled, 2 = both
    float fov_fill_alpha = 0.08f;
    ImU32 fov_outline_color = IM_COL32( 255, 255, 255, 210 );

    float smooth = 14.f;
    float distance_sensitivity = 0.35f;
    float prediction = 0.12f;

    bool sticky = true;
    float sticky_multiplier = 1.6f;
    float sticky_bias = 0.25f;

    void tick( );

private:
    void poll_key( );
    void acquire( visual_engine_t& engine, const vector2& center );
    void draw_fov( );

    std::uint64_t current_target = 0;
    vector3 target_point{};
    vector3 target_velocity{};
    float target_range = 0.f;
    vector2 remainder{};
    bool toggle_state = false;
    bool key_was_down = false;
};

inline std::shared_ptr< aimbot_t > aimbot = std::make_shared< aimbot_t >( );

#endif // aimbot_hpp
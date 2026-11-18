#ifndef visuals_hpp
#define visuals_hpp

#include <imgui_internal.h>

#include <framework/globals.hpp>

struct visuals_t
{
    bool self = false;
    bool names = true;
    bool boxes = true;
    bool health_bar = true;
    bool skeleton = false;

    ImU32 skeleton_color = IM_COL32( 255, 255, 255, 255 );

    bool calculate_bounds( visual_engine_t& engine, entity_t& entity, ImRect& rect );
    void draw_skeleton( visual_engine_t& engine, const entity_t& entity, ImDrawList* draw );
    void render( );
};

inline std::shared_ptr< visuals_t > visuals = std::make_shared< visuals_t >( );

#endif  // visuals_hpp
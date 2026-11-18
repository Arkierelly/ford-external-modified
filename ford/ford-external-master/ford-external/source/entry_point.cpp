#include <Windows.h>

#include <cstdio>
#include <framework/entities/entities.hpp>
#include <framework/globals.hpp>
#include <overlay/overlay.hpp>
#include <string>
#include <thread>

int main( )
{
    SetProcessDpiAwarenessContext( DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 );

    printf( "pid=%d base=%llx\n", g_memory.pid, g_memory.base );

    if ( !g_overlay.init( ) )
    {
        printf( "overlay init failed\n" );
        return 1;
    }

    game->datamodel.tick( );
    cache::tick( );

    std::this_thread::sleep_for( std::chrono::milliseconds( 2500 ) );

    printf( "datamodel=%llx players=%llx local=%llx\n", game->datamodel.address, game->players.address, game->local_player.address );

    while ( g_overlay.begin_frame( ) )
    {
        g_overlay.end_frame( );
    }

    g_overlay.shutdown( );

    return 0;
}
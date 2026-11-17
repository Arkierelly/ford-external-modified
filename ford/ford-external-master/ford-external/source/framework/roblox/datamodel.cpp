#include "datamodel.hpp"

#include <chrono>
#include <framework/globals.hpp>
#include <thread>

std::uint64_t datamodel_t::get_place_id( )
{
    return get_member< std::uint64_t >( Offsets::DataModel::PlaceId );
}

std::uint64_t datamodel_t::get_creator_id( )
{
    return get_member< std::uint64_t >( Offsets::DataModel::CreatorId );
}

std::uint64_t datamodel_t::get_job_id( )
{
    return get_member< std::uint64_t >( Offsets::DataModel::JobId );
}

std::uint64_t datamodel_t::get_game_id( )
{
    return get_member< std::uint64_t >( Offsets::DataModel::GameId );
}

bool datamodel_t::is_in_game( )
{
    return get_name( ) == "Ugc";
}

bool datamodel_t::is_game_loaded( )
{
    return get_member< bool >( Offsets::DataModel::GameLoaded );
}

datamodel_t datamodel_t::get( )
{
    const auto fake = g_memory.read< std::uint64_t >( g_memory.base + Offsets::FakeDataModel::Pointer );
    if ( !fake )
        return datamodel_t( );

    const auto real = g_memory.read< std::uint64_t >( fake + Offsets::FakeDataModel::RealDataModel );
    return datamodel_t( real );
}

void datamodel_t::tick( )
{
    std::thread(
        []( )
        {
            std::this_thread::sleep_for( std::chrono::seconds( 3 ) );

            while ( true )
            {
                if ( g_memory.handle && WaitForSingleObject( g_memory.handle, 0 ) != WAIT_TIMEOUT )
                {
                    CloseHandle( g_memory.handle );
                    g_memory.handle = nullptr;
                    g_memory.base = 0;
                }

                if ( !g_memory.handle )
                {
                    auto pid = get_pid_by_name( "RobloxPlayerBeta.exe" );

                    if ( pid )
                    {
                        g_memory.pid = pid;
                        g_memory.handle = OpenProcess( PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid );
                        g_memory.base = g_memory.handle ? get_image_base_from_pid( pid ) : 0;

                        if ( !g_memory.base )
                        {
                            if ( g_memory.handle )
                                CloseHandle( g_memory.handle );

                            g_memory.handle = nullptr;
                        }
                    }
                }

                if ( !g_memory.handle || !g_memory.base )
                {
                    std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
                    continue;
                }

                auto current = datamodel_t::get( );

                if ( current.address && ( !game->players.address || current.address != game->last_datamodel ) )
                {
                    game->datamodel = current;

                    auto players = current.find_first_child_of_class( "Players" );

                    if ( players.address )
                    {
                        game->local_player = instance_t( g_memory.read< std::uint64_t >( players.address + Offsets::Player::LocalPlayer ) );
                        game->players = players;
                        game->last_datamodel = current.address;
                    }
                }

                std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
            }
        } )
        .detach( );
}
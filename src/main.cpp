#include "energy_dbus_server_manager.hpp"
#include "energy_dbus_client_manager.hpp"

src::severity_logger<severity_level> g_logger;

int main()
{
    EnergyDBusClientManager client;
    EnergyDBusServerManager server;
    client.startThread();
    server.startThread();

    while(true)
        pause();

    client.stopThread();
    server.stopThread();

    return 0;
}
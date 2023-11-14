#include "energy_dbus_server_manager.hpp"

// pure virtual function
void EnergyDBusServerManager::energyLoop(){
    DBus::BusDispatcher dispatcher;
	std::cout << "feedback Server Start " << std::endl;
	DBus::default_dispatcher = &dispatcher;

	DBus::Connection conn = DBus::Connection::SystemBus();
	conn.request_name(ENERGY_SERVER_NAME);

	Energy_Adaptor server(conn);
	// 서버 유지
	dispatcher.enter();
}
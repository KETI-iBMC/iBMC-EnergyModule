#include "energy_dbus_client_manager.hpp"
#include "energy_rest_client.hpp"

void EnergyDBusClientManager::connectFeedbackServer(){
    DBus::BusDispatcher dispatcher;
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection conn_n = DBus::Connection::SystemBus();
    Feedback_Proxy dbus_adap_test =
        Feedback_Proxy(conn_n, FEEDBACK_SERVER_PATH, FEEDBACK_SERVER_NAME);
    std::cout << "-------------------------------" << std::endl;    
    std::cout << "feedback 서버 연결 요청" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    dbus_adap_test.feedback_energy();
}

// pure virtual function
void EnergyDBusClientManager::energyLoop(){
	EnergyRestClient energy_rest_client;
	std::thread* t_PSU = new std::thread([&](){energy_rest_client.getPSUValues();});
	std::thread* t_FanRPM = new std::thread([&](){energy_rest_client.getFanRPMValues();});
	std::thread* t_LFC = new std::thread([&](){energy_rest_client.sendlfcTemperature();});

	std::thread* t_Host = new std::thread([&](){energy_rest_client.controlHostAgent();});
	// std::thread* t_CPUVal = new std::thread([&](){energy_rest_client.getCPUValue();});
	std::thread* t_PSUtoAgent = new std::thread([&](){energy_rest_client.sendPSUWattAlgoValue();});
	


	// std::string option="";

	// while(true){
	// 	std::cout << "[ ibmc | get_policy| set_policy | feedback | energy | ssp | send_fanpercent | get_PSUValues ] : " << std::endl;
	// 	std::cin >> option ;
	// 	if(option =="ibmc"){
	// 		std::cout << "ibmc에 연결을 요청합니다." << std::endl;
	// 	//   connect_to_ibmc_server();
	// 	}
	// 	else if (option == "get_policy" || option == "set_policy_temp" || option == "set_policy_algo"){
	// 		std::cout << "policy에 연결을 요청합니다." << std::endl;
	// 	//   connect_to_policy_server(option);
	// 	}
	// 	else if(option == "feedback"){
	// 		std::cout << "feedback에 연결을 요청합니다." << std::endl;
	// 		connectFeedbackServer();
	// 	}
	// 	else if(option == "energy"){
	// 		std::cout << "energy에 연결을 요청합니다." << std::endl;
	// 	//   connect_to_energy_server();
	// 	}
	// 	else if(option == "ssp"){
	// 		std::cout << "ssp에 연결을 요청합니다." << std::endl;
	// 	//   connect_to_ssp_server();
	// 	}
	// 	else if(option.find("send_fanpercent") != string::npos){
	// 		std::cout << "CMM에 fan percentage 데이터를 REST전송합니다." << std::endl;

	// 		string substr = option.substr(option.length() - 2);
	// 		std::stringstream ss(substr);
	// 		int num;
	// 		ss >> num;		
			

	// 		energy_rest_client.controlFan(num);
	// 	}
	// 	else if(option == "get_PSUValues" || option == "a"){
	// 		std::cout << "CMM에 PSU 데이터를 REST요청합니다." << std::endl;

	// 		//energy_rest_client.getPSUValues();
	// 	}
	// 	else if(option == "test_BFC" || option == "b"){
	// 		std::cout << "CMM에 BFC 제어를 REST요청합니다." << std::endl;

	// 		energy_rest_client.bfcSet(json::value::null());
	// 	}
	// 	else if(option == "get_FanRPMValues" || option == "c"){
	// 		std::cout << "CMM에 Fan RPM 정보를 REST요청합니다." << std::endl;

	// 		energy_rest_client.getFanRPMValues();
	// 	}
	// 	else if(option == "lfc" || option == "d"){
	// 		std::cout << "CMM에 lfc 제어를 REST요청합니다." << std::endl;

	// 		energy_rest_client.sendlfcTemperature();
	// 	}
	// 	else {
	// 		std::cout << "다시 입력하세요" << std::endl;
	// 	}
  	// }
	t_PSU->join();
	t_FanRPM->join();
	t_LFC->join();
	t_Host->join();
	// t_CPUVal->join();
	t_PSUtoAgent->join();
}
#include "energy_adaptor_wrap.hpp"

// derived class constructor
Energy_Adaptor::Energy_Adaptor(DBus::Connection& connection) 
    : DBus::ObjectAdaptor(connection, ENERGY_SERVER_PATH) {}

int32_t Energy_Adaptor::emm_ibmc(){

}
int32_t Energy_Adaptor::emm_policy(){

}
int32_t Energy_Adaptor::emm_feedback(){
    std::cout << "DBUS from feedback" << std::endl;
    return 1;
}
int32_t Energy_Adaptor::emm_monitor(){

}
int32_t Energy_Adaptor::emm_ssp(){

}
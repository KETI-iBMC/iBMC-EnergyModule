#ifndef __ENERGY_REST_CLIENT__
#define __ENERGY_REST_CLIENT__

#include "stdafx.hpp"

class EnergyRestClient : public Monostate<EnergyRestClient> {
    
    private:
        string cmm_address = "";
        string host_address = "";
        string ibmc_ipconfpath = "";
        string fan_rpm_path = "";
        string psu_data_path = "";
        string cooling_algo_path = "";
        http_response sendRequest(string addr, string uri, web::http::method method, json::value jv);
        void energyLoop();
        void initIPInfo();

    public:
        EnergyRestClient();
        void controlFan(int _fanpercent);
        void getPSUValues();
        void bfcSet(json::value _inputjv);
        void getFanRPMValues();
        void saveJson(json::value _jv, string _fname);
        void getFanRPMTempChartValues();

        void sendlfcTemperature();

        void controlHostAgent();

        void getCPUValue();
        void sendPSUWattAlgoValue();

};

#endif
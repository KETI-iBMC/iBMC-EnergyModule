#include "energy_rest_client.hpp"

// 얘네는 그냥 함수 형태로 만들어서 통신하면 될듯
// 어차피 response 받는건 server까지도 필요 없음

EnergyRestClient::EnergyRestClient(){
    // 임시. addresss는 virtual ip:8000으로 해야 함
    this->cmm_address = "http://10.0.4.123:8000"; 
    this->host_address = "http://10.0.4.143:8000";
    this->ibmc_ipconfpath = "/conf/ibmcipconf";
    this->fan_rpm_path = "/conf/fans.json";
    this->psu_data_path = "/conf/psu.json";
    this->cooling_algo_path = "/conf/CoolingAlgorithm.json";
    initIPInfo();
}

void EnergyRestClient::initIPInfo() {

    INI::File ft;
    if(!ft.Load(this->ibmc_ipconfpath))
    {
        log(warning) << "No IP init Config File( " << this->ibmc_ipconfpath << ")";
        log(info) << "Creating config file.. (" << this->ibmc_ipconfpath << ")";

        system(("touch " + this->ibmc_ipconfpath).c_str());
        if(!ft.Load(this->ibmc_ipconfpath)){
            log(warning) << "Creating failed!: IP init config file(" << this->ibmc_ipconfpath << ")";
            return;
        }

        //

        // // 
        // if(ft.GetSection("Address") == nullptr){
        //     ft.GetSection("Address")->SetValue("CMM", this->cmm_address);    
        // }
    }

    if(ft.GetSection("Address")->GetValue("CMM", -1).AsString() == "-1"){
        ft.GetSection("Address")->SetValue("CMM", this->cmm_address);
    }

    if(ft.GetSection("Address")->GetValue("Host", -1).AsString() == "-1"){
        ft.GetSection("Address")->SetValue("Host", this->host_address);
    }

    
    // ft.GetSection("Address")->SetValue("Host", this->host_address);
    ft.Save(this->ibmc_ipconfpath);

    this->cmm_address = ft.GetSection("Address")->GetValue("CMM", -1).AsString();
    this->host_address = ft.GetSection("Address")->GetValue("Host", -1).AsString();

    if(this->cmm_address.find("http" == string::npos)){
        this->cmm_address = "http://" + this->cmm_address + ":8000";
    }

    log(info) << "Read CMM address: \t" << this->cmm_address;
    log(info) << "Read host address: \t" << this->host_address;
    ft.Save(this->ibmc_ipconfpath);
    ft.Unload();
}

void EnergyRestClient::energyLoop(){

}

http_response EnergyRestClient::sendRequest(string addr, string uri, web::http::method method, json::value jv)
{
	http_client client(addr);
	http_request req(method);
	req.set_request_uri(uri);

	http_response response;
    // response.headers().add("Access-Control-Allow-Origin", "*");
    // response.headers().add("Access-Control-Allow-Credentials", "true");
    // response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
    // response.headers().add("Access-Control-Max-Age", "3600");
    // response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
    // response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");

	if(jv != json::value::null())
		req.set_body(jv);

	try
	{
		pplx::task<http_response> responseTask = client.request(req);
		response = responseTask.get();
        
        if(response.status_code() == status_codes::OK)
            cout << uri << " OK" << endl;
        else
            cout << uri << " BadRequest" << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		response.set_status_code(status_codes::BadRequest);
	}
	
	return response;
}

void EnergyRestClient::controlFan(int _fanpercent){
    string uri = "/redfish/v1/Chassis/CMM1/Thermal/Fans";
    json::value j_body;

    j_body["FanSpeed"] = json::value::string(std::to_string(_fanpercent) + "%");
    http_response response;
    response = this->sendRequest(this->cmm_address, uri, methods::PATCH, j_body);

    // {FanSpeed: "80%"};

    if(response.status_code() == status_codes::OK)
        cout << "controlFan OK" << endl;
    else
        cout << "controlFan BadRequest" << endl;
}

void EnergyRestClient::getPSUValues(){
    string uri = "/redfish/v1/getPSUValues";
    http_response response;
    while(1){
        try{
            response = sendRequest(this->cmm_address, uri, methods::GET, json::value::null());

            if(response.status_code() == status_codes::OK){
                json::value jv = response.extract_json().get();
                cout << "getPSUValues OK";
                cout << ", Power: " << jv["PSU0"]["SMBusIPMIFRU"]["InputPower"]["Value"];
                cout << ", Voltage: " << jv["PSU0"]["SMBusIPMIFRU"]["InputVoltage"]["Value"];
                cout << endl;
                this->saveJson(jv, this->psu_data_path);
            }
            else
                cout << "getPSUValues BadRequest" << endl;
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << "getPSUValues failed";
            std::cout << "\033[0m";
            continue;
        }

        // json::value jv = response.extract_json().get();
        // cout << jv << endl;

        sleep(1);
    }
}

// frontend to CMM
// {"fanTempRPMList":[
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"},
//   {"data":[0,17.5,35,52.5,77.8,75,80,85,90,95,100],"label":[0,10,20,30,40,50,60,70,80,90,100],"algo":"Custom","tempsource":"CPU"}
//   ]
// }

// 사실상 json 그대로 던지면 됨

// KETI-Edge로부터 그래프 데이터 + BFC를 얻어오면 여기를 거쳐서 CMM으로 전송
void EnergyRestClient::bfcSet(json::value _inputjv){
    string uri = "/redfish/v1/FanBFCiBMC";
    json::value j_body;

    // j_body["Algorithm"] = json::value::string("BFC");

    // j_body["fanTempRPMList"] = json::value::string("BFC");
    // j_body["Algorithm"] = json::value::string("BFC");


    // temp 데이터
    json::value json_value;
    json_value["fanTempRPMList"] = json::value::array();
    for(int i = 0; i < 9; i++){
        json::value jv;
        jv["data"] = json::value::array();
        jv["data"][0] = json::value::number(0);
        jv["data"][1] = json::value::number(17.5);
        jv["data"][2] = json::value::number(80);
        jv["data"][3] = json::value::number(80);
        jv["data"][4] = json::value::number(80);
        jv["data"][5] = json::value::number(80);
        jv["data"][6] = json::value::number(80);
        jv["data"][7] = json::value::number(80);
        jv["data"][8] = json::value::number(80);
        jv["data"][9] = json::value::number(80);
        jv["data"][10] = json::value::number(80);

        jv["label"] = json::value::array();
        jv["label"][0] = json::value::number(0);
        jv["label"][1] = json::value::number(10);
        jv["label"][2] = json::value::number(20);
        jv["label"][3] = json::value::number(30);
        jv["label"][4] = json::value::number(40);
        jv["label"][5] = json::value::number(50);
        jv["label"][6] = json::value::number(60);
        jv["label"][7] = json::value::number(70);
        jv["label"][8] = json::value::number(80);
        jv["label"][9] = json::value::number(90);
        jv["label"][10] = json::value::number(100);

        jv["algo"] = json::value::string("Custom");
        jv["tempsource"] = json::value::string("CPU");

        json_value["fanTempRPMList"][i] = jv;
    }

    http_response response;
    response = this->sendRequest(this->cmm_address, uri, methods::PATCH, json_value);

    if(response.status_code() == status_codes::OK)
        cout << "BFC control OK" << endl;
    else
        cout << "BFC control BadRequest" << endl;
}


void EnergyRestClient::getFanRPMValues(){
    string uri = "/redfish/v1/Chassis/CMM1/Thermal/Fans";
    http_response response;
    while(1){
        try
        {
            response = sendRequest(this->cmm_address, uri, methods::GET, json::value::null());

            if(response.status_code() == status_codes::OK)
                cout << "getFanRPMValues OK" << endl;
            else{
                cout << "getFanRPMValues BadRequest" << endl;
                sleep(3);
                continue;
            }

            json::value jv = response.extract_json().get();

            // cout << jv << endl;
            this->saveJson(jv, this->fan_rpm_path);
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << "getFanRPMValues failed";
            std::cout << "\033[0m";
            continue;
        }
        
        sleep(3);
    }
}

void EnergyRestClient::getFanRPMTempChartValues(){
    string uri = "/redfish/v1/FanRPMTempInfo";
    http_response response;
    while(1){
        response = sendRequest(this->cmm_address, uri, methods::GET, json::value::null());

        if(response.status_code() == status_codes::OK)
            cout << "getFanRPMValues OK" << endl;
        else
            cout << "getFanRPMValues BadRequest" << endl;

        json::value jv = response.extract_json().get();

        // cout << jv << endl;
        this->saveJson(jv, this->fan_rpm_path);
        sleep(3);
    }
}


void EnergyRestClient::saveJson(json::value _jv, string _fname){
    std::string filename = _fname;
    std::ofstream outputFile(filename);
    try{
        if (!outputFile) {
            std::cerr << "Failed to open the file for writing." << std::endl;
        }

        // cout << _jv.to_string() << endl;

        // cout << _js << endl;

        utility::string_t jsonString = _jv.to_string();
        std::string jsonStringStd = utility::conversions::to_utf8string(jsonString);

        // Write data to the file
        outputFile << jsonStringStd << std::endl;

        // Close the file
        outputFile.close();
        std::cout << "Data has been written to " << filename << std::endl;
    }
    catch(const std::exception& e)
    {
        std::ostringstream oss;
        oss << "\033[1;" << 35 << "m"; // magenta
        std::cout << oss.str();

        std::cerr << e.what() << '\n';
        log(warning) << "saveJson failed";
        std::cout << "\033[0m";
    }
}

void EnergyRestClient::sendlfcTemperature(){

    bool once = true;

    // string 데이터를 json으로 바꾼 후 보내기
    std::string filename = "/conf/lfc.json";
    std::string coolingAlgoFilename = this->cooling_algo_path;

    while(1){
        std::ifstream coolingAlgoInputFile(coolingAlgoFilename);
        if (!coolingAlgoInputFile.is_open()) {
            std::cerr << "Failed to open the file for reading.: " << coolingAlgoFilename << std::endl;
            sleep(1);
            continue;
        }
        // Read the JSON content into a string
        std::string coolingAlgoJsonData((std::istreambuf_iterator<char>(coolingAlgoInputFile)), std::istreambuf_iterator<char>());

        // Close the file
        coolingAlgoInputFile.close();
        web::json::value coolingAlgoJsonValue;
        try
        {
            coolingAlgoJsonValue = web::json::value::parse(utility::conversions::to_string_t(coolingAlgoJsonData));
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << "coolingalgo json read failed";
            std::cout << "\033[0m";
        }
        string CoolingAlgoString = coolingAlgoJsonValue["CoolingAlgorithm"].as_string();
        
        if(CoolingAlgoString == "LFC" || CoolingAlgoString == "BFC" || CoolingAlgoString == "Default Auto"){
            // Read the JSON data from the file
            std::ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                std::cerr << "Failed to open the file for reading.: " << filename << std::endl;
                sleep(1);
                continue;
            }

            // Read the JSON content into a string
            std::string jsonData((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

            // Close the file
            inputFile.close();

            string lfc_mode_uri = "/redfish/v1/FanTemperatureCriteria";

            json::value j_tempcrit;
            j_tempcrit["TemperatureCriteria"] = json::value::string("LFCFutureTemp");

            http_response mode_response;
            mode_response = this->sendRequest(this->cmm_address, lfc_mode_uri, methods::PATCH, j_tempcrit);

            if(mode_response.status_code() == status_codes::OK)
                cout << CoolingAlgoString << " mode control OK" << endl;
            else
                cout << CoolingAlgoString << " mode control BadRequest" << endl;

            // // Parse the JSON string into a web::json::value

            web::json::value jsonValue;
            try
            {
                jsonValue = web::json::value::parse(utility::conversions::to_string_t(jsonData));
            }
            catch(const std::exception& e)
            {
                std::ostringstream oss;
                oss << "\033[1;" << 35 << "m"; // magenta
                std::cout << oss.str();

                std::cerr << e.what() << '\n';
                log(warning) << "json read failed";
                std::cout << "\033[0m";
            }


            // Now, you can work with the JSON data as a web::json::value

            // Example: Print the JSON data
            // std::wcout << L"timestamp: " << jsonValue[U("timestamp")].as_double() << std::endl;
            // std::wcout << L"NextCPUTmp: " << jsonValue[U("NextCPUTmp")].as_double() << std::endl;

            // cout << jsonValue << endl;

            // json::value ibmc_jv;
            // ibmc_jv["timestamp"] = static_cast<int>(jsonValue[U("timestamp")].as_double());
            // ibmc_jv["NextCPUTmp"] = json::value::number(static_cast<int>(jsonValue[U("NextCPUTmp")].as_double()));

            // cout << ibmc_jv << endl;

            if(CoolingAlgoString == "LFC"){
                string lfcuri = "/redfish/v1/FanLFCiBMC";

                // temp 데이터
                http_response temp_response;
                temp_response = this->sendRequest(this->cmm_address, lfcuri, methods::PATCH, jsonValue);

                if(temp_response.status_code() == status_codes::OK){
                    cout << CoolingAlgoString << " control OK";
                    cout << ", timestamp: " << jsonValue[U("timestamp")].as_double();
                    cout << ", NextCPUTemp: " << jsonValue[U("NextCPUTmp")].as_double();
                    cout << ", PkgTmp: " << jsonValue[U("PkgTmp")].as_double();
                    //PkgTmp
                    cout << endl;
                }
                else
                    cout << CoolingAlgoString << " control BadRequest" << endl;
            }
            else{
                string nonlfcuri = "/redfish/v1/FannonLFCiBMC";

                // temp 데이터
                http_response temp_response;
                temp_response = this->sendRequest(this->cmm_address, nonlfcuri, methods::PATCH, jsonValue);

                if(temp_response.status_code() == status_codes::OK){
                    cout << CoolingAlgoString << " control OK";
                    cout << ", timestamp: " << jsonValue[U("timestamp")].as_double();
                    cout << ", NextCPUTemp: " << jsonValue[U("NextCPUTmp")].as_double();
                    cout << ", PkgTmp: " << jsonValue[U("PkgTmp")].as_double();
                    //PkgTmp
                    cout << endl;
                }
                else
                    cout << CoolingAlgoString << " control BadRequest" << endl;
            }
            once = true;
        }
        else{
            if(once){
                string mode_uri = "/redfish/v1/FanTemperatureCriteria";

                json::value j_tempcrit;
                j_tempcrit["TemperatureCriteria"] = json::value::string("Max");

                http_response mode_response;
                mode_response = this->sendRequest(this->cmm_address, mode_uri, methods::PATCH, j_tempcrit);

                if(mode_response.status_code() == status_codes::OK)
                    cout << "Max mode control OK" << endl;
                else
                    cout << "Max mode control BadRequest" << endl;

                // // Parse the JSON string into a web::json::value
                once = false;
            }
            
        }
        sleep(1);
    }
    
}

void EnergyRestClient::controlHostAgent(){
    std::string powerfilename = "/conf/CPUPower.json";
    string hostAgentUri = "/cpulimit";
    string hostAgentIp = "http://10.0.4.143:8080";
    while(1){
        std::ifstream powerInputFile(powerfilename);
        if (!powerInputFile.is_open()) {
            std::cerr << "Failed to open the file for reading.: " << powerfilename << std::endl;
            sleep(1);
            continue;
        }
        // Read the JSON content into a string
        std::string powerJsonData((std::istreambuf_iterator<char>(powerInputFile)), std::istreambuf_iterator<char>());

        // Close the file
        powerInputFile.close();
        web::json::value powerJsonValue;
        try
        {
            powerJsonValue = web::json::value::parse(utility::conversions::to_string_t(powerJsonData));
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << "cpupower json read failed";
            std::cout << "\033[0m";
        }

        http_response mode_response;
        mode_response = this->sendRequest(hostAgentIp, hostAgentUri, methods::PUT, powerJsonValue);

        if(mode_response.status_code() == status_codes::OK)
            cout << "Agent control OK" << endl;
        else
            cout << "Agent control BadRequest" << endl;

        sleep(1);
    }
}


void EnergyRestClient::getCPUValue(){
    string uri = "/cpuValue";
    http_response response;
    while(1){
        http_client client("http://10.0.4.143:8080");
        http_request req(methods::GET);
        req.headers().set_content_type(web::http::details::mime_types::application_json);
        // req.headers().add("Access-Control-Allow-Origin", "*");
        // req.headers().add("Access-Control-Allow-Credentials", "true");
        // req.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
        // req.headers().add("Access-Control-Max-Age", "3600");
        // req.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
        // req.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");
        
        req.set_request_uri(uri);

        http_response response;
        

        try
        {
            pplx::task<http_response> responseTask = client.request(req);
            response = responseTask.get();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            response.set_status_code(status_codes::BadRequest);
        }

        if(response.status_code() == status_codes::OK){
            cout << "getCPUValue OK" << endl;
            json::value jv = response.extract_json().get();
            cout << jv << endl;
            this->saveJson(jv, "/conf/CPU_VALUE.json");
        }

        else{
            cout << "getCPUValue BadRequest" << endl;
            // json::value jv = response.extract_json().get();
            // cout << jv << endl;
        }


        sleep(3);
    }
}

void EnergyRestClient::sendPSUWattAlgoValue(){
    string uri = "/lstm";
    string psufilename = this->psu_data_path;
    string coolingAlgoFilename = this->cooling_algo_path;
    http_response response;
    while(1){
        std::ifstream psuInputFile(psufilename);
        if (!psuInputFile.is_open()) {
            std::cerr << "Failed to open the file for reading.: " << psufilename << std::endl;
            sleep(1);
            continue;
        }
        // Read the JSON content into a string
        std::string psuJsonData((std::istreambuf_iterator<char>(psuInputFile)), std::istreambuf_iterator<char>());

        // Close the file
        psuInputFile.close();
        web::json::value psuJsonValue;
        json::value lstmjv;
        try
        {
            psuJsonValue = web::json::value::parse(utility::conversions::to_string_t(psuJsonData));
            lstmjv["ChassisWatt"] = psuJsonValue["PSU0"]["SMBusIPMIFRU"]["InputPower"]["Value"];
            // cout << lstmjv << endl;
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << psufilename << " read failed";
            std::cout << "\033[0m";
            continue;
        }

        std::ifstream coolingalgoInputFile(coolingAlgoFilename);
        if (!coolingalgoInputFile.is_open()) {
            std::cerr << "Failed to open the file for reading.: " << coolingAlgoFilename << std::endl;
            sleep(1);
            continue;
        }
        // Read the JSON content into a string
        std::string coolingalgoJsonData((std::istreambuf_iterator<char>(coolingalgoInputFile)), std::istreambuf_iterator<char>());

        // Close the file
        coolingalgoInputFile.close();
        web::json::value coolingalgoJsonValue;
        try
        {
            coolingalgoJsonValue = web::json::value::parse(utility::conversions::to_string_t(coolingalgoJsonData));
            lstmjv["CoolingAlgorithm"] = coolingalgoJsonValue["CoolingAlgorithm"];
            cout << lstmjv << endl;
        }
        catch(const std::exception& e)
        {
            std::ostringstream oss;
            oss << "\033[1;" << 35 << "m"; // magenta
            std::cout << oss.str();

            std::cerr << e.what() << '\n';
            log(warning) << coolingAlgoFilename << " read failed";
            std::cout << "\033[0m";
            continue;
        }



        http_response mode_response;

        mode_response = this->sendRequest("http://10.0.4.143:8000", uri, methods::POST, lstmjv);
        if(response.status_code() == status_codes::OK){
            cout << "sendPSUWattAlgoValue " << uri << " OK" << endl;
        }
        else{
            cout << "sendPSUWattAlgoValue " << uri << " BadRequest" << endl;
        }

        sleep(1);
    }
}

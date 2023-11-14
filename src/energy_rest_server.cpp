#include "energy_rest_server.hpp"

// extern unordered_map<string, Resource *> g_record;
// extern unordered_map<uint8_t, Task_Manager *> task_map;
// extern ChassisFan *chassis_Fan[CHASSIS_MAX_FAN];
// // extern unordered_map<string, unordered_map<string, Task *> > task_map;
// extern Value_About_HA ha_value;
// unsigned int g_count = 0;
// //ssdp timer
// long long last_time,findlast_time;
// long long current_time,findcurrent_time;


/**
 * @brief GET method request handler
 * 
 * @param _request Request object
 */
void EnergyRestServer::handleGet(http_request _request)
{
    log(info) << "Request method: GET";
    std::string uri = _request.request_uri().to_string();
    vector<string> uri_tokens = string_split(uri, '/');
    std::string filtered_uri = make_path(uri_tokens);
    log(info) << "Reqeust URL : " << filtered_uri;
    log(info) << "Request Body : " << _request.to_string();


    //여기에 pplx시작하면 될듯
    _request
    .extract_json()
    .then([&_request, uri_tokens, uri](pplx::task<json::value> json_value){
        try
        {
            // #오픈시스넷 CORS 처리용
            http_response response;

            response.headers().add("Access-Control-Allow-Origin", "*");
            response.headers().add("Access-Control-Allow-Credentials", "true");
            response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
            response.headers().add("Access-Control-Max-Age", "3600");
            response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
            response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");

            // log(info) << "json_value : " << json_value.get().to_string();

            if(uri == "/")
            {
                json::value j;
                j["Message"] = json::value::string("Uri '/' is not supported");
                response.set_status_code(status_codes::BadRequest);
                response.set_body(j);
                _request.reply(response);
                // _request.reply(status_codes::OK, j);
                return ;
            }

            // update file test
            if(uri_tokens[0] == "asdfasdf")
            {
                json::value j;
                j["Version"] = json::value::string("OLD Version");
                // j["Version"] = json::value::string("NEW Version");
                response.set_status_code(status_codes::OK);
                response.set_body(j);
                _request.reply(response);
                return ;

            }
                
            

            // [HA] 
            if(uri_tokens[0] == "heartbeat")
            {
                response.set_status_code(status_codes::OK);
                _request.reply(response);
                return ;
            }


            if(uri_tokens[0] == "myuri")
            {
                string host, path, query, fragment;
                int port;
                host = _request.request_uri().host();
                port = _request.request_uri().port();
                path = _request.request_uri().path();
                query = _request.request_uri().query();
                fragment = _request.request_uri().fragment();
                cout << "PRINT >> " << endl;
                cout << "Host : " << host << endl;
                cout << "Port : " << port << endl;
                cout << "Path : " << path << endl;
                cout << "Query : " << query << endl;
                cout << "Fragment : " << fragment << endl;
                map<string, string> mm;
                mm = uri::split_query(query);
                map<string, string>::iterator iter;
                cout << "Split -------------" << endl;
                for(iter = mm.begin(); iter != mm.end(); iter++)
                {
                    cout << iter->first << " / " << iter->second << endl;
                }

                _request.reply(status_codes::Locked);
                return ;

            }

            if(uri_tokens[0] == "datasync"){
                //string tarcmd = "tar jcvf ";
                string tarcmd = "tar jcf ";
                string tarpath = "/tmp/datasync.tar.gz";
                tarcmd += tarpath;
                tarcmd += " /redfish/v1";
                tarcmd += " /redfish/v1.json";
                tarcmd += " /redfish/log.db";
                tarcmd += " /conf/module/table.json";
                tarcmd += " /conf/fan/config.ini";
                system(tarcmd.c_str());
                _request.reply(status_codes::OK, Concurrency::streams::fstream::open_istream(tarpath).get())
                .then([](){
                    system("rm -rf /tmp/datasync.tar.gz");
                });
            }

            if(uri == "/reading/temp")
            {
                json::value rep;
                // rep = select_all_reading("Temperature");
                _request.reply(status_codes::OK, rep);
                return ;
            }
            response.set_status_code(status_codes::BadRequest);
            _request.reply(response);
            return ;

        }
        catch(json::json_exception& e)
        {
            http_response response;

            response.headers().add("Access-Control-Allow-Origin", "*");
            response.headers().add("Access-Control-Allow-Credentials", "true");
            response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
            response.headers().add("Access-Control-Max-Age", "3600");
            response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
            response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");

            response.set_status_code(status_codes::BadRequest);
            _request.reply(response);
            // _request.reply(status_codes::BadRequest);
            return ;
        }
        

    })
    .wait();

}

/**
 * @brief DELETE request handler
 * 
 * @param _request Request object
 */
void EnergyRestServer::handleDelete(http_request _request)
{
    /**
     * @brief ODATA_ACCOUNT_ID 로 계정삭제
     * @authors 강
     * @details UserName 이랑 Password 둘다 일치하는 녀석을 지움
     * 
     * // record(ODATA_ACCOUNT_ID+/username) 을 지웠고 AccountService의 collection에서 지웠음
     */
    string uri = _request.request_uri().to_string();
    vector<string> uri_tokens = string_split(uri, '/');
    string filtered_uri = make_path(uri_tokens);


    log(info) << "Request method: DELETE";
    log(info) << "Reqeust uri : " << filtered_uri;

    http_response response;

    response.headers().add("Access-Control-Allow-Origin", "*");
    response.headers().add("Access-Control-Allow-Credentials", "true");
    response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
    response.headers().add("Access-Control-Max-Age", "3600");
    response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
    response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");


    // catch(json::json_exception &e)
    // {
    //     _request.reply(status_codes::BadRequest);
    // }

    // @@@@@@ 여기까지

    cout << "handle_delete request" << endl;

    // auto j = _request.extract_json().get();

    // _request.reply(status_codes::NotImplemented, U("DELETE Request Response"));
}

/**
 * @brief PUT request handler
 * 
 * @param _request Request object
 */
void EnergyRestServer::handlePut(http_request _request)
{

    // log(info) << "Request method: PATCH";
    // string uri = _request.request_uri().to_string();
    // vector<string> uri_tokens = string_split(uri, '/');
    // string filtered_uri = make_path(uri_tokens);
    // log(info) << "Reqeust URL : " << filtered_uri;
    // log(info) << "Request Body : " << _request.to_string();

    // try
    // {
    //     /* code */
    //     // if(uri_tokens.size() )
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    

    cout << "handle_put request" << endl;

    auto j = _request.extract_json().get();

    _request.reply(status_codes::NotImplemented, U("PUT Request Response"));
}

// #include <fstream>
// #include <cpprest/filestream.h>
/**
 * @brief POST request handler
 * 
 * @param _request Request object
 */
//using namespace concurrency::streams;
void EnergyRestServer::handlePost(http_request _request)
{

    log(info) << "Request method: POST";
    string uri = _request.request_uri().to_string();
    vector<string> uri_tokens = string_split(uri, '/');
    string filtered_uri = make_path(uri_tokens);
    log(info) << "Reqeust URL : " << filtered_uri;
    log(info) << "Request Body : " << _request.to_string();

    http_response response;

    response.headers().add("Access-Control-Allow-Origin", "*");
    response.headers().add("Access-Control-Allow-Credentials", "true");
    response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
    response.headers().add("Access-Control-Max-Age", "3600");
    response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
    response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");

    try
    {
        // 하이픈 동작 확인
        if(uri_tokens.size() == 1 && uri_tokens[0] == "CM1-REST")
        {
            // json::value j;
            // j["Content"] = json::value::string(uri_tokens[0]);
            // response.set_status_code(status_codes::OK);
            // response.set_body(j);
            // _request.reply(response);
            http_response rrr;
            rrr.headers().add("Access-Control-Allow-Origin", "*");
            rrr.headers().add("Access-Control-Allow-Credentials", "true");
            rrr.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
            rrr.headers().add("Access-Control-Max-Age", "3600");
            rrr.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
            rrr.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");

            // auto in_filestream = concurrency::streams::fstream::open_istream("/redfish/v1.json").get();
            auto in_filestream = concurrency::streams::fstream::open_istream("/redfish_directory.tar").get();

            rrr.set_body(in_filestream);//, _XPLATSTR("application/octet-stream"));
            rrr.set_status_code(status_codes::OK);
            // rrr.headers().set_content_type("image/png");
            rrr.headers().set_content_type("application/x-tar");
            // 파일전송 사용할때 나중에 파일 유형에따라서 content-type 다르게 해줘야함
            _request.reply(rrr);
            return ;
        }

        // ftft
        if(uri_tokens.size() == 1 && uri_tokens[0] == "ftft")
        {
            
            // auto fileStream = std::make_shared<Concurrency::streams::ostream >();
            // //저장할 파일 이름 생성
            //pplx::task<void> fileStream=Concurrency::streams::fstream::open_ostream("filename", std::ios_base::in | std::ios_base::out |std::ios::binary).get();
            string filepath="filesavetest.txt";
            // string header = _request.headers()["Content-Type"];
            // cout << "HEADER : " << header << endl;
            // string boundary = header.substr(header.find("boundary=")+9, header.find("\r")-(header.find("boundary=")+9));
            // cout << "BOUNDARY : " << boundary << endl;

            auto bodyStream = _request.body();
            auto fileStream = concurrency::streams::fstream::open_ostream(utility::conversions::to_string_t(filepath), std::ios::out | std::ios::binary).get();
            fileStream.flush();
            // cout << "ASDFASDF : " << endl << bodyStream.extract().get() << endl;
            // auto my_stream = concurrency::streams::streambuf()
            bodyStream.read_to_end(fileStream.streambuf()).wait();
            fileStream.close().wait();
            
            _request.reply(status_codes::OK);
            return ;
        }

        // /Heartbeat 
        if(uri_tokens.size() == 1 && uri_tokens[0] == "Heartbeat")
        {
            json::value j;
            json::value j_cycle;
            j_cycle = _request.extract_json().get();
            if(j_cycle.as_object().find("Cycle") == j_cycle.as_object().end())
            {
                response.set_status_code(status_codes::BadRequest);
                _request.reply(response);
                // _request.reply(status_codes::BadRequest);
                return ;
            }


            j[U("Status")] = json::value::string("OK");
            response.set_status_code(status_codes::OK);
            response.set_body(j);
            _request.reply(response);
            // _request.reply(status_codes::OK, j);
            return ;
        }

        if(uri_tokens.size() == 1 && uri_tokens[0] == "Command")
        {
            // string path받아서 명령어처리
            json::value command_info, j;
            command_info = _request.extract_json().get();

            if(command_info.as_object().find("Cmd") == command_info.as_object().end()
            || command_info.as_object().find("Path") == command_info.as_object().end())
            {
                response.set_status_code(status_codes::BadRequest);
                _request.reply(response);
                // _request.reply(status_codes::BadRequest);
                return ;
            }

            string cmd, path, result;
            cmd = command_info.at("Cmd").as_string();
            path = command_info.at("Path").as_string();

            char *boo = (char *)path.c_str();
            char *res;

            res = get_popen_string(boo);
            result = res;
            // cout << "RESULT!!!! : " << result << endl;

            // Todo
            // (popen하는 시간땜에 1초정도 쉬고)
            // 로드(스탠바이상태인 cmm녀석이 백업을 하는거)

            j[U("Status")] = json::value::string("OK");
            // cout << "dd : " << result << endl;
            // j[U("Result")] = json::value::string(result);

            response.set_status_code(status_codes::OK);
            // cout << "STATUS : " << response.status_code() << endl;
            response.set_body(j);
            // cout << "BODY : " << j << endl;
            _request.reply(response);
            // _request.reply(status_codes::OK, j);
            return ;
            // Cmd가 FileSync 일 때 자기랑 반대되는 cmm에다가 json파일 보낸거 읽어서 백업하기

        }

        // 내부 api /command/~~로 정리할까 생각중
        if(uri == "/command/inner/sensorupdate")
        {
            // #1 extract_json 해서 리퀘스트 바디받아오면 array형식으로 센서 좌라락 들어옴
            // #2 거기서 먼저 모듈id읽고 모듈id 테이블에서 추가된 모듈인가 체크
            // #3 있으면 이제 array member 1개에서 센서id읽고 /~~/Chassis/모듈id/Sensors/센서id가 리소스로 존재하
            // 는지를 검사함 >>>>  존재한다->#4, 존재않는다->#5
            // #4 존재하면 리소스의 reading time과 json body의 reading time을 비교해서 최신시간으로 변경되었으면
            // 리소스의 reading time과 reading 값 업데이트
            // #5 존재하지 않는다면 리소스를 생성하고 넘겨받은 정보들로 값 넣어줌
            // #6 4,5 두 경우 모두 수행하고나서 DataBase Reading Table에 로그기록 insert해줘야함

            
            _request.reply(status_codes::OK);
            return ;
        }

        /*hg*/
        if (uri_tokens.size() == 1 && uri_tokens[0] == "smartfan") {
            http_response response;
            json::value j;
            j[U("message")] = json::value::string("save next period cpu temp");
            response.set_status_code(status_codes::OK);
            response.set_body(j);
            _request.reply(response);
            return;
        }
        /*hg end*/
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        response.set_status_code(status_codes::BadRequest);
        _request.reply(response);
        // _request.reply(status_codes::BadRequest);
        return ;
    }
        

}

/**
 * @brief PATCH request handler
 * @authors 강
 * @param _request Request object
 */
void EnergyRestServer::handlePatch(http_request _request)
{
    log(info) << "Request method: PATCH";
    string uri = _request.request_uri().to_string();
    vector<string> uri_tokens = string_split(uri, '/');
    string filtered_uri = make_path(uri_tokens);
    log(info) << "Reqeust URL : " << filtered_uri;
    log(info) << "Request Body : " << _request.to_string();

    // cout << "HELL YEAH" << endl;
    // cout << _request.get_remote_address() << endl;
    // cout << _request.remote_address() << endl;

    http_response response;

    response.headers().add("Access-Control-Allow-Origin", "*");
    response.headers().add("Access-Control-Allow-Credentials", "true");
    response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
    response.headers().add("Access-Control-Max-Age", "3600");
    response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
    response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");
    

    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        response.set_status_code(status_codes::BadRequest);
        _request.reply(response);
        // _request.reply(status_codes::BadRequest);
        return ;
    }
    
}

/**
 * @brief OPTIONS request handler
 * 
 * @param _request Request object
 */
void EnergyRestServer::handleOptions(http_request _request)
{
    log(info) << "Request method: OPTIONS";
    string uri = _request.request_uri().to_string();
    vector<string> uri_tokens = string_split(uri, '/');
    string filtered_uri = make_path(uri_tokens);
    log(info) << "Reqeust URL : " << filtered_uri;
    log(info) << "Request Body : " << _request.to_string();

    cout << "handle_options request" << endl;

    http_response response(status_codes::OK);
    response.headers().add("Access-Control-Allow-Origin", "*");
    response.headers().add("Access-Control-Allow-Credentials", "true");
    response.headers().add("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PATCH");
    response.headers().add("Access-Control-Max-Age", "3600");
    response.headers().add("Access-Control-Allow-Headers", "Content-Type, Accept, X-Requested-With, remember-me, X-Auth-Token");
    response.headers().add("Access-Control-Expose-Headers", "X-Auth-Token, Location");
    _request.reply(response);
    return ;
}

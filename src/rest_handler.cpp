#include "rest_handler.hpp"

Handler::Handler(utility::string_t _url, http_listener_config _config) : m_listener(_url, _config)
{
    // Handler connection
    this->m_listener.support(methods::GET, bind(&Handler::handleGet, this, std::placeholders::_1));
    this->m_listener.support(methods::PUT, bind(&Handler::handlePut, this, std::placeholders::_1));
    this->m_listener.support(methods::POST, bind(&Handler::handlePost, this, std::placeholders::_1));
    this->m_listener.support(methods::DEL, bind(&Handler::handleDelete, this, std::placeholders::_1));
    this->m_listener.support(methods::PATCH, bind(&Handler::handlePatch, this, std::placeholders::_1));
    this->m_listener.support(methods::OPTIONS, bind(&Handler::handleOptions, this, std::placeholders::_1));
}

// /*hg start*/
// void handlePost(http_request message){
//     std::string uri_path = message.relative_uri().to_string();
//     cout<<uri_path<<endl;

//     auto body_json = message.extract_string();
//     std::string json = utility::conversions::to_utf8string(body_json.get());
//     cout << json << endl;

//     //파일 저장
//     std::string filePath = "/conf/lfc.json";
//     std::ofstream outputFile(filePath);

//     if(outputFile.is_open()){
//         outputFile << json;
//         outputFile.close();
//         std::cout<<"Success Store Json Data"<<std::endl;
//     }
//     else{
//         std::cerr<<"Failed to Store Smart Data"<<std::endl;
//     }

//     if(uri_path == "/smartfan"){
//         cout<<"smartfan post request"<<endl;
        
//     }
//     cout<<"Sending ok"<<endl;
//     message.reply(status_codes::OK);
// }
// /*hg end*/
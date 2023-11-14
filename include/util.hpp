#include "stdafx.hpp"

vector<string> string_split(const string _string, char _delimiter);

bool get_value_from_json_key(json::value body, string key, int& value);

bool get_value_from_json_key(json::value body, string key, unsigned int& value);

bool get_value_from_json_key(json::value body, string key, string& value);

bool get_value_from_json_key(json::value body, string key, json::value& value);

bool get_value_from_json_key(json::value body, string key, double& value);

bool get_value_from_json_key(json::value body, string key, bool& value);

char *get_popen_string(char *command);

string get_popen_string(string command);

http_response sendRequest(string addr, string uri, web::http::method method, json::value jv);

string make_path(vector<string> _tokens);

json::value redfish_request_get(string _path, string _url);
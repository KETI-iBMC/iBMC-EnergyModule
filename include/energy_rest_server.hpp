#ifndef __ENERGY_REST_SERVER__
#define __ENERGY_REST_SERVER__

#include "rest_handler.hpp"


class EnergyRestServer : public Handler {
    private:
        void handleGet(http_request _request);
        void handlePut(http_request _request);
        void handlePost(http_request _request);
        void handleDelete(http_request _request);
        void handlePatch(http_request _request);
        void handleOptions(http_request _request);
    public:
        EnergyRestServer(const utility::string_t& uri) : Handler(){
            
        }

};

#endif
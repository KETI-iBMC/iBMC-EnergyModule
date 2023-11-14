#ifndef __REST_HANDLER__
#define __REST_HANDLER__
#include "util.hpp"

class Handler {
public:
    // Constructor
    Handler(){};
    Handler(utility::string_t _url, http_listener_config _config);

    // Destructor
    ~Handler(){};

    // Server operation
    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

protected:
    http_listener m_listener;

    // Request handler
    virtual void handleGet(http_request _request){}
    virtual void handlePut(http_request _request){}
    virtual void handlePost(http_request _request){}
    virtual void handleDelete(http_request _request){}
    virtual void handlePatch(http_request _request){}
    virtual void handleOptions(http_request _request){}
};

#endif
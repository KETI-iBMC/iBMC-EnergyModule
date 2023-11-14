#include "proxy_wrap.hpp"

Feedback_Proxy::Feedback_Proxy(DBus::Connection &connection, const char *path,
    const char *name) : DBus::ObjectProxy(connection, path, name) {}
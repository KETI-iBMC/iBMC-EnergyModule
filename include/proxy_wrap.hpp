#ifndef __PROXY_WRAP__
#define __PROXY_WRAP__


#include <dbus-c++-1/dbus-c++/dbus.h>
#include <cassert>

#include "feedback_proxy.hpp"

// class Ibmc_Proxy : public org::freedesktop::keti::bmc::ibmc_proxy,
//                    public DBus::IntrospectableProxy,
//                    public DBus::ObjectProxy {
//  public:
//   Ibmc_Proxy(DBus::Connection &connection, const char *path,
//                    const char *name);
//   ~Ibmc_Proxy(){};
// };

// class Policy_Proxy : public org::freedesktop::keti::bmc::policy_proxy,
//                    public DBus::IntrospectableProxy,
//                    public DBus::ObjectProxy {
//  public:
//   Policy_Proxy(DBus::Connection &connection, const char *path,
//                    const char *name);
//   ~Policy_Proxy(){};
// };

// class Monitor_Proxy : public org::freedesktop::keti::bmc::monitor_proxy,
//                    public DBus::IntrospectableProxy,
//                    public DBus::ObjectProxy {
//  public:
//   Monitor_Proxy(DBus::Connection &connection, const char *path,
//                    const char *name);
//   ~Monitor_Proxy(){};
// };

// class Energy_Proxy : public org::freedesktop::keti::bmc::energy_proxy,
//                    public DBus::IntrospectableProxy,
//                    public DBus::ObjectProxy {
//  public:
//   Energy_Proxy(DBus::Connection &connection, const char *path,
//                    const char *name);
//   ~Energy_Proxy(){};
// };

// class Ssp_Proxy : public org::freedesktop::keti::bmc::ssp_proxy,
//                    public DBus::IntrospectableProxy,
//                    public DBus::ObjectProxy {
//  public:
//   Ssp_Proxy(DBus::Connection &connection, const char *path,
//                    const char *name);
//   ~Ssp_Proxy(){};
// };

class Feedback_Proxy : public org::freedesktop::keti::bmc::feedback_proxy,
                   public DBus::IntrospectableProxy,
                   public DBus::ObjectProxy {
 public:
  Feedback_Proxy(DBus::Connection &connection, const char *path,
                   const char *name);
  ~Feedback_Proxy(){};
};

#endif
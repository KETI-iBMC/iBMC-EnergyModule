#ifndef __ENERGY_DBUS_CLIENT_MANAGER__
#define __ENERGY_DBUS_CLIENT_MANAGER__

#include "energy_adaptor_wrap.hpp"
#include "proxy_wrap.hpp"

class EnergyDBusClientManager : public Monostate<EnergyDBusClientManager>{
    private:
        void energyLoop();
        void connectFeedbackServer(); // thread
    public:
};

#endif
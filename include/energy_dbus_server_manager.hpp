#ifndef __ENERGY_DBUS_SERVER_MANAGER__
#define __ENERGY_DBUS_SERVER_MANAGER__

#include "energy_adaptor_wrap.hpp"
#include "proxy_wrap.hpp"

class EnergyDBusServerManager : public Monostate<EnergyDBusServerManager>{
    private:
        void energyLoop();
    public:
};

#endif
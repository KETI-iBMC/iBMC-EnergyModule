#ifndef __ENERGY_ADAPTOR_WRAP__
#define __ENERGY_ADAPTOR_WRAP__

#include "stdafx.hpp"
#include "energy_adaptor.hpp"
#include "energy_proxy.hpp"

class Energy_Adaptor : public org::freedesktop::keti::bmc::energy_adaptor,
	public DBus::IntrospectableAdaptor,
	public DBus::ObjectAdaptor

{
	public:
		Energy_Adaptor(DBus::Connection& connection);

		int32_t emm_ibmc();
		int32_t emm_policy();
		int32_t emm_feedback();
		int32_t emm_monitor();
		int32_t emm_ssp();
};

#endif
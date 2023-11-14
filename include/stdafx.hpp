#ifndef __ENERGY_STDAFX__
#define __ENERGY_STDAFX__

#include <unistd.h>

#include <dbus-c++-1/dbus-c++/dbus.h>
#include <dbus-c++-1/dbus-c++/message.h>
#include <dbus-c++-1/dbus-c++/interface.h>

#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <cpprest/filestream.h>

#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <iostream>
#include <thread>
#include <string>

#include "singleton.hpp"
#include "iniparser.hpp"

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::http::experimental::listener;

namespace logging = boost::log;
namespace src = boost::log::sources;
// namespace sinks = boost::log::sinks;
// namespace keywords = boost::log::keywords;

using namespace logging::trivial;

/**
 * @brief Logging macro
 */
extern src::severity_logger<severity_level> g_logger;
#define log(level) BOOST_LOG_SEV(g_logger, level)


static const char *FEEDBACK_SERVER_NAME = "org.freedesktop.keti.bmc.feedback";
static const char *FEEDBACK_SERVER_PATH = "/org/freedesktop/keti/bmc/feedback";

static const char *POLICY_SERVER_NAME = "org.freedesktop.keti.bmc.policy";
static const char *POLICY_SERVER_PATH = "/org/freedesktop/keti/bmc/policy";

static const char *IBMC_SERVER_NAME = "org.freedesktop.keti.bmc.ibmc";
static const char *IBMC_SERVER_PATH = "/org/freedesktop/keti/bmc/ibmc";

static const char *MONITOR_SERVER_NAME = "org.freedesktop.keti.bmc.monitor";
static const char *MONITOR_SERVER_PATH = "/org/freedesktop/keti/bmc/monitor";

static const char *ENERGY_SERVER_NAME = "org.freedesktop.keti.bmc.energy";
static const char *ENERGY_SERVER_PATH = "/org/freedesktop/keti/bmc/energy";

static const char *SSP_SERVER_NAME = "org.freedesktop.keti.bmc.ssp";
static const char *SSP_SERVER_PATH = "/org/freedesktop/keti/bmc/ssp";

#endif
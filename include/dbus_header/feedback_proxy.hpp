
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__feedback_proxy_h__PROXY_MARSHAL_H
#define __dbusxx__feedback_proxy_h__PROXY_MARSHAL_H

#include <dbus-c++-1/dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace freedesktop {
namespace keti {
namespace bmc {

class feedback_proxy
: public ::DBus::InterfaceProxy
{
public:

    feedback_proxy()
    : ::DBus::InterfaceProxy("org.freedesktop.keti.bmc.feedback")
    {
    }

public:

    /* properties exported by this interface */
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    int32_t feedback_ibmc()
    {
        ::DBus::CallMessage call;
        call.member("feedback_ibmc");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    int32_t feedback_policy()
    {
        ::DBus::CallMessage call;
        call.member("feedback_policy");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    int32_t feedback_monitor()
    {
        ::DBus::CallMessage call;
        call.member("feedback_monitor");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    int32_t feedback_energy()
    {
        ::DBus::CallMessage call;
        call.member("feedback_energy");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    int32_t feedback_ssp()
    {
        ::DBus::CallMessage call;
        call.member("feedback_ssp");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } } 
#endif //__dbusxx__feedback_proxy_h__PROXY_MARSHAL_H

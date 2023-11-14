#!/bin/sh

dbusxx-xml2cpp energy.xml --proxy=energy_proxy.hpp --adaptor=energy_adaptor.hpp
mv energy_proxy.hpp energy_adaptor.hpp ../include/dbus_header
chown -R keti ../include/dbus_header/*

# Variable definition
## Execute file
set(
    OUTPUT
    KETI-EMM
)
set (
    SOURCE_FILES
    energy_dbus_server_manager.cpp
    energy_dbus_client_manager.cpp
    energy_adaptor_wrap.cpp
    proxy_wrap.cpp
    energy_rest_client.cpp
    energy_rest_server.cpp
    rest_handler.cpp
    util.cpp
    main.cpp
)


set(PROJECT_SOURCE_DIR /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM)


set(DBus_INCLUDE_DIR /home/keti/KETI_BMC/KETI-APP/sysroots/armv7ahf-vfpv4d16-KETI-linux-gnueabi/usr/include/dbus-c++-1)
include_directories(
   ${POPULATE_SDK_INCLUDE_DIR}
   ${INC_DIR}
   ${PROJECT_SOURCE_DIR}/include/
   ${PROJECT_SOURCE_DIR}/include/dbus_header
)
## Source
link_directories(
    ${POPULATE_SDK_LIBRARY_DIR}
)
# Build
add_executable(${OUTPUT} ${SOURCE_FILES})
target_link_libraries( ${OUTPUT}
    crypto 
    ssl
    pthread
    libdbus-c++-1.so.0
    boost_system
    boost_log
    boost_log_setup
    boost_thread
    cpprest
	#boost_program_options
    #${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libapps.a
)
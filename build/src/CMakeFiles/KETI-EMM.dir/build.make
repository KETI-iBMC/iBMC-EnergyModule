# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build

# Include any dependencies generated for this target.
include src/CMakeFiles/KETI-EMM.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/KETI-EMM.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/KETI-EMM.dir/flags.make

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o: ../src/energy_dbus_server_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_server_manager.cpp

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_server_manager.cpp > CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.i

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_server_manager.cpp -o CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.s

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o


src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o: ../src/energy_dbus_client_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_client_manager.cpp

src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_client_manager.cpp > CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.i

src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_dbus_client_manager.cpp -o CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.s

src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o


src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o: ../src/energy_adaptor_wrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_adaptor_wrap.cpp

src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_adaptor_wrap.cpp > CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.i

src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_adaptor_wrap.cpp -o CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.s

src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o


src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o: ../src/proxy_wrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/proxy_wrap.cpp

src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/proxy_wrap.cpp > CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.i

src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/proxy_wrap.cpp -o CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.s

src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o


src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o: ../src/energy_rest_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_client.cpp

src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_client.cpp > CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.i

src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_client.cpp -o CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.s

src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o


src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o: ../src/energy_rest_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_server.cpp

src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_server.cpp > CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.i

src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/energy_rest_server.cpp -o CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.s

src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o


src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o: ../src/rest_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/rest_handler.cpp

src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/rest_handler.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/rest_handler.cpp > CMakeFiles/KETI-EMM.dir/rest_handler.cpp.i

src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/rest_handler.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/rest_handler.cpp -o CMakeFiles/KETI-EMM.dir/rest_handler.cpp.s

src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o


src/CMakeFiles/KETI-EMM.dir/util.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/KETI-EMM.dir/util.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/util.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/util.cpp

src/CMakeFiles/KETI-EMM.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/util.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/util.cpp > CMakeFiles/KETI-EMM.dir/util.cpp.i

src/CMakeFiles/KETI-EMM.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/util.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/util.cpp -o CMakeFiles/KETI-EMM.dir/util.cpp.s

src/CMakeFiles/KETI-EMM.dir/util.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/util.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/util.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/util.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/util.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/util.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/util.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/util.cpp.o


src/CMakeFiles/KETI-EMM.dir/main.cpp.o: src/CMakeFiles/KETI-EMM.dir/flags.make
src/CMakeFiles/KETI-EMM.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/KETI-EMM.dir/main.cpp.o"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KETI-EMM.dir/main.cpp.o -c /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/main.cpp

src/CMakeFiles/KETI-EMM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KETI-EMM.dir/main.cpp.i"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/main.cpp > CMakeFiles/KETI-EMM.dir/main.cpp.i

src/CMakeFiles/KETI-EMM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KETI-EMM.dir/main.cpp.s"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src/main.cpp -o CMakeFiles/KETI-EMM.dir/main.cpp.s

src/CMakeFiles/KETI-EMM.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/KETI-EMM.dir/main.cpp.o.requires

src/CMakeFiles/KETI-EMM.dir/main.cpp.o.provides: src/CMakeFiles/KETI-EMM.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/KETI-EMM.dir/build.make src/CMakeFiles/KETI-EMM.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/KETI-EMM.dir/main.cpp.o.provides

src/CMakeFiles/KETI-EMM.dir/main.cpp.o.provides.build: src/CMakeFiles/KETI-EMM.dir/main.cpp.o


# Object files for target KETI-EMM
KETI__EMM_OBJECTS = \
"CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o" \
"CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o" \
"CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o" \
"CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o" \
"CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o" \
"CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o" \
"CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o" \
"CMakeFiles/KETI-EMM.dir/util.cpp.o" \
"CMakeFiles/KETI-EMM.dir/main.cpp.o"

# External object files for target KETI-EMM
KETI__EMM_EXTERNAL_OBJECTS =

src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/util.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/main.cpp.o
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/build.make
src/KETI-EMM: src/CMakeFiles/KETI-EMM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable KETI-EMM"
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KETI-EMM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/KETI-EMM.dir/build: src/KETI-EMM

.PHONY : src/CMakeFiles/KETI-EMM.dir/build

src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/energy_dbus_server_manager.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/energy_dbus_client_manager.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/energy_adaptor_wrap.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/proxy_wrap.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/energy_rest_client.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/energy_rest_server.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/rest_handler.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/util.cpp.o.requires
src/CMakeFiles/KETI-EMM.dir/requires: src/CMakeFiles/KETI-EMM.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/KETI-EMM.dir/requires

src/CMakeFiles/KETI-EMM.dir/clean:
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src && $(CMAKE_COMMAND) -P CMakeFiles/KETI-EMM.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/KETI-EMM.dir/clean

src/CMakeFiles/KETI-EMM.dir/depend:
	cd /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/src /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src /home/keti/KETI_BMC/KETI-APP/IBMC-APP/KETI-EMM/build/src/CMakeFiles/KETI-EMM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/KETI-EMM.dir/depend

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
CMAKE_SOURCE_DIR = "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build"

# Include any dependencies generated for this target.
include third_party/glfw/tests/CMakeFiles/threads.dir/depend.make

# Include the progress variables for this target.
include third_party/glfw/tests/CMakeFiles/threads.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/glfw/tests/CMakeFiles/threads.dir/flags.make

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o: third_party/glfw/tests/CMakeFiles/threads.dir/flags.make
third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o: ../third_party/glfw/tests/threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/threads.c.o   -c "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/tests/threads.c"

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/threads.c.i"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/tests/threads.c" > CMakeFiles/threads.dir/threads.c.i

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/threads.c.s"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/tests/threads.c" -o CMakeFiles/threads.dir/threads.c.s

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires:

.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides: third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires
	$(MAKE) -f third_party/glfw/tests/CMakeFiles/threads.dir/build.make third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides.build
.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides

third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides.build: third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o


third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o: third_party/glfw/tests/CMakeFiles/threads.dir/flags.make
third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o: ../third_party/glfw/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/__/deps/tinycthread.c.o   -c "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/tinycthread.c"

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/__/deps/tinycthread.c.i"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/tinycthread.c" > CMakeFiles/threads.dir/__/deps/tinycthread.c.i

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/__/deps/tinycthread.c.s"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/tinycthread.c" -o CMakeFiles/threads.dir/__/deps/tinycthread.c.s

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires:

.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires
	$(MAKE) -f third_party/glfw/tests/CMakeFiles/threads.dir/build.make third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides.build
.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides.build: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o


third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o: third_party/glfw/tests/CMakeFiles/threads.dir/flags.make
third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o: ../third_party/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/__/deps/glad.c.o   -c "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/glad.c"

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/__/deps/glad.c.i"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/glad.c" > CMakeFiles/threads.dir/__/deps/glad.c.i

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/__/deps/glad.c.s"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/deps/glad.c" -o CMakeFiles/threads.dir/__/deps/glad.c.s

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.requires:

.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.requires

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.provides: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.requires
	$(MAKE) -f third_party/glfw/tests/CMakeFiles/threads.dir/build.make third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.provides.build
.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.provides

third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.provides.build: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o


# Object files for target threads
threads_OBJECTS = \
"CMakeFiles/threads.dir/threads.c.o" \
"CMakeFiles/threads.dir/__/deps/tinycthread.c.o" \
"CMakeFiles/threads.dir/__/deps/glad.c.o"

# External object files for target threads
threads_EXTERNAL_OBJECTS =

third_party/glfw/tests/threads: third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o
third_party/glfw/tests/threads: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o
third_party/glfw/tests/threads: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o
third_party/glfw/tests/threads: third_party/glfw/tests/CMakeFiles/threads.dir/build.make
third_party/glfw/tests/threads: third_party/glfw/src/libglfw3.a
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/librt.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libm.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libX11.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libXrandr.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libXinerama.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
third_party/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libXcursor.so
third_party/glfw/tests/threads: third_party/glfw/tests/CMakeFiles/threads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable threads"
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threads.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/glfw/tests/CMakeFiles/threads.dir/build: third_party/glfw/tests/threads

.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/build

third_party/glfw/tests/CMakeFiles/threads.dir/requires: third_party/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires
third_party/glfw/tests/CMakeFiles/threads.dir/requires: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires
third_party/glfw/tests/CMakeFiles/threads.dir/requires: third_party/glfw/tests/CMakeFiles/threads.dir/__/deps/glad.c.o.requires

.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/requires

third_party/glfw/tests/CMakeFiles/threads.dir/clean:
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" && $(CMAKE_COMMAND) -P CMakeFiles/threads.dir/cmake_clean.cmake
.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/clean

third_party/glfw/tests/CMakeFiles/threads.dir/depend:
	cd "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project" "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/third_party/glfw/tests" "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build" "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests" "/home/brothercarrillo/Dropbox (MIT)/Senior/6.837/finalproject/bijection-project/build/third_party/glfw/tests/CMakeFiles/threads.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : third_party/glfw/tests/CMakeFiles/threads.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/glenn/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/glenn/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/glenn/EXAMEN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glenn/EXAMEN/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EXAMEN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EXAMEN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EXAMEN.dir/flags.make

CMakeFiles/EXAMEN.dir/kvdb.c.o: CMakeFiles/EXAMEN.dir/flags.make
CMakeFiles/EXAMEN.dir/kvdb.c.o: ../kvdb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glenn/EXAMEN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EXAMEN.dir/kvdb.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EXAMEN.dir/kvdb.c.o   -c /home/glenn/EXAMEN/kvdb.c

CMakeFiles/EXAMEN.dir/kvdb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EXAMEN.dir/kvdb.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/glenn/EXAMEN/kvdb.c > CMakeFiles/EXAMEN.dir/kvdb.c.i

CMakeFiles/EXAMEN.dir/kvdb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EXAMEN.dir/kvdb.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/glenn/EXAMEN/kvdb.c -o CMakeFiles/EXAMEN.dir/kvdb.c.s

CMakeFiles/EXAMEN.dir/kvdb.c.o.requires:

.PHONY : CMakeFiles/EXAMEN.dir/kvdb.c.o.requires

CMakeFiles/EXAMEN.dir/kvdb.c.o.provides: CMakeFiles/EXAMEN.dir/kvdb.c.o.requires
	$(MAKE) -f CMakeFiles/EXAMEN.dir/build.make CMakeFiles/EXAMEN.dir/kvdb.c.o.provides.build
.PHONY : CMakeFiles/EXAMEN.dir/kvdb.c.o.provides

CMakeFiles/EXAMEN.dir/kvdb.c.o.provides.build: CMakeFiles/EXAMEN.dir/kvdb.c.o


CMakeFiles/EXAMEN.dir/getSet.c.o: CMakeFiles/EXAMEN.dir/flags.make
CMakeFiles/EXAMEN.dir/getSet.c.o: ../getSet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glenn/EXAMEN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/EXAMEN.dir/getSet.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EXAMEN.dir/getSet.c.o   -c /home/glenn/EXAMEN/getSet.c

CMakeFiles/EXAMEN.dir/getSet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EXAMEN.dir/getSet.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/glenn/EXAMEN/getSet.c > CMakeFiles/EXAMEN.dir/getSet.c.i

CMakeFiles/EXAMEN.dir/getSet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EXAMEN.dir/getSet.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/glenn/EXAMEN/getSet.c -o CMakeFiles/EXAMEN.dir/getSet.c.s

CMakeFiles/EXAMEN.dir/getSet.c.o.requires:

.PHONY : CMakeFiles/EXAMEN.dir/getSet.c.o.requires

CMakeFiles/EXAMEN.dir/getSet.c.o.provides: CMakeFiles/EXAMEN.dir/getSet.c.o.requires
	$(MAKE) -f CMakeFiles/EXAMEN.dir/build.make CMakeFiles/EXAMEN.dir/getSet.c.o.provides.build
.PHONY : CMakeFiles/EXAMEN.dir/getSet.c.o.provides

CMakeFiles/EXAMEN.dir/getSet.c.o.provides.build: CMakeFiles/EXAMEN.dir/getSet.c.o


CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o: CMakeFiles/EXAMEN.dir/flags.make
CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o: ../kvdbFunctions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glenn/EXAMEN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o   -c /home/glenn/EXAMEN/kvdbFunctions.c

CMakeFiles/EXAMEN.dir/kvdbFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EXAMEN.dir/kvdbFunctions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/glenn/EXAMEN/kvdbFunctions.c > CMakeFiles/EXAMEN.dir/kvdbFunctions.c.i

CMakeFiles/EXAMEN.dir/kvdbFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EXAMEN.dir/kvdbFunctions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/glenn/EXAMEN/kvdbFunctions.c -o CMakeFiles/EXAMEN.dir/kvdbFunctions.c.s

CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.requires:

.PHONY : CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.requires

CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.provides: CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.requires
	$(MAKE) -f CMakeFiles/EXAMEN.dir/build.make CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.provides.build
.PHONY : CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.provides

CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.provides.build: CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o


# Object files for target EXAMEN
EXAMEN_OBJECTS = \
"CMakeFiles/EXAMEN.dir/kvdb.c.o" \
"CMakeFiles/EXAMEN.dir/getSet.c.o" \
"CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o"

# External object files for target EXAMEN
EXAMEN_EXTERNAL_OBJECTS =

EXAMEN: CMakeFiles/EXAMEN.dir/kvdb.c.o
EXAMEN: CMakeFiles/EXAMEN.dir/getSet.c.o
EXAMEN: CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o
EXAMEN: CMakeFiles/EXAMEN.dir/build.make
EXAMEN: CMakeFiles/EXAMEN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glenn/EXAMEN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable EXAMEN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EXAMEN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EXAMEN.dir/build: EXAMEN

.PHONY : CMakeFiles/EXAMEN.dir/build

CMakeFiles/EXAMEN.dir/requires: CMakeFiles/EXAMEN.dir/kvdb.c.o.requires
CMakeFiles/EXAMEN.dir/requires: CMakeFiles/EXAMEN.dir/getSet.c.o.requires
CMakeFiles/EXAMEN.dir/requires: CMakeFiles/EXAMEN.dir/kvdbFunctions.c.o.requires

.PHONY : CMakeFiles/EXAMEN.dir/requires

CMakeFiles/EXAMEN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EXAMEN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EXAMEN.dir/clean

CMakeFiles/EXAMEN.dir/depend:
	cd /home/glenn/EXAMEN/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glenn/EXAMEN /home/glenn/EXAMEN /home/glenn/EXAMEN/cmake-build-debug /home/glenn/EXAMEN/cmake-build-debug /home/glenn/EXAMEN/cmake-build-debug/CMakeFiles/EXAMEN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EXAMEN.dir/depend


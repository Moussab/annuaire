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
CMAKE_COMMAND = /usr/local/Clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/Clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amrine/CLionProjects/annuaire

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amrine/CLionProjects/annuaire/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/annuaire.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/annuaire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/annuaire.dir/flags.make

CMakeFiles/annuaire.dir/main.c.o: CMakeFiles/annuaire.dir/flags.make
CMakeFiles/annuaire.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amrine/CLionProjects/annuaire/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/annuaire.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/annuaire.dir/main.c.o   -c /home/amrine/CLionProjects/annuaire/main.c

CMakeFiles/annuaire.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/annuaire.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amrine/CLionProjects/annuaire/main.c > CMakeFiles/annuaire.dir/main.c.i

CMakeFiles/annuaire.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/annuaire.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amrine/CLionProjects/annuaire/main.c -o CMakeFiles/annuaire.dir/main.c.s

CMakeFiles/annuaire.dir/main.c.o.requires:

.PHONY : CMakeFiles/annuaire.dir/main.c.o.requires

CMakeFiles/annuaire.dir/main.c.o.provides: CMakeFiles/annuaire.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/annuaire.dir/build.make CMakeFiles/annuaire.dir/main.c.o.provides.build
.PHONY : CMakeFiles/annuaire.dir/main.c.o.provides

CMakeFiles/annuaire.dir/main.c.o.provides.build: CMakeFiles/annuaire.dir/main.c.o


CMakeFiles/annuaire.dir/linkedList.c.o: CMakeFiles/annuaire.dir/flags.make
CMakeFiles/annuaire.dir/linkedList.c.o: ../linkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amrine/CLionProjects/annuaire/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/annuaire.dir/linkedList.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/annuaire.dir/linkedList.c.o   -c /home/amrine/CLionProjects/annuaire/linkedList.c

CMakeFiles/annuaire.dir/linkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/annuaire.dir/linkedList.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amrine/CLionProjects/annuaire/linkedList.c > CMakeFiles/annuaire.dir/linkedList.c.i

CMakeFiles/annuaire.dir/linkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/annuaire.dir/linkedList.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amrine/CLionProjects/annuaire/linkedList.c -o CMakeFiles/annuaire.dir/linkedList.c.s

CMakeFiles/annuaire.dir/linkedList.c.o.requires:

.PHONY : CMakeFiles/annuaire.dir/linkedList.c.o.requires

CMakeFiles/annuaire.dir/linkedList.c.o.provides: CMakeFiles/annuaire.dir/linkedList.c.o.requires
	$(MAKE) -f CMakeFiles/annuaire.dir/build.make CMakeFiles/annuaire.dir/linkedList.c.o.provides.build
.PHONY : CMakeFiles/annuaire.dir/linkedList.c.o.provides

CMakeFiles/annuaire.dir/linkedList.c.o.provides.build: CMakeFiles/annuaire.dir/linkedList.c.o


CMakeFiles/annuaire.dir/utilities.c.o: CMakeFiles/annuaire.dir/flags.make
CMakeFiles/annuaire.dir/utilities.c.o: ../utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amrine/CLionProjects/annuaire/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/annuaire.dir/utilities.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/annuaire.dir/utilities.c.o   -c /home/amrine/CLionProjects/annuaire/utilities.c

CMakeFiles/annuaire.dir/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/annuaire.dir/utilities.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amrine/CLionProjects/annuaire/utilities.c > CMakeFiles/annuaire.dir/utilities.c.i

CMakeFiles/annuaire.dir/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/annuaire.dir/utilities.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amrine/CLionProjects/annuaire/utilities.c -o CMakeFiles/annuaire.dir/utilities.c.s

CMakeFiles/annuaire.dir/utilities.c.o.requires:

.PHONY : CMakeFiles/annuaire.dir/utilities.c.o.requires

CMakeFiles/annuaire.dir/utilities.c.o.provides: CMakeFiles/annuaire.dir/utilities.c.o.requires
	$(MAKE) -f CMakeFiles/annuaire.dir/build.make CMakeFiles/annuaire.dir/utilities.c.o.provides.build
.PHONY : CMakeFiles/annuaire.dir/utilities.c.o.provides

CMakeFiles/annuaire.dir/utilities.c.o.provides.build: CMakeFiles/annuaire.dir/utilities.c.o


# Object files for target annuaire
annuaire_OBJECTS = \
"CMakeFiles/annuaire.dir/main.c.o" \
"CMakeFiles/annuaire.dir/linkedList.c.o" \
"CMakeFiles/annuaire.dir/utilities.c.o"

# External object files for target annuaire
annuaire_EXTERNAL_OBJECTS =

annuaire: CMakeFiles/annuaire.dir/main.c.o
annuaire: CMakeFiles/annuaire.dir/linkedList.c.o
annuaire: CMakeFiles/annuaire.dir/utilities.c.o
annuaire: CMakeFiles/annuaire.dir/build.make
annuaire: CMakeFiles/annuaire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amrine/CLionProjects/annuaire/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable annuaire"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/annuaire.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/annuaire.dir/build: annuaire

.PHONY : CMakeFiles/annuaire.dir/build

CMakeFiles/annuaire.dir/requires: CMakeFiles/annuaire.dir/main.c.o.requires
CMakeFiles/annuaire.dir/requires: CMakeFiles/annuaire.dir/linkedList.c.o.requires
CMakeFiles/annuaire.dir/requires: CMakeFiles/annuaire.dir/utilities.c.o.requires

.PHONY : CMakeFiles/annuaire.dir/requires

CMakeFiles/annuaire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/annuaire.dir/cmake_clean.cmake
.PHONY : CMakeFiles/annuaire.dir/clean

CMakeFiles/annuaire.dir/depend:
	cd /home/amrine/CLionProjects/annuaire/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amrine/CLionProjects/annuaire /home/amrine/CLionProjects/annuaire /home/amrine/CLionProjects/annuaire/cmake-build-debug /home/amrine/CLionProjects/annuaire/cmake-build-debug /home/amrine/CLionProjects/annuaire/cmake-build-debug/CMakeFiles/annuaire.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/annuaire.dir/depend


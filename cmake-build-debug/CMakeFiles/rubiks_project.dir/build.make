# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ahylp\rubiks_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ahylp\rubiks_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rubiks_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rubiks_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rubiks_project.dir/flags.make

CMakeFiles/rubiks_project.dir/src/main.c.obj: CMakeFiles/rubiks_project.dir/flags.make
CMakeFiles/rubiks_project.dir/src/main.c.obj: CMakeFiles/rubiks_project.dir/includes_C.rsp
CMakeFiles/rubiks_project.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ahylp\rubiks_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rubiks_project.dir/src/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\rubiks_project.dir\src\main.c.obj -c C:\Users\Ahylp\rubiks_project\src\main.c

CMakeFiles/rubiks_project.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rubiks_project.dir/src/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ahylp\rubiks_project\src\main.c > CMakeFiles\rubiks_project.dir\src\main.c.i

CMakeFiles/rubiks_project.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rubiks_project.dir/src/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ahylp\rubiks_project\src\main.c -o CMakeFiles\rubiks_project.dir\src\main.c.s

CMakeFiles/rubiks_project.dir/src/rubiks.c.obj: CMakeFiles/rubiks_project.dir/flags.make
CMakeFiles/rubiks_project.dir/src/rubiks.c.obj: CMakeFiles/rubiks_project.dir/includes_C.rsp
CMakeFiles/rubiks_project.dir/src/rubiks.c.obj: ../src/rubiks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ahylp\rubiks_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/rubiks_project.dir/src/rubiks.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\rubiks_project.dir\src\rubiks.c.obj -c C:\Users\Ahylp\rubiks_project\src\rubiks.c

CMakeFiles/rubiks_project.dir/src/rubiks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rubiks_project.dir/src/rubiks.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ahylp\rubiks_project\src\rubiks.c > CMakeFiles\rubiks_project.dir\src\rubiks.c.i

CMakeFiles/rubiks_project.dir/src/rubiks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rubiks_project.dir/src/rubiks.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ahylp\rubiks_project\src\rubiks.c -o CMakeFiles\rubiks_project.dir\src\rubiks.c.s

# Object files for target rubiks_project
rubiks_project_OBJECTS = \
"CMakeFiles/rubiks_project.dir/src/main.c.obj" \
"CMakeFiles/rubiks_project.dir/src/rubiks.c.obj"

# External object files for target rubiks_project
rubiks_project_EXTERNAL_OBJECTS =

rubiks_project.exe: CMakeFiles/rubiks_project.dir/src/main.c.obj
rubiks_project.exe: CMakeFiles/rubiks_project.dir/src/rubiks.c.obj
rubiks_project.exe: CMakeFiles/rubiks_project.dir/build.make
rubiks_project.exe: CMakeFiles/rubiks_project.dir/linklibs.rsp
rubiks_project.exe: CMakeFiles/rubiks_project.dir/objects1.rsp
rubiks_project.exe: CMakeFiles/rubiks_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ahylp\rubiks_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable rubiks_project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rubiks_project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rubiks_project.dir/build: rubiks_project.exe

.PHONY : CMakeFiles/rubiks_project.dir/build

CMakeFiles/rubiks_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rubiks_project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rubiks_project.dir/clean

CMakeFiles/rubiks_project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ahylp\rubiks_project C:\Users\Ahylp\rubiks_project C:\Users\Ahylp\rubiks_project\cmake-build-debug C:\Users\Ahylp\rubiks_project\cmake-build-debug C:\Users\Ahylp\rubiks_project\cmake-build-debug\CMakeFiles\rubiks_project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rubiks_project.dir/depend


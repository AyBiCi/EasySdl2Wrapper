# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/rotator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/rotator/build

# Include any dependencies generated for this target.
include CMakeFiles/Renderer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Renderer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Renderer.dir/flags.make

CMakeFiles/Renderer.dir/main.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/main.cpp.o: /home/user/rotator/main.cpp
CMakeFiles/Renderer.dir/main.cpp.o: CMakeFiles/Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/rotator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Renderer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Renderer.dir/main.cpp.o -MF CMakeFiles/Renderer.dir/main.cpp.o.d -o CMakeFiles/Renderer.dir/main.cpp.o -c /home/user/rotator/main.cpp

CMakeFiles/Renderer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/rotator/main.cpp > CMakeFiles/Renderer.dir/main.cpp.i

CMakeFiles/Renderer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/rotator/main.cpp -o CMakeFiles/Renderer.dir/main.cpp.s

CMakeFiles/Renderer.dir/renderer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/renderer.cpp.o: /home/user/rotator/renderer.cpp
CMakeFiles/Renderer.dir/renderer.cpp.o: CMakeFiles/Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/rotator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Renderer.dir/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Renderer.dir/renderer.cpp.o -MF CMakeFiles/Renderer.dir/renderer.cpp.o.d -o CMakeFiles/Renderer.dir/renderer.cpp.o -c /home/user/rotator/renderer.cpp

CMakeFiles/Renderer.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/rotator/renderer.cpp > CMakeFiles/Renderer.dir/renderer.cpp.i

CMakeFiles/Renderer.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/rotator/renderer.cpp -o CMakeFiles/Renderer.dir/renderer.cpp.s

# Object files for target Renderer
Renderer_OBJECTS = \
"CMakeFiles/Renderer.dir/main.cpp.o" \
"CMakeFiles/Renderer.dir/renderer.cpp.o"

# External object files for target Renderer
Renderer_EXTERNAL_OBJECTS =

Renderer: CMakeFiles/Renderer.dir/main.cpp.o
Renderer: CMakeFiles/Renderer.dir/renderer.cpp.o
Renderer: CMakeFiles/Renderer.dir/build.make
Renderer: /usr/lib/libSDL2main.a
Renderer: /usr/lib/libSDL2-2.0.so.0.2600.1
Renderer: CMakeFiles/Renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/rotator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Renderer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Renderer.dir/build: Renderer
.PHONY : CMakeFiles/Renderer.dir/build

CMakeFiles/Renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Renderer.dir/clean

CMakeFiles/Renderer.dir/depend:
	cd /home/user/rotator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/rotator /home/user/rotator /home/user/rotator/build /home/user/rotator/build /home/user/rotator/build/CMakeFiles/Renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Renderer.dir/depend


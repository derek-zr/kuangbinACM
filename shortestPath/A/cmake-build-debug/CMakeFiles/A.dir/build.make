# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/zhengr/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6262.62/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/zhengr/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6262.62/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A.dir/flags.make

CMakeFiles/A.dir/main.cpp.o: CMakeFiles/A.dir/flags.make
CMakeFiles/A.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A.dir/main.cpp.o -c /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/main.cpp

CMakeFiles/A.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/main.cpp > CMakeFiles/A.dir/main.cpp.i

CMakeFiles/A.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/main.cpp -o CMakeFiles/A.dir/main.cpp.s

# Object files for target A
A_OBJECTS = \
"CMakeFiles/A.dir/main.cpp.o"

# External object files for target A
A_EXTERNAL_OBJECTS =

A : CMakeFiles/A.dir/main.cpp.o
A : CMakeFiles/A.dir/build.make
A : CMakeFiles/A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A.dir/build: A

.PHONY : CMakeFiles/A.dir/build

CMakeFiles/A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A.dir/clean

CMakeFiles/A.dir/depend:
	cd /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug /Users/zhengr/Documents/codes/kuangbinACM/shortestPath/A/cmake-build-debug/CMakeFiles/A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A.dir/depend


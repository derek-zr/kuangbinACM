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
CMAKE_SOURCE_DIR = /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/H.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/H.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/H.dir/flags.make

CMakeFiles/H.dir/main.cpp.o: CMakeFiles/H.dir/flags.make
CMakeFiles/H.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/H.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/H.dir/main.cpp.o -c /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/main.cpp

CMakeFiles/H.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/H.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/main.cpp > CMakeFiles/H.dir/main.cpp.i

CMakeFiles/H.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/H.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/main.cpp -o CMakeFiles/H.dir/main.cpp.s

# Object files for target H
H_OBJECTS = \
"CMakeFiles/H.dir/main.cpp.o"

# External object files for target H
H_EXTERNAL_OBJECTS =

H : CMakeFiles/H.dir/main.cpp.o
H : CMakeFiles/H.dir/build.make
H : CMakeFiles/H.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable H"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/H.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/H.dir/build: H

.PHONY : CMakeFiles/H.dir/build

CMakeFiles/H.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/H.dir/cmake_clean.cmake
.PHONY : CMakeFiles/H.dir/clean

CMakeFiles/H.dir/depend:
	cd /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug /Users/zhengr/Documents/codes/kuangbinACM/simpleSearch/H/cmake-build-debug/CMakeFiles/H.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/H.dir/depend


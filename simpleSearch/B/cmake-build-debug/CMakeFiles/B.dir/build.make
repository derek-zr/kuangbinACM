# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\user\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6262.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\user\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6262.62\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\zr\codes\kuangbinACM\simpleSearch\B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B.dir/flags.make

CMakeFiles/B.dir/main.cpp.obj: CMakeFiles/B.dir/flags.make
CMakeFiles/B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-5~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B.dir\main.cpp.obj -c E:\zr\codes\kuangbinACM\simpleSearch\B\main.cpp

CMakeFiles/B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-5~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\zr\codes\kuangbinACM\simpleSearch\B\main.cpp > CMakeFiles\B.dir\main.cpp.i

CMakeFiles/B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-5~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\zr\codes\kuangbinACM\simpleSearch\B\main.cpp -o CMakeFiles\B.dir\main.cpp.s

# Object files for target B
B_OBJECTS = \
"CMakeFiles/B.dir/main.cpp.obj"

# External object files for target B
B_EXTERNAL_OBJECTS =

B.exe: CMakeFiles/B.dir/main.cpp.obj
B.exe: CMakeFiles/B.dir/build.make
B.exe: CMakeFiles/B.dir/linklibs.rsp
B.exe: CMakeFiles/B.dir/objects1.rsp
B.exe: CMakeFiles/B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B.dir/build: B.exe

.PHONY : CMakeFiles/B.dir/build

CMakeFiles/B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B.dir/clean

CMakeFiles/B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\zr\codes\kuangbinACM\simpleSearch\B E:\zr\codes\kuangbinACM\simpleSearch\B E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug E:\zr\codes\kuangbinACM\simpleSearch\B\cmake-build-debug\CMakeFiles\B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B.dir/depend


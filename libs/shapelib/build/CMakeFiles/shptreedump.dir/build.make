# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\code\shp_viewer_qt\libs\shapelib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\code\shp_viewer_qt\libs\shapelib\build

# Include any dependencies generated for this target.
include CMakeFiles/shptreedump.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shptreedump.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shptreedump.dir/flags.make

CMakeFiles/shptreedump.dir/shptreedump.c.obj: CMakeFiles/shptreedump.dir/flags.make
CMakeFiles/shptreedump.dir/shptreedump.c.obj: ../shptreedump.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\code\shp_viewer_qt\libs\shapelib\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/shptreedump.dir/shptreedump.c.obj"
	C:\Qt\Qt5.10.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\shptreedump.dir\shptreedump.c.obj   -c C:\code\shp_viewer_qt\libs\shapelib\shptreedump.c

CMakeFiles/shptreedump.dir/shptreedump.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/shptreedump.dir/shptreedump.c.i"
	C:\Qt\Qt5.10.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\code\shp_viewer_qt\libs\shapelib\shptreedump.c > CMakeFiles\shptreedump.dir\shptreedump.c.i

CMakeFiles/shptreedump.dir/shptreedump.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/shptreedump.dir/shptreedump.c.s"
	C:\Qt\Qt5.10.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\code\shp_viewer_qt\libs\shapelib\shptreedump.c -o CMakeFiles\shptreedump.dir\shptreedump.c.s

# Object files for target shptreedump
shptreedump_OBJECTS = \
"CMakeFiles/shptreedump.dir/shptreedump.c.obj"

# External object files for target shptreedump
shptreedump_EXTERNAL_OBJECTS =

shptreedump.exe: CMakeFiles/shptreedump.dir/shptreedump.c.obj
shptreedump.exe: CMakeFiles/shptreedump.dir/build.make
shptreedump.exe: dll/libshp.dll.a
shptreedump.exe: CMakeFiles/shptreedump.dir/linklibs.rsp
shptreedump.exe: CMakeFiles/shptreedump.dir/objects1.rsp
shptreedump.exe: CMakeFiles/shptreedump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\code\shp_viewer_qt\libs\shapelib\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable shptreedump.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\shptreedump.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shptreedump.dir/build: shptreedump.exe

.PHONY : CMakeFiles/shptreedump.dir/build

CMakeFiles/shptreedump.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\shptreedump.dir\cmake_clean.cmake
.PHONY : CMakeFiles/shptreedump.dir/clean

CMakeFiles/shptreedump.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\code\shp_viewer_qt\libs\shapelib C:\code\shp_viewer_qt\libs\shapelib C:\code\shp_viewer_qt\libs\shapelib\build C:\code\shp_viewer_qt\libs\shapelib\build C:\code\shp_viewer_qt\libs\shapelib\build\CMakeFiles\shptreedump.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shptreedump.dir/depend


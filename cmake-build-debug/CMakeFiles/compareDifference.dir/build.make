# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/yangfan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/yangfan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yangfan/CLionProjects/compareDifference

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yangfan/CLionProjects/compareDifference/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/compareDifference.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/compareDifference.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compareDifference.dir/flags.make

CMakeFiles/compareDifference.dir/main.cpp.o: CMakeFiles/compareDifference.dir/flags.make
CMakeFiles/compareDifference.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/compareDifference.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compareDifference.dir/main.cpp.o -c /Users/yangfan/CLionProjects/compareDifference/main.cpp

CMakeFiles/compareDifference.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareDifference.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangfan/CLionProjects/compareDifference/main.cpp > CMakeFiles/compareDifference.dir/main.cpp.i

CMakeFiles/compareDifference.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareDifference.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangfan/CLionProjects/compareDifference/main.cpp -o CMakeFiles/compareDifference.dir/main.cpp.s

CMakeFiles/compareDifference.dir/fileReader.cpp.o: CMakeFiles/compareDifference.dir/flags.make
CMakeFiles/compareDifference.dir/fileReader.cpp.o: ../fileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/compareDifference.dir/fileReader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compareDifference.dir/fileReader.cpp.o -c /Users/yangfan/CLionProjects/compareDifference/fileReader.cpp

CMakeFiles/compareDifference.dir/fileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareDifference.dir/fileReader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangfan/CLionProjects/compareDifference/fileReader.cpp > CMakeFiles/compareDifference.dir/fileReader.cpp.i

CMakeFiles/compareDifference.dir/fileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareDifference.dir/fileReader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangfan/CLionProjects/compareDifference/fileReader.cpp -o CMakeFiles/compareDifference.dir/fileReader.cpp.s

CMakeFiles/compareDifference.dir/fileCompare.cpp.o: CMakeFiles/compareDifference.dir/flags.make
CMakeFiles/compareDifference.dir/fileCompare.cpp.o: ../fileCompare.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/compareDifference.dir/fileCompare.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compareDifference.dir/fileCompare.cpp.o -c /Users/yangfan/CLionProjects/compareDifference/fileCompare.cpp

CMakeFiles/compareDifference.dir/fileCompare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareDifference.dir/fileCompare.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangfan/CLionProjects/compareDifference/fileCompare.cpp > CMakeFiles/compareDifference.dir/fileCompare.cpp.i

CMakeFiles/compareDifference.dir/fileCompare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareDifference.dir/fileCompare.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangfan/CLionProjects/compareDifference/fileCompare.cpp -o CMakeFiles/compareDifference.dir/fileCompare.cpp.s

CMakeFiles/compareDifference.dir/fileWriter.cpp.o: CMakeFiles/compareDifference.dir/flags.make
CMakeFiles/compareDifference.dir/fileWriter.cpp.o: ../fileWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/compareDifference.dir/fileWriter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compareDifference.dir/fileWriter.cpp.o -c /Users/yangfan/CLionProjects/compareDifference/fileWriter.cpp

CMakeFiles/compareDifference.dir/fileWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareDifference.dir/fileWriter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangfan/CLionProjects/compareDifference/fileWriter.cpp > CMakeFiles/compareDifference.dir/fileWriter.cpp.i

CMakeFiles/compareDifference.dir/fileWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareDifference.dir/fileWriter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangfan/CLionProjects/compareDifference/fileWriter.cpp -o CMakeFiles/compareDifference.dir/fileWriter.cpp.s

CMakeFiles/compareDifference.dir/errorLog.cpp.o: CMakeFiles/compareDifference.dir/flags.make
CMakeFiles/compareDifference.dir/errorLog.cpp.o: ../errorLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/compareDifference.dir/errorLog.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compareDifference.dir/errorLog.cpp.o -c /Users/yangfan/CLionProjects/compareDifference/errorLog.cpp

CMakeFiles/compareDifference.dir/errorLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareDifference.dir/errorLog.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangfan/CLionProjects/compareDifference/errorLog.cpp > CMakeFiles/compareDifference.dir/errorLog.cpp.i

CMakeFiles/compareDifference.dir/errorLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareDifference.dir/errorLog.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangfan/CLionProjects/compareDifference/errorLog.cpp -o CMakeFiles/compareDifference.dir/errorLog.cpp.s

# Object files for target compareDifference
compareDifference_OBJECTS = \
"CMakeFiles/compareDifference.dir/main.cpp.o" \
"CMakeFiles/compareDifference.dir/fileReader.cpp.o" \
"CMakeFiles/compareDifference.dir/fileCompare.cpp.o" \
"CMakeFiles/compareDifference.dir/fileWriter.cpp.o" \
"CMakeFiles/compareDifference.dir/errorLog.cpp.o"

# External object files for target compareDifference
compareDifference_EXTERNAL_OBJECTS =

compareDifference: CMakeFiles/compareDifference.dir/main.cpp.o
compareDifference: CMakeFiles/compareDifference.dir/fileReader.cpp.o
compareDifference: CMakeFiles/compareDifference.dir/fileCompare.cpp.o
compareDifference: CMakeFiles/compareDifference.dir/fileWriter.cpp.o
compareDifference: CMakeFiles/compareDifference.dir/errorLog.cpp.o
compareDifference: CMakeFiles/compareDifference.dir/build.make
compareDifference: CMakeFiles/compareDifference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable compareDifference"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compareDifference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compareDifference.dir/build: compareDifference
.PHONY : CMakeFiles/compareDifference.dir/build

CMakeFiles/compareDifference.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compareDifference.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compareDifference.dir/clean

CMakeFiles/compareDifference.dir/depend:
	cd /Users/yangfan/CLionProjects/compareDifference/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yangfan/CLionProjects/compareDifference /Users/yangfan/CLionProjects/compareDifference /Users/yangfan/CLionProjects/compareDifference/cmake-build-debug /Users/yangfan/CLionProjects/compareDifference/cmake-build-debug /Users/yangfan/CLionProjects/compareDifference/cmake-build-debug/CMakeFiles/compareDifference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compareDifference.dir/depend


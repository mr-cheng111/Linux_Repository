# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/mr-cheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mr-cheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build

# Include any dependencies generated for this target.
include CMakeFiles/Kalman_Mouse_Detect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Kalman_Mouse_Detect.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Kalman_Mouse_Detect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kalman_Mouse_Detect.dir/flags.make

CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o: CMakeFiles/Kalman_Mouse_Detect.dir/flags.make
CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o: /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/Kalman_Mouse_Detect.cpp
CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o: CMakeFiles/Kalman_Mouse_Detect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o -MF CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o.d -o CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o -c /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/Kalman_Mouse_Detect.cpp

CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/Kalman_Mouse_Detect.cpp > CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.i

CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/Kalman_Mouse_Detect.cpp -o CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.s

# Object files for target Kalman_Mouse_Detect
Kalman_Mouse_Detect_OBJECTS = \
"CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o"

# External object files for target Kalman_Mouse_Detect
Kalman_Mouse_Detect_EXTERNAL_OBJECTS =

Kalman_Mouse_Detect: CMakeFiles/Kalman_Mouse_Detect.dir/Kalman_Mouse_Detect.cpp.o
Kalman_Mouse_Detect: CMakeFiles/Kalman_Mouse_Detect.dir/build.make
Kalman_Mouse_Detect: /usr/local/lib/libopencv_gapi.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_highgui.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_ml.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_objdetect.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_photo.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_stitching.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_video.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_videoio.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_dnn.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_calib3d.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_features2d.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_flann.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_imgproc.so.4.7.0
Kalman_Mouse_Detect: /usr/local/lib/libopencv_core.so.4.7.0
Kalman_Mouse_Detect: CMakeFiles/Kalman_Mouse_Detect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Kalman_Mouse_Detect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Kalman_Mouse_Detect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kalman_Mouse_Detect.dir/build: Kalman_Mouse_Detect
.PHONY : CMakeFiles/Kalman_Mouse_Detect.dir/build

CMakeFiles/Kalman_Mouse_Detect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Kalman_Mouse_Detect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Kalman_Mouse_Detect.dir/clean

CMakeFiles/Kalman_Mouse_Detect.dir/depend:
	cd /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build /home/mr-cheng/Linux_Repository/Cpp/OpenCV/Kalman_Mouse_Detect/build/CMakeFiles/Kalman_Mouse_Detect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kalman_Mouse_Detect.dir/depend


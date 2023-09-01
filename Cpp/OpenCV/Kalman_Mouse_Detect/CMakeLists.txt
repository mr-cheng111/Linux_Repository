cmake_minimum_required(VERSION 2.8)
project( Kalman_Mouse_Detect )

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Kalman_Mouse_Detect Kalman_Mouse_Detect.cpp )
target_link_libraries( Kalman_Mouse_Detect ${OpenCV_LIBS} )
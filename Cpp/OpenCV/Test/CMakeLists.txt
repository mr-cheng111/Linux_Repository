cmake_minimum_required(VERSION 2.8)
project( Test )

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Test test.cpp )
target_link_libraries( Test ${OpenCV_LIBS} )
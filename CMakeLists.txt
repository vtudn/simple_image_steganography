cmake_minimum_required(VERSION 2.8)

project( encode )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( encode encode.cpp )
target_link_libraries( encode ${OpenCV_LIBS} )

project( decode )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( decode decode.cpp )
target_link_libraries( decode ${OpenCV_LIBS} )

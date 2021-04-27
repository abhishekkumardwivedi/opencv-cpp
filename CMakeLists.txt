cmake_minimum_required(VERSION 3.16)
project(simple)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 14)

add_executable(simple main.cpp display_image.cpp display_video.cpp display_video.h)
target_link_libraries( simple ${OpenCV_LIBS} )
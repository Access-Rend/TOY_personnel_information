cmake_minimum_required(VERSION 3.18)
project(personnel_information)

set(CMAKE_CXX_STANDARD 14)
set(INC_DIR /mnt/d/mywork/jsoncpp/include) #your jsoncpp location
set(LINK_DIR /usr/local/lib/) #your libjsoncpp location

include_directories(INC_DIR)
link_directories({LINK_DIR})
link_libraries(jsoncpp)

add_executable(personnel_information main.cpp)
target_link_libraries(personnel_information jsoncpp)
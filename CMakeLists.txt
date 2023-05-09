cmake_minimum_required(VERSION 3.5)

project(HelloWorld)

set(CMAKE_CXX_FLAGS, "$CMAKE_CXX_FLAGS -std=c++14")

file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cc"
)

message(${SOURCES})

add_executable(HelloWorld ${SOURCES})

find_package(Protobuf REQUIRED)

target_link_libraries(HelloWorld PRIVATE protobuf::libprotobuf)

cmake_minimum_required(VERSION 2.8.4)
project(aquaExternal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -std=c++11 -Wunused")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(EXECUTABLE_OUTPUT_PATH ./aquaExternal/)

set(CMAKE_BUILD_TYPE RELEASE)

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/*.cpp")
add_executable(aquaExternal ${SOURCE_FILES})
target_link_libraries(aquaExternal "-lX11 -lconfig++" xdo)

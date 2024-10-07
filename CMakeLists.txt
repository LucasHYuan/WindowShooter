cmake_minimum_required(VERSION 3.10)
project(WindowShooter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置 SDL2 的相对路径
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.30.8/include")
set(SDL2_LIB_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.30.8/lib/x64")  # x64 库路径

# 包含 SDL2 头文件
include_directories(${SDL2_INCLUDE_DIR})

# 添加源文件
add_executable(WindowShooter src/main.cpp)

# 链接 SDL2 的 .lib 文件
target_link_libraries(WindowShooter "${SDL2_LIB_DIR}/SDL2.lib" "${SDL2_LIB_DIR}/SDL2main.lib")

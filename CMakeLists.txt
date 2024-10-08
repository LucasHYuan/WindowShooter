cmake_minimum_required(VERSION 3.10)
project(WindowShooter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.30.8/include")
set(SDL2_LIB_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.30.8/lib/x64")

include_directories(
    ${SDL2_INCLUDE_DIR}
    include
)

add_executable(WindowShooter
    src/main.cpp
    src/Character/Character.cpp
    src/Character/Player.cpp
    src/Input/InputProcessor.cpp
    src/Bullet/Bullet.cpp
)

target_link_libraries(WindowShooter "${SDL2_LIB_DIR}/SDL2.lib" "${SDL2_LIB_DIR}/SDL2main.lib")

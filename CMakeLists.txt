cmake_minimum_required(VERSION 3.11)
project(PongPlusPlus)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Raylib paths
set(RAYLIB_PATH "/opt/homebrew/Cellar/raylib/5.5")
set(RAYLIB_INCLUDE_PATH "${RAYLIB_PATH}/include")
set(RAYLIB_LIB_PATH "${RAYLIB_PATH}/lib")

# Find Raylib package
find_package(raylib 4.0 QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# Add executable
add_executable(PongPlusPlus
    src/main.cpp
    src/GameManager.cpp
    src/Paddle.cpp
    src/Ball.cpp
    src/PowerUp.cpp
    src/UI.cpp
    src/Utilities.cpp
)

# Link libraries
target_link_libraries(PongPlusPlus PRIVATE raylib)

# Include directories
target_include_directories(PongPlusPlus PRIVATE 
    include
    ${RAYLIB_INCLUDE_PATH}
)

# Link directories
link_directories(${RAYLIB_LIB_PATH}) 
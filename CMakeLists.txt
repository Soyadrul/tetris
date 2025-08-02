cmake_minimum_required(VERSION 3.15)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build." FORCE)
endif()


project(tetris
    VERSION 1.0
    LANGUAGES C CXX
)

# Standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master     # oppure un tag di versione, es. 4.5.0
)
FetchContent_MakeAvailable(raylib)


# src files
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/draw.cpp"
    "${PROJECT_SOURCE_DIR}/src/board.cpp"

    "${PROJECT_SOURCE_DIR}/include/draw.h"
    "${PROJECT_SOURCE_DIR}/src/board.hpp"
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Linking
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Include project directories (optional)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

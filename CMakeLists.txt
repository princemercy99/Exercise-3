# ------------------------------------------------------------------------------
# LICENCE (MIT):
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
# OR OTHER DEALINGS IN THE SOFTWARE.
# ------------------------------------------------------------------------------
# Parts of this CMakeLists.txt file come from these sources:
# https://github.com/itsYakub/RaylibGameTemplate and
# https://github.com/robloach/raylib-cpp
# ------------------------------------------------------------------------------
message("Processing CMakeLists.txt")
cmake_minimum_required(VERSION 3.30) # the currently stable version of CMake is required
project(elen3009-lab-4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ====================== Download and Build Dependencies ======================
include(FetchContent)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
        GIT_SHALLOW 1 # only clone latest commit, restricted to branch names and tags
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v5.0.2
        GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# =========================== Select Source Files for Compilation ============================

set(MAIN_CPP "main.cpp") # the cpp file that runs the graph plotter and contains the entry point main() function

# CONFIGURE_DEPENDS is used to make sure that the globbing is re-run when a new source file is added
file(GLOB LAB_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/graph-plotter/*.cpp)

# ==================================== Setup Target ========================================

# Graph plotter executable
set(LAB_EXE "graph-plotter") # name of the executable

if (WIN32)
    add_executable(${LAB_EXE} ${LAB_SRC}) # hides the console window
else()
    add_executable(${LAB_EXE} ${LAB_SRC}) # shows the console window
endif()

# ================================= Linker Settings ==========================================

if (WIN32)
    message("Linking target for Windows")

    # Statically link libraries
    # (Source: https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)
    target_link_options(${LAB_EXE} PRIVATE -static)
    target_link_libraries(${LAB_EXE} PRIVATE raylib_cpp raylib)
endif()

if (LINUX)
    message("Linking target for Linux")

    # LINUX: Telling the linker to statically link the libgcc and libstdc++ to out project.
    # (Source: https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)
    target_link_options(${LAB_EXE} PRIVATE -static-libgcc -static-libstdc++)
    target_link_libraries(${LAB_EXE} PRIVATE raylib_cpp raylib) # CMAKE generates the linker flags
endif()

if (APPLE)
    message("Linking target for macOS")

    # Include paths for IntelliSense and compiling
    include_directories("/path/to/raylib-cpp/include")
    include_directories("/path/to/raylib/include")
    # Link the necessary macOS frameworks
    target_link_libraries(${LAB_EXE}
        "-framework IOKit"  # Access hardware devices and drivers from your apps and services.
        "-framework Cocoa"  # Native object-oriented application programming interface.
        "-framework OpenGL" # Cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics.
        raylib_cpp
        raylib
    )
endif()
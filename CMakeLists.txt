cmake_minimum_required(VERSION 3.7)

# set the project name
project(app)

# set flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# add header files
include_directories(_include)

# add source files
file(GLOB_RECURSE MY_SOURCES "src/*.cpp")


# add the executable
add_executable(${PROJECT_NAME} ${MY_SOURCES} )

# set GDB debug flag (-g)
# by typing:
# > cmake -DCMAKE_BUILD_TYPE=Debug .
# you will be able to debug with gdb
set(CMAKE_BUILD_TYPE Debug)

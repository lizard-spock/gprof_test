cmake_minimum_required(VERSION 3.2)

# Set the project name
project(MyProject)

# Set C++ standard (optional but recommended)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add flags for profiling with gprof
# set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -pg -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -pg -fno-omit-frame-pointer -DNDEBUG")#-fno-inline-functions -fno-inline-functions-called-once -fno-optimize-sibling-calls")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")

# set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -pg -fno-omit-frame-pointer -DNDEBUG")#-fno-inline-functions -fno-inline-functions-called-once -fno-optimize-sibling-calls")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")

# Add the executable
add_executable(test test.cc)

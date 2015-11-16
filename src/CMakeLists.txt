cmake_minimum_required(VERSION 3.3.0)
project(hemorrhage)


include(GetGitVersion)
get_git_version(GIT_VERSION)

find_package(Threads REQUIRED)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM: ${LLVM_PACKAGE_VERSION}")

find_program(LLVM_CONFIG_EXECUTABLE NAMES llvm-config DOC "llvm-config executable")
if(LLVM_CONFIG_EXECUTABLE STREQUAL "LLVM_CONFIG_EXECUTABLE-NOTFOUND")
	message(FATAL_ERROR "llvm-config could not be found!")
else()
	message(STATUS "Found llvm-config: ${LLVM_CONFIG_EXECUTABLE}")
endif()

include_directories(include)
include_directories(${LLVM_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})

add_definitions(-DATROPHY_VERSION_STRING="${GIT_VERSION}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -fno-builtin --param max-inline-insns-auto=100 --param early-inlining-insns=200")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-overflow=1 -Wformat=2 -Wuninitialized -Werror=return-type  -Werror=shadow -fstack-protector -Wformat-security")

execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --cxxflags
	OUTPUT_VARIABLE LLVM_CXXFLAGS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
	COMMAND ${LLVM_CONFIG_EXECUTABLE} --system-libs
	OUTPUT_VARIABLE LLVM_SYSTEM_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXXFLAGS}")

file(GLOB SOURCES "./*.cc")

add_executable(hemorrhage ${SOURCES})


target_link_libraries(hemorrhage dl LLVM clang)

cmake_minimum_required(VERSION 3.27.4 FATAL_ERROR)

project(CpEngine)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE ENGINE_SOURCE 
	"${CMAKE_CURRENT_LIST_DIR}/src/*.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
)

include_directories(
	"${CMAKE_CURRENT_LIST_DIR}/include"
	"${CMAKE_CURRENT_LIST_DIR}/src"
	"${CMAKE_CURRENT_LIST_DIR}/src/render"
)

add_library(CpEngine SHARED ${ENGINE_SOURCE})

file(GLOB_RECURSE PROGRAM_SOURCE
	"${CMAKE_CURRENT_LIST_DIR}/projects/*.h"
	"${CMAKE_CURRENT_LIST_DIR}/projects/*.cpp"
)
add_executable(program ${PROGRAM_SOURCE})

target_link_libraries(program
	CpEngine
)
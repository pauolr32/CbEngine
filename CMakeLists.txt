cmake_minimum_required(VERSION 3.27.4 FATAL_ERROR)

project(CpEngine)
set(CMAKE_CXX_STANDARD 20)

set(ENGINE_SOURCE
	${CMAKE_CURRENT_LIST_DIR}/src/CEngine.h
	${CMAKE_CURRENT_LIST_DIR}/src/CEngine.cpp
)
add_library(engine STATIC ${ENGINE_SOURCE})

set(TESTING_SOURCE
	${CMAKE_CURRENT_LIST_DIR}/src/Testing.cpp
)
add_executable(program ${TESTING_SOURCE})

target_link_libraries(program
	CEngine
)
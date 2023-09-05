cmake_minimum_required(VERSION 3.27.4 FATAL_ERROR)

project(engine)
set(CMAKE_CXX_STANDARD 20)

set(ENGINE_SOURCE
	${CMAKE_CURRENT_LIST_DIR}/src/engine.h
	${CMAKE_CURRENT_LIST_DIR}/src/engine.cpp
)
add_library(engine STATIC ${ENGINE_SOURCE})

set(TESTING_SOURCE
	${CMAKE_CURRENT_LIST_DIR}/src/testing.cpp
)
add_executable(program ${TESTING_SOURCE})

target_link_libraries(program
	engine
)
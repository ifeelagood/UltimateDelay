cmake_minimum_required(VERSION 3.5)

add_library(uopslib STATIC
	src/MicroArchitectureIdentifier.cpp
)

set(UOPS_INCLUDE_DIR "./include")

target_include_directories(uopslib PUBLIC ${UOPS_INCLUDE_DIR})


cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(UltimateDelay)

set(SRC
	src/main.cpp
)

set(INC

)

add_executable(${PROJECT_NAME} ${SRC} ${INC} "src/UltimateDelay.h"   "src/uops/include/MicroArchitecture.h" "src/uops/include/MicroArchitectureIdentifier.h" "src/uops/src/MicroArchitectureIdentifier.cpp")

add_subdirectory(src/uops)

target_link_libraries(${PROJECT_NAME} uopslib)
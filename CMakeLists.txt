cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(UltimateDelay)

set(SRC
	src/main.cpp
)

set(INC

)

add_executable(${PROJECT_NAME} ${SRC} ${INC})

add_subdirectory(src/uops)

target_link_libraries(${PROJECT_NAME} uopslib)
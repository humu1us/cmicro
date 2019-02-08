cmake_minimum_required(VERSION 3.5.1)

project(cmicro C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# setting output
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# group source files
# libraries:  file(GLOB UPPER_CASE_LIB_NAME_SRC src/files.c)
# executable: files(GLOB MAIN_SRC src/main.c)

# sources end

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

if (${DEBUG} AND ${DEBUG} EQUAL 1)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()

include_directories(include)

# output files:
# libraries: add_library("library_name" SHARED | STATIC "${VAR_WITH_SOURCES}")
# executable: add_executable(${PROJECT_NAME} ${MAIN_SRC})

enable_testing()
add_subdirectory(test)
# add test as follow
# add_test(test_name test/test_name "${CURRENT_LIST_DIR}")

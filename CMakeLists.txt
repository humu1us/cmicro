cmake_minimum_required(VERSION 3.8.0)

project(cmicro CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# setting output
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# group source files
# libraries:  file(GLOB UPPER_CASE_LIB_NAME_SRC src/files.cc)
# executable: file(GLOB MAIN_SRC src/main.cc)
file(GLOB BUFFER_SRC src/buffer.cc)
file(GLOB MESSAGE_SRC src/message.cc)

# sources end

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${DEBUG} AND ${DEBUG} EQUAL 1)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

include_directories(include)

# output files:
# libraries: add_library("library_name" SHARED | STATIC "${VAR_WITH_SOURCES}")
# executable: add_executable(${PROJECT_NAME} ${MAIN_SRC})
add_library("buffer" SHARED "${BUFFER_SRC}")
add_library("message" SHARED "${MESSAGE_SRC}")

enable_testing()
add_subdirectory(test)
# add test as follow
# add_test(test_name test/test_name "${CURRENT_LIST_DIR}")
add_test(create_buffer test/create_buffer)
add_test(push_pop test/push_pop)

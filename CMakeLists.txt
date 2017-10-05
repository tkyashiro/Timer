project(PTimer)

cmake_minimum_required(VERSION 2.8.10.2)
enable_testing()

set(BINDIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINDIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINDIR})

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(TimerTutorial)
add_subdirectory(Timer)



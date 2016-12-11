project(PTimer)

cmake_minimum_required(VERSION 2.8.10.2)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PTimer_SOURCES
    )

set(PTimer_UI_SOURCES
    mainwindow.ui
    mainwindow.cpp
    )

add_executable(PTimer main.cpp ${PTimer_SOURCES} ${PTimer_UI_SOURCES})

QT5_USE_MODULES(PTimer Widgets)


######### for unit tests #########

enable_testing()

find_package(Qt5Test REQUIRED)

#file(GLOB testfiles "*test.cpp")
set(testfiles
    sandboxTest.cpp
    )
foreach(testfile ${testfiles})
    get_filename_component(testname ${testfile} NAME_WE)
    add_executable(${testname} ${testfile} ${PTimer_SOURCES})
    QT5_USE_MODULES(${testname} Test)
    add_test(${testname} ${testname})
endforeach(testfile)

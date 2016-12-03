project(PTimer)

cmake_minimum_required(VERSION 2.8.10.2)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PTimer_SOURCES
    main.cpp
    mainwindow.cpp
    )

set(PTimer_UI_SOURCES
    mainwindow.ui )

add_executable(PTimer ${PTimer_SOURCES} ${PTimer_UI_SOURCES})

QT5_USE_MODULES(PTimer Widgets)

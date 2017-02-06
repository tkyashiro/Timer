project(PTimer)

cmake_minimum_required(VERSION 2.8.10.2)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

###### アプリ設定 ######
## ここにソースを追加する
set(PTimer_SOURCES
    Pomodoro.cpp
    Log.cpp
    LogRepository.cpp
    )

set(PTimer_UI_SOURCES
    mainwindow.ui
    mainwindow.cpp
    PomodoroWidget.cpp
    PomodoroWidget.ui
    )

add_executable(PTimer main.cpp ${PTimer_SOURCES} ${PTimer_UI_SOURCES})

QT5_USE_MODULES(PTimer Widgets)


######### for unit tests #########

enable_testing()

find_package(Qt5Test REQUIRED)

## ここにテストのソースを追加する
set(testfiles
    sandboxTest.cpp
    LogRepositoryTest.cpp
    PomodoroTest.cpp
    )

## 上記ファイルそれぞれに対してテストexeを作製、追加する。
foreach(testfile ${testfiles})
    get_filename_component(testname ${testfile} NAME_WE)
    add_executable(${testname} ${testfile} ${PTimer_SOURCES})
    QT5_USE_MODULES(${testname} Test)
    ### testfile と、Timerのロジックソースからテストを作成する
    add_test(${testname} ${testname})
endforeach(testfile)



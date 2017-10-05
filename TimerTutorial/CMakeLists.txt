###### アプリ設定 ######
## ここにソースを追加する
set(TimerTutorial_SOURCES
    Pomodoro.cpp
    Log.cpp
    LogRepository.cpp
    )

set(TimerTutorial_UI_SOURCES
    mainwindow.ui
    mainwindow.cpp
    PomodoroWidget.cpp
    PomodoroWidget.ui
    )

add_executable(TimerTutorial main.cpp ${TimerTutorial_SOURCES} ${TimerTutorial_UI_SOURCES})

QT5_USE_MODULES(TimerTutorial Widgets)


######### for unit tests #########

enable_testing()
find_package(Qt5Test REQUIRED)

file(GLOB testfiles "tests/*.cpp")

foreach(testfile ${testfiles})
    get_filename_component(testname ${testfile} NAME_WE)
    add_executable(${testname} ${testfile} ${TimerTutorial_SOURCES} )
    QT5_USE_MODULES(${testname} Test)
    ### testfile と、Timerのロジックソースからテストを作成する
    add_test(${testname} ${testname})
endforeach(testfile)


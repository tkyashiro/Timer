###### アプリ設定 ######
## ここにソースを追加する
set(Timer_SOURCES
    main.cpp
    Category.cpp
    Task.cpp
    TaskWindow.cpp
    TaskWidget.cpp
    TaskRecorder.cpp
    TaskLog.cpp
    LogRepository.cpp
    )

set(Timer_UI_SOURCES
    )

add_executable(Timer main.cpp ${Timer_SOURCES} ${Timer_UI_SOURCES})

QT5_USE_MODULES(Timer Widgets)


######### for unit tests #########

enable_testing()
find_package(Qt5Test REQUIRED)

file(GLOB testfiles "tests/*.cpp")

foreach(testfile ${testfiles})
    get_filename_component(testname ${testfile} NAME_WE)
    add_executable(${testname} ${testfile} ${Timer_SOURCES} )
    QT5_USE_MODULES(${testname} Test)
    ### testfile と、Timerのロジックソースからテストを作成する
    add_test(${testname} ${testname})
endforeach(testfile)


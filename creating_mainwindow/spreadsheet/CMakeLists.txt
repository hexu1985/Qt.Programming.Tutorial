cmake_minimum_required(VERSION 3.1.0)

project(app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(QRC_SOURCE_FILES "")
qt5_add_resources(QRC_SOURCE_FILES spreadsheet.qrc)

add_executable(spreadsheet
    cell.cpp
    cell.h
    finddialog.cpp
    finddialog.h
    gotocelldialog.cpp
    gotocelldialog.h
    mainwindow.cpp
    mainwindow.h
    sortdialog.cpp
    sortdialog.h
    spreadsheet.cpp
    spreadsheet.h
    main.cpp
    ${QRC_SOURCE_FILES}
    )

target_link_libraries(spreadsheet Qt5::Widgets)

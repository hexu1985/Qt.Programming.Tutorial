cmake_minimum_required(VERSION 3.1.0)

project(app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#list(APPEND CMAKE_PREFIX_PATH "/home/mackhe/Qt5.14.2/5.14.2/gcc_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(hello hello.cpp)

target_link_libraries(hello Qt5::Widgets)

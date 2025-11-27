cmake_minimum_required(VERSION 3.16)

project(BeautifulUI VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(BeautifulUI
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    resources/resources.qrc
)

target_link_libraries(BeautifulUI PRIVATE Qt6::Widgets)

target_include_directories(BeautifulUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

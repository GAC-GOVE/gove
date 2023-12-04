cmake_minimum_required(VERSION 3.16)

project(LocationApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)

add_executable(LocationApp
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )

target_link_libraries(LocationApp PRIVATE 
    Qt5::Widgets
    Qt5::Quick
    location
)

#set_target_properties(LocationApp PROPERTIES FOLDER app)
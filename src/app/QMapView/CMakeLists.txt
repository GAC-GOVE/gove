cmake_minimum_required(VERSION 3.10)

project(TileMapService LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TileMapService
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )

target_link_libraries(TileMapService PRIVATE Qt5::Widgets)
set_target_properties(TileMapService PROPERTIES FOLDER app)
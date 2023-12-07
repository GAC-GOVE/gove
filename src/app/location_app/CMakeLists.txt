cmake_minimum_required(VERSION 3.16)

project(LocationApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE QML_LIST *.qml)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)

file(GLOB_RECURSE SOURCE_LIST *.cc)
file(GLOB_RECURSE HEADER_LIST *.h)

add_executable(LocationApp
    ${SOURCE_LIST}
	${HEADER_LIST}
	qml.qrc
  )

target_link_libraries(LocationApp PRIVATE 
    Qt5::Widgets
    Qt5::Quick
    GACLocationPlugin
)

add_custom_target(LocationApp-Qml
	SOURCES
        MapView.qml
)
#set_target_properties(LocationApp PROPERTIES FOLDER app)
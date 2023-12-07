set(PROJECT_NAME "GACLocationPlugin")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE SOURCE_LIST *.cc)
file(GLOB_RECURSE HEADER_LIST *.h)

add_library(${PROJECT_NAME} OBJECT ${SOURCE_LIST} ${HEADER_LIST} )

find_package(Qt5 COMPONENTS Widgets Quick location sql REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC
	Qt5::Location
    Qt5::LocationPrivate
	Qt5::Sql
)

target_include_directories(${PROJECT_NAME}
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
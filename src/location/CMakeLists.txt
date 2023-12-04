set(PROJECT_NAME "location")

file(GLOB_RECURSE SOURCE_LIST *.cc)
file(GLOB_RECURSE HEADER_LIST *.h)

add_library(${PROJECT_NAME} OBJECT ${SOURCE_LIST} ${HEADER_LIST} )

target_link_libraries(${PROJECT_NAME}
	httplib
)

target_include_directories(${PROJECT_NAME}
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
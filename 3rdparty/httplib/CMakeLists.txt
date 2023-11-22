set(PROJECT_NAME "httplib")

add_library(${PROJECT_NAME} httplib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ./)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER 3rdparty)

if(UNIX)
    target_compile_options(${PROJECT_NAME} PUBLIC -Wno-all)
else()
    target_compile_options(${PROJECT_NAME} PUBLIC /W0)
endif()

set(PROJECT_NAME "gtest")

find_package(Threads REQUIRED)

add_library(${PROJECT_NAME} src/gtest-all.cc src/gtest_main.cc)
target_include_directories(${PROJECT_NAME} PUBLIC include src ./)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER 3rdparty)

if(UNIX)
    target_compile_options(${PROJECT_NAME} PUBLIC -Wno-all)
else()
    target_compile_options(${PROJECT_NAME} PUBLIC /W0)
endif()

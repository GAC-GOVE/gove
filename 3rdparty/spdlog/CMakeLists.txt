find_package(Threads REQUIRED)

add_library("spdlog" INTERFACE)

target_include_directories("spdlog" INTERFACE ./include/)

target_link_libraries("spdlog" INTERFACE ${CMAKE_THREAD_LIBS_INIT})

set_target_properties("spdlog" PROPERTIES FOLDER 3rdparty)
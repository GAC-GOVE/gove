add_library(json INTERFACE)

add_library(nlohmann::json ALIAS json)
add_library(Nlohmann::Json ALIAS json)

target_include_directories(json
    INTERFACE
        ./
)

set_target_properties(json PROPERTIES FOLDER 3rdparty)


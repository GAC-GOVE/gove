#include "MapEngineImpl.h"
#include "MapProvider.h"
#include "TianMapProvider.h"

namespace gove {
namespace location {

Location::Impl::Impl() { InitMapContainer(); }

void Location::Impl::InitMapContainer() { 
    map_container_["TianMap"] = std::make_shared<TianMapProvider>(
        "TianMap", "0aa1147d0129a72f6958656125461fe6");

    SetMapProvider("TianMap");
}

bool Location::Impl::GetTile(int x, int y, int zoom, std::string& image) {
    //get tile from memory cache

    //get tile from location cache

    //get tile from map service
    if (map_provider_ptr_ != nullptr) {
        return map_provider_ptr_->GetTile(x,y,zoom,image);
    }

    return false;
}

bool Location::Impl::SetMapName(const std::string& map_name) {
    for (const auto& map : map_container_) {
        if (map.first == map_name) {
            map_provider_ptr_ = map.second;
            return true;
        }
    }

    return false;
}

std::string Location::Impl::GetMapName() {
    std::string map_name{};
    if (Valid()) {
        map_name = map_provider_ptr_->GetMapName();
    }
    return map_name;
}


std::vector<std::string> Location::Impl::GetMapNameList() {
    std::vector<std::string> map_name_list;
    for (const auto& map : map_container_) {
        map_name_list.emplace_back(map.first);
    }
    return map_name_list;
}

void Location::Impl::SetToken(const std::string& token) { token_ = token; }

std::string Location::Impl::GetErrorMessage() { return error_message_; }

void Location::Impl::SetMapProvider(const std::string& map_name) {
    for (const auto& map : map_container_) {
        if (map.first == map_name) {
            map_provider_ptr_ = map.second;
        }
    }
}

bool Location::Impl::Valid() { 
    if (!VaildMapProvider()) {
        return false;
    }
    return true;
}

}  // namespace location
}  // namespace gove
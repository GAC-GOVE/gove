#include "GACMapEngine.h"
#include "GACTianMapProvider.h"

namespace gove {
namespace location {

std::vector<std::string> GACMapEngine::GetSupportMapList() {
    std::vector<std::string> map_list{};
    for (const auto&map:map_container_){
        map_list.emplace_back(map.first);
    }
    return map_list;
}

std::string GACMapEngine::GetCurrectMapName() { return map_name_; }

void GACMapEngine::SetCurrectMapName(std::string map_name) { map_name_=map_name; }

std::string GACMapEngine::GetURL(int x, int y, int zoom) {
    std::string url{};
    auto provider = GetMapProvider();
    if (provider != nullptr) {
        url = provider->GetURL(x,y,zoom);
    }
    return url;
}

void GACMapEngine::SetToken(const std::string& token) {
    auto map_provider = GetMapProvider(); 
    if (map_provider != nullptr) {
        map_provider->SetToken(token);
    }
}

void GACMapEngine::Init() {
    std::string tianditu_map_name = "TianDiTu";
    std::string tianditu_token = "0aa1147d0129a72f6958656125461fe6";
    map_container_[tianditu_map_name] =
        std::make_shared<GACTianMapProvider>(tianditu_token);
    
    map_name_ = tianditu_map_name;
}

std::shared_ptr<GACMapProvider> GACMapEngine::GetMapProvider() {
    std::shared_ptr<GACMapProvider> provider = nullptr;
    for (const auto&map:map_container_){
        if (map.first == map_name_){
            provider = map.second;
        }
    }
    return provider;
}

}  // namespace location
}  // namespace gove

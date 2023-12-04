#pragma once

#include "MapEngine.h"
#include "MapProvider.h"

#include <vector>
#include <string>
#include <memory>
#include <Map>

namespace gove {
namespace location {

class Location::Impl {
public:
    Impl();

    bool GetTile(int x, int y, int zoom, std::string& image);

    bool SetMapName(const std::string& map_name);

    std::string GetMapName();

    std::vector<std::string> GetMapNameList();

    void SetToken(const std::string& token);

    std::string GetErrorMessage();

private:
    void InitMapContainer();
    bool Valid();
    inline bool VaildMapProvider() { return map_provider_ptr_ != nullptr; }
    void SetMapProvider(const std::string& map_name);

private:
    std::string error_message_{};
    std::string token_{};
    std::shared_ptr<MapProvider> map_provider_ptr_{nullptr};
    std::map<std::string, std::shared_ptr<MapProvider>> map_container_{};

};

}  // namespace location
}  // namespace gove
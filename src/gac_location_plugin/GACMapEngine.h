#pragma once

#include "GACMapProvider.h"

#include<vector>
#include<Map>
#include <string>
#include <memory>

namespace gove {
namespace location {
	
class GACMapEngine {
public:
    static GACMapEngine& Instance() {
        static GACMapEngine engine;
        return engine;
    }

    std::vector<std::string> GetSupportMapList();
    std::string GetCurrectMapName();
    void SetCurrectMapName(std::string map_name);

    std::string GetURL(int x, int y, int zoom);
    void SetToken(const std::string& token);
    void Init();

private:
    GACMapEngine() = default;
    ~GACMapEngine() = default;
    GACMapEngine(const GACMapEngine&) = delete;
    GACMapEngine& operator=(const GACMapEngine&) = delete;

    std::shared_ptr<GACMapProvider> GetMapProvider();

private:
    std::string map_name_{};
    std::map<std::string, std::shared_ptr<GACMapProvider>> map_container_{};
};

}  // namespace location
}  // namespace gove

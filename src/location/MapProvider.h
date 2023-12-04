#pragma once

#include <httplib.h>
#include <string>

namespace gove {
namespace location {

class MapProvider {
public:
    MapProvider() = default;
    
    bool GetTile(int x, int y, int zoom, std::string& image);
    virtual std::string GetMapName() = 0;
    virtual std::string GetHost() = 0;

private:
    virtual std::string GetURL(int x, int y, int zoom)= 0;
};

}  // namespace location
}  // namespace gove
#pragma once
#include <string>

namespace gove {
namespace location {

class GACMapProvider {
public:
    GACMapProvider() = default;

    virtual std::string GetURL(int x, int y, int zoom) = 0;
    virtual std::string GetMapName() = 0;
    virtual std::string GetHost() = 0;
    virtual void SetToken(const std::string& token) {}
};

}  // namespace location
}  // namespace gove

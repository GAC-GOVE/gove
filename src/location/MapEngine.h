#pragma once

#include <vector>
#include <string>
#include <memory>

namespace gove {
namespace location {

class Location {
public:

    bool GetTile(int x, int y, int zoom, std::string& image);

    bool SetMapName(const std::string& map_name);

    std::string GetMapName();

    std::vector<std::string> GetMapNameList();

    void SetToken(const std::string& token);

    std::string GetErrorMessage();

    Location();
    Location(const Location&) = delete;
    Location& operator=(const Location&) = delete;
    Location(Location&&) = default;
    Location& operator=(Location&&) = default;
    ~Location();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl_;
};

}  // namespace location
}  // namespace gove
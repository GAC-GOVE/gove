#pragma once

#include "MapProvider.h"
#include <string>

namespace gove {
namespace location {

class TianMapProvider:public  MapProvider{
public:
    TianMapProvider(const std::string& map_name,const std::string& token);
   
    std::string GetMapName() override;

    std::string GetHost() override;

private:
    virtual std::string GetURL(int x, int y, int zoom) override;

private:
    std::string map_name_;
    std::string token_;
};

}  // namespace location
}  // namespace gove
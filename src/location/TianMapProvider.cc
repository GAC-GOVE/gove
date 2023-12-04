#include "TianMapProvider.h"


namespace gove {
namespace location {

TianMapProvider::TianMapProvider(const std::string& map_name,
                                 const std::string& token)
    : map_name_(map_name) {}

std::string TianMapProvider::GetMapName() { return map_name_; }

std::string TianMapProvider::GetHost() { return "http://t1.tianditu.gov.cn"; }

std::string TianMapProvider::GetURL(int x, int y, int zoom) {
    std::string url =
        R"(http://t0.tianditu.gov.cn/img_w/wmts?SERVICE=WMTS&REQUEST=GetTile&VERSION=1.0.0&LAYER=img&STYLE=default&TILEMATRIXSET=w&FORMAT=tiles&TILEMATRIX=31&TILEROW=35&TILECOL=6&tk=62a5cb82186fdc9e3bdeee153d8673a9)";
    return url;
}

}  // namespace location
}  // namespace gove
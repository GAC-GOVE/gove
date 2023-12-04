#include "MapProvider.h"
#include <httplib.h>
#include <iostream>

namespace gove {
namespace location {

bool MapProvider::GetTile(int x, int y, int zoom, std::string& image){
    auto host = GetHost();
    auto request_url = GetURL(x,y,zoom);

    httplib::Client http_client(host.c_str());
    

    auto res = http_client.Get(request_url.c_str());
    image = res.value().body;

    return true;
}

//std::string MapProvider::GetMapName() { return std::string(); }
//
//std::string MapProvider::GetURL(int x, int y, int zoom) {
//    return std::string();
//}

}
}  // namespace gove
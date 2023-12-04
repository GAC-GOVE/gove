#include "MapEngine.h"
#include "MapEngineImpl.h"

namespace gove {
namespace location {

Location::Location() : pimpl_(std::make_unique<Location::Impl>()) {}

Location::~Location() {}

bool Location::GetTile(int x, int y, int zoom, std::string& image) {
    return pimpl_->GetTile(x, y, zoom, image);
}
bool Location::SetMapName(const std::string& map_name) {
    return pimpl_->SetMapName(map_name);
}
std::string Location::GetMapName() { return pimpl_->GetMapName(); }

std::vector<std::string> Location::GetMapNameList() {
    return pimpl_->GetMapNameList();
}

void Location::SetToken(const std::string& token) { pimpl_->SetToken(token); }

std::string Location::GetErrorMessage() { return pimpl_->GetErrorMessage(); }



}  // namespace location
}  // namespace gove
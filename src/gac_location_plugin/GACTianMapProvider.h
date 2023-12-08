#pragma once
#include "GACMapProvider.h"
#include <string>

namespace gove {
namespace location {
	
class GACTianMapProvider : public GACMapProvider {

public:
    GACTianMapProvider() = default;
    ~GACTianMapProvider() = default;

    GACTianMapProvider(const std::string& token_);

    std::string GetMapName() override final;
    std::string GetHost() override final;
    std::string GetURL(int x, int y, int zoom) override final;

private:
    const std::string map_name_{"TianDiTu"};
    const std::string host_{"http://t0.tianditu.gov.cn"};
    std::string token_{};
};
}  // namespace location
}  // namespace gove

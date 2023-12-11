#include <gtest/gtest.h>
#include <iostream>
#include<GACMapEngine.h>

TEST(location, SetCurrectMapName) {
    using namespace gove::location;

    std::string image;
    GACMapEngine::Instance().Init();
    auto map_name = GACMapEngine::Instance().GetCurrectMapName();

    ASSERT_EQ(map_name, "TianDiTu");
}

TEST(location, GetMapNameList) {
    using namespace gove::location;

    std::string image;
    GACMapEngine::Instance().Init();
    auto map_list = GACMapEngine::Instance().GetSupportMapList();

    ASSERT_EQ(map_list.empty(), false);
}

TEST(location, GetURL) {
    using namespace gove::location;
    bool result = false;

    std::string image;
    GACMapEngine::Instance().Init();
    auto tian_url = GACMapEngine::Instance().GetURL(1,1,1);

    ASSERT_EQ(tian_url.empty(), false);
}

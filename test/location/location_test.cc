#include <gtest/gtest.h>
#include <iostream>
#include<MapEngine.h>

TEST(location, GetMapName) {
    using namespace gove::location;

    std::string image;
    auto map_engine_ptr = std::make_unique<Location>();
    auto result = map_engine_ptr->GetMapName();

    ASSERT_EQ(result, "TianMap");
}

TEST(location, GetMapNameList) {
    using namespace gove::location;

    std::string image;
    auto map_engine_ptr = std::make_unique<Location>();
    auto result = map_engine_ptr->GetMapNameList();

    ASSERT_EQ(result.empty(), false);
}

TEST(location, GetTile) {
    using namespace gove::location;
    bool result = false;

    std::string image;
    auto map_engine_ptr = std::make_unique<Location>();
    auto reslut = map_engine_ptr->GetTile(1, 1, 1, image);
    std::cout << image << std::endl;

    ASSERT_EQ(result, true);
}

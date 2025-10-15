#include "framework_info.h"

#include <gtest/gtest.h>
#include <string_view>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const auto version = metrology::framework_version();
  constexpr std::string_view expected_suffix = "-dev";
  EXPECT_THAT(version, ::testing::EndsWith(expected_suffix));
}

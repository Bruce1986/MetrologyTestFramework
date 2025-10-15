#include "framework_info.h"

#include <gtest/gtest.h>
#include <string_view>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const auto version = metrology::framework_version();
  EXPECT_FALSE(version.empty());
  constexpr std::string_view expected_suffix = "-dev";
  // Check that the version string ends with the expected suffix.
  EXPECT_TRUE(version.ends_with(expected_suffix));
}

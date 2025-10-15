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
  ASSERT_GE(version.size(), expected_suffix.size());
  // Check that the version string ends with "-dev".
  EXPECT_EQ(version.substr(version.size() - expected_suffix.size()),
            expected_suffix);
}

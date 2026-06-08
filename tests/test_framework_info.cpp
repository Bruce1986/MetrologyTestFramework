#include "framework_info.h"

#include <gtest/gtest.h>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const auto version = metrology::framework_version();
  EXPECT_FALSE(version.empty());
  ASSERT_GE(version.size(), 4u);
  // Check that the version string ends with "-dev".
  EXPECT_EQ(version.substr(version.size() - 4), "-dev");
}

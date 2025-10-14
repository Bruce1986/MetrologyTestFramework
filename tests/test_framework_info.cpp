#include "framework_info.h"

#include <gtest/gtest.h>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const std::string version(metrology::framework_version());
  EXPECT_FALSE(version.empty());
  ASSERT_GE(version.size(), 4u);
  const std::size_t suffix_position = version.rfind("-dev");
  ASSERT_NE(suffix_position, std::string::npos);
  EXPECT_EQ(suffix_position, version.size() - 4);
}

#include "framework_info.h"

#include <gtest/gtest.h>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const std::string version = metrology::framework_version();
  EXPECT_FALSE(version.empty());
  EXPECT_NE(version.find("dev"), std::string::npos);
}

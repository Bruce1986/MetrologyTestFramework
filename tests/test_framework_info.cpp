#include "framework_info.h"

#include <gtest/gtest.h>

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

static_assert(metrology::kFrameworkVersion.size() >= sizeof("-dev") - 1,
              "Framework version must include a pre-release suffix.");
static_assert(
    metrology::kFrameworkVersion.substr(metrology::kFrameworkVersion.size() - (sizeof("-dev") - 1)) == "-dev",
    "Framework version must end with -dev");

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  const auto version = metrology::framework_version();
  EXPECT_FALSE(version.empty());
  ASSERT_GE(version.size(), 4u);
  EXPECT_EQ(version.substr(version.size() - 4), "-dev");
  EXPECT_EQ(version, metrology::kFrameworkVersion);
}

#include "framework_info.h"

#include <gtest/gtest.h>
#include <string_view>

namespace {

inline constexpr std::string_view kFrameworkVersionSuffix{"-dev"};

}  // namespace

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

static_assert(
    metrology::kFrameworkVersion.size() >= kFrameworkVersionSuffix.size(),
    "Framework version must include a pre-release suffix.");
static_assert(
    metrology::kFrameworkVersion.substr(metrology::kFrameworkVersion.size() -
                                        kFrameworkVersionSuffix.size()) ==
        kFrameworkVersionSuffix,
    "Framework version must end with -dev");

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  EXPECT_EQ(metrology::framework_version(), metrology::kFrameworkVersion);
}

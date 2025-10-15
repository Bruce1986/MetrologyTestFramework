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
    [](std::string_view str, std::string_view suffix) constexpr {
      return str.size() >= suffix.size() &&
             str.substr(str.size() - suffix.size()) == suffix;
    }(metrology::kFrameworkVersion, kFrameworkVersionSuffix),
    "Framework version must end with the '-dev' suffix.");

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  EXPECT_EQ(metrology::framework_version(), metrology::kFrameworkVersion);
}

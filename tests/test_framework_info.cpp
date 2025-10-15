#include "framework_info.h"

#include <gtest/gtest.h>
#include <string_view>

namespace {

inline constexpr std::string_view kFrameworkVersionSuffix{"-dev"};

constexpr auto ends_with = [](std::string_view str, std::string_view suffix) constexpr {
  return str.size() >= suffix.size() &&
         str.substr(str.size() - suffix.size()) == suffix;
};

static_assert(ends_with(metrology::kFrameworkVersion, kFrameworkVersionSuffix),
    "Framework version must end with the '-dev' suffix.");

}  // namespace

TEST(FrameworkInfoTest, BannerIsStable) {
  EXPECT_EQ(metrology::framework_banner(), "Metrology Test Framework");
}

TEST(FrameworkInfoTest, VersionFollowsSemverPreRelease) {
  EXPECT_EQ(metrology::framework_version(), metrology::kFrameworkVersion);
}

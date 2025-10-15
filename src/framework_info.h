#pragma once

#include <string>
#include <string_view>

namespace metrology {

//! Returns a user-friendly banner used by the placeholder application.
std::string framework_banner();

//! Returns the semantic version string advertised by the framework skeleton.
std::string framework_version();

//! Framework version constant for compile-time checks.
inline constexpr std::string_view kFrameworkVersion = "0.1.0-dev";

}  // namespace metrology

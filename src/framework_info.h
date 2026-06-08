#pragma once

#include <string_view>

namespace metrology {

//! Returns a user-friendly banner used by the placeholder application.
std::string_view framework_banner();

//! Returns the semantic version string advertised by the framework skeleton.
std::string_view framework_version();

}  // namespace metrology

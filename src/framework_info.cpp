#include "framework_info.h"

namespace metrology {

std::string framework_banner() {
  return "Metrology Test Framework";
}

std::string framework_version() {
  return std::string(kFrameworkVersion);
}

}  // namespace metrology

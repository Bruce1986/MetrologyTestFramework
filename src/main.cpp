#include "framework_info.h"

#include <iostream>

int main() {
  std::cerr << metrology::framework_banner() << " v"
            << metrology::framework_version() << '\n';
  return 0;
}

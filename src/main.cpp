#include "framework_info.h"

#include <iostream>

int main() {
  std::cout << metrology::framework_banner() << " v"
            << metrology::framework_version() << std::endl;
  return 0;
}

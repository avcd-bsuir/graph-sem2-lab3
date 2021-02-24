#include "utils.hpp"

void throwError(std::string type, std::string details) {
    std::cout << "error: " << type << ": " << details << "\n";
    exit(-1);
}

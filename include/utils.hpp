#ifndef UTILS_HPP
#define UTILS_HPP

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void log(std::string, std::string);

void throwError(std::string, std::string);

// This function really should be here, but C++ standart no longer supports "export" keyword, that was supposed to export instantiable.
// template<typename T>
// T lerp(T a, T b, float u);

#endif

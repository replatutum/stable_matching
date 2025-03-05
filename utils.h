#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<std::vector<std::string>> readNames(const std::string& filename);
std::vector<std::vector<int>> readPreferences(const std::string& filename, int n);

#endif

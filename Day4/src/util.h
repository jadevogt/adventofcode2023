//
// Created by Jade Vogt on 12/3/23.
//

#ifndef DAY4_UTIL_H
#define DAY4_UTIL_H
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <utility>
#include <sstream>
std::vector<std::string> readLines(const std::string &filename);
std::pair<std::set<int>, std::set<int>> get_numbers(std::string &inputLine);
#endif //DAY4_UTIL_H

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
#include <iostream>

struct mapEntry {
    long long destinationRangeStart;
    long long sourceRangeStart;
    long long rangeLength;
};
long long convertValueBackwards(const std::vector<mapEntry> &entries, long long inputNumber);
long long convertValue(const std::vector<mapEntry> &entries, long long inputNumber);
std::pair<std::vector<long long>, std::vector<std::vector<mapEntry>>> getMaps(const std::string& filename);
mapEntry mapFromLine(const std::string& inputLine);
std::vector<std::string> readLines(const std::string &filename);
std::pair<std::set<int>, std::set<int>> getNumbers(std::string &inputLine);
#endif //DAY4_UTIL_H

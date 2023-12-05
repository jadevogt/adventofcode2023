//
// Created by Jade Vogt on 12/3/23.
//

#ifndef DAY4_UTIL_H
#define DAY4_UTIL_H
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_set>
#include <iostream>
#include <utility>
#include <sstream>

struct mapEntry {
    long long destinationRangeStart;
    long long sourceRangeStart;
    long long rangeLength;
};

struct mapEntryTwo {
    long long start;
    long long end;
    long long val;
};

long long convertValue(const std::vector<mapEntry> &entries, long long inputNumber);


mapEntry mapFromLine(const std::string& inputLine);
mapEntryTwo mapFromLineTwo(const std::string& inputLine);


std::vector<std::pair<long long int, long long int>> convertValueTwo(const std::vector<mapEntryTwo> &entries, std::pair<long long, long long> inputRange);
std::pair<std::vector<std::pair<long long, long long>>, std::vector<std::vector<mapEntryTwo>>> getMapsTwo(const std::string& filename = "inputalt.txt");
std::pair<std::vector<long long>, std::vector<std::vector<mapEntry>>> getMaps(const std::string& filename = "inputalt.txt");

std::vector<std::string> readLines(const std::string &filename);
std::pair<std::set<int>, std::set<int>> getNumbers(std::string &inputLine);
#endif //DAY4_UTIL_H

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

struct node {
    std::string left;
    std::string right;
    std::string name;
};

std::vector<std::string> startingNodes(const std::vector<std::string>& lines);
std::pair<std::unordered_map<std::string, node>, std::string> parseNodes(const std::vector<std::string>& lines);
std::vector<std::string> readLines(const std::string &filename);
std::pair<std::set<int>, std::set<int>> getNumbers(std::string &inputLine);
#endif //DAY4_UTIL_H

//
// Created by Jade Vogt on 12/3/23.
//

#ifndef DAY4_UTIL_H
#define DAY4_UTIL_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <utility>
#include <sstream>
struct hand {
    long bid;
    long score;
    std::string cards;
    std::string swapped;
    std::vector<int> vals;
};
bool compareHands(const hand& first, const hand& second);
std::vector<std::string> readLines(const std::string &filename);
std::pair<std::set<int>, std::set<int>> getNumbers(std::string &inputLine);
std::vector<hand> getHands(const std::string &filename);
hand getHand(const std::string &line);



#endif //DAY4_UTIL_H

//
// Created by Jade Vogt on 12/3/23.
//

#ifndef DAY_6_UTIL_H
#define DAY_6_UTIL_H
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <utility>
#include <sstream>
struct race {
    long long time;
    long long distance;
};

long long calculateMarginOfError(const std::vector<race> &races);
long long calculateNumWins(long long timeLimit, long long currentRecord);
long long calculateDistance(long long timeHeld, long long timeLimit);
#endif //DAY_6_UTIL_H

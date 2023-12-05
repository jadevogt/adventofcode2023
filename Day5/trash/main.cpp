#include <iostream>
#include "util.h"

void partOne();
void partTwo();

int main() {
    partOne();
    partTwo();
}

void partOne() {
    unsigned long long result = 0;
    auto maps = getMapsTwo();
    std::vector<std::pair<long long, long long>> newRanges;
    for (const auto& seed : maps.first) {
        std::vector<std::pair<long long, long long>> seedRange = {seed};
        for (auto range: seedRange) {
            std::cout << "seed range " << range.first << ", " << range.second << "\n";
            for (const auto& map : maps.second) {
                auto x = convertValueTwo(map, range);
                newRanges.insert(newRanges.end(), x.begin(), x.end());
            }
        }
    }
    std::cout << "Part one: " << result;
    for (auto range : newRanges) {
        std::cout << "\t range: " << range.first << " - " << range.second << "\n";
    }
}

void partTwo() {
}


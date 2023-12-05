#include <iostream>
#include "util.h"

void partOne();
void partTwo();

void forwards() {
    long long result = 0;
    auto maps = getMaps("inputalt.txt");
    for (const auto& seed : maps.first) {
        long long num = seed;
        for (const auto& map : maps.second) {
            num = convertValue(map, num);
        }
        if (num < result || result == 0) {
            result = num;
        }
    }
    std::cout << "Part one: " << result;
}

void backwards() {
    auto maps = getMaps("input.txt");
    for (long long i = 0; i < 999999999999999999; i++) {
        long long num = i;
        for (size_t j = maps.second.size(); j > 0; j--) {
            num = convertValueBackwards(maps.second[j-1], num);
        }
        if (
                        (num > 5844012 && num < (5844012+110899473)) ||
                        (num > 1132285750LL && num < (1132285750LL+58870036LL)) ||
                        (num > 986162929LL && num < (986162929LL+109080640LL)) ||
                        (num > 3089574276LL && num < (3089574276LL+100113624LL)) ||
                        (num > 2693179996LL && num < (2693179996LL+275745330LL)) ||
                        (num > 2090752257LL && num < (2090752257LL+201704169LL)) ||
                        (num > 502075018LL && num < (502075018LL+396653347LL)) ||
                        (num > 1540050181LL && num < (1540050181LL+277513792LL)) ||
                        (num > 1921754120LL && num < (1921754120LL+26668991LL)) ||
                        (num > 3836386950LL && num < (3836386950LL+66795009LL))
                ) {
            std::cout << i << "! \n";
            return;
        }
    }
}

int main() {
    backwards();
}

void partTwo() {
}

void partOne() {
}

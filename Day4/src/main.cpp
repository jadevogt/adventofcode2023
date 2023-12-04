#include <iostream>
#include "util.h"

void partOne();
void partTwo();

int main() {
    partOne();
    partTwo();
}

void partTwo() {
    auto lines = readLines("input.txt");
    std::vector<size_t> copyCount(lines.size());
    std::fill(copyCount.begin(), copyCount.end(), 1);
    for (size_t i = 0; i < lines.size(); i++) {
        auto numberSets = getNumbers(lines[i]);
        int matches = 1;
        for (auto winningNumber : numberSets.first) {
            if (numberSets.second.contains(winningNumber)) {
                copyCount[i + matches++] += (1 * copyCount[i]);
            }
        }
    }
    long long sum = 0;
    for (unsigned long i : copyCount) {
        sum += static_cast<long long>(i);
    }
    std::cout << "Part Two: " << sum << '\n';
}

void partOne() {
    auto lines = readLines("input.txt");
    long long sum{0};
    for (auto line : lines) {
        long long tempSum = 0;
        auto numberSets = getNumbers(line);
        for (auto n : numberSets.first) {
            if (numberSets.second.contains(n)) {
                tempSum = tempSum == 0 ? tempSum + 1 : tempSum * 2;
            }
        }
        sum += tempSum;
    }
    std::cout << "Part One: " << sum << '\n';
}
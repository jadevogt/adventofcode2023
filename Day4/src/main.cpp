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
    std::vector<size_t> copyCount{};
    for (size_t i = 0; i < lines.size(); i++) {
        copyCount.push_back(1);
    }
    for (size_t i = 0; i < copyCount.size(); i++) {
        auto x = get_numbers(lines[i]);
        int matches = 1;
        for (auto n : x.first) {
            if (x.second.contains(n)) {
                copyCount[i + matches] += (1 * copyCount[i]);
                matches++;
            }
        }
    }
    long long sum = 0;
    for (size_t i = 0; i < copyCount.size(); i++) {
        sum += copyCount[i];
    }
    std::cout << "Part Two: " << sum << '\n';
}

void partOne() {
    auto lines = readLines("input.txt");
    std::vector<int> copyCount{};
    for (size_t i = 0; i < lines.size(); i++) {
        copyCount.push_back(1);
    }
    long long sum{0};
    for (auto line : lines) {
        long long tmp_sum = 0;
        auto x = get_numbers(line);
        for (auto n : x.first) {
            if (x.second.contains(n)) {
                if (tmp_sum == 0) {
                    tmp_sum += 1;
                }
                else {
                    tmp_sum *= 2;
                }
            }
        }
        sum += tmp_sum;
    }
    std::cout << "Part One: " << sum << '\n';
}
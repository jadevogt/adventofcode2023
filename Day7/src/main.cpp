#include <iostream>
#include "util.h"

void partOne();
void partTwo();

int main() {
    partOne();
    partTwo();
}

void partTwo() {
}

void partOne() {
    std::cout << "Part One:\n";
    auto testHands = getHands("inputalt.txt");
    std::sort(testHands.begin(), testHands.end(), compareHands);
    unsigned long total = 0;
    for (size_t i = 0; i < testHands.size(); i++) {
        total += (testHands[i].bid * (i + 1));
    }
    for (int i = 0; i < testHands.size(); i++) {
        std::cout << testHands[i].cards << " ("  << testHands[i].swapped << ") " << testHands[i].bid << " " << testHands[i].score << " {";
        for (auto n : testHands[i].vals) {
            std::cout << " " << n;
        }
        std::cout << "}\n";
    }
    std::cout << "\tTest Result: " << total << "\n";
    auto inputHands = getHands("input.txt");
    std::sort(inputHands.begin(), inputHands.end(), compareHands);
    total = 0;
    for (size_t i = 0; i < inputHands.size(); i++) {
        total += (inputHands[i].bid * (i + 1));
    }
    std::cout << "\tInput Result: " << total << "\n";
}

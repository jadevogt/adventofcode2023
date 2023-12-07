#include <iostream>
#include "util.h"

std::vector<race> TEST_RACES {
        {7, 9}, {15, 40}, {30, 200}
};

race LONG_TEST_RACE {
        71530,
        940200
};

// just enter your input, it'll be faster
std::vector<race> INPUT_RACES {
};

// replace with your input
race LONG_INPUT_RACE {
    10, 10
};

void partOne();
void partTwo();

int main() {
    partOne();
    partTwo();
}

void partTwo() {
    std::cout << "Part Two: \n";
    auto testResult = calculateNumWins(LONG_TEST_RACE.time, LONG_TEST_RACE.distance);
    std::cout << "\tTest Result: " << testResult << "\n";
    auto inputResult = calculateNumWins(LONG_INPUT_RACE.time, LONG_INPUT_RACE.distance);
    std::cout << "\tInput Result: " << inputResult << "\n";
}

void partOne() {
    std::cout << "Part One: \n";
    auto testResult = calculateMarginOfError(TEST_RACES);
    std::cout << "\tTest Result: " << testResult << "\n";
    auto inputResult = calculateMarginOfError(INPUT_RACES);
    std::cout << "\tInput Result: " << inputResult << "\n";
}

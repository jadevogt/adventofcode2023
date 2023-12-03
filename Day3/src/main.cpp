#include "util.h"

void partOne(const char *input_file);

void partTwo(const char *input_file);

int main(int argc, char *argv[]) {
    // get optional command line argument specifying filename
    const char *input_file = "input.txt";
    if (argc >= 2) {
        input_file = argv[1];
    }
    partOne(input_file);
    partTwo(input_file);
    return 0;
}


void partOne(const char *input_file) {
    /*
     * Prints the solution for part one of the day 3 challenge
     * Using the given input, return the sum of all numbers surrounded by a special character (excluding .)
     */
    auto lines = parseLines(input_file);
    long long sum{0};
    for (size_t y = 0; y < lines.size(); y++) {
        std::string number;
        bool valid = false;
        for (size_t x = 0; x < lines.at(y).length(); x++) {
            if (isNumeric(lines.at(y)[x])) {
                number += lines.at(y)[x];
                if (checkSurrounding(lines, x, y))
                    valid = true;
            } else {
                if (valid) {
                    try {
                        sum += std::stoi(number);
                    } catch (std::exception &e) {
                        continue;
                    }
                }
                valid = false;
                number = "";
            }
        }
        if (valid) {
            try {
                sum += std::stoi(number);
            } catch (std::exception &e) {
                continue;
            }
        }
    }
    std::cout << "Part One Answer: " << sum << "\n";
}


void partTwo(const char *input_file) {
    /*
     * Prints the solution for part two of the day 3 challenge
     * Using the given input, calculate the sum of all products of numbers surrounding asterisks, if the asterisk in question
     * is surrounded by exactly two numbers.
     */
    auto lines = parseLines(input_file);
    long long sum{0};
    auto field = buildField(static_cast<int>(lines.at(0).length()), static_cast<int>(lines.size()));
    for (size_t y = 0; y < lines.size(); y++) {
        std::string number;
        std::set<std::pair<int, int>> currentStars{};
        for (size_t x = 0; x < lines.at(y).length(); x++) {
            if (isNumeric(lines.at(y)[x])) {
                number += lines.at(y)[x];
                auto newStars = getStars(lines, x, y);
                std::set<std::pair<int, int>> combined;
                std::set_union(currentStars.begin(), currentStars.end(), newStars.begin(), newStars.end(),
                               std::inserter(combined, std::begin(combined)));
                currentStars = combined;
            } else {
                if (!number.empty()) {
                    for (std::pair<int, int> star: currentStars) {
                        try {
                            field[star.first][star.second].insert(std::stoi(number));
                        } catch (std::exception &e) {
                            continue;
                        }
                    }
                }
                number = "";
                currentStars = std::set < std::pair<int, int>>
                {};
            }
        }
        if (!number.empty()) {
            for (std::pair<int, int> star: currentStars) {
                try {
                    field[star.first][star.second].insert(std::stoi(number));
                } catch (std::exception &e) {
                    continue;
                }
            }
        }
    }
    for (const auto &row: field) {
        for (const auto &col: row) {
            if (col.size() == GEAR_COUNT) {
                int tmp = 1;
                for (auto x: col) {
                    tmp *= x;
                }
                sum += tmp;
            }
        }
    }
    std::cout << "Part Two Answer: " << sum << "\n";
}



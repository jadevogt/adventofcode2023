//
// Created by Jade Vogt on 12/3/23.
//

#include "util.h"

std::vector<std::string> readLines(const std::string &filename) {
    std::ifstream infile;
    std::vector<std::string> lines{};
    infile.open(filename);
    std::string currentLine;
    // exit early if the file failed to open
    if (!infile) {
        return lines;
    }
    while (std::getline(infile, currentLine)) {
        lines.push_back(currentLine);
    }
    return lines;
}

// A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2
int val(char c) {
    switch (c) {
        case 'A': return 13; break;
        case 'K': return 12; break;
        case 'Q': return 11; break;
        case 'T': return 10; break;
        case '9': return 9; break;
        case '8': return 8; break;
        case '7': return 7; break;
        case '6': return 6; break;
        case '5': return 5; break;
        case '4': return 4; break;
        case '3': return 3; break;
        case '2': return 2; break;
        case 'J': return 1; break;
    }
    return 0;
}

hand getHand(const std::string &line) {
    std::stringstream ss{line};
    std::string cards;
    long bid;
    ss >> cards;
    ss >> bid;
    long score = 0;
    std::vector<int> vals{};
    char mostCommon = 'J';
    long topCount = 0;
    for (char c : cards) {
        long count = std::ranges::count(cards.begin(), cards.end(),c);
        if (count > topCount && c != 'J') {
            mostCommon = c;
            topCount = count;
        }
    }
    std::string c = cards;
    std::replace(c.begin(), c.end(), 'J', mostCommon);

    for (size_t i = 0; i < 5; i++) {
        score += std::ranges::count(c, c[i]);
        vals.push_back(val(cards[i]));
    }
    return {bid, score, cards, c, vals};
}

std::vector<hand> getHands(const std::string &filename) {
    auto lines = readLines(filename);
    std::vector<hand> hands{};
    hands.reserve(lines.size());
for (const auto& line : lines) {
        hand x = getHand(line);
        hands.push_back(x);
    }
    return hands;
}

bool compareHands(const hand& first, const hand& second) {
    if (first.score != second.score) {
        return (first.score < second.score);
    }
    for (size_t i = 0; i < 5; i++) {
        if (first.vals.at(i) == second.vals.at(i)) {
            continue;
        }
        return (first.vals[i] < second.vals[i]);
    }
    return false;
}
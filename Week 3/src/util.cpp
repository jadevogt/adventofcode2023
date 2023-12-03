//
// Created by Jade Vogt on 12/3/23.
//
#include "util.h"

std::vector<std::string> parseLines(const char* input_file) {
    std::string line;
    std::vector<std::string> lines{};
    std::ifstream infile(input_file);
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();
    return lines;
}

bool isNumeric(char c) {
    if (c < '0' || c > '9')
        return false;
    return true;
}

bool isSymbol(char c) {
    if (c != '.' && !isNumeric(c)) {
        return true;
    }
    return false;
}

bounds getBounds(const std::vector<std::string> &grid, int x, int y) {
    auto min_x = x == 0 ? 0 : x - 1;
    auto max_x = x < grid.at(y).length() - 1 ? x + 1 : x;
    auto min_y = y == 0 ? 0 : y - 1;
    auto max_y = y < grid.size() - 1 ? y + 1 : y;
    return bounds{min_x, max_x, min_y, max_y};
}

bool checkSurrounding(const std::vector<std::string> &grid, const int x, const int y) {
    bounds bnds = getBounds(grid, x, y);
    for (int a = bnds.min_x; a <= bnds.max_x; a++) {
        for (int b = bnds.min_y; b <= bnds.max_y; b++) {
            if (isSymbol(grid.at(b)[a]))
                return true;
        }
    }
    return false;
}

std::set<std::pair<int, int>> getStars(const std::vector<std::string> &grid, int x, int y) {
    bounds bnds = getBounds(grid, x, y);
    std::set<std::pair<int, int>> stars{};
    for (int a = bnds.min_x; a <= bnds.max_x; a++) {
        for (int b = bnds.min_y; b <= bnds.max_y; b++) {
            if (grid.at(b)[a] == '*') {
                stars.insert(std::pair<int, int>{b, a});
            }
        }
    }
    return stars;
}

std::vector<std::vector<std::set<int>>> buildField(int width, int height) {
    std::vector<std::vector<std::set<int>>> field(width);
    for (int x = 0; x < width; x++) {
        field[x] = std::vector<std::set<int>>(height);
        for (int y = 0; y < height; y++) {
            field[x][y] = std::set<int>{};
        }
    }
    return field;
}
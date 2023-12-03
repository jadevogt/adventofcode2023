//
// Created by Jade Vogt on 12/3/23.
//

#ifndef WEEK_3_UTIL_H
#define WEEK_3_UTIL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <set>

const int GEAR_COUNT = 2;

struct bounds {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
};

std::vector<std::string> parseLines(const char *input_file);

bool isNumeric(char c);

bool isSymbol(char c);

bounds getBounds(const std::vector<std::string> &grid, int x, int y);

bool checkSurrounding(const std::vector<std::string> &grid, int x, int y);

std::set<std::pair<int, int>> getStars(const std::vector<std::string> &grid, int x, int y);

std::vector<std::vector<std::set<int>>> buildField(int width, int height);

#endif //WEEK_3_UTIL_H

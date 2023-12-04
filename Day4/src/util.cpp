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

bool isNumeric(char c) {
    if (c < '0' || c > '9') {
        return false;
    }
    return true;
}

std::pair<std::set<int>, std::set<int>> get_numbers(std::string &inputLine) {
    std::string_view trimmed{inputLine};
    size_t colon_index = trimmed.find_first_of(':');
    std::pair<std::set<int>, std::set<int>> nums{};
    if (colon_index != std::string::npos) {
        trimmed.remove_prefix(colon_index + 1);
    }
    size_t bar_index = trimmed.find_first_of('|');
    if (bar_index == std::string::npos) {
        return nums;
    }
    auto winners_str = trimmed.substr(0, bar_index);
    auto has_str = trimmed.substr(bar_index);
    std::stringstream winners_stream{std::string{winners_str}};
    std::stringstream has_stream{std::string{has_str}};
    std::string tmp;
    while (winners_stream >> tmp) {
        if (!isNumeric(tmp[0]))
            continue;
        nums.first.insert(std::stoi(tmp));
    }
    tmp = "";
    while (has_stream >> tmp) {
        if (!isNumeric(tmp[0]))
            continue;
        nums.second.insert(std::stoi(tmp));
    }
    return nums;
}
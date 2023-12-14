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

std::vector<std::string> startingNodes(const std::vector<std::string>& lines) {
    std::vector<std::string> nodes{};
    for (size_t i = 2; i < lines.size(); i++) {
        if (lines[i][2] == 'A') {
            nodes.push_back(lines[i].substr(0,3));
        }
    }
    return nodes;
}

std::pair<std::unordered_map<std::string, node>, std::string> parseNodes(const std::vector<std::string>& lines) {
    std::unordered_map<std::string, node> returnValue{};
    std::string instructions{};
    for (size_t i = 0; i < lines.size(); i++) {
        if (i == 0) {
            instructions = lines[i];
            continue;
        }
        if (i == 1) {
            continue;
        }
        auto name = lines[i].substr(0, 3);
        auto left = lines[i].substr(7, 3);
        auto right = lines[i].substr(12, 3);
        returnValue[name] = {left, right, name};
    }
    return {returnValue, instructions};
};

std::pair<std::set<int>, std::set<int>> getNumbers(std::string &inputLine) {
    std::string_view trimmed{inputLine};
    size_t colonIndex = trimmed.find_first_of(':');
    std::pair<std::set<int>, std::set<int>> nums{};
    if (colonIndex != std::string::npos) {
        trimmed.remove_prefix(colonIndex + 1);
    }
    size_t bar_index = trimmed.find_first_of('|');
    if (bar_index == std::string::npos) {
        return nums;
    }
    auto winnersStr = trimmed.substr(0, bar_index);
    auto hasStr = trimmed.substr(bar_index);
    std::stringstream winnersStream{std::string{winnersStr}};
    std::stringstream hasStream{std::string{hasStr}};
    std::string tmp;
    while (winnersStream >> tmp) {
        if (!isNumeric(tmp[0]))
            continue;
        nums.first.insert(std::stoi(tmp));
    }
    tmp = "";
    while (hasStream >> tmp) {
        if (!isNumeric(tmp[0]))
            continue;
        nums.second.insert(std::stoi(tmp));
    }
    return nums;
}

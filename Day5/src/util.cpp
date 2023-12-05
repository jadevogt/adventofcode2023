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

long long convertValue(const std::vector<mapEntry> &entries, long long inputNumber) {
    auto num = inputNumber;
    for (auto entry : entries) {
        if (num >= entry.sourceRangeStart && num < entry.sourceRangeStart + entry.rangeLength) {
            num = entry.destinationRangeStart + (inputNumber - entry.sourceRangeStart);
            return num;
        }
    }
    return num;
}

long long convertValueBackwards(const std::vector<mapEntry> &entries, long long inputNumber) {
    auto num = inputNumber;
    for (auto entry : entries) {
        if (num >= entry.destinationRangeStart && num < entry.destinationRangeStart + entry.rangeLength) {
            num = entry.sourceRangeStart + (inputNumber - entry.destinationRangeStart);
            return num;
        }
    }
    return num;
}

std::pair<std::vector<long long>, std::vector<std::vector<mapEntry>>> getMaps(const std::string& filename) {
    std::ifstream infile;
    std::cout << filename;
    infile.open(filename);
    std::string currentLine;
    std::vector<std::vector<mapEntry>> maps{};
    std::vector<mapEntry> currentMaps{};
    std::vector<long long> seeds;
    long long currentSeed = 0;
    while (std::getline(infile, currentLine)) {
        if (currentLine.starts_with("seeds: ")) {
            continue;
        }
        if (!isNumeric(currentLine[0]) && !currentMaps.empty()) {
            maps.push_back(currentMaps);
            currentMaps = std::vector<mapEntry>{};
            continue;
        }
        if (!isNumeric(currentLine[0])) {
            continue;
        }
        currentMaps.push_back(mapFromLine(currentLine));
    }
    maps.push_back(currentMaps);
    return std::pair<std::vector<long long>, std::vector<std::vector<mapEntry>>>{seeds, maps};
}

mapEntry mapFromLine(const std::string& inputLine) {
    long long dest;
    long long src;
    long long len;
    std::stringstream entryStream{inputLine};
    entryStream >> dest;
    entryStream >> src;
    entryStream >> len;
    return mapEntry{dest, src, len};
}
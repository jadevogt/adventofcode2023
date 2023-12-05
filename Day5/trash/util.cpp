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

mapEntryTwo mapFromLineTwo(const std::string& inputLine) {
    long long dest;
    long long src;
    long long len;
    std::stringstream entryStream{inputLine};
    entryStream >> dest;
    entryStream >> src;
    entryStream >> len;
    return mapEntryTwo{src, src+len, dest - src};
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

std::pair<std::vector<std::pair<long long, long long>>, std::vector<std::vector<mapEntryTwo>>> getMapsTwo(const std::string& filename) {
    std::ifstream infile;
    std::cout << filename;
    infile.open(filename);
    std::string currentLine;
    std::vector<std::vector<mapEntryTwo>> maps{};
    std::vector<mapEntryTwo> currentMaps{};
    std::vector<std::pair<long long, long long>> seeds;
    long long currentSeed = 0;
    while (std::getline(infile, currentLine)) {
        if (currentLine.starts_with("seeds: ")) {
            std::cout << "Parsing seeds \n";
            auto trimmed = currentLine.substr(6);
            std::stringstream seedStream{trimmed};
            std::string tmp;
            while (seedStream >> tmp) {
                if (!isNumeric(tmp[0]))
                    continue;
                long long in = std::stoll(tmp);
                if (currentSeed == 0) {
                    currentSeed = in;
                    continue;
                }
                else {
                    seeds.emplace_back(currentSeed, currentSeed+in);
                }
                currentSeed = 0;
            }
            continue;
        }
        if (!isNumeric(currentLine[0]) && !currentMaps.empty()) {
            maps.push_back(currentMaps);
            currentMaps = std::vector<mapEntryTwo>{};
            continue;
        }
        if (!isNumeric(currentLine[0])) {
            continue;
        }
        currentMaps.push_back(mapFromLineTwo(currentLine));
    }
    maps.push_back(currentMaps);
    return std::pair<std::vector<std::pair<long long, long long>>, std::vector<std::vector<mapEntryTwo>>>{seeds, maps};
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
            std::cout << "Parsing seeds \n";
            auto trimmed = currentLine.substr(6);
            std::stringstream seedStream{trimmed};
            std::string tmp;
            while (seedStream >> tmp) {
                if (!isNumeric(tmp[0]))
                    continue;
                long long in = std::stoll(tmp);
                if (currentSeed == 0) {
                    currentSeed = in;
                    continue;
                }
                else {
                    for (long long i = 0; i < in; i++) {
                        seeds.push_back(currentSeed + i);
                    }
                }
                currentSeed = 0;
            }
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

std::vector<std::pair<long long int, long long int>> convertValueTwo(const std::vector<mapEntryTwo> &entries, std::pair<long long, long long> inputRange) {
    std::vector<std::pair<long long, long long>> ranges{inputRange};
    std::vector<std::pair<long long, long long>> newRanges{};
    for (auto entry : entries) {
        for (auto range : ranges) {
            //std::cout << "converting range " << range.first << " - " << range.second << "\n";
            if (range.first >= entry.start && range.second < entry.end) {
                newRanges.emplace_back(range.first+entry.val, range.second+entry.val);
            }
            else if ((range.first < entry.start && range.second < entry.start) || range.first > entry.end) {
                newRanges.emplace_back(range);
            }
            else if (range.first < entry.start && range.second <= entry.end) {
                newRanges.emplace_back(range.first, entry.start);
                newRanges.emplace_back(entry.start+entry.val, range.second+entry.val);
            }
            else if (range.first > entry.start && range.second > entry.end) {
                newRanges.emplace_back(range.first+entry.val, entry.end+entry.val);
                newRanges.emplace_back(entry.end, range.second);
            }
        }
    }
    return newRanges;
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
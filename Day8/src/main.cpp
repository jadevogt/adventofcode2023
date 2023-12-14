#include <iostream>
#include "util.h"

void partOne(std::string);
void partTwo();

int main() {
    partOne("AAA");
    partOne("VLA");
    partOne("PJA");
    partOne("VSA");
    partOne("QKA");
    partOne("CPA");
    //partTwo();
}

bool endsWithZ(const node& n) {
    return n.name[2] == 'Z';
}

bool endsWithZ(const std::string &s) {
    return s[2] == 'Z';
}

void partTwo() {
    /*
    auto lines = readLines("input.txt");
    auto x = parseNodes(lines);
    auto starters = startingNodes(lines);
    std::vector<node> nodes{};
    nodes.reserve(starters.size());
    for (auto n: starters) {
        nodes.push_back(x.first[n]);
    }
    std::string currentNode = "AAA";
    unsigned long long steps = 0;
    bool done = false;
    start:
    for (auto c : x.second) {
        if (std::all_of(nodes.begin(), nodes.end(), endsWithZ)) {
            done = true;
            std::cout << "Part Two Result: " << steps << "\n";
            break;
        }
        if (c == 'L') {
            for (size_t n = 0; n < nodes.size(); n++) {
                nodes[n] = x.first.at(nodes[n].left);
            }
            steps += 1;
            continue;
        }
        if (c == 'R') {
            for (size_t n = 0; n < nodes.size(); n++) {
                nodes[n] = x.first.at(nodes[n].right);
            }
            steps += 1;
            continue;
        }

    }
    if (!done) {
        goto start;
    }
     */
}

void partOne(std::string starterNode) {
    auto x = parseNodes(readLines("input.txt"));
    std::string currentNode = starterNode;
    unsigned long long steps = 0;
    bool done = false;
    start:
    for (auto c : x.second) {
        if (endsWithZ(currentNode)) {
            done = true;
            std::cout << "Part One Result: " << steps << "\n";
            break;
        }
        if (c == 'L') {
            currentNode = x.first.at(currentNode).left;
            steps += 1;
            continue;
        }
        if (c == 'R') {
            currentNode = x.first.at(currentNode).right;
            steps += 1;
            continue;
        }

    }
    if (!done) {
        goto start;
    }
}

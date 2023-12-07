//
// Created by Jade Vogt on 12/3/23.
//

#include "util.h"

long long calculateMarginOfError(const std::vector<race> &races) {
    long long total = 1;
    for (auto race:races) {
        total *= calculateNumWins(race.time, race.distance);
    }
    return total;
}

long long calculateNumWins(long long timeLimit, long long currentRecord) {
    long long total = 0;
    for (long long i = 0; i < timeLimit; i++) {
        if (calculateDistance(i, timeLimit) > currentRecord) {
            total += 1;
        }
    }
    return total;
}

long long calculateDistance(long long timeHeld, long long timeLimit) {
    auto distance = (timeLimit - timeHeld) * (timeHeld);
    return distance >= 0 ? distance : 0;
}

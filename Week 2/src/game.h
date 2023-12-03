//
// Created by Jade Vogt on 12/2/23.
//

#ifndef WEEK_2_GAME_H
#define WEEK_2_GAME_H

struct game {
    int id;
    long long redCount;
    long long greenCount;
    long long blueCount;
};
struct subGame {
    long long redCount;
    long long greenCount;
    long long blueCount;
};
game parseGame(std::string inputLine);
std::vector<int> getIndices(std::string inputString, char delimiter);
subGame getSubGame(std::string subgameStr);
#endif //WEEK_2_GAME_H

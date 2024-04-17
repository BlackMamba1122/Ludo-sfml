#pragma once
#include "Source.h"
class Game {
private:
    sf::RenderWindow window;
    int playernum;
    int piecenum;
    int team_size;
    bool continu;

public:
    Game() : window(sf::VideoMode(1700, 950), "LUDO", sf::Style::Close), playernum(6), piecenum(3), team_size(1), continu(false) {}

    void play() {
        StartScreen(window, continu);
        if (!continu) {
            PlayerSelect(window, playernum);
            PieceSelect(window, piecenum);
            if (playernum == 4 || playernum == 6)
                SingMultSelect(window, team_size);
        }
        startGame(window, playernum, piecenum, team_size, continu);
    }
};



#include <SFML/Graphics.hpp>
#pragma once
#include "../Blocks/Block.hpp"
struct Map {
    sf::RectangleShape board;
    void use(int x, int y);
    int field[20][10];
};

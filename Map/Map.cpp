#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void Map::use(int x ,int y){
        board.setOrigin(150,150);
        board.setSize(sf::Vector2f(x,y));
        board.setPosition(300,300);
        for(int i =0; i<20; i++){
                for(int j=0; j<10; j++){
                    field[i][j] = 0;
                }
        }
}





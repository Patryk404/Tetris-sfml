#include <SFML/Graphics.hpp>
#include "../Engine/Engine.hpp"
#include "../Blocks/Block.hpp"
#include <iostream>
#include <string>
#include <sstream>
class UI {
public:
    UI(Engine &engine);
    void set_score(Engine &engine);
    void render_score(sf::RenderWindow &window);
    Block next_block[4];
    sf::Text game_over[2];
private:
    sf::Text score;
    sf::Text next;
    sf::RectangleShape next_block_sp;
    sf::Text Tetris;
    sf::Text Credits[2];
    sf::Font font;
    sf::Sprite background;
    sf::RectangleShape right;
    sf::Texture texture;
};

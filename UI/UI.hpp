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
private:
    sf::Text score;
    sf::Text next;
    sf::RectangleShape next_block_sp;
    sf::Font font;
    sf::Sprite background;
    sf::RectangleShape right;
    sf::Texture texture;
};

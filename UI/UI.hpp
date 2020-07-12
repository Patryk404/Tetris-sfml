#include <SFML/Graphics.hpp>
#include "../Engine/Engine.hpp"
#include <iostream>
#include <string>
#include <sstream>
class UI {
public:
    UI();
    void set_score(Engine &engine);
    void render_score(sf::RenderWindow &window);
private:
    sf::Text score;
    sf::Text next;
    sf::Sprite next_block;
    sf::Font font;
    sf::Sprite background;
    sf::RectangleShape right;
    sf::Texture texture;
};

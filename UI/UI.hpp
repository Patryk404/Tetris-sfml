#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class UI {
public:
    UI();
    void set_score(int score);
    void render_score(sf::RenderWindow &window);
private:
    sf::Text score;
    sf::Font font;
};

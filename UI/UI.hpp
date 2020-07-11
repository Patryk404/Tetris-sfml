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
    sf::Font font;
};

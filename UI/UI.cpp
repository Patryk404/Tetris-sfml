#include "UI.hpp"

UI::UI(){
    if(!font.loadFromFile("font/tetris.ttf")){
        std::cout<<"Error"<<std::endl;
    }
    score.setFont(font);
    score.setCharacterSize(20);
    score.setFillColor(sf::Color::Blue);
    score.setString("Score: ");
    score.setPosition(sf::Vector2f(500,200));
}

void UI::render_score(sf::RenderWindow &window){
    window.draw(score);
}

void UI::set_score(Engine &engine){
    std::ostringstream oStrStream;
    oStrStream << engine.score;
    score.setString("Score: "+ oStrStream.str());
}

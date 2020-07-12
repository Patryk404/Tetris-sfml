#include "UI.hpp"

UI::UI(){
    if(!font.loadFromFile("font/tetris.ttf")){
        std::cout<<"Error"<<std::endl;
    }
    score.setFont(font);
    score.setCharacterSize(20);
    score.setFillColor(sf::Color::Red);
    score.setString("Score: ");
    score.setPosition(sf::Vector2f(450,275));
    next.setFont(font);
    next.setCharacterSize(20);
    next.setFillColor(sf::Color::Red);
    next.setString("NEXT: ");
    next.setPosition(sf::Vector2f(450,350));
    right.setSize(sf::Vector2f(200,300));
    right.setOrigin(100,150);
    sf::Color color(183,184,169);
    right.setFillColor(color);
    right.setPosition(sf::Vector2f(500,400));
    if(!texture.loadFromFile("images/background.jpg")){
        std::cout<<"Error"<<std::endl;
    }
    background.setTexture(texture);
    next_block_sp.setSize(sf::Vector2f(18,18));
}

void UI::render_score(sf::RenderWindow &window){
    window.draw(background);
    window.draw(right);
    window.draw(score);
    window.draw(next);
    for (int i=0;i<4;i++)
      {
        next_block_sp.setPosition(next_block[i].x*20,next_block[i].y*20);
        next_block_sp.setFillColor(sf::Color::Red);
        next_block_sp.move(500,400); //offset
        window.draw(next_block_sp);
      }
}

void UI::set_score(Engine &engine){
    std::ostringstream oStrStream;
    oStrStream << engine.score;
    score.setString("Score: "+ oStrStream.str());
}

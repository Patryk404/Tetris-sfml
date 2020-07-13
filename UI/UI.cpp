#include "UI.hpp"

UI::UI(Engine &engine){
    if(!font.loadFromFile("font/tetris.ttf")){
        std::cout<<"Error"<<std::endl;
    }
    if(!icon.loadFromFile("images/icon.png")){
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
    for (int i=0; i<2; i++){
    game_over[i].setFont(font);
    game_over[i].setCharacterSize(32);
    game_over[i].setFillColor(sf::Color::Red);
    }
    game_over[0].setString("Game Over");
    game_over[0].setPosition(sf::Vector2f(200,300));
    game_over[1].setString("PRESS ENTER TO PLAY AGAIN");
    game_over[1].setPosition(75,400);
    Tetris.setFont(font);
    Tetris.setCharacterSize(50);
    sf::Color color1(2,231,247);
    Tetris.setFillColor(color1);
    Tetris.setString("TETRIS");
    Tetris.setPosition(sf::Vector2f(200,100));
    sf::Color color2(247,2,43);
    for(int i=0; i<2; i++){
    Credits[i].setFont(font);
    Credits[i].setCharacterSize(20);
    Credits[i].setFillColor(color2);
    }
    Credits[0].setString("Credits:");
    Credits[0].setPosition(sf::Vector2f(50,50));
    Credits[1].setString("Patryk 'Patryk404' Kurek");
    Credits[1].setPosition(sf::Vector2f(50,75));
    right.setSize(sf::Vector2f(200,300));
    right.setOrigin(100,150);
    sf::Color color3(183,184,169);
    right.setFillColor(color3);
    right.setPosition(sf::Vector2f(500,400));
    if(!texture.loadFromFile("images/background.jpg")){
        std::cout<<"Error"<<std::endl;
    }
    background.setTexture(texture);
    next_block_sp.setSize(sf::Vector2f(18,18));
    // Randomizing next block and giving it into UI class
    Block next_block[4];
    int n= rand()%7;
    int random_spawnpoint = rand()%6+2;
    for(int i=0; i<4; i++){ //randoming our next_block
            next_block[i].x = engine.figures[n][i] % 2;
            next_block[i].y = engine.figures[n][i] /2;
            UI::next_block[i] = next_block[i];
    }
    // ///////////////////////////////////////
}

void UI::render_score(sf::RenderWindow &window){
    window.draw(background);
    window.draw(right);
    window.draw(score);
    window.draw(next);
    window.draw(Tetris);
    for (int i=0; i<2; i++){
        window.draw(Credits[i]);
    }
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

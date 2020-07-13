#include <SFML/Graphics.hpp>
#include "Engine/Engine.hpp"
#include "UI/UI.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <time.h>

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris");
    window.setFramerateLimit(30);
    Engine engine;
    UI UI(engine);
    sf::Clock timer;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            engine.check_events(event);
        }
                engine.run_timer();
                engine.move();
                engine.rotation();
               engine.tick(UI.next_block);
               engine.check_lines();
               engine.check_gameover();
               engine.set_default();
               UI.set_score(engine);
        window.clear();
        UI.render_score(window);
        engine.render(window,UI.game_over);
        window.display();
    }
        return 0;
}

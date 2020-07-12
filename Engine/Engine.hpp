#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#pragma once
#include "../Blocks/Block.hpp"
#include "../Map/Map.hpp"

class Engine {
    public:
        Engine();
        void move();
        void rotation();
        void tick(std::array<Block, 4> block);
        void check_lines();
        void check_gameover();
        void run_timer();
        void set_default();
        void check_events(sf::Event &event);
        void render(sf::RenderWindow &window);
    private:
        const int figures[7][4] =
                {
                    {1,3,5,7}, // I
                    {2,4,5,7}, // Z
                    {3,5,4,6}, // S
                    {3,5,4,7}, // T
                    {2,3,5,7}, // L
                    {3,5,7,6}, // J
                    {2,3,4,5} // O
                };
        float time;
        int delay;
        bool game;
        int direction;
        int score;
        bool rotate;
        bool first;
        sf::Music music;
        sf::SoundBuffer buffer;
        sf::Sound dissmiss;
        sf::RectangleShape s;
        sf::Clock timer;
        Block a[4],b[4];
        Map Map;
        bool check();
        std::array<Block,4> randomize_block();

        friend class UI;
};

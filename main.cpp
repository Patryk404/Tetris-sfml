#include <SFML/Graphics.hpp>
#include "Engine/Engine.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <time.h>

/*const int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };
int direction = 0; // to move
int delay = 1;
bool rotate = 0;
sf::Music music;
bool game = true;
bool first = true;
Block a[4], b[4];
Map Map(300,600);
bool check(){
   for (int i=0;i<4;i++)
      if (a[i].x<0 || a[i].x>=10 || a[i].y>=20) return false;
      else if (Map.field[a[i].y][a[i].x]) return false;

   return true;
}*/

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris");
    window.setFramerateLimit(30);
    Engine engine;
    sf::Clock timer;
    //sf::RectangleShape s(sf::Vector2f(18,18));
    //sf::Clock timer;
    //float time = 0;
    //direction = 0;
    /*if (!music.openFromFile("music/tetris.wav")){
        std::cout<<"Error"<<std::endl;
    }
    music.setVolume(50);
    music.setLoop(true);
    music.play();*/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            engine.check_events(event);
            /*if (event.type == sf::Event::KeyPressed && engine.game)
            {
                if (event.key.code == sf::Keyboard::Left){
                    engine.direction = -1;
                }
                if (event.key.code == sf::Keyboard::Right){
                    engine.direction = 1;
                }
                if (event.key.code == sf::Keyboard::Up){
                    engine.rotate = 1;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    engine.delay = 0.2;
                }
            }*/
        }
                //time = timer.getElapsedTime().asSeconds();
                engine.run_timer();
                        //// <- Move -> ///
                        engine.move();
                /*for (int i=0;i<4;i++)  { b[i]=a[i]; a[i].x+=direction; }
                if (!check()) for (int i=0;i<4;i++) a[i]=b[i];*/
                ///////////////////////
                    //////Rotate//////
                    engine.rotation();
            /*if (rotate &&game)
              {
                Block p = a[1]; //center of rotation
                for (int i=0;i<4;i++)
                  {
                    int x = a[i].y-p.y;
                    int y = a[i].x-p.x;
                    a[i].x = p.x - x;
                    a[i].y = p.y + y;
                   }
                   if (!check()) for (int i=0;i<4;i++) a[i]=b[i];
              }*/
              //////////////////////
            engine.tick();
            /*if (time>delay && game)
            {
              for (int i=0;i<4;i++) { b[i]=a[i]; a[i].y+=1; }
                if (!check())
                {
                 for (int i=0;i<4;i++) Map.field[b[i].y][b[i].x]=1;

                 int n=rand()%7;
                 for (int i=0;i<4;i++)
                   {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                   }
                   s.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
                }
                else if(first){
                    int n=rand()%7;
                 for (int i=0;i<4;i++)
                   {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                   }
                    s.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
                   first = false;
                }
                  timer.restart();
            }*/
               ///////check lines//////////
               engine.check_lines();
            /*int k=20-1;
            for (int i=20-1;i>0;i--)
            {
                int count=0;
                for (int j=0;j<10;j++)
                {
                    if (Map.field[i][j]) count++;
                    Map.field[k][j]=Map.field[i][j];
                }
                if (count<10) k--;
            }*/
            //check is game over
            engine.check_gameover();
            /*int lol = false;
            for (int i=0; i<10; i++)
            {
                if (Map.field[0][i]){
                   lol = true;
                }
            }
            if (lol){
                game =false;
            }*/
            /////
            engine.set_default();
            /*direction = 0;
            rotate = 0;
            delay = 1;*/
        window.clear();
        /*window.draw(Map.board);
            for (int i=0;i<20;i++)
         for (int j=0;j<10;j++)
           {
             if (Map.field[i][j]==0) continue;
             s.setPosition(j*20,i*20);
             s.move(200,200); //offset
             window.draw(s);
           }
    if(!first)
    {
    for (int i=0;i<4;i++)
      {
        s.setPosition(a[i].x*20,a[i].y*20);
        s.move(200,200); //offset
        window.draw(s);
      }
    }*/
        engine.render(window);
        window.display();
    }
        return 0;
}

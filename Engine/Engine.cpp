#include "Engine.hpp"

Engine::Engine(){
    direction = 5;
    delay = 1;
    score = 0;
    rotate = false;
    game = true;
    first = true;
    Map.use(200,425);
    s.setSize(sf::Vector2f(18,18));
    if(!buffer.loadFromFile("music/dissmiss.wav")){
        std::cout<<"Error"<<std::endl;
    }
    dissmiss.setBuffer(buffer);
    dissmiss.setVolume(100);
    time = 0;
    for (int i=0; i<4; i++)
    {
        a[i].x = 0;
        b[i].x=0;
        a[i].y = 0;
        b[i].y=0;
    }
    if (!music.openFromFile("music/tetris.wav")){
        std::cout<<"Error"<<std::endl;
    }
    music.setVolume(50);
    music.setLoop(true);
    music.play();
}

bool Engine::check(){
   for (int i=0;i<4;i++)
      if (a[i].x<0 || a[i].x>=10 || a[i].y>=20) {
            return false;
      }
      else if (Map.field[a[i].y][a[i].x]) {
            return false;
      }

   return true;
}


void Engine::move(){
    for (int i=0;i<4;i++)  {
            b[i]=a[i]; a[i].x+=direction;
    }
    if (!check()) for (int i=0;i<4;i++) {
        a[i]=b[i];
    }
}

void Engine::rotation(){
 if (rotate &&game)
        {
        Block p = a[1]; //center of rotation
        for (int i=0;i<4;i++)
            {
                int x = a[i].y-p.y;
                int y = a[i].x-p.x;
                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }
            if (!check()) for (int i=0;i<4;i++) {
                a[i]=b[i];
            }
        }
}

void Engine::tick(Block block[]){
     if (time>delay && game)
            {
                for (int i=0;i<4;i++) { // one move down
                        b[i]=a[i]; a[i].y+=1;
                }
                Block next_block[4];
                int n= rand()%7;
                int random_spawnpoint = rand()%6+2;
                for(int i=0; i<4; i++){ //randoming our next_block
                    next_block[i].x = figures[n][i] % 2;
                    next_block[i].y = figures[n][i] /2;
                    block[i] = next_block[i];
                }

                if (!check())
                {
                 for (int i=0;i<4;i++) {
                        Map.field[b[i].y][b[i].x]=1;
                 }

                 int n=rand()%7;
                 for (int i=0;i<4;i++)
                   {
                    a[i].x = next_block[i].x+ random_spawnpoint;
                    a[i].y = next_block[i].y;
                   }
                   s.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
                    // Randomizing next block and giving it into UI class
                    block = randomize_block();
                    // ///////////////////////////////////////
                }
                else if(first){
                    int n=rand()%7;
                 for (int i=0;i<4;i++)
                   {
                    a[i].x = next_block[i].x + random_spawnpoint;
                    a[i].y = next_block[i].y;
                   }
                    s.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
                    // Randomizing next block and giving it into UI class
                    block = randomize_block();
                    // ///////////////////////////////////////
                   first = false;
                }
              timer.restart();
            }
}

void Engine::check_lines(){
        int k=20-1;
        for (int i=20-1;i>0;i--)
        {
            int count=0;
            for (int j=0;j<10;j++)
            {
                if (Map.field[i][j]) {
                        count++;
                    }
                Map.field[k][j]=Map.field[i][j];
            }
            if (count<10) {
                    k--;
                }
            if (count==10)
            {
                dissmiss.play();
                score += 10;
            }
        }
}

void Engine::check_gameover(){
        int lol = false;
        for (int i=0; i<10; i++)
        {
            if (Map.field[0][i]){
                lol = true;
            }
        }
        if (lol){
            game =false;
        }
}

void Engine::set_default(){
    direction = 0;
    rotate = 0;
    delay = 1;
}

void Engine::render(sf::RenderWindow &window){
        window.draw(Map.board);
        for (int i=0;i<20;i++){
         for (int j=0;j<10;j++)
           {
             if (Map.field[i][j]==0) continue;
             s.setPosition(j*20,i*20);
             s.move(200,200); //offset
             window.draw(s);
           }
        }
    if(!first)
    {
    for (int i=0;i<4;i++)
      {
        s.setPosition(a[i].x*20,a[i].y*20);
        s.move(200,200); //offset
        window.draw(s);
      }
    }
}

void Engine::check_events(sf::Event &event){
     if (event.type == sf::Event::KeyPressed && game)
            {
                if (event.key.code == sf::Keyboard::Left){
                    direction = -1;
                }
                if (event.key.code == sf::Keyboard::Right){
                    direction = 1;
                }
                if (event.key.code == sf::Keyboard::Up){
                    rotate = 1;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    delay = 0.2;
                }
            }
}

void Engine::run_timer(){
time = timer.getElapsedTime().asSeconds();
}

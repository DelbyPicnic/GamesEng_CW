#include "engine.h"
#include "game.h"
#include "scenes/menu.h"
#include "scenes/Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

MainMenu menu;
Level level;

int main(){
    Engine::Start(1280, 720, "Last Man Standing", &menu);
}
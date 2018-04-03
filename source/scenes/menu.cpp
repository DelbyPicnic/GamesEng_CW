#include "menu.h"
#include "../game.h"
#include "../components/cmp_text.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MainMenu::Load() {
    cout << "Loading main menu..." << endl;
    {
        auto txt = makeEntity();
        auto t = txt->addComponent<MenuTextComponent>("Press [SPACE] to start...\nPress O for Options...");

    }    
    setLoaded(true);
}

void MainMenu::Update(const double& dt){
    if(sf::Keyboard::isKeyPressed(Keyboard::Space)){
        cout << "Changing to game scene..." << endl;
    }
    if(sf::Keyboard::isKeyPressed(Keyboard::O)){
        Engine::ChangeScene(&optmenu);
    }
    Scene::Update(dt);
}

void OptionMenu::Load(){
    cout << "Loading Options Menu..." << endl;
    {
        auto txt = makeEntity();
        auto t = txt->addComponent<TextComponent>("Options Menu...");
    }
    setLoaded(true);
}

void OptionMenu::Update(const double& dt){
    if(sf::Keyboard::isKeyPressed(Keyboard::BackSpace)){
        Engine::ChangeScene(&mainmenu);
    }
}
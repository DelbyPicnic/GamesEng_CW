#include "menu.h"
#include "../game.h"
#include "../components/cmp_text.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MainMenu::Load() {
    cout << "Loading main menu" << endl;
    {
        auto txt = makeEntity();
        auto t = txt->addComponent<TextComponent>("Press [SPACE] to start...");
    }    
    setLoaded(true);
}

void MainMenu::Update(const double& dt){
    if(sf::Keyboard::isKeyPressed(Keyboard::Space)){
        cout << "Changing to game scene..." << endl;
    }
    Scene::Update(dt);
}
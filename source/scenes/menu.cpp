#include "menu.h"
#include "../game.h"
#include "../components/cmp_text.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <thread>

using namespace std;
using namespace sf;

void MainMenu::Load() {
    cout << "Loading main menu..." << endl;
    {   
        // Get midpoint of the screen
        auto scrMiddle = Engine::GetWindowSize().x /2;

        // Make logo
        auto mainLogo = makeEntity();
        auto logoText = mainLogo->addComponent<TextComponent>("Last Man Standing");
        mainLogo->addTag("logo");
        logoText->SetFont("zombie.ttf");
        logoText->SetFontSize(80);

        // Calculate midpoint - offset
        float logoMPoint = scrMiddle - (logoText->getWidth() / 2);
        mainLogo->setPosition(Vector2f(static_cast<float>(logoMPoint), 70.0f));
    
        // Build menu
        std::array<std::string, 5> menuItems {"New Game", "Load Game", "Options", "Credits", "Quit"};
        for(unsigned int i = 0; i < menuItems.size(); i++ ){
            auto mItem = makeEntity();
            auto mItemText = mItem->addComponent<TextComponent>(menuItems[i]);
            mItem->addTag("menu");
            mItem->addTag(to_string(i));
;
            // Calculate midpoint - offset
            float textMPoint = scrMiddle - (mItemText->getWidth() / 2);
            mItem->setPosition(Vector2f(static_cast<float>(textMPoint), 270.f + (35.0f * i)));
        }
        // Add load time *** TEMP ***
        //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        
    }
    setLoaded(true);
}

void MainMenu::Update(const double& dt){
    // Get system events from the window:
    sf::Event event;
    while(Engine::GetWindow().pollEvent(event)){
        if(event.type == Event::Closed){
                Engine::GetWindow().close();
        }
        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Up){
                if(_selItem > 0){
                    _selItem--;
                }
            }
            if(event.key.code == sf::Keyboard::Down){
                if (_selItem < 4){
                    _selItem++;
                }
            }
        }
    }

    // Update all menu items
    vector<shared_ptr<Entity>> mItems = ents.find("menu");
    for(auto &ent : mItems){
        // Get entity component
        auto entText = ent->get_components<TextComponent>();
        entText[0]->SetColour(sf::Color::White);
    }

    // Update the selected menu item
    vector<shared_ptr<Entity>> selItem = ents.find(to_string(_selItem));
    if(selItem[0] != nullptr){
        // Get item component
        auto selEntText = selItem[0]->get_components<TextComponent>();
        selEntText[0]->SetColour(sf::Color::Red);
    }else{
        std::cout << "No Item Selected!" << std::endl;
    }

    // User selection actionables
    if(Keyboard::isKeyPressed(Keyboard::Return)){
        switch(_selItem){
            case 0 :    std::cout << "Start New Game" << std::endl;
                        break;
            case 1 :    std::cout << "Load Saved Game" << std::endl;
                        break;
            case 2 :    Engine::ChangeScene(&optmenu);
                        break;
            case 3 :    std::cout << "Opening Credits" << std::endl;
                        break;
            case 4 :    Engine::GetWindow().close();
                        break;
        }
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
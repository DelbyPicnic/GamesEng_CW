#include "engine.h"
#include "game.h"
#include "scenes/menu.h"

using namespace std;

MainMenu mainmenu;
OptionMenu optmenu;

int main(){
    Engine::Start(1280, 720, "Last Man Standing", &mainmenu);
}
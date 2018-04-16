#include "engine.h"
#include "game.h"
#include "scenes/menu.h"

using namespace std;

MainMenu mainmenu;
OptionMenu optmenu;
CreditsMenu crdmenu;

int main(){
    Settings* s = new Settings();
    s->screen_width = 1280;
    s->screen_height = 720;
    s->vsync = true;
    s->fullscreen = false;
    s->input_type = "KEYBOARD";

    Engine::Start(*s, "Last Man Standing", &mainmenu);
}
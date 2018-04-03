#pragma once
#include "engine.h"

class MainMenu : public Scene {
public:
    MainMenu() = default;
    ~MainMenu() override = default;
    void Load() override;
    void Update(const double& dt) override;
};

class OptionMenu : public Scene {
public:
    OptionMenu() = default;
    ~OptionMenu() override = default;
    void Load() override;
    void Update(const double& dt) override;
};
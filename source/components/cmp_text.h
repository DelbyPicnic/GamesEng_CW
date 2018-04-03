#pragma once

#include <SFML/Graphics/Text.hpp>
#include <ecm.h>

class TextComponent : public Component {
public:
    TextComponent() = delete;
    ~TextComponent() override = default;

    explicit TextComponent(Entity* p, const std::string& str = "");
    void update(double dt) override;
    void render() override;
    void SetText(const std::string& str);

protected:
    std::shared_ptr<sf::Font> _font;
    std::string _string;
    sf::Text _text;
};

class MenuTextComponent : public Component {
public:
    MenuTextComponent() = delete;
    ~MenuTextComponent() override = default;

    explicit MenuTextComponent(Entity* p, const std::string& str = "");
    void update(double dt) override;
    void render() override;
    void SetText(const std::string& str);

protected:
    std::shared_ptr<sf::Font> _font;
    std::string _string;
    sf::Text _text;
};
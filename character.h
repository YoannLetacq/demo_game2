#ifndef  CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "base_character.h"

class character : public base_character
{
public:
    character(int window_width, int window_height);
    virtual void tick(float dt) override;
    virtual Vector2 get_screen_pos() override;
    Rectangle get_weapon_col() {return weapon_col_rec;}
    float get_health() {return health;}
    void take_damage(float damage);
private:
    int window_width{};
    int window_height{};
    Texture2D weapon{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/weapon_sword.png")};
    Rectangle weapon_col_rec{};
    float rotation{};
    float health{100.f};
};

#endif
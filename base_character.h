#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"
#include "raymath.h"

class base_character
{
public:
    base_character();
    virtual void tick(float dt);
    Rectangle get_collision_rec();
    Vector2 get_world_pos(){return world_pos;}
    virtual Vector2 get_screen_pos() = 0;
    void undo_movement();
    bool get_alive() {return alive;}
    void set_alive(bool is_alive) {alive = is_alive;}
protected:
    Texture2D texture{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_run_spritesheet.png")};
    Vector2 world_pos{670.0, 360.0};
    Vector2 world_pos_last_frame{};
    Vector2 velocity{};
    float width{};
    float height{};
    float scale{4.f};
    float right_left{1.0f};
    float running_time{};
    const float update_time{1.0f / 12.0f};
    const int max_frame{6};
    float speed{5.f};
    int frame{};

private:
    bool alive{true};
};

#endif
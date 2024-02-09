#include "raylib.h"
#include "base_character.h"
class enemy : public base_character
{
public:
    enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    Vector2 get_world_pos() { return world_pos; }
    void tick(float dt);
    void undo_movement();
    Rectangle get_collision_rec();

private:
    Texture2D texture{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_run_spritesheet.png")};
    Vector2 screen_pos{};
    Vector2 world_pos{670.0, 360.0};
    Vector2 world_pos_last_frame{};
    float width{};
    float height{};
    float right_left{1.0f};
    float running_time{};
    const float update_time{1.0f / 12.0f};
    const float speed{5.f};
    const int max_frame{6};
    int frame{};

};
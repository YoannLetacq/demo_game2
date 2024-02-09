#include "raylib.h"

class prop
{
public:
    prop(Vector2 pos, Texture tex);
    void render(Vector2 player_pos);
    Rectangle get_collision_rec(Vector2 player_pos);
private:
    Vector2 world_pos{};
    Texture2D texture{};
    float scale{4.f};
    float rotation{0.f};
    float padding{20.f};
};
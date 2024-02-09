#include "prop.h"
#include "raymath.h"
prop::prop(Vector2 pos, Texture2D tex) : world_pos(pos), texture(tex) {}


void prop::render(Vector2 player_pos)
{
    Vector2 screen_pos = Vector2Subtract(world_pos,player_pos);
    DrawTextureEx(texture, screen_pos, rotation, scale, WHITE);
}

Rectangle prop::get_collision_rec(Vector2 player_pos)
{
    Vector2 screen_pos = Vector2Subtract(world_pos,player_pos);
    return Rectangle{
        screen_pos.x,
        screen_pos.y,
        static_cast<float>(texture.width) * scale - padding,
        static_cast<float>(texture.height) * scale -  padding
    };
}
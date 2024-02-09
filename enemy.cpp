#include "enemy.h"

enemy::enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) :
world_pos(pos), texture(idle_texture), idle(idle_texture), run(run_texture)
{
    width = (float) texture.width / (float) max_frame;
    height = (float) texture.height;

}

void enemy::tick(float dt)
{
    world_pos = world_pos_last_frame;

    //update animation
    running_time += dt;
    if (running_time >= update_time) {
        running_time = 0.0;
        frame++;
        if (frame > max_frame) frame = 0;
    }

    //draw
    Rectangle source{
            (float) frame * width, 0.0f,
            right_left * width, height,
    };
    Rectangle dest{
            screen_pos.x, screen_pos.y,
            6.f * width, 6.f * height
    };
    Vector2 origin_vec{};
    DrawTexturePro(texture, source, dest, origin_vec, 1.0, WHITE);
}

void enemy::undo_movement()
{
    world_pos = world_pos_last_frame;
}

Rectangle enemy::get_collision_rec()
{
    return Rectangle {
            screen_pos.x,
            screen_pos.y,
            width * 6.f,
            height * 6.f,
    };
}
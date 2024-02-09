#include "character.h"
#include "raymath.h"


character::character(int window_width, int window_height, float scale) {
    width = (float) texture.width / (float) max_frame;
    height = (float) texture.height;
    screen_pos = {
            static_cast<float>(window_width) / 2.0f - scale * (0.5f * width),
            static_cast<float>(window_height) / 2.0f - scale * (0.5f * height)
    };
}

void character::tick(float dt) {
    world_pos_last_frame = world_pos;
    Vector2 direction{};
    if (IsKeyDown(KEY_A)) direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) direction.x += 1.0;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0;
    if (IsKeyDown(KEY_S)) direction.y += 1.0;


    if (Vector2Length(direction) != 0.0) {
        texture = run;
        world_pos = Vector2Add(world_pos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? right_left = -1.0f : right_left = 1.0f;
    } else {
        texture = idle;
    }

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

void character::undo_movement()
{
    world_pos = world_pos_last_frame;
}

Rectangle character::get_collision_rec()
{
    return Rectangle {
        screen_pos.x,
        screen_pos.y,
        width * 6.f,
        height * 6.f,
    };
}
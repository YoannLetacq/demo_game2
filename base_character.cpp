#include "base_character.h"
#include "raymath.h"
    base_character::base_character() {}


void base_character::undo_movement()
{
    world_pos = world_pos_last_frame;
}

Rectangle base_character::get_collision_rec()
{
    return Rectangle {
            get_screen_pos().x,
            get_screen_pos().y,
            width * 6.f,
            height * 6.f,
    };
}


void base_character::tick(float dt) {
    world_pos_last_frame = world_pos;

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
            get_screen_pos().x, get_screen_pos().y,
            6.f * width, 6.f * height
    };
    Vector2 origin_vec{};

    if (Vector2Length(velocity) != 0.0) {
        texture = run;
        world_pos = Vector2Add(world_pos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.0f ? right_left = -1.0f : right_left = 1.0f;
    } else {
        texture = idle;
    }
    velocity = {};
    DrawTexturePro(texture, source, dest, origin_vec, 1.0, WHITE);
}

#include "enemy.h"
#include "raymath.h"

enemy::enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) {
    world_pos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = (float) texture.width / (float) max_frame;
    height = (float) texture.height;

    speed = 3.f;
}

void enemy::tick(float dt) {
    if (!get_alive()) return;
    velocity = {Vector2Subtract(target->get_screen_pos(), get_screen_pos())};

    if (Vector2Length(velocity) < radius) velocity = {};

    base_character::tick(dt);
    if (CheckCollisionRecs(target->get_collision_rec(), get_collision_rec())) {
        target->take_damage(damage_per_sec * dt);
    }
}

Vector2 enemy::get_screen_pos() {
    return Vector2Subtract(world_pos, target->get_world_pos());
}
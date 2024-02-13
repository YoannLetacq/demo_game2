#include "character.h"
#include "raymath.h"


character::character(int window_width, int window_height)
: window_width(window_width), window_height(window_height)
{
    width = (float) texture.width / (float) max_frame;
    height = (float) texture.height;

}

Vector2 character::get_screen_pos()
{
    return Vector2 {
            static_cast<float>(window_width) / 2.0f - scale * (0.5f * width),
            static_cast<float>(window_height) / 2.0f - scale * (0.5f * height)
    };
}

void character::tick(float dt) {
    if (!get_alive()) return;

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) velocity.x += 1.0;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_S)|| IsKeyDown(KEY_DOWN)) velocity.y += 1.0;
    base_character::tick(dt);

    Vector2 origin{};
    Vector2 offset{};
    if (right_left > 0.f)
    {
        origin = {0.f, static_cast<float>(weapon.height) * scale};
        offset = {55.f, 75.f};
        weapon_col_rec = {
                get_screen_pos().x + offset.x,
                get_screen_pos().y + offset.y - static_cast<float>(weapon.height) * scale,
                static_cast<float>(weapon.width) * scale,
                static_cast<float>(weapon.height) * scale
        };
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 35.f : 0.f;
    }
    else
    {
        origin = {static_cast<float>(weapon.width) * scale, static_cast<float>(weapon.height) * scale};
        offset = { 35.f, 75.f};
        weapon_col_rec = {
                get_screen_pos().x + offset.x - static_cast<float>(weapon.width) * scale,
                get_screen_pos().y + offset.y - static_cast<float>(weapon.height) * scale,
                static_cast<float>(weapon.width) * scale,
                static_cast<float>(weapon.height) * scale
        };
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? -35.f : 0.f;
    }

    //draw weapons
    Rectangle source{
        0.f, 0.f, static_cast<float>(weapon.width) * right_left
        , static_cast<float>(weapon.height)
    };
    Rectangle dest{
        get_screen_pos().x + offset.x, get_screen_pos().y + offset.y,
        static_cast<float>(weapon.width) * scale, static_cast<float>(weapon.height) * scale
    };
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
}

void character::take_damage(float damage)
{
    health -= damage;
    if (health <= 0.f)
    {
        set_alive(false);
    }
}
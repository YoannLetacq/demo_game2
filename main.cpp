#include "raylib.h"
#include "raymath.h"
#include "character.h"

struct Window {
    const int width, height;
    const char *title;

    Window(const int width, const int height, const char *title) : width(width), height(height), title(title) {}

};

/*
 * MAP
 */

Texture2D map_loader() {
    Texture2D bg = LoadTexture("/home/yoann/CLionProjects/litle_word/map_set/worldMap2.png");
    return bg;
}

/*
 * GAME DATA
 */
float speed{5.0};
const float rotation{0.0};
const float scale{4.0};
//(px)
const float map_padding{200.0};

Vector2 map_pos{1.0, 1.0};
/*
 * PLAYER
 */

Texture2D player_loader() {
    Texture2D player = LoadTexture("/home/yoann/CLionProjects/litle_word/characters/knight_idle_spritesheet.png");
    return player;
}


int main() {
    Window window(800, 600, "Little world");
    InitWindow(window.width, window.height, window.title);
    //fix window fps
    SetTargetFPS(60);

    Texture2D bg{map_loader()};
    character player{window.width, window.height, scale};
    //game engine loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        const float dt{GetFrameTime()};

        map_pos = Vector2Scale(player.get_world_pos(), -1.f);
        DrawTextureEx(bg, map_pos, rotation, scale, WHITE);
        player.tick(dt);
        // check map bound

        if (player.get_world_pos().x < 0.f + map_padding ||
            player.get_world_pos().y < 0.f + map_padding||
            player.get_world_pos().x + (float)window.width > (float)bg.width * scale + map_padding||
            player.get_world_pos().y + (float)window.height > (float)bg.height * scale + map_padding)
        {
            player.undo_movement();
        }
        EndDrawing();
    }
    UnloadTexture(bg);
    CloseWindow();
}

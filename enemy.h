#include "raylib.h"
#include "base_character.h"
#include "character.h"

class enemy : public base_character
{
public:
    enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float dt) override;
    void set_target(character* character) {target = character;}
    virtual Vector2 get_screen_pos() override;
private:
    character* target;
    float damage_per_sec{10.f};
};
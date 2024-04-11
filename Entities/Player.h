#ifndef ARNOLD_PLAYER_H
#define ARNOLD_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cstdio>
#include <map>
#include "Entity.h"
#include "../Engine/Game.h"
#include "../Engine/Utilities/Utils.h"

class Projectile;

#include "Projectile.h"
#include "../Engine/MessageHandler.h"


class Player : public Entity {
public:
    Player(Coordinates _coordinates, Game *_game) : Entity(_coordinates, _game) {
        dimensions = {20, 20};
        gunSound = Utils::Audio::loadMedia(("../assets/audio/laser.mp3"));
    }

    void registerMovementKey(SDL_Keycode key, bool isHeld);

    void handleEvents(SDL_Event sdlEvent);

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;

    void takeDamage(double damage) const;


private:
    Projectile spawnProjectile(Coordinates destination);

    double movementSpeed = 150.0;

    double health = 100;

    std::vector<SDL_Keycode> currentHeldKeys;

    Mix_Chunk *gunSound = nullptr;

    std::map<SDL_Keycode, bool> movementKeys = {
            {SDLK_w, false},
            {SDLK_a, false},
            {SDLK_s, false},
            {SDLK_d, false}
    };
};


#endif //ARNOLD_PLAYER_H

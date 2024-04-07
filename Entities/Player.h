#ifndef ARNOLD_PLAYER_H
#define ARNOLD_PLAYER_H

#include <SDL2/SDL.h>
#include <cstdio>
#include "Entity.h"
#include "../Game.h"
#include "Projectile.h"

#define MOVE_AMOUNT 20

class Player : public Entity {
public:
    Player(float _x, float _y, Game *_game) : Entity(_x, _y, _game) {
        dimensions = {20, 20};
    }

    bool isMoving = false;

    void handleMovement(SDL_Keycode key);

    void handleEvents(SDL_Event sdlEvent);

    void render(SDL_Renderer *renderer) override;

    void update(double deltaTime) override;
};


#endif //ARNOLD_PLAYER_H

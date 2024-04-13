#ifndef ARNOLD_ENTITY_H
#define ARNOLD_ENTITY_H

#include <SDL2/SDL.h>
#include "Utilities/Utils.h"

class Game;

using namespace Utils;

class Entity {
public:
    Entity(const Geometry::Vector2D _coordinates, Game *_game) {
        coordinates = _coordinates;
        game = _game;
    };

    virtual ~Entity() = default;

    virtual void render(SDL_Renderer *renderer) = 0;

    virtual void update(double deltaTime) = 0;

    bool isMarkedForRemoval = false;

    Geometry::Vector2D dimensions{};
    Geometry::Vector2D coordinates{};
    Game *game;
};


#endif //ARNOLD_ENTITY_H
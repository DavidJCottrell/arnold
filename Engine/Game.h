#ifndef ARNOLD_GAME_H
#define ARNOLD_GAME_H

#include <SDL2/SDL.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "../Constants.h"

class Entity;

#include "../Entities/Entity.h"

class Game {
public:
    Game();

    bool init(const char *windowTitle,
              int xPos, int yPos,
              int width, int height);

    void handleEvents();

    void update();

    void render();

    void clean();

    template<typename T>
    void addEntity(T entity) {
        static_assert(std::is_base_of<Entity, T>::value, "Provided class must be derived from Entity");
        entities.push_back(std::make_unique<T>(std::move(entity)));
    }

    [[nodiscard]] const std::vector<std::unique_ptr<Entity>> &getEntities() const;


    [[nodiscard]] bool getIsRunning() const { return isRunning; }

    void endGame() { isRunning = false; }

private:
    Uint32 lastFrameTime = 0;
    bool isRunning = false;

    std::vector<std::unique_ptr<Entity>> entities;

private:

    void removeMarkedEntities();

    SDL_Window *window{};
    SDL_Renderer *renderer{};
};


#endif //ARNOLD_GAME_H
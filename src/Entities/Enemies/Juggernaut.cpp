#include <Arnold.h>

void Juggernaut::takeDamage() const {
    health -= 20;
}

void Juggernaut::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    const SDL_Rect enemyRect = {
            static_cast<int>(coordinates.x),
            static_cast<int>(coordinates.y),
            static_cast<int>(dimensions.x),
            static_cast<int>(dimensions.y)
    };
    SDL_RenderFillRect(renderer, &enemyRect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 10);
    const SDL_Rect healthBarBackground = {
            static_cast<int>(coordinates.x - (dimensions.x / 2)),
            static_cast<int>(coordinates.y + dimensions.x) + 5,
            healthCapacity,
            2
    };
    SDL_RenderFillRect(renderer, &healthBarBackground);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    const SDL_Rect healthBar = {
            static_cast<int>(coordinates.x - (dimensions.x / 2)),
            static_cast<int>(coordinates.y + dimensions.x) + 5,
            health,
            2
    };
    SDL_RenderFillRect(renderer, &healthBar);
}

void Juggernaut::update(const double deltaTime) {
    if (health <= 0) isMarkedForRemoval = true;

    // Check for player collisions
    const auto *pPlayer = game->getPlayer();
    if (isColliding(pPlayer->coordinates, pPlayer->dimensions, coordinates, dimensions)) {
        isMarkedForRemoval = true;
        pPlayer->takeDamage(5);
    }

    // Move towards the player
    Vector2D playerCoordinates = pPlayer->coordinates;
    const auto [dx, dy] = getUnitVector(coordinates, playerCoordinates);

    coordinates.x += static_cast<float>(dx * movementSpeed * deltaTime);
    coordinates.y += static_cast<float>(dy * movementSpeed * deltaTime);
}

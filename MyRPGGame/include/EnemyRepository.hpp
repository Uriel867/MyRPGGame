#ifndef MYRPGGAME_ENEMYREPOSITORY_HPP
#define MYRPGGAME_ENEMYREPOSITORY_HPP

#include "GameEntityMovement.hpp"
#include "GameEntityBattle.hpp"

class EnemyRepository {
private:
    GameMap *map;
    GameEntityMovement *movementHandler;
    GameEntityBattle *battleHandler;
    Player *player;

public:
    explicit EnemyRepository(GameEntityMovement *movement, GameEntityBattle *battle,
                    Player *player, GameMap *gameMap);
    ~EnemyRepository();

    void setGameMap(GameMap *gameMap);

    void move(float dt);
    bool attack(GameEntity *entity, float dt);
    void update(float dt);
};

#endif //MYRPGGAME_ENEMYREPOSITORY_HPP

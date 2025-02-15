#include "../include/Weapon.hpp"

Weapon::Weapon(Point *center, WeaponType type) {
    // TODO: handle shield differently with the directions map
    transitionDirectionsSpritesMap[MoveDirection::UP] = 1;
    transitionDirectionsSpritesMap[MoveDirection::LEFT] = 2;
    transitionDirectionsSpritesMap[MoveDirection::DOWN] = 3;
    transitionDirectionsSpritesMap[MoveDirection::RIGHT] = 4;

    weaponCircle = new Circle(center, (float) Constants::TILE_SIZE/4);

    switch (type) {
        case WeaponType::SWORD:
            name = "Sword";
            attackPoints = 10;
            hitRadius = 5 * 6.5f;
            numHitsPerSecond = 3;
            // init graphics
            sprite = new Sprite();
            if (!texture.loadFromFile("../graphics/images/weapons/oversize/right_hand/male/longsword_male.png")) {
                std::cout << "Texture NOT loaded properly!" << endl;
                texture.setSmooth(true);
            } else std::cout << "Weapon loaded properly." << endl;
            sprite->setTexture(texture);
            sprite->setTextureRect(sf::IntRect(transitionDirectionsSpritesMap[transitionDirection]*Constants::TILE_SIZE, 0, Constants::TILE_SIZE, Constants::TILE_SIZE));
            sprite->setOrigin(Constants::TILE_SIZE/2, Constants::TILE_SIZE/2);
            sprite->setPosition(position.x, position.y);

            break;
        case WeaponType::DAGGER:
            name = "Dagger";
            attackPoints = 5;
            hitRadius = 2 * 4.5f;
            numHitsPerSecond = 7;
            break;
        case WeaponType::AXE:
            name = "Axe";
            attackPoints = 12;
            hitRadius = 6.5f * 6.5f;
            numHitsPerSecond = 2;
            break;
        case WeaponType::MACE:
            name = "Mace";
            attackPoints = 12;
            hitRadius = 6.5f * 6.5f;
            numHitsPerSecond = 2;
            break;
        case WeaponType::BARE_HANDED:
            name = "Bare Handed";
            attackPoints = 1;
            hitRadius = 1 * 3.5f;
            numHitsPerSecond = 12;
            break;
        case WeaponType::STAFF:
            name = "Staff";
            attackPoints = 2;
            hitRadius = 3 * 4.5f;
            numHitsPerSecond = 3;
            break;
    }

    position.x = weaponCircle->getCenter()->getX();
    position.y = weaponCircle->getCenter()->getY();
}

void Weapon::increaseAttackPoints(int amount) {
    attackPoints += amount;
}

void Weapon::increaseHitRadius(float amount) {
    hitRadius += amount;
}

void Weapon::increaseNumHitsPerSecond(int amount) {
    numHitsPerSecond += amount;
}

void Weapon::decreaseAttackPoints(int amount) {
    // don't let any attack points lower than 1
    if (attackPoints - amount <= 1) return;
    attackPoints -= amount;
}

void Weapon::decreaseHitRadius(float amount) {
    // don't let any hit radius lower than 1
    if (hitRadius - amount <= 1) return;
    hitRadius -= amount;
}

void Weapon::decreaseNumHitsPerSecond(int amount) {
    // don't let any hit radius lower than 1
    if (numHitsPerSecond - amount <= 1) return;
    numHitsPerSecond -= amount;
}

int Weapon::getAttackPoints() {
    return attackPoints;
}

float Weapon::getHitRadius() {
    return hitRadius;
}

int Weapon::getNumHitsPerSecond() {
    return numHitsPerSecond;
}

void Weapon::setIntRectPosition(int left, int top, int width, int height) {
    spriteRect.left = left;
    spriteRect.top = top;
    spriteRect.width = width;
    spriteRect.height = height;
    sprite->setTextureRect(spriteRect);
}

MoveDirection Weapon::getTransitionDirection() {
    return transitionDirection;
}

map<MoveDirection, int> Weapon::getTransitionDirectionsSpritesMap() {
    return transitionDirectionsSpritesMap;
}

Vector2i Weapon::getPosition() {
    return position;
}

Sprite* Weapon::getSprite() {
    return sprite;
}

Circle* Weapon::getWeaponCircle() {
    return weaponCircle;
}

int Weapon::getTransition() {
    return transition;
}

void Weapon::incrementTransition() {
    // defined by the pngs order
    // TODO: add an extra field for identifying another weapons which uses different logic
    if (transition < Constants::WEAPON_TRANSITION_MAX) transition++;
    else transition = Constants::WEAPON_TRANSITION_MIN;
}

void Weapon::setTransitionDirection(MoveDirection direction) {
    transitionDirection = direction;
}

void Weapon::update(Point ***points) {
    sprite->setPosition(position.x, position.y);
    weaponCircle->setCenter(points[position.y][position.x]);
}

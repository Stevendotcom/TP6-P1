#include "Crossbowman.h"

#include <iostream>

Crossbowman::Crossbowman(const float Min,
                         const float Max,
                         const float Life,
                         const float Stamina,
                         const float Armor,
                         const float Damage,
                         const Vector2D Position)
    : Ranged(Min, Max, Life, Stamina, Armor, Damage, Position) {
}

Crossbowman::~Crossbowman() {
  std::cout << "A Crossbowman has been killed"
            << "\n";
}

void Crossbowman::Attack(Soldier* Target) {

}

#include "Archer.h"

#include <iostream>

Archer::Archer(const float Min,
               const float Max,
               const float Life,
               const float Stamina,
               const float Armor,
               const float Damage,
               const Vector2D Position)
  : Ranged(Min, Max, Life, Stamina, Armor, Damage, Position) {
  
}

Archer::~Archer() {
  std::cout << "An Archer has been killed"
            << "\n";
}

void Archer::Attack(Soldier* Target) {

  constexpr float k_StaminaCost = 10;

  if (this->IsInRange(Target) && this->f_Stamina >= k_StaminaCost) {

    Target->ReceiveDamage(this->f_Damage);
    this->f_Stamina -= k_StaminaCost;

  }
}

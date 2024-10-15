#include "Swordsman.h"

#include <cmath>
#include <iostream>

Swordsman::Swordsman(const float Radius,
                     const float Life,
                     const float Stamina,
                     const float Armor,
                     const float Damage,
                     const Vector2D Position)
    : Melee(Radius, Life, Stamina, Armor,  Damage, Position) {
}

Swordsman::~Swordsman() {
  std::cout << "A Swordsman has been killed"
            << "\n";
}


void Swordsman::Attack(Soldier* Target) {
  constexpr float k_StaminaCost = 10;
  if (this->IsInRange(Target) && this->f_Stamina >= k_StaminaCost) {
    Target->ReceiveDamage(f_Damage);
    this->f_Stamina -= k_StaminaCost;
  }
}

void Swordsman::ReceiveDamage(const float Damage) {
  this->f_Life -= Damage - 100 / this->f_Armor;
}

void Swordsman::Rest() {
  constexpr float k_StaminaRecovery = 50;
  this->f_Stamina = k_StaminaRecovery;
}

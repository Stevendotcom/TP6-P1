#include "Swordsman.h"

#include <iostream>

#include "Entities/Abstracts/Melee.h"
#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Finals;

float Swordsman::f_MaxStaminaDef = 65.0F;



Swordsman::Swordsman(const float Radius,
                     const float Life,
                     const float Stamina,
                     const float Armor,
                     const float Damage)
  : Melee(Radius, Life, Stamina, Armor, Damage, f_MaxStaminaDef) {
  f_Color = raylib::Color::Blue();
  f_Type = Types::Swordsman;

}



Swordsman::~Swordsman() {
  std::cout << "A Swordsman has been killed" << "\n";
}



void Swordsman::Attack(Soldier* Target) {
  constexpr float k_StaminaCost = 10;
  if (f_Stamina >= k_StaminaCost) {
    Target->ReceiveDamage(f_Damage);
    f_Stamina -= k_StaminaCost;
    PrintResult(Target);
  }
}



void Swordsman::ReceiveDamage(const float Damage) {
  f_Life -= Damage - 100 / f_Armor;
}



void Swordsman::Rest() {
  constexpr float k_StaminaRecovery = 50;
  f_Stamina = k_StaminaRecovery;
}



bool Swordsman::IsInRange(int TargetPos) {
  return abs(f_Id - TargetPos) <= f_AckRadius;
}


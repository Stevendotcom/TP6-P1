#include "Archer.h"

#include <iostream>

#include "Entities/Abstracts/Ranged.h"
#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Finals;

float Archer::f_MaxStaminaDef = 30.0F;



Archer::Archer(const float MinDistance,
               const float MaxDistance,
               const float Life,
               const float Stamina,
               const float Armor,
               const float Damage)
  : Ranged(MinDistance, MaxDistance, Life, Stamina, Armor, Damage, f_MaxStaminaDef) {
  f_Color = raylib::Color::Gold();
  f_Type = Types::Archer;
}



Archer::~Archer() {
  std::cout << "An Archer has been killed" << "\n";
}



void Archer::Attack(Soldier* Target) {

  constexpr float k_StaminaCost = 10;

  if (f_Stamina >= k_StaminaCost) {

    Target->ReceiveDamage(f_Damage);
    f_Stamina -= k_StaminaCost;

    PrintResult(Target);
  }
}



void Archer::Rest() {
  f_Stamina = f_MaxStamina;
}



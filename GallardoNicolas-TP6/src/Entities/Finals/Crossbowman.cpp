#include "Crossbowman.h"

#include <iostream>
#include <raylib-cpp.hpp>

#include "Entities/Abstracts/Ranged.h"
#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Finals;

float Crossbowman::f_MaxStaminaDef = 40.0F;



Crossbowman::Crossbowman(const float MinDistance,
                         const float MaxDistance,
                         const float Life,
                         const float Stamina,
                         const float Armor,
                         const float Damage)
  : Ranged(MinDistance, MaxDistance, Life, Stamina, Armor, Damage, f_MaxStaminaDef) {
  f_Color = raylib::Color::Green();
  f_Type = Types::Crossbowman;
}



Crossbowman::~Crossbowman() {
  std::cout << "A Crossbowman has been killed" << "\n";
}



void Crossbowman::Attack(Soldier* Target) {
  constexpr float k_StaminaCost = 15;

  if (f_Stamina >= k_StaminaCost && DoesItHit(Target->GetArmor())) {

    Target->ReceiveDamage(f_Damage);
    Target->ReceiveDamage(f_Damage);
    f_Stamina -= k_StaminaCost;

    PrintResult(Target);

  }
}



void Crossbowman::Rest() {
  f_Stamina = f_MaxStamina;
}



bool Crossbowman::DoesItHit(const float Armor) const {
  const float ChanceToNotHit = Armor / f_Stamina;
  return ChanceToNotHit <= static_cast<float>(GetRandomValue(1, static_cast<int>(f_MaxDistance)));
}





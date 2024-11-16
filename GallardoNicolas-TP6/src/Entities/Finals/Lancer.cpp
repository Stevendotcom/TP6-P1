#include "Lancer.h"

#include <iostream>
#include <list>
#include <vector>

#include "Vector2.hpp"
#include "Entities/Abstracts/Melee.h"
#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Finals;
float Lancer::f_MaxStaminaDef = 50.0F;



Lancer::Lancer(const float Radius, const float Life, const float Stamina, const float Armor, const float Damage)
  : Melee(Radius, Life, Stamina, Armor, Damage, f_MaxStaminaDef) {
  f_Color = raylib::Color::Red();
  f_Type = Types::Lancer;
}



Lancer::~Lancer() {
  std::cout << "A Lancer has been killed" << "\n";
}



bool Lancer::Attack(const std::vector<Soldier*>::iterator& Self,
                    const std::vector<Soldier*>::iterator& Target,
                    std::vector<Soldier*>& Soldiers) {

  constexpr float k_StaminaCost = 20;
  const float k_DistanceTarget = static_cast<float>(Self - Target);
  float DistanceSoldier;
  bool AttackedAny = false;

  if (f_Stamina >= k_StaminaCost) {
    for (std::vector<Soldier*>::iterator Iter = Soldiers.begin(); Iter != Soldiers.end(); ++Iter) {
      DistanceSoldier = static_cast<float>(Iter - Self);

      if (*Iter && static_cast<float>(Iter - Soldiers.begin()) <= abs(DistanceSoldier)) {

        if ((k_DistanceTarget >= 0 && Self < Iter) || (k_DistanceTarget < 0 && Self > Iter)) {

          Attack(*Iter);

          PrintResult(*Iter);

          AttackedAny = true;
        }
      }
    }
    f_Stamina -= k_StaminaCost;
  }

  return AttackedAny;
}



void Lancer::Attack(Soldier* Target) {
  Target->ReceiveDamage(f_Damage);
}



void Lancer::Rest() {
  f_Stamina = f_MaxStamina;
}

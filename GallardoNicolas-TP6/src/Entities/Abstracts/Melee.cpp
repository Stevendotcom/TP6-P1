#include "Melee.h"

#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Abstracts;



Melee::Melee(const float Radius,
             const float Life,
             const float Stamina,
             const float Armor,
             const float Damage,
             const float MaxStamina)
  : Soldier(Life, Stamina, Armor, Damage, MaxStamina) {
  f_AckRadius = Radius;
}



Melee::~Melee() = default;
#include "Ranged.h"

#include <cmath>

#include "Vector2.hpp"
#include "Entities/Abstracts/Soldier.h"

using namespace game::Entities::Abstracts;



Ranged::Ranged(const float MinDistance,
               const float MaxDistance,
               const float Life,
               const float Stamina,
               const float Armor,
               const float Damage,
               const float MaxStamina)
  : Soldier(Life, Stamina, Armor, Damage, MaxStamina) {
  f_MinDistance = MinDistance;
  f_MaxDistance = MaxDistance;
}



Ranged::~Ranged() = default;



bool Ranged::IsInRange(const int TargetPos) {
  return abs(f_Id - TargetPos) <= f_MaxDistance && abs(f_Id - TargetPos) >= f_MinDistance;
}


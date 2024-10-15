#include "Ranged.h"

#include <cmath>

Ranged::Ranged(const float Min,
               const float Max,
               const float Life,
               const float Stamina,
               const float Armor,
               const float Damage,
               const Vector2D Position) 
	: Soldier(Life, Stamina, Position, Armor, Damage) {
  this->f_MinDistance = Min;
  this->f_MaxDistance = Max;
}

Ranged::~Ranged() = default;

bool Ranged::IsInRange(const Soldier* Target) const {

  const float k_Distance = abs(Target->GetPosition().X - this->f_Position.X);

  return k_Distance >= f_MinDistance && k_Distance <= this->f_MaxDistance;
}

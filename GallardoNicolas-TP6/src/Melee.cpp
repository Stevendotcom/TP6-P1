#include "Melee.h"

#include <cmath>

Melee::Melee(const float Radius,
             const float Life,
             const float Stamina,
             const float Armor,
             const float Damage,
             const Vector2D Position)
	: Soldier(Life, Stamina, Position, Armor, Damage) {
  this->f_ACKRadius = Radius;
}

Melee::~Melee() = default;

bool Melee::IsInRange(const Soldier* Target) const {
  return this->f_ACKRadius <= abs(this->f_Position.X - Target->GetPosition().X);
}

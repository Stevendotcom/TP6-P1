#include "Soldier.h"

Soldier::Soldier(const float Life,
                 const float Stamina,
                 const Vector2D Position,
                 const float Armor,
                 const float Damage) {
  this->f_Life = Life;
  this->f_Stamina = Stamina;
  this->f_Position = Position;
  this->f_Armor = Armor;
  this->f_Damage = Damage;
}

Soldier::~Soldier() = default;

void Soldier::ReceiveDamage(const float Damage) {
  this->f_Life -= Damage;
}

const Soldier::Vector2D& Soldier::GetPosition() const {
  return this->f_Position;
}

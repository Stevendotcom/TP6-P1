#include "Lancer.h"

#include <iostream>

Lancer::Lancer(const float Radius,
               const float Life,
               const float Stamina,
               const float Armor,
               const float Damage,
               const Vector2D Position)
  : Melee(Radius, Life, Stamina, Armor, Damage, Position) {
}

Lancer::~Lancer() {
  std::cout << "A Lancer has been killed"
      << "\n";
}

void Lancer::Attack(const std::list<Soldier*>& SoldiersInPath,
                    Soldier* Target) {

  constexpr float k_StaminaCost = 20;
  const float k_TargetPos = Target->GetPosition().X;
  const float k_Distance = k_TargetPos - this->f_Position.X;
  float SoldierPathPosition;

  if (this->f_Stamina >= k_StaminaCost) {
    for (const auto SoldierPath : SoldiersInPath) {

      SoldierPathPosition = SoldierPath->GetPosition().X;

      if (k_Distance > 0) {
        if (SoldierPathPosition > this->f_Position.X &&
            SoldierPathPosition < k_TargetPos) {

          SoldierPath->ReceiveDamage(this->f_Damage);
        }
      } else if (SoldierPathPosition < this->f_Position.X &&
                 SoldierPathPosition > k_TargetPos) {

        SoldierPath->ReceiveDamage(this->f_Damage);

      }
    }

    if (this->IsInRange(Target)) {
      Attack(Target);
    }
    this->f_Stamina -= k_StaminaCost;
  }
}

void Lancer::Attack(Soldier* Target) {
  Target->ReceiveDamage(f_Damage);
}

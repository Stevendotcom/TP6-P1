#pragma once
#include "Ranged.h"

class Archer final : Ranged {
public:
  Archer(float Min,
         float Max,
         float Life,
         float Stamina,
         float Armor,
         float Damage,
         Vector2D Position);
  ~Archer() override;
  void Attack(Soldier* Target) override;
};

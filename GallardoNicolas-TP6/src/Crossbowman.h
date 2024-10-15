#pragma once
#include "Ranged.h"
class Crossbowman final : public Ranged {
public:
  Crossbowman(float Min,
              float Max,
              float Life,
              float Stamina,
              float Armor,
              float Damage,
              Vector2D Position);
  ~Crossbowman() override;
  void Attack(Soldier* Target) override;
};

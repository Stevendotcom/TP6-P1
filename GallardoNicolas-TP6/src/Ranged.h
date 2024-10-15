#pragma once
#include "Soldier.h"
class Ranged : public Soldier {
public:
  Ranged(float Min,
         float Max,
         float Life,
         float Stamina,
         float Armor,
         float Damage,
         Vector2D Position);
  ~Ranged() override;
  bool IsInRange(const Soldier* Target) const override;

protected:
  float f_MinDistance;
  float f_MaxDistance;
};

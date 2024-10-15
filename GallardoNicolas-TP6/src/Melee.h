#pragma once
#include "Soldier.h"
class Melee : public Soldier {

public:
  Melee(float Radius,
        float Life,
        float Stamina,
        float Armor,
        float Damage,
        Vector2D Position);
  ~Melee() override;
  bool IsInRange(const Soldier* Target) const override;
protected:
  float f_ACKRadius;
};

#pragma once
#include "Soldier.h"

namespace game::Entities::Abstracts {
class Ranged abstract : public Soldier {
public:
  Ranged(float MinDistance,
         float MaxDistance,
         float Life,
         float Stamina,
         float Armor,
         float Damage,
         float MaxStamina);

  ~Ranged() override;

  bool IsInRange(int TargetPos) override;

protected:
  float f_MinDistance;
  float f_MaxDistance;
};
}

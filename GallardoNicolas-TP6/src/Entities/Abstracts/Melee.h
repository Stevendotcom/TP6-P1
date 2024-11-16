#pragma once
#include "Soldier.h"

namespace game::Entities::Abstracts {
class Melee abstract : public Soldier {

public:
  Melee(float Radius, float Life, float Stamina, float Armor, float Damage, float MaxStamina);

  ~Melee() override;


protected:
  float f_AckRadius;
};
}

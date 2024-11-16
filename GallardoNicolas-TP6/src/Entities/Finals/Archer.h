#pragma once
#include "Entities/Abstracts/Ranged.h"

namespace game::Entities::Finals {
class Archer final : public Abstracts::Ranged {
public:
  Archer(float MinDistance,
         float MaxDistance,
         float Life,
         float Stamina,
         float Armor,
         float Damage);

  ~Archer() override;

  void Attack(Soldier* Target) override;

  void Rest() override;


  static float f_MaxStaminaDef;
};
}

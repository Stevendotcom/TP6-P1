#pragma once

#include "Entities/Abstracts/Ranged.h"

namespace game::Entities::Finals {
class Crossbowman final : public Abstracts::Ranged {
public:
  Crossbowman(float MinDistance,
              float MaxDistance,
              float Life,
              float Stamina,
              float Armor,
              float Damage);

  ~Crossbowman() override;

  void Attack(Soldier* Target) override;

  void Rest() override;

  bool DoesItHit(float Armor) const;

  static float f_MaxStaminaDef;
};
}

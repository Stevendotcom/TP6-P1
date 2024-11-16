#pragma once
#include "Entities/Abstracts/Melee.h"

namespace game::Entities::Finals {
class Swordsman final : public Abstracts::Melee {
public:
  Swordsman(float Radius, float Life, float Stamina, float Armor, float Damage);

  ~Swordsman() override;

  void Attack(Soldier* Target) override;

  void ReceiveDamage(float Damage) override;

  void Rest() override;

  bool IsInRange(int TargetPos) override;

  static float f_MaxStaminaDef;

};
}

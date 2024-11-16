#pragma once
#include <vector>

#include "Entities/Abstracts/Melee.h"

namespace game::Entities::Finals {
class Lancer final : public Abstracts::Melee {
public:
  Lancer(float Radius, float Life, float Stamina, float Armor, float Damage);

  ~Lancer() override;

  bool Attack(const std::vector<Soldier*>::iterator& Self,
              const std::vector<Soldier*>::iterator& Target,
              std::vector<Soldier*>& Soldiers);

  void Rest() override;

  static float f_MaxStaminaDef;

private:
  void Attack(Soldier* Target) override;

  bool IsInRange(int TargetPos) override;

};



inline bool Lancer::IsInRange(int TargetPos) {
  return false;
}
}

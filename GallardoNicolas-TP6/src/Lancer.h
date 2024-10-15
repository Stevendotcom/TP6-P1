#pragma once
#include <list>

#include "Melee.h"
class Lancer final : public Melee {
public:
  Lancer(float Radius,
         float Life,
         float Stamina,
         float Armor,
         float Damage,
         Vector2D Position);
  ~Lancer() override;
  void Attack(const std::list<Soldier*>& SoldiersInPath, Soldier* Target);

private:
  void Attack(Soldier* Target) override;
};

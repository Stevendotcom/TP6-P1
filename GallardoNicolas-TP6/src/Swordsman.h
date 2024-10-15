#pragma once
#include "Melee.h"
class Swordsman final : public Melee {
public:
  Swordsman(float Radius,
            float Life,
            float Stamina,
            float Armor,
            float Damage,
            Vector2D Position);
  ~Swordsman() override;
  void Attack(Soldier* Target) override;
  void ReceiveDamage(float Damage) override;
  void Rest() override;
};

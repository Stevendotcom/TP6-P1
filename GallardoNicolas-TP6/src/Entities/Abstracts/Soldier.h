#pragma once
#include <raylib-cpp.hpp>

namespace game::Entities::Abstracts {

class Soldier abstract {

public:

  enum class Types : unsigned char {
    Archer,
    Crossbowman,
    Lancer,
    Swordsman,
  };

  Soldier(float Life, float Stamina, float Armor, float Damage, float MaxStamina);

  float GetLife() const;

  float GetArmor() const;

  void Draw(int Pos, int ScreenHeight) const;

  int GetId() const;

  Types GetSoldierType() const;

  void PrintResult(const Soldier* Target) const;

  void ForceAttack(Soldier* Target) const;

  virtual ~Soldier();

  virtual void ReceiveDamage(float Damage);

  virtual void Attack(Soldier* Target) = 0;

  virtual void Rest() = 0;

  virtual bool IsInRange(int TargetPos) = 0;

  static std::string TypeToString(Types Type);

protected:
  float f_Life;
  float f_Stamina;
  float f_MaxStamina;
  float f_Armor;
  float f_Damage;
  int f_Id;
  raylib::Color f_Color;
  Types f_Type;

  private:
  static int f_IdCounter;
};
}

#include "Soldier.h"

#include <iostream>

using namespace game::Entities::Abstracts;

int Soldier::f_IdCounter = 0;



Soldier::Soldier(const float Life, const float Stamina, const float Armor, const float Damage, const float MaxStamina) {
  f_Life = Life;
  f_Stamina = Stamina;
  f_Armor = Armor;
  f_Damage = Damage;
  f_MaxStamina = MaxStamina;
  f_Id = f_IdCounter;
  f_IdCounter++;
}



float Soldier::GetLife() const {
  return f_Life;
}



float Soldier::GetArmor() const {
  return f_Armor;
}



void Soldier::Draw(int Pos, int ScreenHeight) const {
  const raylib::Rectangle Rect(40.0F * (Pos + 1.0F) + 40.0F * Pos, static_cast<float>(ScreenHeight / 2), 50, 50);
  Rect.Draw(f_Color);
}



int Soldier::GetId() const {
  return f_Id;
}



Soldier::Types Soldier::GetSoldierType() const {
  return f_Type;
}



void Soldier::PrintResult(const Soldier* Target) const {
  std::cout << TypeToString(f_Type) << " n" << f_Id << " attacked " << TypeToString(Target->GetSoldierType()) << " n" <<
      Target->GetId() << '\n';
}



void Soldier::ForceAttack(Soldier* Target) const {
  Target->ReceiveDamage(f_Damage);
  PrintResult(Target);
}



Soldier::~Soldier() = default;



void Soldier::ReceiveDamage(const float Damage) {
  f_Life -= Damage;
}



std::string Soldier::TypeToString(const Types Type) {
  switch (Type) {
    case Types::Archer:
      return "Archer";
    case Types::Crossbowman:
      return "Crossbowman";
    case Types::Lancer:
      return "Lancer";
    case Types::Swordsman:
      return "Swordsman";
    default:
      return "Error";
  }
}

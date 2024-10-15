#pragma once
class Soldier {
public:
  struct Vector2D {
    float X;
    float Y;
  };

  Soldier(float Life, float Stamina, Vector2D Position, float Armor, float Damage);
  virtual ~Soldier();
  virtual void Attack(Soldier* Target) = 0;
  virtual void Rest() = 0;
  virtual bool IsInRange(const Soldier* Target) const = 0;
  virtual void ReceiveDamage(float Damage);
  const Vector2D& GetPosition() const;

protected:
  float f_Life;
  float f_Stamina;
  float f_Armor;
  float f_Damage;
  Vector2D f_Position;
};



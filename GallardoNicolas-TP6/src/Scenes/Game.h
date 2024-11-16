#pragma once
#include <raylib-cpp.hpp>

#include "Entities/Abstracts/Soldier.h"

namespace game::Scenes::Finals {
class Game final {
public:
  Game();

  ~Game();

  void Play();

private:
  raylib::Window f_Window;
  raylib::Color f_BackgroundColor;
  std::vector<Entities::Abstracts::Soldier*> f_Soldiers;

  bool f_SoldierWon;
  int f_AmountSoldiersAlive;

  bool f_NextTurn = false;
  bool f_Exit = false;

  void Input();

  void Update();

  void Draw();

  Entities::Abstracts::Soldier* GetRandomTarget(int Position) const;

  std::vector<Entities::Abstracts::Soldier*>::iterator PointerToIter(Entities::Abstracts::Soldier* pSoldier);

  Entities::Abstracts::Soldier* GetWinner() const;

  static float GetRandomValueF(float Min, float Max);

  static int f_Amount;
};
}

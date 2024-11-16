#include "Game.h"

#include <iostream>

#include "Entities/Finals/Archer.h"
#include "Entities/Finals/Crossbowman.h"
#include "Entities/Finals/Lancer.h"
#include "Entities/Finals/Swordsman.h"

using namespace game::Scenes::Finals;

using namespace game::Entities::Finals;

using namespace game::Entities::Abstracts;

int Game::f_Amount = 10;



Game::Game() {
  f_Window.Init(1000, 600, "TP6");
  f_BackgroundColor = raylib::Color::Black();
  f_SoldierWon = false;
  f_AmountSoldiersAlive = f_Amount;

  f_Window.SetTargetFPS(60);
  f_Window.SetConfigFlags(FLAG_VSYNC_HINT);

  f_Soldiers.resize(f_Amount);

  for (int I = 0; I < f_Amount; I++) {

    switch (static_cast<Soldier::Types>(GetRandomValue(static_cast<int>(Soldier::Types::Archer),
                                                       static_cast<int>(Soldier::Types::Swordsman)))) {
      case Soldier::Types::Archer:
        f_Soldiers.at(I) = new Archer(GetRandomValueF(1, 3), GetRandomValueF(6, 8), 80, Archer::f_MaxStaminaDef,
                                      GetRandomValueF(30.0F, 50.0F), GetRandomValueF(20.0F, 30.0F));
        break;
      case Soldier::Types::Crossbowman:
        f_Soldiers.at(I) = new Crossbowman(GetRandomValueF(1, 2), GetRandomValueF(5, 7), 80,
                                           Crossbowman::f_MaxStaminaDef, GetRandomValueF(30.0F, 50.0F),
                                           GetRandomValueF(15.0F, 25.0F));
        break;
      case Soldier::Types::Lancer:
        f_Soldiers.at(I) = new Lancer(GetRandomValueF(1, 3), 100, Lancer::f_MaxStaminaDef,
                                      GetRandomValueF(30.0F, 80.0F), GetRandomValueF(25.0F, 30.0F));
        break;
      case Soldier::Types::Swordsman:
        f_Soldiers.at(I) = new Swordsman(GetRandomValueF(2, 4), 100, Swordsman::f_MaxStaminaDef,
                                         GetRandomValueF(30.0F, 80.0F), GetRandomValueF(25.0F, 30.0F));
        break;
    }
  }

}



Game::~Game() {
  for (auto Soldier : f_Soldiers) {
    delete Soldier;
  }

  f_Window.Close();
}



void Game::Play() {
  while (!f_Window.ShouldClose() && !f_Exit) {
    Input();
    if (f_NextTurn && !f_Exit) {
      Update();
    }
    Draw();
  }
}



void Game::Input() {
  if (IsKeyReleased(KEY_ENTER)) {
    f_NextTurn = true;
    std::cout << "----------------------" << '\n';
    if (f_SoldierWon) {
      f_Exit = true;
    }
  }
}



void Game::Update() {

  f_NextTurn = false;

  Soldier* Target;

  for (std::vector<Soldier*>::iterator Iter = f_Soldiers.begin(); Iter != f_Soldiers.end(); ++Iter) {

    Target = GetRandomTarget(static_cast<int>(Iter - f_Soldiers.begin()));

    if (dynamic_cast<Lancer*>(*Iter)) {
      if (!dynamic_cast<Lancer*>(*Iter)->Attack(Iter, PointerToIter(Target), f_Soldiers)) {
        (*Iter)->ForceAttack(Target);
      }
    } else if (*Iter && (*Iter)->IsInRange(PointerToIter(Target) - f_Soldiers.begin())) {
      (*Iter)->Attack(Target);
    } else if (*Iter) {
      (*Iter)->ForceAttack(Target);
    } else {
      continue;
    }

    if (Target->GetLife() <= 0) {

      *(PointerToIter(Target)) = nullptr;
      delete Target;
      f_AmountSoldiersAlive--;

    }

    if (f_AmountSoldiersAlive <= 1) {
      f_SoldierWon = true;
      break;
    }
  }
}



void Game::Draw() {
  f_Window.BeginDrawing();
  {
    f_Window.ClearBackground();

    for (std::vector<Soldier*>::iterator Iter = f_Soldiers.begin(); Iter != f_Soldiers.end(); ++Iter) {

      if (*Iter) {
        (*Iter)->Draw(Iter - f_Soldiers.begin(), f_Window.GetHeight());
      }

    }

    if (f_SoldierWon) {
      {
        Soldier* Winner = GetWinner();
        raylib::DrawText(
            TextFormat("%s n %i has won!", Soldier::TypeToString(Winner->GetSoldierType()).c_str(), Winner->GetId()),
            30, 100, 64, raylib::Color::Gold());
      }
    }

  }
  f_Window.EndDrawing();
}



Soldier* Game::GetRandomTarget(int Position) const {

  int TargetPos = GetRandomValue(0, f_Amount - 1);
  Soldier* Target;

  do {
    TargetPos = GetRandomValue(0, f_Amount - 1);
    Target = f_Soldiers.at(TargetPos);
  } while (TargetPos == Position || Target == nullptr);

  return Target;
}



std::vector<Soldier*>::iterator Game::PointerToIter(Soldier* pSoldier) {

  auto Iter = f_Soldiers.begin();

  for (; Iter != f_Soldiers.end(); ++Iter) {
    if (*Iter == pSoldier) {
      break;
    }
  }

  return Iter;
}



Soldier* Game::GetWinner() const {
  for (auto Soldier : f_Soldiers) {
    if (Soldier) {
      return Soldier;
    }
  }
  return nullptr;
}



float Game::GetRandomValueF(const float Min, const float Max) {
  return static_cast<float>(rand() % (static_cast<int>(Max) + 1 - static_cast<int>(Min)) + static_cast<int>(Min));
}

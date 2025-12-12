// Player.h
// Copyright (c) 2025 by OptimalTime99. All rights reserved.

#pragma once

class Player {
 private:
    int status[4];
    int ability[4];
    int HPPotion, MPPotion;
    int level, exp;
    int statPoint;
    int RollStat();

 public:
    Player();
    void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);
    void RandomAbility(int* ability, int size);
    bool UsePotion(int& potionCount, int& stat, const char* statName);
    bool IncreasePower(int& power, const char* powerName);
    bool IncreaseAbility(int& statPoint, int& ability, const char* name);
    void PrintStatus(const int status[], const int ability[],
        int level, int statPoint, int HPPotion, int MPPotion);
    void LevelUP(int& exp, int& HPPotion, int& MPPotion,
        int& level, int& statPoint);

    bool IsValidHPMP(int hp, int mp);
    bool IsValidPower(int attack, int defense);
    bool IsStart(char answer);
    bool HasPotion(int potion);

    void InputHPMP(int& hp, int& mp);
    void InputPower(int& attack, int& defense);
    void InitAbility(int* ability);

    void PrintMenu();

    int* GetStatus();
    int* GetAbility();

    int GetLevel();
    int GetExp();
    int GetHPPotion();
    int GetMPPotion();
    int GetStatPoint();
};

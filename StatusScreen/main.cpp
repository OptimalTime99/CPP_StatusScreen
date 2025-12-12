// main.cpp
// Copyright (c) 2025 by OptimalTime99. All rights reserved.

#include <iostream>
#include <random>
#include "Player.h"

int main() {
    Player player;
    int* status = player.GetStatus();
    int* ability = player.GetAbility();
    int HPPotion = player.GetHPPotion();
    int MPPotion = player.GetMPPotion();
    int exp = player.GetExp();
    int level = player.GetLevel();
    int statPoint = player.GetStatPoint();
    int choice = -1;

    player.InputHPMP(status[0], status[1]);
    player.InputPower(status[2], status[3]);
    player.InitAbility(ability);
    player.SetPotion(5, &HPPotion, &MPPotion);

    player.PrintMenu();

    while (choice != 0) {
        std::cout << "번호를 선택해주세요: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            player.UsePotion(HPPotion, status[0], "HP");
            break;
        case 2:
            player.UsePotion(MPPotion, status[1], "MP");
            break;
        case 3:
            player.IncreasePower(status[2], "공격력");
            break;
        case 4:
            player.IncreasePower(status[3], "방어력");
            break;
        case 5:
            player.IncreaseAbility(statPoint, ability[0], "힘");
            break;
        case 6:
            player.IncreaseAbility(statPoint, ability[1], "민첩");
            break;
        case 7:
            player.IncreaseAbility(statPoint, ability[2], "지능");
            break;
        case 8:
            player.IncreaseAbility(statPoint, ability[3], "행운");
            break;
        case 9:
            player.PrintStatus(status, ability, level,
                statPoint, HPPotion, MPPotion);
            break;
        case 10:
            player.LevelUP(exp, HPPotion, MPPotion,
                level, statPoint);
            break;
        case 0:
            std::cout << "프로그램을 종료합니다.\n";
            break;
        default:
            std::cout << "잘못된 번호 선택입니다. 다시 선택해주세요.\n";
            break;
        }
    }

    return 0;
}

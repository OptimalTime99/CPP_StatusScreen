// Player.cpp
// Copyright (c) 2025 by OptimalTime99. All rights reserved.

#include <iostream>
#include <random>
#include "Player.h"

Player::Player()
    : status{ 0, 0, 0, 0 }
        , ability{ 0, 0, 0, 0 }
        , HPPotion(0)
        , MPPotion(0)
        , level(0)
        , exp(0)
        , statPoint(0)
{};

void Player::SetPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int Player::RollStat() {
    std::mt19937 rng(std::random_device {}());
    std::uniform_int_distribution<int> dist(1, 10);
    return dist(rng);
}

void Player::RandomAbility(int* ability, int size) {
    for (int i = 0; i < size; i++) {
        *(ability + i) = RollStat();
    }
}

bool Player::IsValidHPMP(int hp, int mp) {
    return hp > 50 && mp > 50;
}

bool Player::IsValidPower(int attack, int defense) {
    return attack > 0 && defense > 0;
}

bool Player::IsStart(char answer) {
    return answer == 'n' || answer == 'N';
}

bool Player::HasPotion(int potion) {
    return potion > 0;
}

void Player::InputHPMP(int& hp, int& mp) {
    while (true) {
        std::cout << "HP와 MP를 입력해주세요: ";
        std::cin >> hp >> mp;

        if (IsValidHPMP(hp, mp)) break;

        std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }
}

void Player::InputPower(int& attack, int& defense) {
    while (true) {
        std::cout << "공격력과 방어력을 입력해주세요: ";
        std::cin >> attack >> defense;

        if (IsValidPower(attack, defense)) break;

        std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }
}

void Player::InitAbility(int* ability) {
    while (true) {
        char answer;
        RandomAbility(ability, 4);
        std::cout << "능력치 주사위를 굴렸습니다.\n"
            << "< 현재 능력치 >\n"
            << "힘 : " << ability[0] << "\n"
            << "민첩 : " << ability[1] << "\n"
            << "지능 : " << ability[2] << "\n"
            << "행운 : " << ability[3] << "\n\n";
        std::cout << "다시 굴리시겠습니까?(Y/N)\n";
        std::cin >> answer;

        if (IsStart(answer)) break;
    }
}

void Player::PrintMenu() {
    std::cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
    std::cout << "=============================================\n"
        << "< 스탯 관리 시스템 >\n"
        << "1. HP UP\n"
        << "2. MP UP\n"
        << "3. 공격력 UP\n"
        << "4. 방어력 UP\n"
        << "5. 힘 UP\n"
        << "6. 민첩 UP\n"
        << "7. 지능 UP\n"
        << "8. 행운 UP\n"
        << "9. 현재 능력치\n"
        << "10. Level UP\n"
        << "0. 나가기\n";
}

bool Player::UsePotion(int& potionCount, int& stat, const char* statName) {
    if (!HasPotion(potionCount)) {
        std::cout << "포션이 부족합니다.\n";
        return false;
    }

    stat += 20;
    --potionCount;

    std::cout << "* " << statName
        << "가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
    std::cout << "현재 " << statName << ": " << stat << "\n";
    std::cout << "남은 포션 수: " << potionCount << "\n";
    return true;
}

bool Player::IncreasePower(int& power, const char* powerName) {
    power <<= 1;
    std::cout << "* " << powerName << "이 2배로 증가되었습니다.\n";
    std::cout << "현재 " << powerName << ": " << power << "\n";
    return true;
}

bool Player::IncreaseAbility(int& statPoint, int& ability, const char* name) {
    if (statPoint <= 0) {
        std::cout << "남은 스탯 포인트가 없습니다.\n";
        return false;
    }
    ++ability;
    --statPoint;

    std::cout << "* " << name << "이(가) 1 상승했습니다.\n";
    std::cout << "현재 " << name << ": " << ability << "\n";
    return true;
}

void Player::PrintStatus(const int status[], const int ability[],
    int level, int statPoint, int HPPotion, int MPPotion) {
    std::cout << "* HP : " << status[0]
        << ", MP : " << status[1]
        << ", 공격력 : " << status[2]
        << ", 방어력 : " << status[3] << "\n"
        << "  힘 : " << ability[0]
        << ", 민첩 : " << ability[1]
        << ", 지능 : " << ability[2]
        << ", 행운 : " << ability[3] << "\n"
        << "  레벨 : " << level
        << ", 남은 스탯 포인트: " << statPoint
        << ", 남은 HP/MP 포션 수 : " << HPPotion
        << "/" << MPPotion << "\n";
}

void Player::LevelUP(int& exp, int& HPPotion, int& MPPotion,
    int& level, int& statPoint) {
    exp++;
    std::cout << "경험치를 쌓았습니다.\n"
        << "현재 경험치: " << exp << "\n";
    if (exp >= 6) {
        exp -= 6;
        HPPotion++;
        MPPotion++;
        level++;
        statPoint += 5;
        std::cout << "* 레벨업! 스탯 포인트와 HP/MP 포션이 지급됩니다.\n";
        std::cout << "남은 스탯 포인트 : " << statPoint << "\n";
        std::cout << "남은 HP/MP 포션 수 : " << HPPotion <<
            "/" << MPPotion << "\n";
    }
}

int* Player::GetStatus() {
    return status;
}

int* Player::GetAbility() {
    return ability;
}

int Player::GetLevel() {
    return level;
}
int Player::GetExp() {
    return exp;
}
int Player::GetHPPotion() {
    return HPPotion;
}
int Player::GetMPPotion() {
    return MPPotion;
}
int Player::GetStatPoint() {
    return statPoint;
}

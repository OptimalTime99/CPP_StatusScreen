// main.cpp
// Copyright (c) 2025 by OptimalTime99. All rights reserved.

#include <iostream>
#include <random>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

static int rollStat() {
    std::mt19937 rng(std::random_device {}());
    std::uniform_int_distribution<int> dist(1, 10);
    return dist(rng);
}

static void randomAbility(int* ability, int size) {
    for (int i = 0; i < size; i++) {
        *(ability + i) = rollStat();
    }
}

static bool isValidHPMP(int hp, int mp) {
    return hp > 50 && mp > 50;
}

static bool isValidPower(int attack, int defense) {
    return attack > 0 && defense > 0;
}

static bool isStart(char answer) {
    return answer == 'n' || answer == 'N';
}

static bool hasPotion(int potion) {
    return potion > 0;
}

static void inputHPMP(int& hp, int& mp) {
    while (true) {
        std::cout << "HP와 MP를 입력해주세요: ";
        std::cin >> hp >> mp;

        if (isValidHPMP(hp, mp)) break;

        std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }
}

static void inputPower(int& attack, int& defense) {
    while (true) {
        std::cout << "공격력과 방어력을 입력해주세요: ";
        std::cin >> attack >> defense;

        if (isValidPower(attack, defense)) break;

        std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }
}

static void initAbility(int* ability) {
    while (true) {
        char answer;
        randomAbility(ability, 4);
        std::cout << "능력치 주사위를 굴렸습니다.\n"
            << "< 현재 능력치 >\n"
            << "힘 : " << ability[0] << "\n"
            << "민첩 : " << ability[1] << "\n"
            << "지능 : " << ability[2] << "\n"
            << "행운 : " << ability[3] << "\n\n";
        std::cout << "다시 굴리시겠습니까?(Y/N)\n";
        std::cin >> answer;

        if (isStart(answer)) break;
    }
}

static void printMenu() {
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

static bool usePotion(int& potionCount, int& stat, const char* statName) {
    if (!hasPotion(potionCount)) {
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

static bool increasePower(int &power, const char* powerName) {
    power <<= 1;
    std::cout << "* " << powerName << "이 2배로 증가되었습니다.\n";
    std::cout << "현재 " << powerName << ": " << power << "\n";
    return true;
}

static bool increaseAbility(int& statPoint, int& ability, const char* name) {
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

static void printStatus(const int status[], const int ability[],
    int level, int statPoint, int HPPotion, int MPPotion) {
    std::cout << "* HP : "     << status[0]
              << ", MP : "     << status[1]
              << ", 공격력 : " << status[2]
              << ", 방어력 : " << status[3] << "\n"
              << "  힘 : "   << ability[0]
              << ", 민첩 : " << ability[1]
              << ", 지능 : " << ability[2]
              << ", 행운 : " << ability[3] << "\n"
              << "  레벨 : " << level
              << ", 남은 스탯 포인트: "      << statPoint
              << ", 남은 HP/MP 포션 수 : " << HPPotion
              << "/" << MPPotion << "\n";
}

static void levelUP(int& exp, int& HPPotion, int& MPPotion,
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

int main() {
    int status[4] = { 0, 0, 0, 0 };
    int choice = -1;
    int HPPotion = 0;
    int MPPotion = 0;
    int level = 1;
    int exp = 0;

    int ability[4] = { 0, 0, 0, 0 };
    int statPoint = 0;

    inputHPMP(status[0], status[1]);
    inputPower(status[2], status[3]);
    initAbility(ability);
    setPotion(5, &HPPotion, &MPPotion);

    printMenu();

    while (choice != 0) {
        std::cout << "번호를 선택해주세요: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            usePotion(HPPotion, status[0], "HP");
            break;
        case 2:
            usePotion(MPPotion, status[1], "MP");
            break;
        case 3:
            increasePower(status[2], "공격력");
            break;
        case 4:
            increasePower(status[3], "방어력");
            break;
        case 5:
            increaseAbility(statPoint, ability[0], "힘");
            break;
        case 6:
            increaseAbility(statPoint, ability[1], "민첩");
            break;
        case 7:
            increaseAbility(statPoint, ability[2], "지능");
            break;
        case 8:
            increaseAbility(statPoint, ability[3], "행운");
            break;
        case 9:
            printStatus(status, ability, level, statPoint, HPPotion, MPPotion);
            break;
        case 10:
            levelUP(exp, HPPotion, MPPotion, level, statPoint);
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

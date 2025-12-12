// main.cpp
// Copyright (c) 2025 by OptimalTime99. All rights reserved.

#include <iostream>
#include <random>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

static void randomAbility(int* ability, int size) {
    std::mt19937 rng(std::random_device {}());
    std::uniform_int_distribution<int> dist(1, 10);

    for (int i = 0; i < size; i++) {
        *(ability + i) = dist(rng);
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
    bool isStart = false;


    while (status[0] <= 50 || status[1] <= 50) {
        std::cout << "HP와 MP를 입력해주세요: ";
        std::cin >> status[0] >> status[1];

        if (status[0] <= 50 || status[1] <= 50) {
            std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
        }
    }

    while (status[2] <= 0 || status[3] <= 0) {
        std::cout << "공격력과 방어력을 입력해주세요: ";
        std::cin >> status[2] >> status[3];

        if (status[2] <= 0 || status[3] <= 0) {
            std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
        }
    }

    while (!isStart) {
        char answer;
        randomAbility(ability, 4);
        std::cout << "능력치 주사위를 굴렸습니다.\n"
                  << "< 현재 능력치 >\n"
                  << "힘 : "   << ability[0] << "\n"
                  << "민첩 : " << ability[1] << "\n"
                  << "지능 : " << ability[2] << "\n"
                  << "행운 : " << ability[3] << "\n\n";
        std::cout << "다시 굴리시겠습니까?(Y/N)\n";
        std::cin >> answer;

        if (answer == 'n' || answer == 'N') {
            isStart = true;
        }
    }

    setPotion(5, &HPPotion, &MPPotion);

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

    while (choice != 0) {
        std::cout << "번호를 선택해주세요: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (HPPotion <= 0) {
                std::cout << "포션이 부족합니다.\n";
                break;
            }
            status[0] += 20;
            HPPotion--;
            std::cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
            std::cout << "현재 HP: " << status[0] << "\n";
            std::cout << "남은 포션 수: " << HPPotion << "\n";
            break;
        case 2:
            if (MPPotion <= 0) {
                std::cout << "포션이 부족합니다.\n";
                break;
            }
            status[1] += 20;
            MPPotion--;
            std::cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
            std::cout << "현재 MP: " << status[1] << "\n";
            std::cout << "남은 포션 수: " << MPPotion << "\n";
            break;
        case 3:
            status[2] <<= 1;
            std::cout << "* 공격력이 2배로 증가되었습니다.\n";
            std::cout << "현재 공격력: " << status[2] << "\n";
            break;
        case 4:
            status[3] <<= 1;
            std::cout << "* 방어력이 2배로 증가되었습니다.\n";
            std::cout << "현재 방어력: " << status[3] << "\n";
            break;
        case 5:
            if (statPoint <= 0) {
                std::cout << "남은 스탯 포인트가 없습니다.\n";
                break;
            }
            ability[0]++;
            statPoint--;
            std::cout << "* 힘이 1 상승했습니다.\n";
            std::cout << "현재 힘: " << ability[0] << "\n";
            break;
        case 6:
            if (statPoint <= 0) {
                std::cout << "남은 스탯 포인트가 없습니다.\n";
                break;
            }
            ability[1]++;
            statPoint--;
            std::cout << "* 민첩이 1 상승했습니다.\n";
            std::cout << "현재 민첩: " << ability[1] << "\n";
            break;
        case 7:
            if (statPoint <= 0) {
                std::cout << "남은 스탯 포인트가 없습니다.\n";
                break;
            }
            ability[2]++;
            statPoint--;
            std::cout << "* 지능이 1 상승했습니다.\n";
            std::cout << "현재 지능: " << ability[2] << "\n";
            break;
        case 8:
            if (statPoint <= 0) {
                std::cout << "남은 스탯 포인트가 없습니다.\n";
                break;
            }
            ability[3]++;
            statPoint--;
            std::cout << "* 행운이 1 상승했습니다.\n";
            std::cout << "현재 행운: " << ability[3] << "\n";
            break;
        case 9:
            std::cout << "* HP : "     << status[0]
                      << ", MP : "     << status[1]
                      << ", 공격력 : " << status[2]
                      << ", 방어력 : " << status[3] << "\n"
                      << "  힘 : "     << ability[0]
                      << ", 민첩 : "   << ability[1]
                      << ", 지능 : "   << ability[2]
                      << ", 행운 : "   << ability[3] << "\n"
                      << "  레벨 : "   << level
                      << ", 남은 스탯 포인트: " << statPoint
                      << ", 남은 HP / MP 포션 수 : " << HPPotion <<
                                               " / " << MPPotion <<  "\n";
            break;
        case 10:
            exp++;
            std::cout << "경험치를 쌓았습니다.\n"
                      << "현재 경험치: " << exp << "\n";
            if (exp >= 6) {
                exp -= 6;
                HPPotion++;
                MPPotion++;
                level++;
                statPoint += 5;
                std::cout << "* 레벨업! HP/MP 포션이 지급됩니다.\n";
                std::cout << "남은 HP/MP 포션 수 : " << HPPotion <<
                                                 "/" << MPPotion << "\n";
            }
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

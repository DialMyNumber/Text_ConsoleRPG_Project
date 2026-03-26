// LifeCycle.cpp
#include "LifeCycle.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

// 생성자 구현
LifeCycle::LifeCycle() : isRunning(true), playerX(0), playerY(0) {}

// 입력 처리 로직 구현
void LifeCycle::ProcessInput() {
    if (_kbhit()) {
        int key = _getch();

        if (key == 224) {
            key = _getch();
            switch (key) {
            case KEY_UP:
                playerY--;
                cout << "위로 이동! 현재 위치: (" << playerX << ", " << playerY << ")" << endl;
                break;
            case KEY_DOWN:
                playerY++;
                cout << "아래로 이동! 현재 위치: (" << playerX << ", " << playerY << ")" << endl;
                break;
            case KEY_LEFT:
                playerX--;
                cout << "왼쪽으로 이동! 현재 위치: (" << playerX << ", " << playerY << ")" << endl;
                break;
            case KEY_RIGHT:
                playerX++;
                cout << "오른쪽으로 이동! 현재 위치: (" << playerX << ", " << playerY << ")" << endl;
                break;
            }
        }
        else {
            switch (key) {
            case 'i':
            case 'I':
                cout << "\n====================" << endl;
                cout << " 인벤토리를 엽니다. " << endl;
                cout << "====================\n" << endl;
                break;

            case KEY_ESC:
                cout << "\n메뉴 화면입니다." << endl;
                cout << "게임을 종료하시겠습니까? (Y/N): ";

                int exitKey = _getch();
                cout << (char)exitKey << endl;

                if (exitKey == 'y' || exitKey == 'Y') {
                    isRunning = false;
                }
                else {
                    cout << "게임으로 돌아갑니다." << endl;
                }
                break;
            }
        }
    }
}

void LifeCycle::BeginPlay() {
    cout << "게임을 시작합니다." << endl;
    cout << "[방향키]: 이동 | [I]: 인벤토리 | [ESC]: 메뉴\n" << endl;
}

void LifeCycle::Tick() {
    ProcessInput();

    // 게임 로직 업데이트 (예: 몬스터 이동, 충돌 체크 등)

    Sleep(10); // 틱간 시간차 
}

void LifeCycle::EndPlay() {
    cout << "\n게임을 종료합니다. 플레이해주셔서 감사합니다!" << endl;
}

bool LifeCycle::IsRunning() const {
    return isRunning;
}
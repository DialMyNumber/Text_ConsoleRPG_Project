#include <iostream>
#include <conio.h> // _kbhit(), _getch() 함수 사용을 위한 헤더
#include <cstdlib>

using namespace std;

// 가독성을 위한 키 코드 상수 정의
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_ESC = 27;

int main() {
    bool isRunning = true;
    int playerX = 0;
	int playerY = 0; // 플레이어의 초기 위치

    cout << "게임을 시작합니다." << endl;
    cout << "[방향키]: 이동 | [I]: 인벤토리 | [ESC]: 메뉴" << endl;

    // 메인 게임 루프
    while (isRunning) 
    {
        // _kbhit()은 키보드 입력이 있을 때만 true를 반환해 루프가 멈추지 않게 함
        if (_kbhit()) 
        {
            int key = _getch(); // 입력된 키 값을 즉시 가져옴 (엔터 필요 없음)

            // 방향키 처리: 방향키는 224라는 특수 값을 먼저 반환하고, 그다음에 실제 방향 코드를 반환함
            if (key == 224) 
            {
                key = _getch(); // 실제 방향키 값 읽기
                switch (key) 
                {
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
			// 일반 키 처리 (I, ESC 등) 이후에 구현한 기능에 따라 추가적인 키 처리 로직을 여기에 작성할 수 있음 
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

                    int exitKey = _getch(); // Y 또는 N 입력 즉시 대기
                    cout << (char)exitKey << endl;

                    if (exitKey == 'y' || exitKey == 'Y') 
                    {
                        isRunning = false;
                        cout << "게임을 종료합니다." << endl;
                    }
                    else 
                    {
                        cout << "게임으로 돌아갑니다." << endl;
                    }
                    break;
                }
            }
        }

        // 이곳에 몬스터의 이동이나 게임 로직 업데이트 코드가 들어갈 수 있어!
        // (CPU 점유율을 낮추려면 <windows.h>의 Sleep() 함수를 추가해 루프 속도를 조절하는 것도 좋아)
    }

    return 0;
}
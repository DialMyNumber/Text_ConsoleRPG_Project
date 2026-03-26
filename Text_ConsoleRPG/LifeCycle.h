// LifeCycle.h
#pragma once 

class LifeCycle 
{
private:
    // 키 코드 상수
    static const int KEY_UP = 72;
    static const int KEY_DOWN = 80;
    static const int KEY_LEFT = 75;
    static const int KEY_RIGHT = 77;
    static const int KEY_ESC = 27;

    bool isRunning;
    int playerX;
    int playerY;

    // 내부에서만 사용하는 입력 처리 함수
    void ProcessInput();

public:
    // 생성자
    LifeCycle();

    // 생명주기 함수들
    void BeginPlay();
    void Tick();
    void EndPlay();

    // 상태 확인 함수
    bool IsRunning() const;
};

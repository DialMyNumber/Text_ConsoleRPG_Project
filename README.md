# Text_ConsoleRPG_Project# ⚔️ [프로젝트 명칭: 예 - C++ Console Dungeon]

> **Visual Studio 2022와 C++로 구현된 정통 텍스트 RPG**
> 객체 지향 프로그래밍(OOP)을 활용하여 설계된 탄탄한 로직의 콘솔 모험기입니다.

---

## 📝 프로젝트 개요
이 프로젝트는 **C++**를 사용하여 개발된 텍스트 기반 RPG입니다. **Visual Studio 2022** 환경에서 작업되었으며, 클래스 상속, 다형성, STL 활용 및 파일 입출력 등 C++의 핵심 기능을 활용하여 안정적인 게임 엔진을 구축하는 것을 목표로 합니다.

### 🌟 주요 특징
* **C++ OOP 설계:** `Character`, `Monster`, `Item` 등의 클래스 구조를 통한 효율적인 객체 관리.
* **캐릭터 성장 시스템:** 경험치 획득에 따른 레벨업 및 스탯(HP, ATK, DEF) 상승 로직.
* **데이터 영속성:** `std::fstream`을 활용한 플레이어 정보 저장(Save) 및 불러오기(Load) 시스템.
* **전투 시스템:** 턴제 기반의 전략적 전투 및 아이템 사용 인터페이스.
* **콘솔 UI 최적화:** `system("cls")` 및 `<Windows.h>`를 활용한 깔끔한 화면 구성.

---

## 🚀 시작하기

### 개발 환경 (Prerequisites)
* **IDE:** Visual Studio 2022
* **Compiler:** MSVC (Microsoft Visual C++)
* **C++ Standard:** C++17 이상 권장

### 빌드 및 실행 방법
1. 이 저장소를 클론(Clone)하거나 소스 코드를 다운로드합니다.
2. Visual Studio 2022를 실행하고 `[프로젝트명].sln` 파일을 엽니다.
3. 상단 솔루션 구성 메뉴에서 **Release** 또는 **Debug**를 선택합니다.
4. 아키텍처 설정이 **x64** 또는 **x86**인지 확인합니다.
5. `Ctrl + F5` (디버깅하지 않고 시작) 또는 `F5`를 눌러 빌드 후 실행합니다.

---

## 📂 프로젝트 구조
C++ 프로젝트 관리에 최적화된 구조입니다.
```text
├── ProjectName/
│   ├── Headers/            # .h 헤더 파일 (클래스 선언)
│   │   ├── Character.h
│   │   ├── Monster.h
│   │   ├── Item.h
│   │   └── GameManager.h
│   ├── Sources/            # .cpp 소스 파일 (로직 구현)
│   │   ├── Character.cpp
│   │   ├── Monster.cpp
│   │   ├── GameManager.cpp
│   │   └── Main.cpp        # 게임 진입점 (main 함수)
│   └── Data/               # 세이브 파일 및 게임 데이터 (.txt / .dat)
├── ProjectName.sln         # Visual Studio 솔루션 파일
└── README.md

🛠 기술 스택
Language: C++

Toolchain: MSVC 143 (Visual Studio 2022)

Libraries: * <iostream>: 표준 콘솔 입출력

<vector>, <map>: 동적 데이터 관리 (STL)

<fstream>: 파일 입출력을 통한 데이터 저장

<string>: 텍스트 데이터 처리

<Windows.h>: 콘솔 화면 제어 및 색상 설정

🎮 주요 기능 구현 현황
[x] 기본적인 캐릭터 생성 및 스탯 시스템

[ ] 턴제 전투 로직 구현

[ ] 아이템 인벤토리 시스템

[ ] 몬스터 종류별 AI 패턴 적용

[ ] 세이브/로드 기능 구현

👤 개발자 정보
개발자: [본인 성함 또는 닉네임]

GitHub: https://github.com/YourID

Email: [Your Email Address]

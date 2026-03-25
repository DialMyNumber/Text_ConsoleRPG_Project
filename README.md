⚔️ [프로젝트 이름: (미정)]
Visual Studio 2022와 C++로 구현된 정통 텍스트 RPG
객체 지향 프로그래밍(OOP)을 활용하여 설계된 탄탄한 로직의 콘솔 모험기입니다.

---

📝 프로젝트 개요
이 프로젝트는 C++를 사용하여 개발된 텍스트 기반 RPG입니다. Visual Studio 2022 환경에서 작업되었으며, 클래스 상속, 다형성, 파일 입출력 등 C++의 핵심 기능을 활용하여 안정적인 게임 엔진을 구축하는 것을 목표로 합니다.

---

🌟 주요 특징
C++ OOP 설계: Character, Monster, Item, Inventory 등의 클래스 구조를 통한 효율적인 데이터 관리.

---

🚀 시작하기
개발 환경 (Prerequisites)
IDE: Visual Studio 2022

Compiler: MSVC (Microsoft Visual C++)

C++ Standard: C++17 또는 C++20 권장

빌드 및 실행 방법
이 저장소를 클론하거나 다운로드합니다.

설치 방법
저장소를 클론합니다.

Bash
git clone https://github.com/parkchanheyk/Text_ConsoleRPG_Project.git

[프로젝트명].sln 파일을 Visual Studio 2022에서 엽니다.

상단 솔루션 구성에서 Release 또는 Debug를 선택하고 x64 아키텍처를 확인합니다.

F5 키를 눌러 빌드 후 실행합니다.

---

📂 프로젝트 구조
C++ 프로젝트 특성에 맞춘 권장 구조입니다.

Plaintext
├── ProjectName/
│   ├── Headers/            # .h 헤더 파일 (클래스 선언)
│   │   ├── Character.h
│   │   ├── Monster.h
│   │   └── GameManager.h
│   ├── Sources/            # .cpp 소스 파일 (로직 구현)
│   │   ├── Character.cpp
│   │   ├── Monster.cpp
│   │   └── Main.cpp        # 진입점
│   └── Data/               # 세이브 파일 및 게임 데이터 (.txt / .dat)
├── ProjectName.sln         # Visual Studio 솔루션 파일
└── README.md

---

🛠 기술 스택
Language: C++

Toolchain: MSVC 143 (Visual Studio 2022)

Libraries: * <iostream>: 콘솔 입출력

<vector>, <map>: 데이터 관리 (STL)

---

🎮 주요 기능 구현 예정
[ ] 플레이어 직업별 고유 스킬 시스템

[ ] 아이템 인벤토리 및 장착 시스템

[ ] 랜덤 맵 생성 또는 층별 던전 시스템

[ ] 턴제 몬스터 (단순 패턴 공격)

👤 개발자 정보
개발자: [CH2 1조]

GitHub: [[GitHub 주소](https://github.com/parkchanheyk/Text_ConsoleRPG_Project)]

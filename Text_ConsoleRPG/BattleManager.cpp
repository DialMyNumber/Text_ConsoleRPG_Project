#include "BattleManager.h"
#include "Player.h"
#include "BossMonster.h"
#include "Monster.h"
#include "ConsumeItem.h"
#include <iostream>
#include <windows.h>
#include <vector>

void BM_Gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}

void BattleManager::DrawBattleScene(std::shared_ptr<Player> player, std::shared_ptr<Character> enemy)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // system("cls"); // 호출하는 쪽(LifeCycle)에서 처리하므로 삭제 권장

    BM_Gotoxy(0, 0);
    std::cout << "=======================================================================================" << std::endl;
    std::cout << "                                   [ FINAL BOSS BATTLE ]                               " << std::endl;
    std::cout << "=======================================================================================" << std::endl;

    // --- 아스키 아트 출력 부분 ---

    // 1. 고양이 아트 (왼쪽, 하늘색) - 띄어쓰기를 조절해 모두 정확히 '25칸'으로 맞췄습니다.
    std::vector<std::string> catArtLines = {
        "          |\\---/|       ",
        "          ( o_o )        ",
        "           > ^ <         "
    };

    // 2. 쥐 보스 아트 (오른쪽, 빨간색)
    std::vector<std::string> ratArtLines = {
        "             __             _,-'~^\"-.",
        "           _// )      _,-'~`         `.",
        "         .' ( /`\"-,-'`                 ;",
        "        / 6                             ;",
        "       /           ,             ,-'     ;",
        "      (,__.--.      \\           /        ;",
        "       //'   /`-.\\   |          |        `._________",
        "         _.-'_/`  )  )--...,,,___\\     \\-----------,)",
        "       (((\"~` _.-'.-'           __`-.   )         //",
        "             (((\"`             (((---~\"`         //",
        "                                                ((________________",
        "                                                `----\"\"\"\"~~~~^^^```"
    };

    int startY = 3;
    int maxLines = ratArtLines.size(); // 12줄
    int catOffset = maxLines - catArtLines.size();

    for (int i = 0; i < maxLines; ++i) 
    {
        BM_Gotoxy(0, startY + i);

        // 왼쪽 고양이 출력 (하늘색)
        SetConsoleTextAttribute(hConsole, 11);
        if (i >= catOffset) {
            std::cout << catArtLines[i - catOffset]; // 정확히 25칸 출력
        }
        else {
            // 핵심 수정: 고양이가 없는 줄도 정확히 25칸의 공백을 출력해야 쥐가 안 밀립니다!
            std::cout << "                         ";
        }

        // 중앙 대치 메시지 (흰색)
        SetConsoleTextAttribute(hConsole, 7);
        if (i == maxLines / 2 + 3) {
            std::cout << "     VS      "; // 13칸
        }
        else {
            std::cout << "             "; // 13칸 공백
        }

        // 오른쪽 쥐 출력 (빨간색)
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << ratArtLines[i] << std::endl;
    }

    SetConsoleTextAttribute(hConsole, 7); // 색상 원상복구

    // 핵심 2: 겹침과 스크롤링을 방지하는 커스텀 UI 대시보드
    int statusY = startY + maxLines + 1;

    BM_Gotoxy(0, statusY);
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    // 첫 번째 줄: 이름 및 레벨 출력
    BM_Gotoxy(2, statusY + 1);
    std::cout << "[플레이어] " << player->getName() << " (Lv." << player->getLevel() << ")";
    BM_Gotoxy(40, statusY + 1);
    std::cout << "| [보스] " << enemy->getName() << " (Lv." << enemy->getLevel() << ")";

    // 두 번째 줄: HP 상태 출력
    BM_Gotoxy(2, statusY + 2);
    std::cout << "HP : " << player->getCurrentHP() << " / " << player->getMaxHP();
    BM_Gotoxy(40, statusY + 2);
    std::cout << "| HP : " << enemy->getCurrentHP() << " / " << enemy->getMaxHP();

    // 세 번째 줄: 공격력 및 스피드 출력
    BM_Gotoxy(2, statusY + 3);
    std::cout << "ATK: " << player->getATK() << "   SPD: " << player->getSpeed();
    BM_Gotoxy(40, statusY + 3);
    std::cout << "| ATK: " << enemy->getATK() << "   SPD: " << enemy->getSpeed();

    BM_Gotoxy(0, statusY + 4);
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    // 남은 빈 공간을 지워주는 더미 공백 출력 (잔상 제거용)
    std::cout << "  1. 공격하기 | 2. 인벤토리 | 3. 도망가기 | 선택:                                           " << std::endl;
    std::cout << "                                                                                " << std::endl;

    // 커서를 입력 위치로 되돌림
    BM_Gotoxy(50, statusY + 5);
}

BattleManager::EBattleResult BattleManager::ProcessTurn(std::shared_ptr<Player> player, std::shared_ptr<Character> enemy, int actionInput)
{
    if (actionInput == '1') 
    {
        // 1. 플레이어 공격
        player->attack(enemy);
        if (enemy->getCurrentHP() <= 0) return EBattleResult::PlayerWin;

        // 2. 적 반격
        enemy->attack(player);
        if (player->getCurrentHP() <= 0) return EBattleResult::EnemyWin;
    }
    else if(actionInput == '2') 
    {
		auto inv = player->GetInventory();
		auto& container = inv->container; // 인벤토리 컨테이너 참조

        if(container.empty()) {
            std::cout << "인벤토리가 비어 있습니다!" << std::endl;
            Sleep(1000);
            return EBattleResult::Progress; // 인벤토리가 비어있으면 아무 행동도 하지 않고 전투 계속
		}

		std::vector<std::shared_ptr<ConsumeItem>> consumeList; // 아이템 목록을 벡터로 변환
		std::vector<std::shared_ptr<ItemBase>> originalKeys; // 인벤토리 아이템 목록

		std::cout << "\n[ 사용할 아이템 선택 ]" << std::endl;
		int idx = 1;
        for (auto& pair : container) {
			// ItemBase 포인터를 ConsumeItem 포인터로 다운캐스팅 시도
			auto consumeItem = std::dynamic_pointer_cast<ConsumeItem>(pair.first);
            if(consumeItem) { // 다운캐스팅이 성공한 경우에만 아이템 목록에 추가
                std::cout << idx << ". " << consumeItem->itemName
                    << " (보유: " << pair.second << "개)" << std::endl;
                consumeList.push_back(consumeItem); // ConsumeItem 목록에 추가
                originalKeys.push_back(pair.first); // 원래 ItemBase 포인터도 저장
                idx++;
			}
		}

        if(consumeList.empty()) {
            std::cout << "사용할 수 있는 소비 아이템이 없습니다!" << std::endl;
            Sleep(1000);
            return EBattleResult::Progress; // 사용할 수 있는 소비 아이템이 없으면 전투 계속
		}

        std::cout << "0. 취소" << std::endl;
        std::cout << "선택: ";

        // 입력 받기
        int choice;
        std::cin >> choice;

        if (choice > 0 && choice <= (int)consumeList.size()) {
            auto selectedItem = consumeList[choice - 1];
            auto itemKey = originalKeys[choice - 1];

            // 2. 아이템 효과 적용 (player는 shared_ptr이므로 그대로 전달)
            if (selectedItem->ApplyEffect(player)) {
                // 3. 사용 성공 시 인벤토리에서 제거
                inv->RemoveItem(itemKey, 1);

                std::cout << "\n아이템을 사용했습니다! 다음은 적의 턴입니다." << std::endl;
                Sleep(1000);

                // 4. 아이템 사용도 턴을 소모하므로 적이 공격함
                std::cout << "\n--- 적의 턴 ---" << std::endl;
                enemy->attack(player);
                if (player->getCurrentHP() <= 0) return EBattleResult::EnemyWin;
            }
        }
        else {
            std::cout << "사용을 취소했습니다." << std::endl;
            Sleep(500);
        }
	}
    else if (actionInput == '3') 
    {
        return EBattleResult::Escape; //도망 
    }

	return EBattleResult::Progress; // 전투 계속
}
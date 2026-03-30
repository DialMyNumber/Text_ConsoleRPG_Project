#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "LifeCycle.h" 
#include "LogManager.h"

int main() 
{
    LogManager::getInstance().start();

	LifeCycle myLifeCycle; // °´Ã¼ »ý¼º

    myLifeCycle.BeginPlay();

    while (myLifeCycle.IsRunning()) {
        myLifeCycle.Tick();
    }

    myLifeCycle.EndPlay();

    LogManager::getInstance().stop();

    return 0;
}
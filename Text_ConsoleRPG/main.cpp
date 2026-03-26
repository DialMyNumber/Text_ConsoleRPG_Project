#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "LifeCycle.h" 

int main() {

	LifeCycle myLifeCycle; // °´Ã¼ »ý¼º

    myLifeCycle.BeginPlay();

    while (myLifeCycle.IsRunning()) {
        myLifeCycle.Tick();
    }

    myLifeCycle.EndPlay();

    return 0;
}
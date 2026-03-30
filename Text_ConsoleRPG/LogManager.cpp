#include "LogManager.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

LogManager& LogManager::getInstance() {
	static LogManager instance("Log.txt");	// 유일한 객체를 생성하고
	return instance;	// 참조를 반환
}

LogManager::LogManager(const std::string& filename) : filename(filename) {}	// 생성자

LogManager::~LogManager() {	// 소멸자
	if (logFile.is_open()) {
		logFile.close();
	}
}

// ---------------- 로그 레벨 문자열 변환
const char* LogManager::levelToString(LogLevel level) {
    switch (level) {
    case LogLevel::INFO: return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::CRITICALERROR: return "ERROR";
    case LogLevel::DEBUG: return "DEBUG";
    }
    return "";
}

void LogManager::writeLog(LogLevel level, const std::string& message) {
    // 현재 시간
    auto now = std::chrono::system_clock::now();

    // 초 단위로 변환
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local{}; // 안전한 tm 구조체

    // Windows: localtime_s / Linux: localtime_r
#ifdef _WIN32
    localtime_s(&local, &now_c);    // 쓰레드 안전
#else
    localtime_r(&now_c, &local);    // POSIX 쓰레드 안전
#endif

    // 밀리초 계산
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ) % 1000;

    // 문자열 생성
    std::ostringstream oss;
    oss << std::put_time(&local, "[%H:%M:%S")           // 시:분:초
        << "." << std::setw(3) << std::setfill('0')
        << ms.count() << "ms] "
        << "[" << levelToString(level) << "] "
        << message;

    logQueue.push(oss.str());
}

// ---------------- 로그 쓰레드 시작
void LogManager::start() {
    isLogRunning = true;
    logThread = std::thread(&LogManager::logThreadFunc, this);
    logThread.detach(); // 메인 루프와 독립
}

void LogManager::stop() {
    isLogRunning = false;
    if (logThread.joinable()) logThread.join(); // 쓰레드 종료 대기
    while (!logQueue.empty()) {
        logFile << logQueue.front() << std::endl;
        logQueue.pop();
    }
    logFile.close();
}

// ---------------- 백그라운드 로그 함수
void LogManager::logThreadFunc() {
    // 시작 시 파일 열기
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "로그 파일 열기 실패!" << std::endl;
        return;
    }

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // 큐가 비어있지 않으면 파일에 기록
        while (!logQueue.empty()) {
            logFile << logQueue.front() << std::endl;
            logQueue.pop();
        }

        // Close → Open 반복 (말씀하신 구조)
        logFile.close();
        logFile.open(filename, std::ios::app);
    }
}
#pragma once
#include <string>
#include <queue>
#include <fstream>
#include <thread>

enum class LogLevel {
	INFO,
	WARNING,
	CRITICALERROR,
	DEBUG
};

class LogManager {
private:
	LogManager(const std::string& filename);
	~LogManager();

	LogManager(const LogManager&) = delete;	// 싱글톤, 복사 생성자 사용 방지
	LogManager& operator=(const LogManager&) = delete;	// 싱글톤, 대입 연산자 사용 방지

	void logThreadFunc();	// 백그라운드에서 실행될 쓰레드 함수
	const char* levelToString(LogLevel level);	// enum을 문자열로 변환

	std::string filename;	// 경로
	std::queue<std::string> logQueue;	// 로그 메세지를 First In First Out 해줄 Queue
	std::ofstream logFile;
	std::thread logThread;
	bool isLogRunning = false;

public:
	static LogManager& getInstance();

	void writeLog(LogLevel level, const std::string& logMessage);	// 로그 입력 함수

	void start();	// LogManager Thread start

	void stop();	// LogManager Thread stop
};
#pragma once

#include "LogManager.h"

#define LOG_INFO(msg)    LogManager::getInstance().writeLog(LogLevel::INFO, msg)
#define LOG_WARNING(msg) LogManager::getInstance().writeLog(LogLevel::WARNING, msg)
#define LOG_ERROR(msg)   LogManager::getInstance().writeLog(LogLevel::CRITICALERROR, msg)
#define LOG_DEBUG(msg)   LogManager::getInstance().writeLog(LogLevel::DEBUG, msg)

/* Usage

로그를 사용할 곳에서
#include "LogManager.h"
#include "LogMacros.h"

LogManager::getInstance().writeLog(LogLevel::INFO, "플레이어 캐릭터 생성");

LOG_INFO("INFO TEXT");
LOG_WARNING("WARNING TEXT");
LOG_ERROR("에러 발생");
LOG_DEBUG("DEBUG TEXT");

*/
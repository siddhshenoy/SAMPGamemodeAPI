#pragma once

#include <string>
#include <sampgdk/sampgdk.h>

//#define DEBUG

//#define		LOGPRINTF_DEBUG_CLASS(function, pointer, extra, ...)	sampgdk::logprintf((std::string("%s(%x)") + ((std::string(extra)).length() > 0 ? (std::string(": ") + std::string(extra)) : std::string(""))).c_str(), function, pointer, __VA_ARGS__);
#define		LOGPRINTF_DEBUG_CLASS(function, pointer, extra, ...)	WriteLog(function, pointer, extra, __VA_ARGS__)//sampgdk::logprintf((std::string("%s(%x)") + ((std::string(extra)).length() > 0 ? (std::string(": ") + std::string(extra)) : std::string(""))).c_str(), function, pointer, __VA_ARGS__);

static void WriteLog(const char* function, void* pointer, const char* extra, ...) {
#ifdef DEBUG
	va_list list;
	va_start(list, extra);
	sampgdk::logprintf((std::string("%s(%x)") + ((std::string(extra)).length() > 0 ? (std::string(": ") + std::string(extra)) : std::string(""))).c_str(), function, pointer, list);
	va_end(list);
#endif
}

#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include <chrono>
#include <ctime>
using namespace std;

string currentTime() {
    auto now = chrono::system_clock::now();
    time_t timeNow = chrono::system_clock::to_time_t(now);
    struct tm localTime;
    localtime_s(&localTime, &timeNow);

    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", &localTime);
    return string(buf);
} // Return current system time as formatted string


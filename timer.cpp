#include "timer.h"

Timer::Timer() : _start(std::chrono::high_resolution_clock::now()) {}

void Timer::restart()
{
    _start = std::chrono::high_resolution_clock::now();
}

long Timer::elapsed() const
{
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start);
    return duration.count();
}

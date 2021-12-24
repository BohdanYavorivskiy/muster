#pragma once

#include <chrono>

class Timer
{
public:
    Timer();

    void start();
    void restart();

    long elapsed() const;

private:
    std::chrono::system_clock::time_point _start;
};

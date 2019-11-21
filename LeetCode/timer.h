#pragma once

#include <chrono>
#include <iostream>

struct Timer {
    Timer()
        : start(std::chrono::steady_clock::now())
    {
    }
    ~Timer()
    {
        auto dif = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count();
        std::cout << "Took " << dif << "\n";
    }
    std::chrono::steady_clock::time_point start;
};

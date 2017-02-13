//
//  Timer.h
//  Signature_Password
//
//  Created by luke anfang on 2/13/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#pragma once

#include <chrono>

class Timer
{
public:
    // Construct the timer
    Timer();
    
    // Start the timer
    void start();
    
    // Get the amount of elapsed time, in seconds since start was called
    double getElapsed();
    
private:
    std::chrono::high_resolution_clock::time_point mStart;
};


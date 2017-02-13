//
//  TimedSignature.h
//  Signature_Password
//
//  Created by luke anfang on 2/13/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

class TimedSignature
{
public:
    TimedSignature(){ mSize = 0; };
    void insertTime(float time);
    float times[29];
    int mSize;
private:
    
};

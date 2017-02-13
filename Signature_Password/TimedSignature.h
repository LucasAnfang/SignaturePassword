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
    TimedSignature();
private:
    float times[30];
    int index;
};

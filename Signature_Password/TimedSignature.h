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
//    operator std::string()
//    {
//        std::string tss;
//        for (int i=0;i < mSize;i++)
//        {
//            tss += "[" + std::to_string(times[i]) + "] ";
//        }
//        return tss;
//    }
    inline friend std::ostream & operator<<(std::ostream & Str, TimedSignature const & ts) {
        // print something from v to str, e.g: Str << v.getX();
        std::string tss;
        for (int i=0;i < ts.mSize;i++)
        {
            tss += "[" + std::to_string(ts.times[i]) + "] ";
        }
        Str << tss;
        return Str;
    }
    
    std::string getTSString()
    {
        std::string tss;
        for (int i=0;i < mSize;i++)
        {
            tss += "[" + std::to_string(times[i]) + "] ";
        }
        return tss;
    }
private:
    
};

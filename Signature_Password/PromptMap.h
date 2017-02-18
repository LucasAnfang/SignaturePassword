//
//  PromptMap.h
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#pragma once
#include <Map>
#include <iostream>
#include "TimedSignature.h"
enum PromptValue
{
    LoginPrompt,
    RegisterPrompt,
    UsernamePrompt,
    PasswordPrompt,
    PasswordRequeryPrompt,
    UsernameRequeryPrompt
};

struct Response
{
    char* username;
    char* password;
    PromptValue mRespondingToPrompt;
    TimedSignature mTimedSignature;
};

struct PromptFuntionMap
{
    void Login(Response r)
    {
        std::cout << "Login Called\n";
    }
    
    void Register(Response r)
    {
        std::cout << "Register Called\n";
    }
    
    void SetUsername(Response r)
    {
        std::cout << "SetUsername Called\n";
    }
    
    void SetPassword(Response r)
    {
        std::cout << "SetUsername Called\n";
    }
};

typedef void (PromptFuntionMap::*prompt_method)(Response);
typedef std::map<PromptValue, prompt_method> prompt_func_map;

class PromptMap
{
public:
    static class _init
    {
    public:
        _init()
        {
            //Initialize variables :: mapping
            FunctionMap[LoginPrompt] = &PromptFuntionMap::Login;
            FunctionMap[RegisterPrompt] = &PromptFuntionMap::Register;
            FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
            FunctionMap[PasswordPrompt] = &PromptFuntionMap::SetPassword;
            //FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
        }
    } _initializer;
    
    static inline const char* ToString(PromptValue p)
    {
        switch (p)
        {
            case LoginPrompt:   return "login";
            case RegisterPrompt:    return "register";
            case UsernamePrompt:    return "username";
            case PasswordPrompt:    return "password";
            case PasswordRequeryPrompt: return "password again";
            case UsernameRequeryPrompt: return "username again";
            default:    return "[Unknown PromptValue]";
        }
    }
    //static inline void Get
 
private:
    PromptMap();
    static prompt_func_map FunctionMap;
};



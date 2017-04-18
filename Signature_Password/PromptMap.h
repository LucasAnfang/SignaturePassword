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
//#include "TimedSignature.h"
//#include "UserInputHandler.h"
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
    //TimedSignature mTimedSignature;
};

struct PromptFuntionMap
{
    void Login(Response *r)
    {
        std::cout << "Login Called\n";
        
    }
    
    void Register(Response *r)
    {
        std::cout << "Register Called\n";
    }
    
    void SetUsername(Response *r)
    {
        std::cout << "SetUsername Called\n";
    }
    
    void SetPassword(Response *r)
    {
        std::cout << "SetUsername Called\n";
    }
};

typedef void (PromptFuntionMap::*prompt_method)(Response*);
typedef std::map<PromptValue, prompt_method> prompt_func_map;

class PromptMap
{
public:
    PromptMap()
    {
        FunctionMap[LoginPrompt] = &PromptFuntionMap::Login;
        FunctionMap[RegisterPrompt] = &PromptFuntionMap::Register;
        FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
        FunctionMap[PasswordPrompt] = &PromptFuntionMap::SetPassword;
        //FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
    }
//    static class _init
//    {
//    public:
//        _init()
//        {
//            //Initialize variables :: mapping
//            FunctionMap[LoginPrompt] = &PromptFuntionMap::Login;
//            FunctionMap[RegisterPrompt] = &PromptFuntionMap::Register;
//            FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
//            FunctionMap[PasswordPrompt] = &PromptFuntionMap::SetPassword;
//            //FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
//        }
//    } _initializer;
    
    inline const char* ToString(PromptValue p)
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
    //service a response to a specific prompt utilizing the prompt to function mapping
    inline void Service(PromptValue pv, Response* r)
    {
        prompt_func_map::iterator x = FunctionMap.find(pv);
        if (x != FunctionMap.end())
        {
            PromptFuntionMap m;
            (m.*(x->second))(r);
        }
    }
    
    PromptValue PromptOption(PromptValue option_one, PromptValue option_two)
    {
        std::string prompt;
        std::string option_one_s = PromptMap::ToString(option_one);
        std::string option_two_s = PromptMap::ToString(option_two);
        std::string userInput = "";
        do
        {
            prompt +=  option_one_s + " or " + option_two_s
            + " : (" + option_one_s + "/" + option_two_s + ")\n";
            std::cout << prompt;
            std::cin >> userInput;
        }
        while ( userInput != option_one_s && userInput != option_two_s);
        if(userInput == option_one_s)
        {
            return option_one;
            //std::cout << "Call to " << option_one_s << "\n";
            //PromptMap::Service(option_one, nullptr);
        }
        else
        {
            return option_two;
            //std::cout << "Call to " << option_two_s << "\n";
            //PromptMap::Service(option_two, nullptr);
        }
    }
    
    void PromptForValue(PromptValue value_one)
    {
        
    }
 
private:
    prompt_func_map FunctionMap;
};



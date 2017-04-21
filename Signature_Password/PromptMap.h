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
#include "UserAuthenticationData.h"
#include "UserSystemManager.h"
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
    bool success;
    UserAuthenticationData uad;
    PromptValue mRespondingToPrompt;
};


struct PromptFuntionMap
{
    void Login(Response &r)
    {
        std::cout << "Login Called\n";
        UserSystemManager::get().PrintUserAuthenticationData();
        std::cout << "Enter Username: ";
        std::string username;
        std::cin >> username;
        
        std::cout << "Enter Password: ";
        std::string password;
        std::cin >> password;
        
        UserAuthenticationData uad;
        uad.SetUsername(username);
        TimedSignature ts;
        uad.SetPassword(password, ts);
        while(!UserSystemManager::get().VerifyUserAuthenticationRequest(uad))
        {
            std::cout << "Invalid authentication request\n";
            std::cout << "Enter Username: ";
            std::string username;
            std::cin >> username;
            
            std::cout << "Enter Password: ";
            std::string password;
            std::cin >> password;
            uad.SetUsername(username);
            TimedSignature ts;
            uad.SetPassword(password, ts);
        }
        r.uad = uad;
    }
    
    void Register(Response &r)
    {
        std::cout << "Register Called\n";
        UserSystemManager::get().PrintUserAuthenticationData();
        std::cout << "Enter Username: ";
        std::string username;
        std::cin >> username;
        
        while(!UserSystemManager::get().VerifyUsernameAvailability(username))
        {
            std::cout << "Invalid registration request (USERNAME ALREADY IN USE)\n";
            std::cout << "Enter Username: ";
            std::cin >> username;
        }
        
        std::cout << "Enter Password: ";
        std::string password;
        std::cin >> password;
        
        UserAuthenticationData uad;
        uad.SetUsername(username);
        TimedSignature ts;
        uad.SetPassword(password, ts);
        r.uad = uad;
        UserSystemManager::get().RegisterUser(uad);
        UserSystemManager::get().PrintUserAuthenticationData();
        
    }
    
    void MeasurePassword(Response &r)
    {
        std::cout << "Measure Password called\n";
        std::cout << "Type your password as you normally would 10 times (hit enter between every entry)\nThis will be used to collect an averaged password signature for extra security\n";
        std::cout << "Data measurement for user: " << r.uad.GetUsername() << std::endl;
        
    }
    
    void SetUsername(Response &r)
    {
        std::cout << "SetUsername Called\n";
    }
    
    void SetPassword(Response &r)
    {
        std::cout << "SetUsername Called\n";
    }
};

typedef void (PromptFuntionMap::*prompt_method)(Response&);
typedef std::map<PromptValue, prompt_method> prompt_func_map;

class PromptMap
{
public:
    PromptMap()
    {
        FunctionMap[LoginPrompt] = &PromptFuntionMap::Login;
        FunctionMap[RegisterPrompt] = &PromptFuntionMap::Register;
        FunctionMap[UsernamePrompt] = &PromptFuntionMap::SetUsername;
        FunctionMap[PasswordPrompt] = &PromptFuntionMap::MeasurePassword;
    }
    
    inline const char* ToString(PromptValue p)
    {
        switch (p)
        {
            case LoginPrompt:   return "login";
            case RegisterPrompt:    return "register";
            case UsernamePrompt:    return "username";
            case PasswordPrompt:    return "password";
            default:    return "[Unknown PromptValue]";
        }
    }
    //service a response to a specific prompt utilizing the prompt to function mapping
    inline void Service(PromptValue pv, Response& r)
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
            prompt =  option_one_s + " or " + option_two_s
            + " : (" + option_one_s + "/" + option_two_s + ")\n";
            std::cout << prompt;
            std::cin >> userInput;
        }
        while ( userInput != option_one_s && userInput != option_two_s);
        if(userInput == option_one_s)
        {
            return option_one;
        }
        else
        {
            return option_two;
        }
    }
    
    void PromptForValue(PromptValue value_one)
    {
        
    }
 
private:
    prompt_func_map FunctionMap;
};



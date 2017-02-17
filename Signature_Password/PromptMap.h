//
//  PromptMap.h
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#include <Map>
#include <iostream>
enum PromptValue
{
    LoginPrompt,
    RegisterPrompt,
    UsernamePrompt,
    PasswordPrompt,
    PasswordRequeryPrompt,
    UsernameRequeryPrompt
};

struct PromptFuntionMap
{
    double sinFunc(double x) { return 0.33; };
    double cosFunc(double x) { return 0.66; };
};

typedef void (PromptFuntionMap::*prompt_method)(void);
typedef std::map<std::string, prompt_method> prompt_func_map;

class PromptMap
{
public:
    
inline const char* ToString(PromptValue p)
{
    switch (p)
    {
        case LoginPrompt:   return "Login";
        case RegisterPrompt:    return "Register";
        case UsernamePrompt:    return "Username";
        case PasswordPrompt:    return "Password";
        case PasswordRequeryPrompt: return "[Password Again";
        case UsernameRequeryPrompt: return "Username Again";
        default:    return "[Unknown PromptValue]";
    }
}
    
void Login()
{
    std::cout << "Login Called\n";
}
    
void Register()
{
    std::cout << "Register Called\n";
}
    
void SetUsername()
{
    std::cout << "SetUsername Called\n";
}
    
    
private:
    PromptMap();
//    std::map<PromptValue, std::string> m = {
//        {Login, "Login"},
//        {Register, "Register"},
//        {Username, "Username"},
//        {Password, "Password"}
//    };
    
};

//
//  UserInputHandler.h
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#pragma once
#include <curses.h>
#include "PromptMap.h"

enum InterfaceType
{
   terminal
};

class UserInputHandler
{
public:    
    // Start the curses terminal
    static void Start(InterfaceType it);
    static void PromptOption_LoginSignup()
    {
        PromptValue choice = mPromptMap -> PromptOption(LoginPrompt, RegisterPrompt);
        if(choice == LoginPrompt)
        {
            
        }
        else if(choice == RegisterPrompt)
        {
            
        }
    }
    
private:
    UserInputHandler();
    static PromptMap* mPromptMap;
    static InterfaceType mInterfaceType;
    
};

//
//  UserInputHandler.h
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#pragma once
//#include <curses.h>
#include "PromptMap.h"
#include "UserAuthenticationData.h"
enum InterfaceType
{
   terminal
};

class UserInputHandler
{
public:    
    // Start the curses terminal
    UserInputHandler(InterfaceType it) { mInterfaceType = it; };
    void Start();
    void PromptOption_LoginSignup()
    {
        Response response;
        PromptValue choice = mPromptMap -> PromptOption(LoginPrompt, RegisterPrompt);
        response.mRespondingToPrompt = choice;
        mPromptMap -> Service(choice, response);
        if(response.mRespondingToPrompt == RegisterPrompt)
        {
            response.mRespondingToPrompt = PasswordPrompt;
            mPromptMap -> Service(PasswordPrompt, response);
        }
    }
    
    
private:
    PromptMap* mPromptMap;
    InterfaceType mInterfaceType;
};

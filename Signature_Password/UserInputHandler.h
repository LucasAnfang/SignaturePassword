//
//  UserInputHandler.h
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#include <curses.h>
#include "PromptMap.h"

class UserInputHandler
{
public:
    
    // Start the curses terminal
    static void Start();
    
    // Prompt
    static void PromptOption(PromptValue option_one, PromptValue option_two);
    
    // Prompt for singular value
    static void PromptForValue(PromptValue value_one);
    
    
    
    
private:
    UserInputHandler();
    
};

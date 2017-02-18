//
//  UserInputHandler.cpp
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include "UserInputHandler.h"
#include "PromptMap.h"
void UserInputHandler::Start()
{
    //initscr();
    std::cout << "START\n";
}

void UserInputHandler::PromptOption(PromptValue option_one, PromptValue option_two)
{
    std::string prompt;
    std::string option_one_s = PromptMap::ToString(option_one);
    std::string option_two_s = PromptMap::ToString(option_two);
    std::string userInput = "";
    do
    {
        prompt +=  option_one_s + " or " + option_two_s
        + " : (" + option_one_s + "," + option_two_s + ")\n";
        std::cout << prompt;
        std::cin >> userInput;
    }
    while ( userInput != option_one_s && userInput != option_two_s);
    if(userInput == option_one_s)
    {
        std::cout << "Call to " << option_one_s << "\n";
    }
    else if(userInput == option_two_s)
    {
        std::cout << "Call to " << option_two_s << "\n";
    }
}

void UserInputHandler::PromptForValue(PromptValue value_one)
{
    
}

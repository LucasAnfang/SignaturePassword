//
//  UserInputHandler.cpp
//  Signature_Password
//
//  Created by luke anfang on 2/16/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include "UserInputHandler.h"
void UserInputHandler::Start(InterfaceType it)
{
    //initscr();
    mInterfaceType = it;
    mPromptMap = new PromptMap();
    std::cout << "START\n";
}


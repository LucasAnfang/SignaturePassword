//
//  UserSystemManager.cpp
//  Signature_Password
//
//  Created by luke anfang on 4/18/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include <stdio.h>
#include "UserSystemManager.h"

bool UserSystemManager::VerifyUserAuthenticationRequest(UserAthenticationData &uad)
{
    
    return false;
}

bool UserSystemManager::VerifyUsernameAvailability(UserAthenticationData& uad)
{
    
    return true;
}

void UserSystemManager::RegisterUser(UserAthenticationData& uad)
{
    
}

UserAthenticationData UserSystemManager::ConvertEntryToUserAuthenticationData(std::string& entry)
{
    UserAthenticationData uad;
    
    return uad;
}

//
//  UserSystemManager.h
//  Signature_Password
//
//  Created by luke anfang on 4/18/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#pragma once
#include "TimedSignature.h"
#include "Singleton.h"
#include "UserAuthenticationData.h"
#include <string>
#define DECLARE_SINGLETON(SingletonClass) friend class Singleton<SingletonClass>;
#define USERS_FILE "UserSys.txt"
class UserSystemManager : public Singleton<UserSystemManager>
{
public:
    bool VerifyUserAuthenticationRequest(UserAthenticationData& uad);
    bool VerifyUsernameAvailability(std::string& username);
    void RegisterUser(UserAthenticationData& uad);
    void PrintUserAuthenticationData();
    void ClearUserSys();
    
private:
    UserAthenticationData ConvertEntryToUserAuthenticationData(std::string& entry);
    std::string GetUsernameFromEntry(std::string& entry);
    
};


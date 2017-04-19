//
//  UserSystemManager.cpp
//  Signature_Password
//
//  Created by luke anfang on 4/18/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include <stdio.h>
#include "UserSystemManager.h"
#include <regex>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>

bool UserSystemManager::VerifyUserAuthenticationRequest(UserAthenticationData &uad)
{
    std::ifstream userFile(USERS_FILE);
    std::string entry;
    while (std::getline(userFile, entry))
    {
        std::cout << "Checking against Entry [" << entry << "]";
        UserAthenticationData entry_uad = ConvertEntryToUserAuthenticationData(entry);
        if(uad.GetUsername() == entry_uad.GetUsername() && uad.GetPasswordData().mPassword == entry_uad.GetPasswordData().mPassword)
        {
            std::cout << " PASSED\n";
            return true;
        }
        std::cout << " FAILED\n";
    }
    return false;
}



bool UserSystemManager::VerifyUsernameAvailability(std::string& username)
{
    std::string strippedUsername = std::regex_replace(username, std::regex("^ +| +$|( ) +"), "$1");
    if(username != strippedUsername)
    {
        std::cout << "Username contained space\n";
        return false;
    }
    
    std::ifstream userFile(USERS_FILE);
    std::string entry;
    
    while (std::getline(userFile, entry))
    {
        if(username == GetUsernameFromEntry(entry))
        {
            return false;
        }
    }
    
    return true;
}

void UserSystemManager::RegisterUser(UserAthenticationData& uad)
{
    std::string entry = "";
    entry += uad.GetUsername();
    entry += "#";
    entry += uad.GetPasswordData().mPassword;
    std::cout << "Entry: " << entry << " to file " << USERS_FILE << std::endl;
    std::ofstream log(USERS_FILE, std::ios_base::app | std::ios_base::out);
    log << entry << std::endl;
}

UserAthenticationData UserSystemManager::ConvertEntryToUserAuthenticationData(std::string& entry)
{
    //entry = entry.substr(0, entry.find(";", 0)); //strip the comment
    std::string username = entry.substr(0,entry.find('#'));
    std::string password = entry.substr(entry.find('#')+1,entry.length()-1);
    UserAthenticationData uad;
    TimedSignature ts;
    //Get Timed Signature from the entry
    uad.SetUsername(username);
    uad.SetPassword(password, ts);
    return uad;
}

std::string UserSystemManager::GetUsernameFromEntry(std::string& entry)
{
    return entry.substr(0,entry.find('#'));
}

void UserSystemManager::PrintUserAuthenticationData()
{
    std::ifstream userFile(USERS_FILE);
    std::string entry;
    while (std::getline(userFile, entry))
    {
        std::cout << entry << std::endl;
    }
    userFile.close();
}

void UserSystemManager::ClearUserSys()
{
    std::ofstream ofs;
    ofs.open(USERS_FILE, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

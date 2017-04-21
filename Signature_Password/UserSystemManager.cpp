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

bool UserSystemManager::VerifyUserAuthenticationRequest(UserAuthenticationData &uad)
{
    std::ifstream userFile(USERS_FILE);
    std::string entry;
    while (std::getline(userFile, entry))
    {
        std::cout << "Checking against Entry [" << entry << "]";
        UserAuthenticationData entry_uad = ConvertEntryToUserAuthenticationData(entry);
        if(uad.GetUsername() == entry_uad.GetUsername() && uad.GetPasswordData().mPassword == entry_uad.GetPasswordData().mPassword)
        {
            userFile.close();
            std::cout << " PASSED\n";
            return true;
        }
        std::cout << " FAILED\n";
    }
    userFile.close();
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
            userFile.close();
            return false;
        }
    }
    userFile.close();
    return true;
}

void UserSystemManager::RegisterUser(UserAuthenticationData& uad)
{
    std::string entry = "";
    entry += uad.GetUsername();
    entry += "#";
    entry += uad.GetPasswordData().mPassword;
    std::cout << "Entry: " << entry << " to file " << USERS_FILE << std::endl;
    std::ofstream userFile(USERS_FILE, std::ios_base::app | std::ios_base::out);
    userFile << entry << std::endl;
    userFile.close();
}

UserAuthenticationData UserSystemManager::ConvertEntryToUserAuthenticationData(std::string& entry)
{
    //entry = entry.substr(0, entry.find(";", 0)); //strip the comment
    std::string username = entry.substr(0,entry.find('#'));
    std::string password = entry.substr(entry.find('#')+1,entry.length()-1);
    UserAuthenticationData uad;
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
    std::cout << "============USERS============\n";
    while (std::getline(userFile, entry))
    {
        std::cout << entry << std::endl;
    }
    std::cout << "=============================\n";
    userFile.close();
}

void UserSystemManager::ClearUserSys()
{
    std::ofstream userFile;
    userFile.open(USERS_FILE, std::ofstream::out | std::ofstream::trunc);
    userFile.close();
}

//
//  UserAuthenticationData.h
//  Signature_Password
//
//  Created by luke anfang on 2/20/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#pragma once
#include "TimedSignature.h"
struct PasswordData
{
    std::string mPassword;
    TimedSignature mTimedSignature;
};
class UserAuthenticationData
{
public:
    UserAuthenticationData()
    {
        mRegistrationPasswordsSize = 0;
    }
    
    void SetUsername(std::string username)
    {
        mUsername = username;
    }
    
    std::string GetUsername()
    {
        return mUsername;
    }
    
    void SetPasswordData(PasswordData *passwordData)
    {
        mPassword = passwordData;
    }
    
    void SetPassword(std::string password, TimedSignature ts)
    {
        PasswordData* pd = new PasswordData();
        pd -> mPassword = password;
        pd -> mTimedSignature = ts;
        mPassword = pd;
    }
    
    void InsertRegistrationPassword(PasswordData ps){
        mRegistrationPasswords[++mRegistrationPasswordsSize] = ps;
        ++mRegistrationPasswordsSize;
    }
    
    void AverageRegistrationPasswords()
    {
        for(int i = 1; i <= mRegistrationPasswordsSize ; i++){
            //mRegistrationPasswords[i]
        }
    }
    
    PasswordData GetPasswordData()
    {
        return *mPassword;
    }
    
private:
    std::string mUsername;
    //this is the averaged password on register or the password on login
    PasswordData* mPassword;
    // this is the array of passwords on initial registration
    PasswordData mRegistrationPasswords [10];
    int mRegistrationPasswordsSize;
    
};

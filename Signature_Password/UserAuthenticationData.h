//
//  UserAuthenticationData.h
//  Signature_Password
//
//  Created by luke anfang on 2/20/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//
#include "TimedSignature.h"
struct PasswordData
{
    std::string mPassword;
    TimedSignature mTimedSignature;
};
class UserAthenticationData
{
public:
    UserAthenticationData();
    
    void SetUsername(std::string username)
    {
        mUsername = username;
    }
    
    std::string GetUsername()
    {
        return mUsername;
    }
    
    void SetPassword(PasswordData passwordData)
    {
        mPassword = passwordData;
    }
    
    void SetPassword(std::string password, TimedSignature ts)
    {
        PasswordData pd = new PasswordData();
        PasswordData.mPassword = password;
        PasswordData.mTimedSignature = ts;
        mPassword = pd;
    }
    
    void InsertRegistrationPassword(Password ps){
        mRegistrationPasswords.insert(ps);
    }
    
    void AverageRegistrationPasswords()
    {
        for(PasswordData pd : mRegistrationPasswords){
            
        }
    }
    
    
private:
    std::string mUsername;
    //this is the averaged password on register or the password on login
    PasswordData mPassword;
    // this is the array of passwords on initial registration
    PasswordData mRegistrationPasswords [10];
    
};

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUser.h"
#include "AdditionalMethods.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUser fileWithUser;

    void addNewUserToFile(User newUser);
    void loadUserFromFile();
    void changePasswordInFile(string newPassword);


public:
    UserManager(string fileWithUserName):fileWithUser(fileWithUserName)
    {
        loadUserFromFile();
    }
    void registerUser();
    int logIn();
    void changePassword();
    void logOut();
};


#endif

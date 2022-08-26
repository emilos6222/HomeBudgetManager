#ifndef FILEWITHUSER_H
#define FILEWITHUSER_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "User.h"

using namespace std;

class FileWithUser : public XmlFile
{
public:
    FileWithUser(string fileWithUserName):XmlFile(fileWithUserName)
    {}
    void addUser(User newUser);
    void loadUsers(vector <User> &users);
    void changePasswordInFile(string newPassword, int loggedUserId);
};


#endif

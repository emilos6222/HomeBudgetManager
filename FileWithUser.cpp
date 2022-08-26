#include "FileWithUser.h"

void FileWithUser::addUser(User newUser)
{
    CMarkup xmlFileWithUsers;

    if(!xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileWithUsers.AddElem("Users");
    }

    xmlFileWithUsers.FindElem();
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("User");
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("userId", newUser.getUserId());
    xmlFileWithUsers.AddElem("login", newUser.getLogin());
    xmlFileWithUsers.AddElem("password", newUser.getPassword());
    xmlFileWithUsers.AddElem("name", newUser.getName());
    xmlFileWithUsers.AddElem("surname", newUser.getSurname());

    xmlFileWithUsers.Save(FILE_NAME);
}

void FileWithUser::loadUsers(vector <User> &user)
{
    CMarkup xmlFileWithUsers;
    User tempUser;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Users

        while(xmlFileWithUsers.FindElem("User"))
        {
            xmlFileWithUsers.IntoElem(); //each User
            xmlFileWithUsers.FindElem("userId");
            tempUser.setUserId(stoi(xmlFileWithUsers.GetData()));
            xmlFileWithUsers.FindElem("login");
            tempUser.setLogin(xmlFileWithUsers.GetData());
            xmlFileWithUsers.FindElem("password");
            tempUser.setPassword(xmlFileWithUsers.GetData());
            xmlFileWithUsers.FindElem("name");
            tempUser.setName(xmlFileWithUsers.GetData());
            xmlFileWithUsers.FindElem("surname");
            tempUser.setSurname(xmlFileWithUsers.GetData());
            xmlFileWithUsers.OutOfElem();

            user.push_back(tempUser);
        }
    }
}

void FileWithUser::changePasswordInFile(string newPassword, int loggedUserId)
{
    CMarkup xmlFileWithUsers;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Users

        while(xmlFileWithUsers.FindElem("User"))
        {
            xmlFileWithUsers.IntoElem();
            xmlFileWithUsers.FindElem("userId");

            if(stoi(xmlFileWithUsers.GetData()) == loggedUserId)
            {
                xmlFileWithUsers.FindElem("password");
                xmlFileWithUsers.RemoveElem();
                xmlFileWithUsers.AddElem("password", newPassword);
                xmlFileWithUsers.Save(FILE_NAME);

                return;
            }
            xmlFileWithUsers.OutOfElem();
        }
        system("cls");
        cout << "Something went wrong. You did not change password"<< endl <<endl;
        system("pause");
    }
}

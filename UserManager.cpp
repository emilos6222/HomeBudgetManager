#include "UserManager.h"

void UserManager::registerUser()
{
    User tempUser;
    string tempData = "";

    if(users.empty() == 1)
        tempUser.setUserId(1);
    else
    {
        tempUser.setUserId(users.back().getUserId()+1);
    }

    system("cls");
    cout << "Insert Your name: "<<endl;
    cin >> tempData;
    tempData = AdditionalMethods::toUpperFirstLetter(tempData);
    tempUser.setName(tempData);
    system("cls");
    cout << "Insert Your surname: "<<endl;
    cin >> tempData;
    tempData = AdditionalMethods::toUpperFirstLetter(tempData);
    tempUser.setSurname(tempData);
    system("cls");
    cout << "Insert Your login: "<<endl;
    cin >> tempData;
    tempUser.setLogin(tempData);
    system("cls");
    cout << "Insert Your password: "<<endl;
    cin >> tempData;
    tempUser.setPassword(tempData);

    users.push_back(tempUser);

    addNewUserToFile(tempUser);

}

void UserManager::addNewUserToFile(User newUser)
{
    fileWithUser.addUser(newUser);
}

void UserManager::loadUserFromFile()
{
    fileWithUser.loadUsers(users);
}

int UserManager::logIn()
{
    string tempLogin = "", tempPassword = "";
    int timesOfImputThePassowrd = 3;

    system("cls");
    cout << "Insert your login: ";
    cin >> tempLogin;

    for(unsigned int i = 0; i < users.size(); i++)
    {
        if(tempLogin == users[i].getLogin())
        {
            for(int j = 0; j < timesOfImputThePassowrd; timesOfImputThePassowrd--)
            {
                system("cls");
                cout << "Insert password. You have only "<<timesOfImputThePassowrd<<" tries: ";
                cin >> tempPassword;
                getchar(); //it prevent from showing that "there is too many letters"

                if(tempPassword == users[i].getPassword())
                {
                    loggedUserId = users[i].getUserId();

                    system("cls");
                    cout << "You have been logged in."<<endl<<endl;
                    system("pause");

                    return loggedUserId;
                }

                if(timesOfImputThePassowrd == 1)
                {
                    system("cls");
                    cout << "You have made too many mistakes during logging."<<endl<<endl;
                    system("pause");
                    return 0;
                }
            }
        }
    }

    system("cls");
    cout << "The user with that login does not exist."<<endl<<endl;
    system("pause");

    return 0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    string oldPassword = "";

    system("cls");
    cout << "Insert old password: ";
    getline(cin, oldPassword);

    for(unsigned int i = 0; i < users.size() ; i++)
    {
        if(loggedUserId == users[i].getUserId())
        {
            if(users[i].getPassword() == oldPassword)
            {
                system("cls");
                cout << "Insert new password: ";
                getline(cin, newPassword);

                users[i].setPassword(newPassword);
                changePasswordInFile(newPassword);

                system("cls");
                cout << "You have changed password"<<endl<<endl;
                system("pause");
                return;
            }
            else
            {
                system("cls");
                cout << "You have insert wrong password."<<endl<<endl;
                system("pause");
                return;
            }
        }
    }

    system("cls");
    cout << "Something went wrong. You did not change password."<<endl<<endl;
    system("pause");
}

void UserManager::changePasswordInFile(string newPassword)
{
    fileWithUser.changePasswordInFile(newPassword, loggedUserId);
}

void UserManager::logOut()
{
    loggedUserId = 0;
}

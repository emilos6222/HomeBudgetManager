#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AdditionalMethods.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string FILE_WITH_EXPENSES_NAME;
    const string FILE_WITH_INCOMES_NAME;

    void showUserMenu();
    void chooseFromUserMenu();
    void registerUser();
    void showAllUsers();
    void logIn();
    void chooseFromBudgetMainMenu();
    void showBudgetMainMenu();
    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForLastMonth();
    void showBalanceForDefiniedPeriod();
    void changePassword();
    void logOut();

public:
    HomeBudget(string fileWithUserName, string fileWithExpensesName, string fileWithIncomesName)
    :userManager(fileWithUserName),FILE_WITH_EXPENSES_NAME(fileWithExpensesName), FILE_WITH_INCOMES_NAME(fileWithIncomesName)
    {
        budgetManager = NULL;
        chooseFromUserMenu();
    }

    ~HomeBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    }
};

#endif

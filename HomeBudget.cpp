#include "HomeBudget.h"

void HomeBudget::chooseFromUserMenu()
{
    char choice = '0';

    while(1)
    {
        showUserMenu();
        choice = AdditionalMethods::getOneChar();

        switch(choice)
        {
        case '1':
            registerUser();
            getchar(); //it prevent from showing that "there is too many letters"
            break;
        case '2':
            logIn();
            break;
        case '3':
            system("cls");
            cout << "Goodbye!!!"<<endl;
            exit(0);
            break;
        default:
            cout<<"You put wrong option."<<endl;
            system("pause");
        }
    }

}

void HomeBudget::showUserMenu()
{
    system("cls");
    cout << "------ YOUR BUDGET MANAGER ------"<<endl<< endl;
    cout << "    Choose one option:"<<endl<<endl;
    cout << "    1 - User registration"<<endl;
    cout << "    2 - User log in"<<endl;
    cout << "    3 - Exit"<<endl;
    cout <<endl<< "Your choice: ";
}

void HomeBudget::registerUser()
{
    userManager.registerUser();
}

void HomeBudget::logIn()
{
    int currentUserId = 0;
    currentUserId = userManager.logIn();

    if(currentUserId != 0)
    {
        budgetManager = new BudgetManager(FILE_WITH_EXPENSES_NAME, FILE_WITH_INCOMES_NAME, currentUserId);
        chooseFromBudgetMainMenu();
    }

}

void HomeBudget::chooseFromBudgetMainMenu()
{
    char choice = '0';
    int exitFromBudgetMenu = 0;

    while(exitFromBudgetMenu == 0)
    {
        showBudgetMainMenu();
        choice = AdditionalMethods::getOneChar();

        switch(choice)
        {
        case '1':
            addIncome();
            getchar(); //getting char otherwise is shows "you put wrong char"
            break;
        case '2':
            addExpense();
            getchar(); //getting char otherwise is shows "you put wrong char"
            break;
        case '3':
            showBalanceForCurrentMonth();
            break;
        case '4':
            showBalanceForLastMonth();
            break;
        case '5':
            showBalanceForDefiniedPeriod();
            break;
        case '6':
            changePassword();
            break;
        case '7':
            logOut();
            exitFromBudgetMenu = 1;
            break;
        default:
            cout<<"You put wrong option."<<endl;
            system("pause");
        }
    }
}

void HomeBudget::showBudgetMainMenu()
{
    system("cls");
    cout << "------ YOUR BUDGET MANAGER ------"<<endl<< endl;
    cout << "    Choose one option:"<<endl<<endl;
    cout << "    1 - Add income"<<endl;
    cout << "    2 - Add expense"<<endl;
    cout << "    3 - Show balance for current month"<<endl;
    cout << "    4 - Show balance for last month"<<endl;
    cout << "    5 - Show balance for defined period"<<endl;
    cout << "    6 - Change password"<<endl;
    cout << "    7 - Log out"<<endl;
    cout <<endl<< "Your choice: ";
}

void HomeBudget::addIncome()
{
    budgetManager -> addIncome();
}

void HomeBudget::addExpense()
{
    budgetManager -> addExpense();
}

void HomeBudget::showBalanceForCurrentMonth()
{
    budgetManager -> showBalanceForCurrentMonth();
}

void HomeBudget::showBalanceForLastMonth()
{
    budgetManager -> showBalanceForLastMonth();
}

void HomeBudget::showBalanceForDefiniedPeriod()
{
    budgetManager -> showBalanceForDefiniedPeriod();
}

void HomeBudget::changePassword()
{
    userManager.changePassword();
}

void HomeBudget::logOut()
{
    userManager.logOut();
    delete budgetManager;
    budgetManager = NULL;
}

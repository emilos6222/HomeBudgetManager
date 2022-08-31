#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Income tempIncome;
    char yesOrNoAnswer = 'n';
    string incomeKind = "";
    double incomeAmount = 0;

    system("cls");
    cout << "Does the income have todays date? Insert 'y' if yes or another one char if no."<<endl;
    cout << "Your answer: ";
    yesOrNoAnswer = AdditionalMethods::getOneChar();

    if(yesOrNoAnswer == 'y')
    {
        tempIncome.setDate(Date::getTodayDate());
    }
    else
    {
        tempIncome.setDate(Date::chooseDateYouWant());
        getchar();//to not take /n
    }


    system("cls");
    cout << "Insert the kind of income: "<< endl;
    getline(cin, incomeKind);
    tempIncome.setItem(incomeKind);

    incomeAmount = insertAmount();

    tempIncome.setAmount(incomeAmount);
    tempIncome.setIncomeId(getLastIncomeId());
    tempIncome.setUserId(USER_ID);

    incomes.push_back(tempIncome);
    saveIncomeInFile(tempIncome);
}

int BudgetManager::getLastIncomeId()
{
    int lastIncomeId = 0;
    lastIncomeId = fileWithIncomes.getLastId();

    return (lastIncomeId + 1);
}

void BudgetManager::saveIncomeInFile(Income incomeToSaveInFile)
{
    fileWithIncomes.saveIncomeInFile(incomeToSaveInFile);
}

void BudgetManager::loadIncomes()
{
    fileWithIncomes.loadIncomes(incomes, USER_ID);
}

void BudgetManager::addExpense()
{
    Expense tempExpense;
    char yesOrNoAnswer = 'n';
    string expenseKind = "";
    double expenseAmount = 0;

    system("cls");
    cout << "Does the expense have todays date? Insert 'y' if yes or another one char if no."<<endl;
    cout << "Your answer: ";
    yesOrNoAnswer = AdditionalMethods::getOneChar();

    if(yesOrNoAnswer == 'y')
    {
        tempExpense.setDate(Date::getTodayDate());
    }
    else
    {
        tempExpense.setDate(Date::chooseDateYouWant());
        getchar();//to not take /n
    }


    system("cls");
    cout << "Insert the kind of expense: "<< endl;
    getline(cin, expenseKind);
    tempExpense.setItem(expenseKind);

    expenseAmount = insertAmount();

    tempExpense.setAmount(expenseAmount);
    tempExpense.setExpenseId(getLastExpenseId());
    tempExpense.setUserId(USER_ID);

    expenses.push_back(tempExpense);
    saveExpenseInFile(tempExpense);
}

int BudgetManager::getLastExpenseId()
{
    int lastExpenseId = 0;
    lastExpenseId = fileWithExpenses.getLastId();

    return (lastExpenseId + 1);
}

void BudgetManager::saveExpenseInFile(Expense expenseToSaveInFile)
{
    fileWithExpenses.saveExpenseInFile(expenseToSaveInFile);
}

void BudgetManager::loadExpenses()
{
    fileWithExpenses.loadExpenses(expenses, USER_ID);
}

void BudgetManager::showBalanceForCurrentMonth()
{
    int currentDate = 0;
    double sumOfIncomes = 0;
    double sumOfExpenses =0;
    vector <Fund *> pointersToFunds;

    system("cls");
    cout << "--------- Balance for current month ---------"<<endl<<endl;

    currentDate = Date::getCurrentDate();

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if((incomes[i].getDate()/100) == (currentDate/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                INCOMES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no incomes during period."<<endl<<endl;


    pointersToFunds.clear();
    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if((expenses[i].getDate()/100) == (currentDate/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                EXPENSES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no expenses during period."<<endl<<endl;

    showBalanceOnScreen(sumOfIncomes, sumOfExpenses );
}

void BudgetManager::showBalanceForLastMonth()
{
    int dateFromLastMonth = 0;
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    vector <Fund *> pointersToFunds;

    system("cls");
    cout << "--------- Balance for last month ---------"<<endl<<endl;

    dateFromLastMonth = Date::getDateFromLastMonth();
    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if((incomes[i].getDate()/100) == (dateFromLastMonth/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                INCOMES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no incomes during period."<<endl<<endl;


    pointersToFunds.clear();
    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if((expenses[i].getDate()/100) == (dateFromLastMonth/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                EXPENSES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no expenses during period."<<endl<<endl;

    showBalanceOnScreen(sumOfIncomes, sumOfExpenses );
}

void BudgetManager::showBalanceForDefiniedPeriod()
{
    int firstDate = 0;
    int lastDate = 0;
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    vector <Fund *> pointersToFunds;

    system("cls");
    cout << "Insert date from when you want check balance."<<endl;
    system("pause");
    firstDate = Date::chooseDateYouWant();

    cout << "Insert date to when you want check balance."<<endl;
    system("pause");
    lastDate = Date::chooseDateYouWant();

    if(firstDate > lastDate)
    {
        system("cls");
        cout<<"First date must be earlier (or equal) than second date"<<endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "--------- Balance for period "<< firstDate/10000 << "-" << setfill('0') << setw(2)<< (firstDate/100)%100 << "-" << setw(2)<< firstDate%100;
    cout << " to "<< lastDate/10000 << "-" << setfill('0') << setw(2) << (lastDate/100)%100 << "-" << setw(2) <<  lastDate%100 << " ---------"<<endl<<endl;

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= firstDate && incomes[i].getDate() <= lastDate) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                INCOMES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no incomes during period."<<endl<<endl;

    pointersToFunds.clear();
    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= firstDate && expenses[i].getDate() <= lastDate) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            pointersToFunds.push_back(&expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    sort(pointersToFunds.begin(), pointersToFunds.end(), [](Fund* a, Fund* b) {return a->getDate() < b->getDate();});
    cout<< "                EXPENSES"<<endl<<endl;
    if(!pointersToFunds.empty())
        showFundsInTable(pointersToFunds);
    else
        cout<< "You have no expenses during period."<<endl<<endl;

    showBalanceOnScreen(sumOfIncomes, sumOfExpenses );
}

void BudgetManager::showBalanceOnScreen(double sumOfIncomes, double sumOfExpenses)
{
    cout <<endl << "                SUMMARY" <<endl<<endl;
    cout << "      The sum of incomes:   " <<setprecision (2) << fixed <<sumOfIncomes << endl;
    cout << "      The sum of expenses:  " <<setprecision (2) << fixed <<sumOfExpenses << endl;
    cout << "      Balance for period:   " << setprecision (2) << fixed << sumOfIncomes - sumOfExpenses << endl << endl;
    system("pause");
}

double BudgetManager::insertAmount()
{
    string amount = "";
    int oneDot = 0;
    int outFromLoop = 0;

    while(outFromLoop == 0)
    {
        oneDot = 0;
        system("cls");
        cout << "Insert amount: "<< endl;
        cin >> amount;

        for(unsigned int i = 0; i < amount.size(); i++)
        {
            if(amount[i] >= '0' && amount[i] <= '9')
            {
                outFromLoop = 1;
            }
            else if((amount[i] == '.' || amount[i] == ',') && oneDot == 0)
            {
                amount[i] = '.';
                oneDot = 1;
            }
            else
            {
                outFromLoop = 0;
                system("cls");
                cout << "You have put wrong format of amount. Try again"<< endl<<endl;
                system("pause");
                break;
            }
        }
    }

    return stod(amount);
}

void BudgetManager::showBorderInTable(int longestItemWord, int longestAmountWord)
{
    cout << "   +-";
    for( int j = 0; j < longestItemWord; j++)
        cout<<"-";
    cout<<"-";

    cout << "+-";
    for( int j = 0; j < longestAmountWord-4; j++)
        cout<<"-";
    cout<<"-";

    cout << "+-";
    for( int j = 0; j < 10; j++)
        cout<<"-";
    cout<<"-+"<<endl;
}

void BudgetManager::showFundsInTable(vector <Fund*> fundsForPeriod)
{
    unsigned int longestItemWord = 0;
    unsigned int longestAmountWord = 0;
    string amountAsString = "";

    for(unsigned int i = 0; i < fundsForPeriod.size(); i++)
    {
        if(fundsForPeriod[i]->getItem().size() > longestItemWord)
            longestItemWord = fundsForPeriod[i]->getItem().size();

        if(to_string(fundsForPeriod[i]->getAmount()).size() > longestAmountWord)
        {
            amountAsString = to_string(fundsForPeriod[i]->getAmount());
            longestAmountWord = amountAsString.size();
        }
    }

    for(unsigned int i = 0; i < fundsForPeriod.size(); i++)
    {
        showBorderInTable(longestItemWord, longestAmountWord);

        cout << "   | "<<fundsForPeriod[i]->getItem();
        for(unsigned int j =0; j < longestItemWord - fundsForPeriod[i]->getItem().size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << setprecision (2) << fixed <<fundsForPeriod[i]->getAmount();
        for(unsigned int j =0; j < longestAmountWord - to_string(fundsForPeriod[i]->getAmount()).size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << AdditionalMethods::addDashesInDate(fundsForPeriod[i]->getDate())<<" |"<<endl;
    }

    showBorderInTable(longestItemWord, longestAmountWord);
    cout <<endl<<endl;
}


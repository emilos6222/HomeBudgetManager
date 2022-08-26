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
        tempIncome.setDate(getTodayDate());
    }
    else
    {
        tempIncome.setDate(chooseDateYouWant());
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

int BudgetManager::getTodayDate()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    fullDate = fullDate + (1900 + lTm->tm_year)*10000;
    fullDate = fullDate + (1+lTm->tm_mon)*100;
    fullDate = fullDate + (lTm->tm_mday);

    return fullDate;
}

int BudgetManager::chooseDateYouWant()
{
    string date = "";

    system("cls");
    cout << "Insert date in this format 'YYYY-MM-DD'."<<endl;
    cout << "Your date: ";
    cin >> date;

    while(!checkDate(date))
    {
        system("cls");
        cout << "Insert date in this format 'YYYY-MM-DD'."<<endl;
        cout << "Your date: ";
        cin >> date;
    }

    return dateStringToInt(date);
}

bool BudgetManager::checkDate(string date)
{
    int year = 0, month = 0, day = 0;
    int daysInMonth = 0;
    int currentDate = 0, currentMonth = 0, currentYear = 0;

    currentDate = getTodayDate();
    currentMonth = (currentDate/100)%100;
    currentYear = currentDate/10000;


    if(date[4] != '-' || date[7] != '-' || date.size() != 10)
    {
        cout << "You insert wrong format of date. Try again."<<endl;
        system("pause");
        return false;
    }
    else
    {
        date = date.erase(4,1);
        date = date.erase(6,1);
    }

    for(unsigned int i= 0; i < date.size(); i++)
    {
        if(date[i] < '0' || date[i] > '9')
        {
            cout << "Make sure you have put figures. Try again."<<endl;
            system("pause");
            return false;
        }

    }

    year = stoi(date.substr(0,4));
    month = stoi(date.substr(4,2));
    day = stoi(date.substr(6,2));
    daysInMonth = checkDaysInMonth(month, year);

    if(year<2000 || year>currentYear || month<1 || month>12 || day<1 || day>daysInMonth || (year==currentYear && month>currentMonth))
    {
        cout << "You have put figures that are outside the date range. Date must be set in range from 2000-01-01 to last day current month."<<endl<<endl;
        system("pause");
        return false;
    }

    return true;

}

int BudgetManager::checkDaysInMonth(int month, int year)
{
    int daysInMonth = 0;

    if(month == 2)
    {
        if(year%4 == 0)
        {
            if(year%100 != 0 )
                daysInMonth = 29;
            else if(year%400 == 0)
                daysInMonth = 29;
            else
                daysInMonth = 28;
        }
        else
            daysInMonth = 28;

        return daysInMonth;
    }

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        daysInMonth = 31;
    else
        daysInMonth = 30;

    return daysInMonth;
}

int BudgetManager::dateStringToInt(string date)
{
    int dateAsInt = 0;

    date = date.erase(4,1);
    date = date.erase(6,1);

    dateAsInt = stoi(date);

    return dateAsInt;
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
        tempExpense.setDate(getTodayDate());
    }
    else
    {
        tempExpense.setDate(chooseDateYouWant());
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
    vector <Income> incomesFromCurrentMonth;
    vector <Expense> expensesFromCurrentMonth;

    currentDate = getCurrentDate();

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if((incomes[i].getDate()/100) == (currentDate/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            incomesFromCurrentMonth.push_back(incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }

    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if((expenses[i].getDate()/100) == (currentDate/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            expensesFromCurrentMonth.push_back(expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }

    sort(incomesFromCurrentMonth.begin(), incomesFromCurrentMonth.end(), [](Income& a, Income& b) {return a.getDate() < b.getDate();});
    sort(expensesFromCurrentMonth.begin(), expensesFromCurrentMonth.end(), [](Expense& a, Expense& b) {return a.getDate() < b.getDate();});


    system("cls");
    cout << "--------- Balance for current month ---------"<<endl<<endl;
    showIncomesInTable(incomesFromCurrentMonth);
    showExpensesInTable(expensesFromCurrentMonth);
    showBalanceOnScreen(sumOfIncomes, sumOfExpenses );
}

int BudgetManager::getCurrentDate()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    fullDate = fullDate + (1900 + lTm->tm_year)*10000;
    fullDate = fullDate + (1+lTm->tm_mon)*100;
    fullDate = fullDate + (lTm->tm_mday);

    return fullDate;
}

void BudgetManager::showBalanceForLastMonth()
{
    int dateFromLastMonth = 0;
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    vector <Income> incomesForLastMonth;
    vector <Expense> expensesForLastMonth;

    dateFromLastMonth = getDateFromLastMonth();

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if((incomes[i].getDate()/100) == (dateFromLastMonth/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            incomesForLastMonth.push_back(incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }

    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if((expenses[i].getDate()/100) == (dateFromLastMonth/100)) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            expensesForLastMonth.push_back(expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }

    sort(incomesForLastMonth.begin(), incomesForLastMonth.end(), [](Income& a, Income& b) {return a.getDate() < b.getDate();});
    sort(expensesForLastMonth.begin(), expensesForLastMonth.end(), [](Expense& a, Expense& b) {return a.getDate() < b.getDate();});

    system("cls");
    cout << "--------- Balance for last month ---------"<<endl<<endl;

    showIncomesInTable(incomesForLastMonth);
    showExpensesInTable(expensesForLastMonth);
    showBalanceOnScreen(sumOfIncomes, sumOfExpenses );
}

int BudgetManager::getDateFromLastMonth()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    if((1+lTm->tm_mon) == 1)
    {
        fullDate = fullDate + (1900 + lTm->tm_year - 1)*10000;
        fullDate = fullDate + 12*100;
        fullDate = fullDate + (lTm->tm_mday);
    }
    else
    {
        fullDate = fullDate + (1900 + lTm->tm_year)*10000;
        fullDate = fullDate + (1+lTm->tm_mon - 1)*100;
        fullDate = fullDate + (lTm->tm_mday);
    }

    return fullDate;

}

void BudgetManager::showBalanceForDefiniedPeriod()
{
    int firstDate = 0;
    int lastDate = 0;
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    vector <Income> incomesForPeriod;
    vector <Expense> expensesForPeriod;

    system("cls");
    cout << "Insert date from when you want check balance."<<endl;
    system("pause");
    firstDate = chooseDateYouWant();

    cout << "Insert date to when you want check balance."<<endl;
    system("pause");
    lastDate = chooseDateYouWant();

    if(firstDate > lastDate)
    {
        system("cls");
        cout<<"First date must be earlier (or equal) than second date"<<endl;
        system("pause");
        return;
    }

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= firstDate && incomes[i].getDate() <= lastDate) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            incomesForPeriod.push_back(incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }

    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= firstDate && expenses[i].getDate() <= lastDate) //int, wiec po podzieleniu tracimy reszte z dzielenia
        {
            expensesForPeriod.push_back(expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }

    sort(incomesForPeriod.begin(), incomesForPeriod.end(), [](Income& a, Income& b) {return a.getDate() < b.getDate();});
    sort(expensesForPeriod.begin(), expensesForPeriod.end(), [](Expense& a, Expense& b) {return a.getDate() < b.getDate();});

    system("cls");
    cout << "--------- Balance for period "<< firstDate/10000 << "-" << setfill('0') << setw(2)<< (firstDate/100)%100 << "-" << setw(2)<< firstDate%100;
    cout << " to "<< lastDate/10000 << "-" << setfill('0') << setw(2) << (lastDate/100)%100 << "-" << setw(2) <<  lastDate%100 << " ---------"<<endl<<endl;
    showIncomesInTable(incomesForPeriod);
    showExpensesInTable(expensesForPeriod);
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

void BudgetManager::showIncomesInTable(vector <Income> incomesForPeriod)
{
    int longestItemWord = 0;
    int longestAmountWord = 0;
    string amountAsString = "";

    for(unsigned int i = 0; i < incomesForPeriod.size(); i++)
    {
        if(incomesForPeriod[i].getItem().size() > longestItemWord)
            longestItemWord = incomesForPeriod[i].getItem().size();

        if(to_string(incomesForPeriod[i].getAmount()).size() > longestAmountWord)
        {
            amountAsString = to_string(incomesForPeriod[i].getAmount());
            longestAmountWord = amountAsString.size();
        }
    }


    cout<< "                INCOMES"<<endl<<endl;
    for(unsigned int i = 0; i < incomesForPeriod.size(); i++)
    {
        showBorderInTable(longestItemWord, longestAmountWord);

        cout << "   | "<<incomesForPeriod[i].getItem();
        for(int j =0; j < longestItemWord - incomesForPeriod[i].getItem().size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << setprecision (2) << fixed << incomesForPeriod[i].getAmount();
        for(int j =0; j < longestAmountWord - to_string(incomesForPeriod[i].getAmount()).size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << AdditionalMethods::addDashesInDate(incomesForPeriod[i].getDate())<<" |"<<endl;
    }

    showBorderInTable(longestItemWord, longestAmountWord);
    cout <<endl<<endl;
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

void BudgetManager::showExpensesInTable(vector <Expense> expensesForPeriod)
{
    int longestItemWord = 0;
    int longestAmountWord = 0;
    string amountAsString = "";

    for(unsigned int i = 0; i < expensesForPeriod.size(); i++)
    {
        if(expensesForPeriod[i].getItem().size() > longestItemWord)
            longestItemWord = expensesForPeriod[i].getItem().size();

        if(to_string(expensesForPeriod[i].getAmount()).size() > longestAmountWord)
        {
            amountAsString = to_string(expensesForPeriod[i].getAmount());
            longestAmountWord = amountAsString.size();
        }
    }

    cout<< "                EXPENSES"<<endl<<endl;
    for(unsigned int i = 0; i < expensesForPeriod.size(); i++)
    {
        showBorderInTable(longestItemWord, longestAmountWord);

        cout << "   | "<<expensesForPeriod[i].getItem();
        for(int j =0; j < longestItemWord - expensesForPeriod[i].getItem().size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << setprecision (2) << fixed <<expensesForPeriod[i].getAmount();
        for(int j =0; j < longestAmountWord - to_string(expensesForPeriod[i].getAmount()).size(); j++)
            cout <<" ";
        cout <<" | ";

        cout << AdditionalMethods::addDashesInDate(expensesForPeriod[i].getDate())<<" |"<<endl;
    }

    showBorderInTable(longestItemWord, longestAmountWord);
    cout <<endl<<endl;
}

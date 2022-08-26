#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "AdditionalMethods.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class BudgetManager
{
    const int USER_ID;
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    vector <Income> incomes;
    vector <Expense> expenses;

    int getTodayDate();
    int chooseDateYouWant();
    bool checkDate(string date);
    int checkDaysInMonth(int month, int year);
    int dateStringToInt(string date);
    int getLastIncomeId();
    void saveIncomeInFile(Income incomeToSaveInFile);
    void loadIncomes();
    int getLastExpenseId();
    void saveExpenseInFile(Expense expenseToSaveInFile);
    void loadExpenses();
    int getCurrentDate();
    int getDateFromLastMonth();
    void showBalanceOnScreen(double sumOfIncomes, double sumOfExpenses);
    double insertAmount();
    void showIncomesInTable(vector <Income> incomesForPeriod);
    void showExpensesInTable(vector <Expense> expensesForPeriod);
    void showBorderInTable(int longestItemWord, int longestAmountWord);

public:
    BudgetManager(string fileWithExpensesName, string fileWithIncomesName, int userId)
    :fileWithExpenses(fileWithExpensesName), fileWithIncomes(fileWithIncomesName), USER_ID(userId)
    {
        loadIncomes();
        loadExpenses();
    }
    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForLastMonth();
    void showBalanceForDefiniedPeriod();
};

#endif

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
#include "Date.h"
#include "Fund.h"

using namespace std;

class BudgetManager
{
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    vector <Income> incomes;
    vector <Expense> expenses;
    const int USER_ID;

    int getLastIncomeId();
    void saveIncomeInFile(Income incomeToSaveInFile);
    void loadIncomes();
    int getLastExpenseId();
    void saveExpenseInFile(Expense expenseToSaveInFile);
    void loadExpenses();
    void showBalanceOnScreen(double sumOfIncomes, double sumOfExpenses);
    double insertAmount();
    void showBorderInTable(int longestItemWord, int longestAmountWord);
    void showFundsInTable(vector <Fund*> fundsForPeriod);

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

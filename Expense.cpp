#include "Expense.h"


int Expense::getExpenseId()
{
    return expenseId;
}

int Expense::getUserId()
{
    return userId;
}

int Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

double Expense::getAmount()
{
    return amount;
}


void Expense::setExpenseId(int expenseId)
{
    this -> expenseId = expenseId;
}

void Expense::setUserId(int userId)
{
    this -> userId = userId;
}

void Expense::setDate(int date)
{
    this -> date = date;
}

void Expense::setItem(string item)
{
    this -> item = item;
}

void Expense::setAmount(double amount)
{
    this -> amount = amount;
}

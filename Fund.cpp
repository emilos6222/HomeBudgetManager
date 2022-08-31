#include "Fund.h"

int Fund::getUserId()
{
    return userId;
}

int Fund::getDate()
{
    return date;
}

string Fund::getItem()
{
    return item;
}

double Fund::getAmount()
{
    return amount;
}

void Fund::setUserId(int userId)
{
    this -> userId = userId;
}

void Fund::setDate(int date)
{
    this -> date = date;
}

void Fund::setItem(string item)
{
    this -> item = item;
}

void Fund::setAmount(double amount)
{
    this -> amount = amount;
}

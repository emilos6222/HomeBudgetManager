#include <iostream>
#include "HomeBudget.h"

using namespace std;

int main()
{
    HomeBudget homeBudget("users.xml", "expenses.xml", "incomes.xml");
    return 0;
}

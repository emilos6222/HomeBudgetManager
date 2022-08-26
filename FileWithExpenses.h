#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>

#include "XmlFile.h"
#include "Expense.h"

using namespace std;

class FileWithExpenses : public XmlFile
{

public:
    FileWithExpenses(string fileName):XmlFile(fileName)
    {}
    void saveExpenseInFile(Expense expenseToAdd);
    void loadExpenses(vector <Expense> &expenses, const int USER_ID);
    int getLastId();
};

#endif

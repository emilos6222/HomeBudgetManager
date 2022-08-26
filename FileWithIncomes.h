#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <string>

#include <bits/stdc++.h>
#include <algorithm>

#include "XmlFile.h"
#include "Income.h"



using namespace std;

class FileWithIncomes : public XmlFile
{
public:
    FileWithIncomes(string fileName):XmlFile(fileName)
    {}
    void saveIncomeInFile(Income incomeToAdd);
    void loadIncomes(vector <Income> &incomes, const int USER_ID);
    int getLastId();
};


#endif

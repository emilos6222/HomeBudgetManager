#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <string>

#include "Fund.h"

using namespace std;

class Income : public Fund
{
    int incomeId;

public:
    int getIncomeId();
    void setIncomeId(int incomeId);

};

#endif

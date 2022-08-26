#include "FileWithIncomes.h"

void FileWithIncomes::saveIncomeInFile(Income incomeToAdd)
{
    CMarkup xmlFileWithUsers;
    string dateIntToString = "";
    string amountWithTwoFiguresAfterComma = "";

    if(!xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileWithUsers.AddElem("Incomes");
    }
    xmlFileWithUsers.FindElem();
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("Income");
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("incomeId", incomeToAdd.getIncomeId());
    xmlFileWithUsers.AddElem("userId", incomeToAdd.getUserId());
    xmlFileWithUsers.AddElem("item", incomeToAdd.getItem());

    amountWithTwoFiguresAfterComma = to_string(incomeToAdd.getAmount());
    amountWithTwoFiguresAfterComma = amountWithTwoFiguresAfterComma.erase(amountWithTwoFiguresAfterComma.size()-4,4);
    xmlFileWithUsers.AddElem("amount",  amountWithTwoFiguresAfterComma);
    xmlFileWithUsers.AddElem("date", AdditionalMethods::addDashesInDate(incomeToAdd.getDate()));

    xmlFileWithUsers.Save(FILE_NAME);
}

void FileWithIncomes::loadIncomes(vector <Income> &incomes, const int USER_ID)
{
    CMarkup xmlFileWithUsers;
    Income tempIncome;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Incomes
        while(xmlFileWithUsers.FindElem("Income"))
        {
            xmlFileWithUsers.IntoElem(); //each Income

            xmlFileWithUsers.FindElem("userId");
            if(stoi(xmlFileWithUsers.GetData()) == USER_ID)
            {
                xmlFileWithUsers.ResetMainPos();
                xmlFileWithUsers.FindElem("incomeId");
                tempIncome.setIncomeId(stoi(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("userId");
                tempIncome.setUserId(stoi(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("item");
                tempIncome.setItem(xmlFileWithUsers.GetData());
                xmlFileWithUsers.FindElem("amount");
                tempIncome.setAmount(stod(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("date");
                tempIncome.setDate(AdditionalMethods::removeDashesFromStringDateToInt(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.OutOfElem();

                incomes.push_back(tempIncome);
            }
            else
            {
                xmlFileWithUsers.OutOfElem();
            }
        }
    }
}

int FileWithIncomes::getLastId()
{
    int lastIncomeId = 0;
    CMarkup xmlFileWithUsers;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Incomes

        while(xmlFileWithUsers.FindElem("Income"))
        {
            xmlFileWithUsers.IntoElem(); //each Income
            xmlFileWithUsers.FindElem("incomeId");
            lastIncomeId = stoi(xmlFileWithUsers.GetData());
            xmlFileWithUsers.OutOfElem();
        }
    }

    return lastIncomeId;
}

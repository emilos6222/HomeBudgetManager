#include "FileWithExpenses.h"

void FileWithExpenses::saveExpenseInFile(Expense expenseToAdd)
{
    CMarkup xmlFileWithUsers;
    string dateIntToString = "";

    if(!xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFileWithUsers.AddElem("Expenses");
    }
    xmlFileWithUsers.FindElem();
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("Expense");
    xmlFileWithUsers.IntoElem();
    xmlFileWithUsers.AddElem("expenseId", expenseToAdd.getExpenseId());
    xmlFileWithUsers.AddElem("userId", expenseToAdd.getUserId());
    xmlFileWithUsers.AddElem("item", expenseToAdd.getItem());
    xmlFileWithUsers.AddElem("amount", to_string(expenseToAdd.getAmount()));
    xmlFileWithUsers.AddElem("date",AdditionalMethods::addDashesInDate(expenseToAdd.getDate()));

    xmlFileWithUsers.Save(FILE_NAME);
}

void FileWithExpenses::loadExpenses(vector <Expense> &expenses, const int USER_ID)
{
    CMarkup xmlFileWithUsers;
    Expense tempExpense;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Incomes
        while(xmlFileWithUsers.FindElem("Expense"))
        {
            xmlFileWithUsers.IntoElem(); //each Income

            xmlFileWithUsers.FindElem("userId");
            if(stoi(xmlFileWithUsers.GetData()) == USER_ID)
            {
                xmlFileWithUsers.ResetMainPos();
                xmlFileWithUsers.FindElem("expenseId");
                tempExpense.setExpenseId(stoi(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("userId");
                tempExpense.setUserId(stoi(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("item");
                tempExpense.setItem(xmlFileWithUsers.GetData());
                xmlFileWithUsers.FindElem("amount");
                tempExpense.setAmount(stod(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.FindElem("date");
                tempExpense.setDate(AdditionalMethods::removeDashesFromStringDateToInt(xmlFileWithUsers.GetData()));
                xmlFileWithUsers.OutOfElem();

                expenses.push_back(tempExpense);
            }
            else
            {
                xmlFileWithUsers.OutOfElem();
            }
        }
    }
}

int FileWithExpenses::getLastId()
{
    int lastExpensesId = 0;
    CMarkup xmlFileWithUsers;

    if(xmlFileWithUsers.Load(FILE_NAME))
    {
        xmlFileWithUsers.FindElem();
        xmlFileWithUsers.IntoElem(); //root Incomes

        while(xmlFileWithUsers.FindElem("Expense"))
        {
            xmlFileWithUsers.IntoElem(); //each Income
            xmlFileWithUsers.FindElem("expenseId");
            lastExpensesId = stoi(xmlFileWithUsers.GetData());
            xmlFileWithUsers.OutOfElem();
        }
    }

    return lastExpensesId;
}

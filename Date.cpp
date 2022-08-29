#include "Date.h"

int Date::getTodayDate()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    fullDate = fullDate + (1900 + lTm->tm_year)*10000;
    fullDate = fullDate + (1+lTm->tm_mon)*100;
    fullDate = fullDate + (lTm->tm_mday);

    return fullDate;
}

int Date::chooseDateYouWant()
{
    string date = "";

    system("cls");
    cout << "Insert date in this format 'YYYY-MM-DD'."<<endl;
    cout << "Your date: ";
    cin >> date;

    while(!checkDate(date))
    {
        system("cls");
        cout << "Insert date in this format 'YYYY-MM-DD'."<<endl;
        cout << "Your date: ";
        cin >> date;
    }

    return AdditionalMethods::dateStringToInt(date);
}

bool Date::checkDate(string date)
{
    int year = 0, month = 0, day = 0;
    int daysInMonth = 0;
    int currentDate = 0, currentMonth = 0, currentYear = 0;

    currentDate = getTodayDate();
    currentMonth = (currentDate/100)%100;
    currentYear = currentDate/10000;


    if(date[4] != '-' || date[7] != '-' || date.size() != 10)
    {
        cout << "You insert wrong format of date. Try again."<<endl;
        system("pause");
        return false;
    }
    else
    {
        date = date.erase(4,1);
        date = date.erase(6,1);
    }

    for(unsigned int i= 0; i < date.size(); i++)
    {
        if(date[i] < '0' || date[i] > '9')
        {
            cout << "Make sure you have put figures. Try again."<<endl;
            system("pause");
            return false;
        }

    }

    year = stoi(date.substr(0,4));
    month = stoi(date.substr(4,2));
    day = stoi(date.substr(6,2));
    daysInMonth = checkDaysInMonth(month, year);

    if(year<2000 || year>currentYear || month<1 || month>12 || day<1 || day>daysInMonth || (year==currentYear && month>currentMonth))
    {
        cout << "You have put figures that are outside the date range. Date must be set in range from 2000-01-01 to last day current month."<<endl<<endl;
        system("pause");
        return false;
    }

    return true;
}

int Date::checkDaysInMonth(int month, int year)
{
    int daysInMonth = 0;

    if(month == 2)
    {
        if(year%4 == 0)
        {
            if(year%100 != 0 )
                daysInMonth = 29;
            else if(year%400 == 0)
                daysInMonth = 29;
            else
                daysInMonth = 28;
        }
        else
            daysInMonth = 28;

        return daysInMonth;
    }

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        daysInMonth = 31;
    else
        daysInMonth = 30;

    return daysInMonth;
}

int Date::getCurrentDate()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    fullDate = fullDate + (1900 + lTm->tm_year)*10000;
    fullDate = fullDate + (1+lTm->tm_mon)*100;
    fullDate = fullDate + (lTm->tm_mday);

    return fullDate;
}

int Date::getDateFromLastMonth()
{
    int fullDate = 0;
    time_t now = time(0);

    tm *lTm = localtime(&now);

    if((1+lTm->tm_mon) == 1)
    {
        fullDate = fullDate + (1900 + lTm->tm_year - 1)*10000;
        fullDate = fullDate + 12*100;
        fullDate = fullDate + (lTm->tm_mday);
    }
    else
    {
        fullDate = fullDate + (1900 + lTm->tm_year)*10000;
        fullDate = fullDate + (1+lTm->tm_mon - 1)*100;
        fullDate = fullDate + (lTm->tm_mday);
    }

    return fullDate;

}

#include "AdditionalMethods.h"

char AdditionalMethods::getOneChar()
{
    string lineOfText = "";
    getline(cin, lineOfText);

    while(lineOfText.size() != 1)
    {
        cout << "You did not put one char."<<endl;
        cout << "Put one char: ";

        getline(cin, lineOfText);
    }

    return lineOfText[0];

}

string AdditionalMethods::toUpperFirstLetter(string wordToUpper)
{
    string tempWord = "";

    for(unsigned int i = 0; i < wordToUpper.size(); i++)
    {
        if(i == 0)
            tempWord += toupper(wordToUpper[i]);
        else
            tempWord += wordToUpper[i];
    }

    return tempWord;
}

string AdditionalMethods::addDashesInDate(int date)
{
    string tempDate = "";
    string dateWithDashes = "";

    tempDate = to_string(date);

    for(unsigned int i = 0; i < tempDate.size(); i++)
    {
        dateWithDashes += tempDate[i];
        if(i == 3 || i == 5)
            dateWithDashes += "-";
    }

    return dateWithDashes;
}

int AdditionalMethods::removeDashesFromStringDateToInt(string date)
{
    int dateAsIntWithoutDashes = 0;

    date = date.erase(4,1);
    date = date.erase(6,1);

    dateAsIntWithoutDashes = stoi(date);

    return dateAsIntWithoutDashes;
}

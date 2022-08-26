#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AdditionalMethods.h"

using namespace std;

class XmlFile
{
protected:
    const string FILE_NAME;

public:
    XmlFile(string fileWithUserName):FILE_NAME(fileWithUserName)
    {}


};

#endif

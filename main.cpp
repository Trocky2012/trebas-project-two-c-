#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include "fcn/functions.h"
#include "fcn/api.h"
#include "fcn/json.hpp"

#define product "product"
#define feedstock "feedstock"
#define sale "sale"
#define purchase "purchase"

using namespace std;

int main()
{
    string entity = product; // Choose: product, feedstock, sale or purchase;

    setFileName("dataFile_"+entity+"List.txt");
    accessEndPoint(getEntityByProject(entity));
    setFileName("dataFile_"+entity+"ById.txt");
    accessEndPoint(getApi()+entity+"/34");

    cout << "\n\nCheck both files in the project folder, please!\n";
    cout << ">> dataFile_"+entity+"List.txt\n";
    cout << ">> dataFile_"+entity+"ById.txt\n\n";
}

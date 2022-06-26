#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>

#include "json.hpp"
using json = nlohmann::json;

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

string myFile = "dataFile.txt";

//Scope
void setFileName(string fileName);
void printMsg(string msg);
void printResponse(string res);
void testsJson(string res);
string accessEndPoint(string url);

//Functions
void setFileName(string fileName){
    myFile = fileName;
}

void printMsg(string msg){
    cout << endl << msg << endl;
}

void printResponse(string res){
    ifstream file(myFile);
    while (getline (file, res)) {
        cout << res << endl;
    }
    file.close();
}

void printResponseByChars(string res){
    ifstream file(myFile);
    for (char c : res) {
        cout << c << ' ';
    }
    file.close();
}

string accessEndPoint(string url){

    url  = "curl -o " + myFile + " " + url;
    system(url.c_str());//Executing script
    string res;
    printResponse(res);
//    remove("data.txt");
    return res;
}

void testsJson(string res){

    json jdEmployees =
    {
        {"firstName","Sean"},
        {"lastName","Brown"},
        {"StudentID",21453},
        {"Department","Computer Sc."}
    };

    // Access the values
    std::string fName = jdEmployees.value("firstName", "oops");
    std::string lName = jdEmployees.value("lastName", "oops");
    int sID = jdEmployees.value("StudentID", 0);
    std::string dept = jdEmployees.value("Department", "oops");

    // Print the values
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Student ID: " << sID << std::endl;
    std::cout << "Department: " << dept << std::endl;

}


#endif //FUNCTIONS_H

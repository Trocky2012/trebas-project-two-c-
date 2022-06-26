#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

#ifndef API_H
#define API_H

using namespace std;

//Scope
string getApi();
string getEntityByProject();

//Functions
string getApi(){
    return "https://asm-manager.herokuapp.com/";
}
string getEntityByProject(string entity){
    return ("https://asm-manager.herokuapp.com/"+entity+"/by-project-id/8");
}

#endif //API_H

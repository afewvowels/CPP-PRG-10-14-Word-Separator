//
//  main.cpp
//  CPP-PRG-10-14-Word-Separator
//
//  Created by Keith Smith on 11/4/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that accepts as input a sentence in which all of the words are run
//  together, but the first character of each word is uppercase. Convert the sentence to a
//  string in which the words are separated by spaces and only the first word starts with
//  an uppercase letter. For example, the string "StopAndSmellTheRoses." would be converted
//  to "Stop and smell the roses."
//

#include <iostream>

using namespace std;

string *getStringFromUser(string *);
string *createCharArray(string *);
void displayResult(string *);

int main()
{
    string *strUserString = nullptr;
    strUserString = new string;
    
    strUserString = getStringFromUser(strUserString);
    
    strUserString = createCharArray(strUserString);
    
//    displayResult(strUserString);
    
    return 0;
}

string *getStringFromUser(string *strUserStr)
{
    cout << "Please enter a string with no spaces\n";
    cout << "and with the words first letters capitalized:\n";
    getline(cin, *strUserStr);
    
    return strUserStr;
}

string *createCharArray(string *strUserStr)
{
    int *intSpaceCounter = nullptr;
    intSpaceCounter = new int;
    *intSpaceCounter = -1;
    
    for (int i = 0 ; i < strUserStr->length() ; i++)
    {
        if (isupper(strUserStr->at(i)))
            *intSpaceCounter += 1;
    }
    
    cout << *intSpaceCounter << endl;
    
    char *chrArrayTemp = nullptr;
    chrArrayTemp = new char[strUserStr->length() + *intSpaceCounter];
    
    strcpy(chrArrayTemp, strUserStr->c_str());
    
    for (int i = strlen(chrArrayTemp) ; i > 0 ; i--)
    {
        if (isupper(chrArrayTemp[i]))
        {
            chrArrayTemp[i] = tolower(chrArrayTemp[i]);
            for (int j = strlen(chrArrayTemp) ; j > i ; j--)
            {
                chrArrayTemp[j] = chrArrayTemp[j - 1];
            }
            chrArrayTemp[i] = ' ';
        }
    }
    
//    strUserStr->clear();
//    strUserStr->resize(strlen(chrArrayTemp));
//    strUserStr->copy(chrArrayTemp, strlen(chrArrayTemp));
    
    for (int i = 0 ; i < strlen(chrArrayTemp) ; i++)
        cout << chrArrayTemp[i];
    
    cout << endl;
    
    return strUserStr;
}

//void displayResult(string *strUserStr)
//{
//    cout << "Properly formatted, your string reads as:\n";
//    cout << *strUserStr << endl;
//}


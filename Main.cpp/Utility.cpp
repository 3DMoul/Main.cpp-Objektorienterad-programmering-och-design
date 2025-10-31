#include "Utility.h"
#include "Storage.h"
#include <random>
#include <iostream>
#include <fstream>
using namespace std;

double Utility::RandomTempreture()
{
    double f = (double)rand() / RAND_MAX;
    double RandomTempreture = 20 + f * (40 - 20);
    return RandomTempreture;
}
int Utility::RandomAirquality()
{
    return rand() % (100 - 1) + 1;
}
int Utility::NumberChoice(std::string StringInput)
{
    std::cout << StringInput << std::endl;
    int Choice;
    //failsafe loop för val
    while (!(cin >> Choice))
    {
        cout << "Error you have inputed a invalid value please input a number:  " << std::endl;
        cin.clear();
        streamsize InputBufferLimit = 10000;
        cin.ignore(InputBufferLimit, '\n');
        cout << StringInput << endl;
    }
    return Choice;
}
string Utility::TimeGenerator()
{
    time_t TimeStamp;
    time(&TimeStamp);
    struct tm timeInfo;
    localtime_s(&timeInfo, &TimeStamp);
    char temp[26];
    asctime_s(temp, sizeof(temp), &timeInfo);
    temp[strlen(temp) - 1] = '\0'; // tar bort newline
    return temp;
}
void Utility::ENTER()
{
    cout << "Klick \"ENTER\" too continue" << endl;
    string str;
    getline(cin, str);
    streamsize InputBufferLimit = 10000;
    cin.ignore(InputBufferLimit, '\n');
}
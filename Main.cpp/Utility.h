#pragma once
#include "Storage.h"
using namespace std;

class Utility
{
public:
	static double RandomTempreture();
	static int RandomAirquality();
	void ReadFile(class Storage CurrentStorage);
	void WriteFile(const string TimeStamp, const string UnitOfMeasurment, double Temperature);
	static int NumberChoice(const string StringInput);
	static string TimeGenerator();
	void ENTER();
};
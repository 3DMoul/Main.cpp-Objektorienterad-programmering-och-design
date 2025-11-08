#pragma once
#include <string>
using namespace std;


class TemperatureSensor
{
private:
	double MinSimulation = 20, MaxSimulation = 40;
	string UnitOfMeasurment = "C";
public:
	double Read();
	string GetUnitOfMeasurment();
};
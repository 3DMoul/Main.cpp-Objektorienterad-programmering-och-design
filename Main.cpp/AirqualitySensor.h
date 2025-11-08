#pragma once

#include <string>
using namespace std;

class AirqualitySensor
{
private:
	double MinSimulation = 1, MaxSimulation = 100;
	string UnitOfMeasurment = "%";
public:
	double Read();
	string GetUnitOfMeasurment();
};
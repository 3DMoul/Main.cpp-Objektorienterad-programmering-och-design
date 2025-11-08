#include "AirqualitySensor.h"
#include "Utility.h"
#include <iostream>
using namespace std;
double AirqualitySensor::Read()
{
	Utility Misc;
	double OutPut = Misc.RandomAirquality(MinSimulation, MaxSimulation);
	return OutPut;
}
string AirqualitySensor::GetUnitOfMeasurment()
{
	return UnitOfMeasurment;
}
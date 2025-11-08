#include "TemperatureSensor.h"
#include "Utility.h"
#include <iostream>
using namespace std;
double TemperatureSensor::Read()
{
	Utility Misc;
	double OutPut = Misc.RandomTempreture(MinSimulation, MaxSimulation);
	return OutPut;
}
string TemperatureSensor::GetUnitOfMeasurment()
{
	return UnitOfMeasurment;
}
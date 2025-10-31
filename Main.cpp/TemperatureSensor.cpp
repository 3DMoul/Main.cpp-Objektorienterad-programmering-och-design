#include "TemperatureSensor.h"
#include <iostream>
using namespace std;


void TemperatureSensor::SensorReading(double NewTemperature, string NewTimeStamp)
{
	Temperature = NewTemperature;
	TimeStamp = NewTimeStamp;
}
void TemperatureSensor::Read() const
{
	cout << Temperature << " " << UnitOfMeasurment << " " << TimeStamp << endl;
}
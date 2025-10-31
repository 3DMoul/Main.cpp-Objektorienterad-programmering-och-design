#include "AirqualitySensor.h"
#include <iostream>
using namespace std;


void AirqualitySensor::SensorReading(int NewAirquality, string NewTimeStamp)
{
	Airquality = NewAirquality;
	TimeStamp = NewTimeStamp;
}
void AirqualitySensor::Read() const
{
	cout << Airquality << " " << UnitOfMeasurment << " " << TimeStamp << endl;
}
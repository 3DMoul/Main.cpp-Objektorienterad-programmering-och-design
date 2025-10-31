#pragma once
#include <string>
using namespace std;


struct TemperatureSensor
{
public:
	//string SensorName;
	double Temperature = 0.0;
	string UnitOfMeasurment = "C";
	string TimeStamp;

	void SensorReading(double NewTempereture, string NewTimeStamp);
	void Read() const;
};
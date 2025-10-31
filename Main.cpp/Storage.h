#pragma once
#include "TemperatureSensor.h"
#include "AirqualitySensor.h"
#include <vector>
#include <fstream>

using namespace std;
class Storage
{
private:
	vector <TemperatureSensor> TemperatureMeasurments;
	vector <AirqualitySensor> AirQualityReadings;
public:
	int SizeofAirquality = size(AirQualityReadings);
	int SizeofTemperature = size(TemperatureMeasurments);
	void GetTemperetureSensor(const TemperatureSensor& TempretureSensor);
	void GetAirqualitySensor(const AirqualitySensor& AirqualitySensor);
	void PrintAll() const;
	void WriteFile(string TimeStamp, string UnitOfMeasurment, double SensorReading);
	void ReadFile();
};
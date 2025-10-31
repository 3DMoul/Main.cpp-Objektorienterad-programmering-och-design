#include "Storage.h"
#include <iostream>
using namespace std;
void Storage::GetTemperetureSensor(const TemperatureSensor& TempretureSensor)
{
	TemperatureMeasurments.push_back(TempretureSensor);
}
void Storage::GetAirqualitySensor(const AirqualitySensor& AirqualitySensor)
{
	AirQualityReadings.push_back(AirqualitySensor);
}
void Storage::PrintAll() const
{
	cout << "Temperature: " << endl;
	for (int i = 0; i < size(TemperatureMeasurments); i++)
	{
		cout << TemperatureMeasurments[i].Temperature << " " << TemperatureMeasurments[i].UnitOfMeasurment << ", " << TemperatureMeasurments[i].TimeStamp << endl;
	}
	cout << "AirQualityReadings: " << endl;
	for (int i = 0; i < size(AirQualityReadings); i++)
	{
		cout << AirQualityReadings[i].Airquality << " " << AirQualityReadings[i].UnitOfMeasurment << ", " << AirQualityReadings[i].TimeStamp << endl;
	}
}
void Storage::WriteFile(string TimeStamp, string UnitOfMeasurment, double SensorReading)
{
    ofstream SensorFile;
    //här öppnar jag upp en ny txt.fil som jag lägger in värden i
    SensorFile.open("SensorReading2.txt", ios::app);
    if (SensorFile.is_open())
    {
        //här läggs det in i txt.filen
        SensorFile << UnitOfMeasurment << ",";
        SensorFile << SensorReading << ",";
        SensorFile << TimeStamp << endl;
        SensorFile.close();
    }
}
void Storage::ReadFile()
{
    ifstream SensorFile;
    //går igenom värdena som var innan och skickar in dem i listan
    SensorFile.open("SensorReading2.txt", ios::in);
    if (SensorFile.is_open())
    {
        int times = 0;
        string line;
        //här går den igenom alla lines av txt filen samt lägger dem in i vector som sätts in i listan
        while (getline(SensorFile, line))
        {
            char str[256];
            strcpy_s(str, line.c_str());
            const char* del = ",";
            char* next_token = nullptr;
            char* FileSegment = strtok_s(str, del, &next_token);
            int FileIteration = 0;
            if (line[0] == 'C')
            {
                TemperatureSensor TemperatureSensorReading;

                while (FileSegment != nullptr)
                {

                    if (FileIteration == 1)
                    {
                        TemperatureSensorReading.Temperature = stod(FileSegment);
                    }
                    else if (FileIteration == 2)
                    {
                        TemperatureSensorReading.TimeStamp = FileSegment;
                    }
                    FileSegment = strtok_s(nullptr, del, &next_token);
                    FileIteration++;
                }
                GetTemperetureSensor(TemperatureSensorReading);
            }
            else if (line[0] == '%')
            {
                AirqualitySensor AirqualitySensorReading;
                while (FileSegment != nullptr)
                {
                    if (FileIteration == 1)
                    {
                        AirqualitySensorReading.Airquality = stod(FileSegment);
                    }
                    else if (FileIteration == 2)
                    {
                        AirqualitySensorReading.TimeStamp = FileSegment;
                    }
                    FileSegment = strtok_s(nullptr, del, &next_token);
                    FileIteration++;
                }
                GetAirqualitySensor(AirqualitySensorReading);
            }
        }
    }
    SensorFile.close();
}
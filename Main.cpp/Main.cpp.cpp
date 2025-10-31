#include "Storage.h"
#include "AirqualitySensor.h"
#include "TemperatureSensor.h"
#include "Utility.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{

	Utility Utility;
	/*TemperatureSensor Temperature;
	AirqualitySensor AirQuality;*/
	Storage MainStore;
	
	MainStore.ReadFile();
	bool MainLoopActive = true;
	while (MainLoopActive == true)
	{
		system("CLS");
		cout << "---------------------------------" << endl;
		cout << "[1] Adding sensor readings" << endl;
		cout << "[2] Read out readings" << endl;
		cout << "[3] " << endl;
		cout << "[4]" << endl;
		cout << "[5]" << endl;
		cout << "[6] Exit program" << endl;
		cout << "[7]" << endl;
		cout << "---------------------------------" << endl;
		string NumberChoice = "Choice between [1]-[6]";
		int Choice = Utility.NumberChoice(NumberChoice);
		switch (Choice)
		{
		case 1:
		{

			system("CLS");
			bool SimulatorRunning = true;
			while (SimulatorRunning == true)
			{
				cout << "Do you want to only simulate Temperature, Airquality or both [ T / A / B ]" << endl;
				cout << "if you dont want to simulate anything press [Q]" << endl;
				char Des;
				cin >> Des;
				//använder toupper så man kan skriva bådde stor eller liten bokstav
				if ((char)toupper(Des) == 'T')
				{
					string TimeQuestion = "How many Temperature readings do you want to simulate?";
					int Iterations = Utility.NumberChoice(TimeQuestion);
					for (int i = 0; i < Iterations; i++)
					{
						TemperatureSensor New_Temperature_Reading;
						New_Temperature_Reading.SensorReading(Utility.RandomTempreture(), Utility.TimeGenerator());
						MainStore.WriteFile(New_Temperature_Reading.TimeStamp, New_Temperature_Reading.UnitOfMeasurment, New_Temperature_Reading.Temperature);
						MainStore.GetTemperetureSensor(New_Temperature_Reading);
						New_Temperature_Reading.Read();
					}
					Utility.ENTER();
					SimulatorRunning = false;
				}
				else if ((char)toupper(Des) == 'A')
				{
					string TimeQuestion = "How many Airquality readings do you want to simulate?";
					int Iterations = Utility.NumberChoice(TimeQuestion);
					for (int i = 0; i < Iterations; i++)
					{
						AirqualitySensor New_AirQuality_Reading;
						New_AirQuality_Reading.SensorReading(Utility.RandomAirquality(), Utility.TimeGenerator());
						MainStore.WriteFile(New_AirQuality_Reading.TimeStamp, New_AirQuality_Reading.UnitOfMeasurment, New_AirQuality_Reading.Airquality);
						MainStore.GetAirqualitySensor(New_AirQuality_Reading);
						New_AirQuality_Reading.Read();
					}
					Utility.ENTER();
					SimulatorRunning = false;
				}
				else if ((char)toupper(Des) == 'B')
				{
					string TimeQuestion = "How many readings do you want to simulate?";
					int Iterations = Utility.NumberChoice(TimeQuestion);
					for (int i = 0; i < Iterations; i++)
					{
						TemperatureSensor New_Temperature_Reading;
						New_Temperature_Reading.SensorReading(Utility.RandomTempreture(), Utility.TimeGenerator());
						MainStore.WriteFile(New_Temperature_Reading.TimeStamp, New_Temperature_Reading.UnitOfMeasurment, New_Temperature_Reading.Temperature);
						MainStore.GetTemperetureSensor(New_Temperature_Reading);
						New_Temperature_Reading.Read();
					}
					for (int i = 0; i < Iterations; i++)
					{
						AirqualitySensor New_AirQuality_Reading;
						New_AirQuality_Reading.SensorReading(Utility.RandomAirquality(), Utility.TimeGenerator());
						MainStore.WriteFile(New_AirQuality_Reading.TimeStamp, New_AirQuality_Reading.UnitOfMeasurment, New_AirQuality_Reading.Airquality);
						MainStore.GetAirqualitySensor(New_AirQuality_Reading);
						New_AirQuality_Reading.Read();
					}
					Utility.ENTER();
					SimulatorRunning = false;
				}
				else
				{
					cout << "Wrong input" << endl;
				}
			}
		}

			break;
		case 2:
		{
			system("CLS");
			bool PrintLoopisRunning = true;
			while (PrintLoopisRunning == true)
			{
				cout << "You have [" << MainStore.SizeofTemperature << "]" << " Temperature" << endl;
				cout << "You have [" << MainStore.SizeofAirquality << "]" << " Airquality" << endl;
				cout << "Do you want to list them [Y/N] : " << endl;
				char Des;
				cin >> Des;
				//använder toupper så man kan skriva bådde stor eller liten bokstav
				if ((char)toupper(Des) == 'Y')
				{
					//detta går igenom bådde <TemperatureSensor> och <AirqualitySensor>
					MainStore.PrintAll();
					Utility.ENTER();
					PrintLoopisRunning = false;
				}

				else if ((char)toupper(Des) == 'N')
				{
					Utility.ENTER();
					PrintLoopisRunning = false;
				}
				else
				{
					cout << "Wrong input" << endl;
				}
				break;
			}
		}
			break;
		case 3:
		{
		}
			break;
		case 4:
		{
		}
			break;
		case 5:
		{
		}
			break;
		case 6:
		{
			Utility.ENTER();
			MainLoopActive = false;
		}
			break;
		default:
		{
			cout << "Wrong input choices are between [1]-[6]" << endl;
		}
			break;
		}

	}
}
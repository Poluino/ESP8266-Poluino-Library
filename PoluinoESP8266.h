// by Dos Banaag
#ifndef POLUINO_H_INCLUDED
#define POLUINO_H_INCLUDED
// #include <HttpClient.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <ArduinoJson.h>
#include <string>

class Board
{
	public:
   		Board(String thisToken);
		String token;
		int login();
	   	String update();
		double setTemperature(double thisTemperature);
		double setPressure(double thisPressure);
		double setHumidity(double thisHumidity);
		double setRainfall(double thisRainfall);
		double setWindSpeed(double thisWindSpeed);
		double setWindDirection(double thisWindDirection);
		double setSoilMoisture(double thisSoilMoisture);
		double setLux(double thisLux);
		double setUvIndex(double thisUvIndex);
		String customGet(String customPath);
		String customGetAnywhere(String customPath);
	private:
		double temperature;
		double pressure;
		double humidity;
		double rainfall;
		double wind_speed;
		double wind_direction;
		double soil_moisture;
		double lux;
		double uv_index;
};

#endif // POLUINO_H_INCLUDED
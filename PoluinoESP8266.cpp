#include "Arduino.h"
#include "ESP8266HTTPClient.h"
#include "ArduinoJson.h"
#include "WiFiClientSecureBearSSL.h"
#include <sstream>
#include <string>
#include "PoluinoESP8266.h"

Board::Board (String thisToken)
{
	token = thisToken;
	temperature = -255;
	pressure = -255;
	humidity = -255;
	rainfall = -255;
	wind_speed = -255;
	wind_direction = -255;
	soil_moisture = -255;
	pressure = -255;
	lux = -255;
	uv_index = -255;
}

int Board::login() {
	std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  	client->setInsecure();
	HTTPClient https;
	String loginURL = "https://beta.api.weatherstationproject.com/data/login/" + token;
	https.begin(*client,loginURL);

	int apiResponse = https.GET();
	return apiResponse;
}

String Board::update() {
	std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  	client->setInsecure();
	HTTPClient https;
	if (https.begin(*client,"https://beta.api.weatherstationproject.com/data/update")) {  // HTTPS
  		https.addHeader("Content-Type", "application/json");

		StaticJsonDocument<200> json_data;
		json_data["token"] = token;
		if (temperature != -255) {
	  		json_data["temperature"] = temperature;
		}
		if (pressure != -255) {
			json_data["pressure"] = pressure;
		}
		if (humidity != -255) {
	  		json_data["humidity"] = humidity;
    	}
		if (rainfall != -255) {
			json_data["rainfall"] = rainfall;
		}
		if (wind_speed != -255) {
	  		json_data["wind_speed"] = wind_speed;
		}
		if (wind_direction != -255) {
			json_data["wind_direction"] = wind_direction;
		}
		if (soil_moisture != -255) {
		  	json_data["soil_moisture"] = soil_moisture;
		}
		if (lux != -255) {
			json_data["lux"] = lux;
		}
		if (uv_index != -255) {
	  		json_data["uv_index"] = uv_index;
		}

		String requestBody;
  		serializeJson(json_data, requestBody);

		int responseCode = https.POST(requestBody);
		return https.getString();
  	} else {
		return "Request failed";
	}
}

double Board::setTemperature(double thisTemperature) {
	temperature = thisTemperature;
	return temperature;
}

double Board::setPressure(double thisPressure) {
	pressure = thisPressure;
	return pressure;
}

double Board::setHumidity(double thisHumidity) {
	humidity = thisHumidity;
	return humidity;
}

double Board::setRainfall(double thisRainfall) {
	rainfall = thisRainfall;
	return rainfall;
}

double Board::setWindSpeed(double thisWindSpeed) {
	wind_speed = thisWindSpeed;
	return wind_speed;
}

double Board::setWindDirection(double thisWindDirection) {
	wind_direction = thisWindDirection;
	return wind_direction;
}

double Board::setSoilMoisture(double thisSoilMoisture) {
	soil_moisture = thisSoilMoisture;
	return soil_moisture;
}

double Board::setLux(double thisLux) {
	lux = thisLux;
	return lux;
}

double Board::setUvIndex(double thisUvIndex) {
	uv_index = thisUvIndex;
	return uv_index;
}

String Board::customGet(String customPath) {
	std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  	client->setInsecure();
	HTTPClient https;
	String customUrl = "https://beta.api.weatherstationproject.com" + customPath;
	https.begin(*client,customUrl);

	int apiResponse = https.GET();
	return https.getString();
}

String Board::customGetAnywhere(String customPath) {
	std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  	client->setInsecure();
	HTTPClient https;
	https.begin(*client,customPath);

	int apiResponse = https.GET();
	return https.getString();
}
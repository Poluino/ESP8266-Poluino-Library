#include <Arduino.h>
#include <ESP8266WiFi.h> // // Default Library in ESP8266 for connecting to WiFi
#include <WiFiClientSecureBearSSL.h> // Default Library in ESP8266 for Security of API calls
#include <ArduinoJson.h> // Library for making JSON files
#include <ESP8266HTTPClient.h> // Default Library in ESP8266 for making API calls
#include <PoluinoESP8266.h> // Official ESP8266 Poluino library written in Arduino

// Initialize Board class
Board station("*your-station-id*");

void setup() {
  Serial.begin(115200);

  Serial.print("Connecting...");
  Serial.println();
  WiFi.begin("*your-ssid*", "*your-wifi-password*");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED){
    Serial.println();
    Serial.println("Connected to :");
    Serial.println(WiFi.SSID());
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  Serial.print("Login Status: ");
  Serial.println(station.login());
}

void loop() {
  Serial.print("Temperature: ");
  Serial.println(station.setTemperature(25)); // sets temperature to 25 degrees Celsius
  Serial.print("Station Update Status: ");
  Serial.println(station.update()); // outputs response from Poluino API
  delay(5000);
}
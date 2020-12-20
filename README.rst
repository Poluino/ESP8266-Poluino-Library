*******************************************
Official Poluino Library v1.0.0 for ESP8266
*******************************************

This page serves as the documentation to the this official Poluino library. This page assumes that you have experience in making Arduino Sketches.

New to Arduino Sketches? Visit this: `<https://www.arduino.cc/en/Tutorial/Sketch>`_ 

Getting Started
===============

Required Libraries:
-------------------

#. **ArduinoJson** By Bartoz Bielawski
#. **PoluinoESP8266** By Poluino

If you need help in installing the libraries, check out this link: `<https://www.arduino.cc/en/Guide/Libraries>`_

Install the ESP8266 Boards from this link: `<https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/>`_

After installing the boards, select your board.

Minimalist Script:
------------------

Now that we have our dependencies in place, let's make a script that logs in our bot.

Open up a new sketch in the ArduinoIDE and follow along.

Import the Libraries:
#####################

We need to import the above mentioned libraries into our sketch.

.. code-block:: C++

  #include <Arduino.h>
  #include <ESP8266WiFi.h>
  #include <WiFiClientSecureBearSSL.h>
  #include <ArduinoJson.h>
  #include <ESP8266HTTPClient.h>
  #include <PoluinoESP8266.h>

* **ESP8266WiFi** is used to connect the ESP8266 to your WiFi Network.
* **ArduinoJson** is used to create json document which we will sent to the website using an API.
* **ESP8266HTTPClient** is used to make HTTP/HTTPS requests such as POST.
* **PoluinoESP8266** is used to easily access the Poluino API.

Define your variables:
----------------------

.. code-block:: C++

  Board station("*your-board-token*");
  long timerDelay = ;

Enter a suitable interval at which your device will send data to our server.

**Caution: The time should be set in milliSeconds, eg: 5 seconds = 5000**

setup():
--------

.. code-block:: C++

  void setup() {
    Serial.begin(115200);

    Serial.print("Connecting...");
    Serial.println();
    WiFi.begin("*your_wifi_name*", "*your_pass*");

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED){
      Serial.println();
      Serial.println("Connected to: ");
      Serial.println(WiFi.SSID());
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
    }

    Serial.print("Login Status: ");
    Serial.println(station.login());
  }

In the 3rd line, replace your_wifi_name and your_pass with your credentials. This enables the ESP32 to connect to your **Home / Office WiFi Network**.

loop():
-------

.. code-block:: C++

  void loop() {
    Serial.print("Login Status: ");
    Serial.println(station.login());
    delay(timerDelay);
  }

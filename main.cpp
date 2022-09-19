#include <Arduino.h>
// "StAuth10184-01: I Kevin Sar, 000390567 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else."

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  // int iVal;
  // double voltage;
 
  // // read digitized value from the D1 Mini's A/D convertor 
  // iVal = analogRead(A0); 
  // voltage = iVal * (3.3 / 1024.0);
  // // print value to the USB port 
  // Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage = " + String(voltage) + "V");
 
  // // wait 0.5 seconds (500 ms) 
  // delay(500); 

  int iVal;
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  double voltage = iVal * (3.3 / 1024.0);
  double temp = iVal * (50 / 1024.0);

  String msg = "";

  if(temp < 10){
    msg = "Cold!";
  } else if (temp > 10 && temp < 15){
    msg = "Cool";
  } else if(temp > 15 && temp < 25){
    msg = "Perfect";
  } else if(temp > 25 && temp < 30){
    msg = "Warm";
  } else if(temp > 30 && temp < 35){
    msg = "Hot";
  } else {
    msg = "Too Hot!";
  }
  // print value to the USB port 
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to temperature input of " + String(temp) + " deg. C, which is " + msg);
 
  // wait 2 seconds (2000 ms) 
  delay(2000); 
}
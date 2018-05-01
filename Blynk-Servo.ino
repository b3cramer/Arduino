/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs on Sparkfun Blynk Board.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * // You will need to make sure these libraries are installed before compiling:
 * // Servo.h
 * //
 *
 * NOTE: You can select NodeMCU 1.0 (compatible board)
 * in the Tools -> Board menu
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

 #define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
 #include <ESP8266WiFi.h>
 #include <BlynkSimpleEsp8266.h>
 #include <Servo.h> //see this documentation for library syntax and examples: https://www.arduino.cc/en/Reference/Servo

 //This block associates your board with your account and your wifi networks
 // You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

//This block defines INPUT: Currently the input is set to V1. You will need to
//change this argument to match what Virtual pin you want to use for the joystick.
BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  //This block defines OUTPUT: You begin by defining the pin you wish to use for the signal out.
  //see this documentation for library syntax and examples: https://www.arduino.cc/en/Reference/Servo
Servo myservo;
void setup()
{
  myservo.attach(9); // the syntax here is myservo.attach(pin); or myservo.attach(pin, min, max); this example has the servo attached to pin 9
  myservo.write(90);  // set servo to mid-point
}
void loop() {}


  //This block is what runs your program:
  void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
}

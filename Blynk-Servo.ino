#define BLYNK_PRINT Serial  // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h> //see this documentation for library syntax and examples: https://www.arduino.cc/en/Reference/Servo


//char auth[] = "7eaee44698f54dd8a9fc65876bd8d32c"; //Pfost phone
char auth[] = "6c6a2ae8df98407d86a14d5fd1495081"; //Cramer phone
char ssid[] = "FAHotspot";
char pass[] = "AtlantaSymphony123";

void setup (){
  Servo myservo;
  myservo.attach(15); // the syntax here is myservo.attach(pin); or myservo.attach(pin, min, max); this example has the servo attached to pin 9
  myservo.write(90); // set servo to mid-point
  Serial.begin(9600);
}
void loop()
{
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  Blynk.run();
}

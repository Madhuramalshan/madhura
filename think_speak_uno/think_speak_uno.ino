#include <SoftwareSerial.h>
SoftwareSerial ESP(10, 11);
const int trigger = 2;
const int echo = 3;
long T;
float distanceCM;
float total_fuel = 1500 ;
void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  ESP.begin(115200);
}
void loop()
{
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  //Serial.println(distanceCM - Higth *width * lenth );
  distanceCM = distanceCM / 2 ;
  Serial.print("Distance cm : ");
  Serial.println(distanceCM  );
  distanceCM = distanceCM  * 17 * 12 ;
  Serial.println("" );

  distanceCM = total_fuel - distanceCM;
  Serial.println("Distance madhu : ");
  Serial.print(distanceCM  );
  Serial.println("" );
  ESP.print(distanceCM);
  delay(1000);
}

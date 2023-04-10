//www.elegoo.com
//2016.12.08
#include <ESP32Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
const int SV_PIN1 = 26;
const int SV_PIN2 = 14;
const int SV_PIN3 = 16;
const int SV_PIN4 = 17;
int servop1;
int servop2;
int servop3;
int servop4;
int data;
uint8_t datah;
uint8_t datal;
float deg1;
float deg2;
float deg3;
float deg4;

void setup() 
{
  Serial.begin(115200);
  myservo1.attach(SV_PIN1, 500, 2400);
  myservo2.attach(SV_PIN2, 500, 2400);
  myservo3.attach(SV_PIN3, 500, 2400);
  myservo4.attach(SV_PIN4, 500, 2400);
}

void loop() 
{
  /*myservo2.write(0);
  delay(1000);
  myservo2.write(180);
  delay(1000);
  myservo2.write(360);
  delay(1000);
  */
 if ( Serial.available() > 0 ) {
    data = Serial.readStringUntil('\n');
    uint8_t datah = highByte(data);
    uint8_t datal = lowByte(data);
    servop1 = datah / 16;
    servop2 = datah % 16;
    servop3 = datal / 16;
    servop4 = datal % 16;

    deg1 = 11* pow(servop1,2) / 45;
    deg2 = 90 - 11* pow(servop2,2) / 45;
    deg3 = 11* pow(servop3,2) / 45;
    deg4 = 90 - 11* pow(servop4,2) / 45;

    myservo1.write(round(deg1));
    myservo2.write(round(deg2));
    myservo3.write(round(deg3));
    myservo4.write(round(deg4));

    /*
    if (servop1 == ) {
      myservo1.write(0);
    }
    else if (idata == 11) {
      myservo1.write(5);
    }
    else if (idata == 12) {
      myservo1.write(10);
    }
    else if (idata == 13) {
      myservo1.write(17);
    }
    else if (idata == 14) {
      myservo1.write(25);
    }
    else if (idata == 15) {
      myservo1.write(50);
    }
    
    else if (idata == 20) {
      myservo2.write(90);
    }
    else if (idata == 21) {
      myservo2.write(85);
    }
    else if (idata == 22) {
      myservo2.write(80);
    }
    else if (idata == 23) {
      myservo2.write(73);
    }
    else if (idata == 24) {
      myservo2.write(65);
    }
    else if (idata == 25) {
      myservo2.write(40);
    }
    else if (idata == 30) {
      myservo3.write(0);
    }
    else if (idata == 31) {
      myservo3.write(5);
    }
    else if (idata == 32) {
      myservo3.write(10);
    }
    else if (idata == 33) {
      myservo3.write(17);
    }
    else if (idata == 34) {
      myservo3.write(25);
    }
    else if (idata == 35) {
      myservo3.write(50);
    }
    
    if (idata == 40) {
      myservo4.write(90);
    }
    else if (idata == 41) {
      myservo4.write(85);
    }
    else if (idata == 42) {
      myservo4.write(80);
    }
    else if (idata == 43) {
      myservo4.write(73);
    }
    else if (idata == 44) {
      myservo4.write(65);
    }
    else if (idata == 45) {
      myservo4.write(40);
    }
 }
 */
  /*
  if (digitalRead(buttonBpin) == LOW)
  {
    myservo1.write(0);
  }
  }
  if (digitalRead(buttonCpin) == LOW)
  {
    myservo2.write(130);                       // waits 15ms for the servo to reach the position
  }
  if (digitalRead(buttonDpin) == LOW)
  {
    myservo2.write(0);
  }*/
}

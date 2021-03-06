/**
  * Ultrasonic module
  * Used to detect person postion
*/

#include "Arduino.h"
#include "ultrasonic.h"

// Ultrasonic sensors pins
static const int pinEcho1 = 6;
static const int pinTrig1 = 7;

static const int pinEcho2 = 4;
static const int pinTrig2 = 5;

// static const int pinEcho3 = 0;
// static const int pinTrig3 = 0;


static unsigned long time1 = 0;
static unsigned long time2 = 0;
// static unsigned long time3 = 0;

static int interval = 100; // Time betweel each wave (µs)

static long time_sync; // Delay (µs)


void init_ultrasonic() {
  /*** Initialize ultrasonic module***/

  pinMode(pinEcho1, INPUT);
  pinMode(pinTrig1, OUTPUT);

  pinMode(pinEcho2, INPUT);
  pinMode(pinTrig2, OUTPUT);

  // pinMode(12, INPUT);
  // pinMode(pinEcho3, INPUT);
  // pinMode(pinTrig3, OUTPUT);

  sync();
}

static void sync() {
  /*** Synchronize robot's Arduino with beacon's Arduino ***/
  int time = 0;
  while(time =! 0) {
    time = pulseIn(pinEcho1, HIGH);
  }
  time_sync = micros();
}

char check_direction() {
  const float pi = 3,1415926535;
  char direction;
  float distance;
  float angle;
  int sensor_dist = 100 ; // Distance between sensors (mm)
  float sound_speed = 0,343; // Speed of sound (mm/µs)
  int d = 200 //Distance between sensors (mm)
  // long gauche = 0;
  // long droite = 0;
  // long compteur = 0;

  Serial.println("Checking direction...");
  /*
  while(compteur < 5000) {
    digitalWrite(pinTrig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig1, LOW);

    digitalWrite(pinTrig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig2, LOW);

    // digitalWrite(pinTrig3, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(pinTrig3, LOW);

    if (digitalRead(pinEcho1) == 1) {
      gauche++;
    }
    if (digitalRead(pinEcho2) == 1) {
      droite++;
    }
    compteur++;
    delayMicroseconds(10);
  }


  if(gauche > droite) {
    Serial.println("Gauche");
    direction = 'l';
  }
  else {
    Serial.println("Droite");
    direction = 'r';
  }
  Serial.println(gauche);
  Serial.println(droite);
  */

while(digitalRead(12) == 0) {
  Serial.println(digitalRead(12));
}

Serial.println(digitalRead(12));

digitalWrite(pinTrig1, HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig1, LOW);
time1 = pulseIn(pinEcho1, HIGH);

digitalWrite(pinTrig2, HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig2, LOW);
time2 = pulseIn(pinEcho2, HIGH);

d1 = time1 * sound_speed;
d2 = time2 * sound_speed;

distance = ( sqrt(sq(d1) +sq(d2) - sq(d) ) )/2;
angle = acos( (sq(distance) + sq(d2) + sq(d/2))/(d*distance) );

Serial.println(distance);
Serial.println(angle);

if(distance < 800) {
  direction = 's';
}
else if (angle > 0,1) {
  direction = 'r';
}
else if(angle < 0,1) {
  direction = 'l';
}
else {
  direction = 'f'
}

delay(10);
return direction;
}

#include <Servo.h>
#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#include "DHT.h"

const int steps = 2048;
int distance;
int LDR;
float T, H, B;
char x;
int Display=0;

int LDRSensor = A0;
int Buzzer = A1;
int Light = A2;

Stepper myStepper = Stepper( steps, 2, 4, 3, 5);
SoftwareSerial bluetooth (6 , 7);
DHT dht( 8 , DHT11 );
int IRSensor = 9;
Ultrasonic USSensor(10,11);
Servo RadarServo;     // pin 10
Servo InputDoorServo; // pin 11
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  pinMode(LDRSensor,INPUT);
  pinMode(IRSensor,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Light,OUTPUT);
  
  myStepper.setSpeed(7);
  
  RadarServo.attach(13); 
  InputDoorServo.attach(12); 
  InputDoorServo.write(90); 
   
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Everything is OK:)");
  
  dht.begin();
  
}

void loop() {

  if (bluetooth.available() > 0 ) {
    x = bluetooth.read() ;
    if ( x == 'L' ) {
      Serial.println(analogRead(A0));
      LDR = analogRead(LDRSensor);
      B = map(LDR,0,1023,0,100);
      bluetooth.print("The garage brightness = ");
      bluetooth.print(B);
      bluetooth.println("%");
      
    }
    else if ( x == 'H' ) {
      H = dht.readHumidity();
      bluetooth.print("Humidity in the garage = ");
      bluetooth.println(H);
    }
    else if ( x == 'T' ) {
      T = dht.readTemperature();
      bluetooth.print("Temperature in the garage = ");
      bluetooth.println(T);
    }
  }

  if(digitalRead(IRSensor)){    // if there isn't a new car comming turn the radar on
    // Turn Right
    int i=0;
    while(i<=60 && digitalRead(IRSensor)){  
      RadarServo.write(i);
      delay(30);
      distance = USSensor.read();
      Serial.print(i); 
      Serial.print(","); 
      Serial.print(distance); 
      Serial.print("."); 
      i++;
      if(distance < 30){
        ThereIsThief();
      }
      else
        digitalWrite(Buzzer,LOW);
        digitalWrite(Light,LOW);
        if (Display){
          lcd.clear();
          lcd.print("Everything is OK:)");
          Display = 0;
        }
        
    }

    // Turn Left
    i=60;
    while(i>0 && digitalRead(IRSensor)){  
      RadarServo.write(i);
      delay(30);
      distance = USSensor.read();
      Serial.print(i);
      Serial.print(",");
      Serial.print(distance);
      Serial.print(".");
      i--;
      if(distance < 30){
         ThereIsThief();
      }else{
        digitalWrite(Buzzer,LOW);
        digitalWrite(Light,LOW);
        if (Display){
          lcd.clear();
          lcd.print("Everything is OK:)");
          Display = 0;
        }
       }
      }
    }else{
    InputDoorServo.write(0);  
    delay(6000);
    InputDoorServo.write(90);    
    delay(3000);      
  }
}

void ThereIsThief(){
  
  lcd.clear();
  lcd.print("There is a THIEF!!");
  delay(100);
  bluetooth.println("ATTENTION THERE IS A THIEF!!!!!!!");
  analogWrite(Light,255);
  tone(Buzzer, 1000, 500);
  myStepper.step(512);
  tone(Buzzer, 1000, 500);
  myStepper.step(512);
  tone(Buzzer, 1000, 500);
  myStepper.step(512);
  tone(Buzzer, 1000, 500);
  myStepper.step(512);
  tone(Buzzer, 1000, 500);
  delay(500);
  Display = 1;
  
}

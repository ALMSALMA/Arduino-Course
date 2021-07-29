// ---------- Project 1 ---------- //

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(1000);
}

// ---------- Project 2 ---------- //

int Light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  Light = analogRead(A0);
  Serial.println(Light);
  delay(100);
  if(Light > 300 ){
      digitalWrite(2,HIGH);    
    }else{
      digitalWrite(2,LOW);
    }
}

// ---------- Project 3 ---------- //

int Count = 0;
int Button = 2; 
int Red = 3; 
int Green = 4; 
int Blue = 5; 

void setup() 
{
  Serial.begin(9600); 
  pinMode( Button, INPUT);
  pinMode( Red, OUTPUT);
  pinMode( Green, OUTPUT);
  pinMode( Blue, OUTPUT);

}
void loop() 
{
  if(!digitalRead(2)){
    Count++;
  } 
  if (Count == 0){
    
    leds ( 0 , 1 , 1 ) ;
    
  }else if(Count == 1){
    
    leds ( 1 , 0 , 1 ) ;
    
  }else if(Count == 2){
    
    leds ( 1 , 1 , 0 ) ;
    
}else
    Count = 0;
  
}

void leds (int a , int b , int c ) {
  digitalWrite(Red , a );
  digitalWrite(Green , b );
  digitalWrite(Blue , c );
}

// ---------- Project 4 ---------- //

int Buzzer = 4; 
int Red = 3; 
int Green = 6; 
int Yellow = 5; 

void setup() 
{
  Serial.begin(9600); 
  pinMode( Buzzer, OUTPUT);
  pinMode( Red, OUTPUT);
  pinMode( Green, OUTPUT);
  pinMode( Yellow, OUTPUT);

}
void loop() 
{
  leds ( 1 , 0 , 0 , 0 ) ;
  delay(15000);
  leds ( 0 , 0 , 1 , 0 ) ;
  delay(2000);
  leds ( 0 , 0 , 0 , 1 ) ;
  delay(500);
  leds ( 0 , 1 , 0 , 0 ) ;
  delay(10000);
}

void leds (int a , int b , int c , int d ) {
  digitalWrite(Red , a );
  digitalWrite(Green , b );
  digitalWrite(Yellow , c );
  digitalWrite(Buzzer , d );
}

// ---------- Project 5 ---------- //

#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Ultrasonic USSensor(3 , 4);
LiquidCrystal_I2C lcd(0x27,16,2);

int Distance;
int Button = 2; 

void setup() 
{
  Serial.begin(9600); 
  pinMode( Button, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

}
void loop() 
{
  if(!digitalRead(2)){
    Distance = USSensor.read();
    lcd.clear();
    lcd.print(Distance);
    
  }   
}

// ---------- Project 6 ---------- //

#include "LedControl.h"

LedControl LEDMAT = LedControl ( 7 , 6 , 5 , 1 ) ;

char M[] = {
            B01111111,
            B00000001,
            B00000010,
            B00000010,
            B00000001,
            B01111111,
           };

char O[] = {
            B01111111,
            B01000001,
            B01000001,
            B01000001,
            B01000001,
            B01111111,
           };

char H[] = {
            B01111111,
            B00001000,
            B00001000,
            B00001000,
            B00001000,
            B01111111,
           };

char A[] = {
            B01111110,
            B00001001,
            B00001001,
            B00001001,
            B00001001,
            B01111110,
           };

char D[] = {
            B01111111,
            B01000001,
            B01000001,
            B01000001,
            B01000001,
            B00111110,
           };

void setup() {
  LEDMAT.shutdown (0 , false ) ;
  LEDMAT.setIntensity ( 0 , 1) ;
  LEDMAT.clearDisplay (0);
}
void loop() {
  LEDMAT_M ();
  delay ( 1000 ) ;
  LEDMAT.clearDisplay (0);
  LEDMAT_O ();
  delay ( 1000 ) ;
  LEDMAT_H ();
  delay ( 1000 ) ;
  LEDMAT_A ();
  delay ( 1000 ) ;
  LEDMAT_M ();
  delay ( 1000 ) ;
  LEDMAT.clearDisplay (0);
  LEDMAT_A ();
  delay ( 1000 ) ;
  LEDMAT.clearDisplay (0);
  LEDMAT_D ();
  delay ( 1000 ) ;
  LEDMAT.clearDisplay (0);
  delay ( 1000 ) ;
}

void LEDMAT_A () {
  LEDMAT.setRow(0,1,A[0]);
  LEDMAT.setRow(0,2,A[1]);
  LEDMAT.setRow(0,3,A[2]);
  LEDMAT.setRow(0,4,A[3]);
  LEDMAT.setRow(0,5,A[4]);
  LEDMAT.setRow(0,6,A[5]);
}

void LEDMAT_O () {
  LEDMAT.setRow(0,1,O[0]);
  LEDMAT.setRow(0,2,O[1]);
  LEDMAT.setRow(0,3,O[2]);
  LEDMAT.setRow(0,4,O[3]);
  LEDMAT.setRow(0,5,O[4]);
  LEDMAT.setRow(0,6,O[5]);
}

void LEDMAT_H () {
  LEDMAT.setRow(0,1,H[0]);
  LEDMAT.setRow(0,2,H[1]);
  LEDMAT.setRow(0,3,H[2]);
  LEDMAT.setRow(0,4,H[3]);
  LEDMAT.setRow(0,5,H[4]);
  LEDMAT.setRow(0,6,H[5]);
}

void LEDMAT_D () {
  LEDMAT.setRow(0,1,D[0]);
  LEDMAT.setRow(0,2,D[1]);
  LEDMAT.setRow(0,3,D[2]);
  LEDMAT.setRow(0,4,D[3]);
  LEDMAT.setRow(0,5,D[4]);
  LEDMAT.setRow(0,6,D[5]);
}

void LEDMAT_M () {
  LEDMAT.setRow(0,1,M[0]);
  LEDMAT.setRow(0,2,M[1]);
  LEDMAT.setRow(0,3,M[2]);
  LEDMAT.setRow(0,4,M[3]);
  LEDMAT.setRow(0,5,M[4]);
  LEDMAT.setRow(0,6,M[5]);
}

// ---------- Project 7 ---------- //

#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht( 2 , DHT11 );
LiquidCrystal_I2C lcd(0x27,16,2);
float H,T;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  delay(1000);  
  lcd.setCursor(0,0);
  float H = dht.readHumidity();
  lcd.print("Hum: ");
  lcd.print(H);
  
  lcd.setCursor(0,1);
  float T = dht.readTemperature();
  lcd.print("Temp: ");
  lcd.print(T);
}

// ---------- Project 8 ---------- //

#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Ultrasonic USSensor(3 , 4);
LiquidCrystal_I2C lcd(0x27,16,2);

int Distance;

void setup() 
{
  Serial.begin(9600); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

}
void loop() 
{
    Distance = USSensor.read();
    lcd.clear();
    lcd.print(Distance);
    delay(300);
}

// ---------- Project 9 ---------- //

#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Ultrasonic USSensor(3 , 4);
LiquidCrystal_I2C lcd(0x27,16,2);

int Distance;

void setup() 
{
  Serial.begin(9600); 
  pinMode(2,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();

}
void loop() 
{
    Distance = USSensor.read();
    if ( Distance < 20 ) {
    digitalWrite ( 2 , HIGH );
    lcd.print("Distance < 20cm!");
    delay(300);
    lcd.clear();
  }
  else {
    digitalWrite ( 2 , LOW );
    lcd.print("Normal");
    delay(300);
    lcd.clear();
}}

// ---------- Project 10 ---------- //

#include <MaxMatrix.h>

MaxMatrix m ( 7 , 5 , 6 , 1 ) ;

char MOHAMAD[] = {48,8,
            B01111111,
            B00000001,
            B00000010,
            B00000010,
            B00000001,
            B01111111,
            B00000000,
            B01111111,
            B01000001,
            B01000001,
            B01000001,
            B01000001,
            B01111111,
            B00000000,
            B01111111,
            B00001000,
            B00001000,
            B00001000,
            B00001000,
            B01111111,
            B00000000,
            B01111110,
            B00001001,
            B00001001,
            B00001001,
            B00001001,
            B01111110,
            B00000000,
            B01111111,
            B00000001,
            B00000010,
            B00000010,
            B00000001,
            B01111111,
            B00000000,
            B01111110,
            B00001001,
            B00001001,
            B00001001,
            B00001001,
            B01111110,
            B00000000,
            B01111111,
            B01000001,
            B01000001,
            B01000001,
            B01000001,
            B00111110,
            B00000000,
           };

           
void setup() {
  m.init(); 
  m.setIntensity(5); 
}
void loop() {
  m.writeSprite(1, 0, MOHAMAD);
  for (int i=0; i<48; i++){
    m.shiftLeft(false,false);
    delay(300);
  }
  m.clear();
}

// ---------- Project 11 ---------- //

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mohammad AL MSALMA");
  delay(100);
}

void loop() {
  
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  delay(100);

}

// ---------- Project 12 ---------- //

int x;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  x = analogRead(A0); 
  if(x < 450){
    Serial.write ( 2 ) ;
    Serial.flush () ;
    delay ( 30 ) ;
  }else if(x > 650){
    Serial.write ( 1 ) ;
    Serial.flush () ;
    delay ( 30 ) ;
  }
  }

// ---------- Project 13 - 14 ---------- //

#include <SoftwareSerial.h>
#include "DHT.h"

SoftwareSerial bluetooth (7 , 8);
DHT dht( 4 , DHT11 );
int Y;
float T, H, B;
char x;

void setup() {
    Serial.begin(9600);
    bluetooth.begin(9600);
    pinMode ( A0 , INPUT );
    dht.begin();
}

void loop() {
  if (bluetooth.available() > 0 ) {
    x = bluetooth.read() ;
    if ( x == 'L' ) {
      Serial.println(analogRead(A0));
      Y = analogRead(A0);
      B = map(Y,0,1023,0,100);
      bluetooth.print("Brightness = ");
      bluetooth.print(B);
      bluetooth.println("%");
      
    }
    else if ( x == 'H' ) {
      H = dht.readHumidity();
      bluetooth.print("Humidity = ");
      bluetooth.println(H);
    }
    else if ( x == 'T' ) {
      T = dht.readTemperature();
      bluetooth.print("Temperature = ");
      bluetooth.println(T);
    }
  }
}

// ---------- Project 15 ---------- //

#include "DHT.h"

DHT dht( 4 , DHT11 );
float T;
int Buzzer = 3;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);
  dht.begin();
}

void loop() {

    T = dht.readTemperature();
    delay(100);
    if ( T > 40 )    
      digitalWrite(Buzzer,HIGH);
    else 
      digitalWrite(Buzzer,LOW);
}

// ---------- Project 16 ---------- //

#include <Servo.h>

Servo myservo;

int IR = 3;

void setup() {
  pinMode(IR,INPUT);
}
void loop() {

  if(!digitalRead(IR)){
    myservo.attach(4);
    delay(1);
    myservo.write(0);  
    delay(3000);       
    myservo.write(150);    
    delay(1000);
    myservo.detach();      
  }

}

// ---------- Project 17 ---------- //

#include <Stepper.h>

const int steps = 2048;
int Red = 8; 
int Green = 9; 
int Blue = 10; 

Stepper myStepper = Stepper( steps, 4, 6, 5, 7);

void setup() {
  myStepper.setSpeed(3);
  
  pinMode( Red, OUTPUT);
  pinMode( Green, OUTPUT);
  pinMode( Blue, OUTPUT);
}
void loop() {
  myStepper.step(400);
  Leds(1,0,0);
  delay(5);
  myStepper.step(400);
  Leds(0,1,0);
  
  delay(5);
  myStepper.step(400);
  Leds(0,0,1);
  delay(5);
}

void Leds (int a , int b , int c ) {
  digitalWrite(Red , a );
  digitalWrite(Green , b );
  digitalWrite(Blue , c );
}

// ---------- Project 18 ---------- //

#include <Stepper.h>

const int steps = 2048;
int IR = 3;

Stepper myStepper = Stepper( steps, 4, 6, 5, 7);

void setup() {
  myStepper.setSpeed(8);
  pinMode(IR,INPUT);
}
void loop() {

  if(!digitalRead(IR)){
    myStepper.step(300);
    delay(5);
  }

}

// ---------- Project 19 ---------- //

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(7, 8); // RX,TX

void setup() {
  Serial.begin(9600);
  bluetooth.begin (9600);
}

void loop() {
  if (bluetooth.available() > 0 ){
    char x = bluetooth.read() ;
    if(x == '1'){
      Serial.write((int)x-48);
      Serial.flush () ;
      delay ( 1 ) ;}
  }}

// ---------- Project 20 ---------- //

int Button = 4;
int Buzzer = 3;
int IR = 2;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);
  pinMode(IR,INPUT);
  pinMode(Button,INPUT);
}

void loop() {
  if(!digitalRead(Button)){
    if(digitalRead(IR) == 0){
      digitalWrite(Buzzer,HIGH);   
    }else
      digitalWrite(Buzzer,LOW);   
   }
}

// ---------- Project 21 ---------- //

int LED = 2;
int Button1 = 3;
int Button2 = 4;

int Choice = 1;
int ON_OFF = 0;
int Speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  if(!digitalRead(Button1)){
    Choice = 1;
    ON_OFF = !ON_OFF;
    delay(500);
   }
   if(!digitalRead(Button2)){
    Choice = 2;
    Speed = !Speed;
    delay(500);
    }
    if(Choice == 1){
      if(ON_OFF)
        digitalWrite(LED,HIGH);
      else
        digitalWrite(LED,LOW);
   }else if(Choice == 2){
       if(Speed){
          digitalWrite(LED,HIGH);
          delay(500);
          digitalWrite(LED,LOW);
          delay(500);
       }else{
          digitalWrite(LED,HIGH);
          delay(100);
          digitalWrite(LED,LOW);
          delay(100);
       }
   }
}

// ---------- Project 22 ---------- //

int Button1 = 2;
int Button2 = 3;
int Button3 = 4;
int Red = 5; 
int Green = 6; 
int Blue = 7; 

int BrightnessR = 255;
int BrightnessG = 255;
int BrightnessB = 255;
int Brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  pinMode(Button3,INPUT);
  pinMode( Red, OUTPUT);
  pinMode( Green, OUTPUT);
  pinMode( Blue, OUTPUT);
  pinMode( A0, INPUT);
  Leds(BrightnessR,BrightnessG,BrightnessB );  
}

void loop() {
  
  if(!digitalRead(Button1)){
    Brightness = analogRead(A0);
    BrightnessR = map(Brightness,0,1023,0,255);
    Leds(BrightnessR,BrightnessG,BrightnessB );
   }
   if(!digitalRead(Button2)){
    Brightness = analogRead(A0);
    BrightnessG = map(Brightness,0,1023,0,255);
    Leds(BrightnessR,BrightnessG,BrightnessB );
   }  
   if(!digitalRead(Button3)){
    Brightness = analogRead(A0);
    BrightnessB = map(Brightness,0,1023,0,255);
    Leds(BrightnessR,BrightnessG,BrightnessB );
   }
}

void Leds (int a , int b , int c ) {
  analogWrite(Red , a );
  analogWrite(Green , b );
  analogWrite(Blue , c );
}

// ---------- Project 23 ---------- //

#include <SoftwareSerial.h>
#include <Ultrasonic.h>


SoftwareSerial bluetooth(10,9); // RX,TX
Ultrasonic USSensor(5 , 6);

int Button1 = 2;
int Button2 = 3;
int IR = 4;
int Distance;

void setup() {
  Serial.begin(9600);
  bluetooth.begin (9600);
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  pinMode(IR,INPUT);
}

void loop() {
  if(!digitalRead(Button1)){
    Distance = USSensor.read();
    bluetooth.print("Distance = ");
    bluetooth.println(Distance);
    delay(500);
  }
  if(!digitalRead(Button2)){
    bluetooth.print("IR = ");
    bluetooth.println(digitalRead(IR));
    delay(500);
  }
}

// ---------- Project 24 ---------- //

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

char ch;
void dot(){lcd.print(".");}
void dash(){lcd.print("-");}
void  A () {dot();dash(); }
void  B () {dash();dot();dot();dot(); }
void  C () {dash();dot();dash();dot(); }
void  D () {dash();dot();dot(); }
void  E () {dot(); }
void  f () {dot();dot();dash();dot(); }
void  G () {dash();dash();dot(); }
void  H () {dot();dot();dot();dot(); }
void  I () {dot();dot(); }
void  J () {dot();dash();dash();dash(); }
void  K () {dash();dot();dash(); }
void  L () {dot();dash();dot();dot(); }
void  M () {dash();dash(); }
void  N () {dash();dot(); }
void  O () {dash();dash();dash(); }
void  P () {dot();dash();dash();dot(); }
void  Q () {dash();dash();dot();dash(); }
void  R () {dot();dash();dot(); }
void  S () {dot();dot();dot(); }
void  T () {dash(); }
void  U () {dot();dot();dash(); }
void  V () {dot();dot();dot();dash(); }
void  W () {dot();dash();dash(); }
void  X () {dash();dot();dot();dash(); }
void  Y () {dash();dot();dash();dash(); }
void  Z () {dash();dash();dot();dot(); }
void one(){dot();dash();dash();dash();dash();}
void two(){dot();dot();dash();dash();dash();}
void three(){dot();dot();dot();dash();dash();}
void four(){dot();dot();dot();dot();dash();}
void five(){dot();dot();dot();dot();dot();}
void six(){dash();dot();dot();dot();dot();}
void seven(){dash();dash();dot();dot();dot();}
void eight(){dash();dash();dash();dot();dot();}
void nine(){dash();dash();dash();dash();dot();}
void zero(){dash();dash();dash();dash();dash();}

void setup() {
Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter a Ch:");
}
void loop() {
while (Serial.available())
{   
  lcd.setCursor(0,1);
  ch = Serial.read();
  if (ch == 'A' || ch == 'a'){A();lcd.print(" ");}
  else if (ch == 'B' || ch == 'b'){B();lcd.print("   ");}
  else if (ch == 'C' || ch == 'c'){C();lcd.print("   ");}
  else if (ch == 'D' || ch == 'd'){D();lcd.print("   ");}
  else if (ch == 'E' || ch == 'e'){E();lcd.print("   ");}
  else if (ch == 'F' || ch == 'f'){f();lcd.print("   ");}
  else if (ch == 'G' || ch == 'g'){G();lcd.print("   ");}
  else if (ch == 'H' || ch == 'h'){H();lcd.print("   ");}
  else if (ch == 'I' || ch == 'i'){I();lcd.print("   ");}
  else if (ch == 'J' || ch == 'j'){J();lcd.print("   ");}
  else if (ch == 'K' || ch == 'k'){K();lcd.print("   ");}
  else if (ch == 'L' || ch == 'l'){L();lcd.print("   ");}
  else if (ch == 'M' || ch == 'm'){M();lcd.print("   ");}
  else if (ch == 'N' || ch == 'n'){N();lcd.print("   ");}
  else if (ch == 'O' || ch == 'o'){O();lcd.print("   ");}
  else if (ch == 'P' || ch == 'p'){P();lcd.print("   ");}
  else if (ch == 'Q' || ch == 'q'){Q();lcd.print("   ");}
  else if (ch == 'R' || ch == 'r'){R();lcd.print("   ");}
  else if (ch == 'S' || ch == 's'){S();lcd.print("   ");}
  else if (ch == 'T' || ch == 't'){T();lcd.print("   ");}
  else if (ch == 'U' || ch == 'u'){U();lcd.print("   ");}
  else if (ch == 'V' || ch == 'v'){V();lcd.print("   ");}
  else if (ch == 'W' || ch == 'w'){W();lcd.print("   ");}
  else if (ch == 'X' || ch == 'x'){X();lcd.print("   ");}
  else if (ch == 'Y' || ch == 'y'){Y();lcd.print("   ");}
  else if (ch == 'Z' || ch == 'z'){Z();lcd.print("   ");}
  else if (ch == '0'){zero();lcd.print("   ");}
  else if (ch == '1'){one();lcd.print("   ");}
  else if (ch == '2'){two();lcd.print("   ");}
  else if (ch == '3'){three();lcd.print("   ");}
  else if (ch == '4'){four();lcd.print("   ");}
  else if (ch == '5'){five();lcd.print("   ");}
  else if (ch == '6'){six();lcd.print("   ");}
  else if (ch == '7'){seven();lcd.print("   ");}
  else if (ch == '8'){eight();lcd.print("   ");}
  else if (ch == '9'){nine();lcd.print("   ");}
  }
}

// ---------- Project 25 ---------- //

#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;

SoftwareSerial bluetooth(8,9); // RX,TX

int LED = 2;

void setup() {
  pinMode(LED,OUTPUT);
  bluetooth.begin (9600);
  myservo.attach(4);
  myservo.write(180);  
  delay(3000);      
}
void loop() {
    if (bluetooth.available() > 0 ){
    char x = bluetooth.read() ;
    if(x == '1'){
      delay(1);
      digitalWrite(LED,HIGH);
      myservo.write(15);  
      delay(3000);      
    }else if(x == '2'){ 
      digitalWrite(LED,LOW); 
      myservo.write(180);    
      delay(3000);
    }
  }
}

// ---------- Project 26 ---------- //

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10,9); // RX,TX

int Buzzer = 2;
int Delay, Turn = 0;
char x;

void setup() {
  Serial.begin(9600);
  bluetooth.begin (9600);
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  Turn = 0;
  if (bluetooth.available() > 0 ){
    x = bluetooth.read() ;
    if(x == '1'){
      bluetooth.println("Please enter the duration :)");
      Turn = 1;
    }
    while(Turn){
      if (bluetooth.available() > 0 ){
        x = bluetooth.read() ;
        Delay = ((int)x-48)*1000;  
        digitalWrite(Buzzer,HIGH);
        delay(Delay);
        digitalWrite(Buzzer,LOW);
        break;
      }
    }
  }
}

// ---------- Project 27 ---------- //

int IR = 3;
int RLED = 4;
int GLED = 5;
String Password = "";

void setup() {
  Serial.begin(9600);
  pinMode(IR,INPUT);
  pinMode(RLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  digitalWrite(RLED,HIGH);
}
void loop() 
{   
    if (!digitalRead(IR)){        
      Serial.println("Please Enter the password:");      
      delay(500);
      while(!Serial.available());    
      Password = Serial.readString();
      Password.trim();      
      delay(500);
      if (Password == "12345"){
        digitalWrite(RLED,LOW);
        digitalWrite(GLED,HIGH);
        Serial.println("Correct Password :)");                
      }else        
        Serial.println("Wrong Password :(");   
    }
  }

// ---------- Project 28 ---------- //

#include "DHT.h"
#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht( 3 , DHT11 );
Ultrasonic USSensor(4 , 5);

float T;
int Distance;
int Direction;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);  
  dht.begin();
}
void loop() 
{ 
  Direction = analogRead(A0);
  if (Direction > 650){
    lcd.clear();
    T = dht.readTemperature();
    lcd.print("Temp = ");
    lcd.print(T);      
    delay(300);
  }else if(Direction < 450){
    Distance = USSensor.read();
    lcd.clear();
    lcd.print("Distance = ");
    lcd.print(Distance);   
    delay(300);
  }else{    
    lcd.clear();
    lcd.print("Turn R or L");   
    delay(300);
  }
}

// ---------- Project 29 ---------- //

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

char ch;
int Button = 2;

void setup() {
  Serial.begin(9600);
  pinMode(Button,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
}
void loop() {
  if(!digitalRead(Button)){
    for(int i = 60; i >= 0; i--){
      lcd.clear();
      lcd.print(i);
      delay(1000);
    }
     lcd.clear();
     lcd.print("Time out!!");
   }

}

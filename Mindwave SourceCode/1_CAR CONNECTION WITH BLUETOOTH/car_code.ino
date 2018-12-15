#include<SoftwareSerial.h>

//MotorContoller
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 13;
const int ENB = 12;

//Bluetooth 
#define TxD 10
#define RxD 11
#define LED_PIN 8
SoftwareSerial bluetoothSerial(TxD, RxD);
char c;
int speed = 255;

void setup() {
  //Setup Motorcontroller
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  //Setup Bluetooth
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {

  
  if(bluetoothSerial.available()){
    c = bluetoothSerial.read();
    Serial.println(c);
    Serial.println(speed);
    if( c == '1') //forward
    {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        
    
  analogWrite(ENA, speed);
 analogWrite(ENB, speed);
    }
     
     else if( c == '2')  //Backword
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
    }
      else if( c == '3')  //Right
    {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
    }
      if( c == '4') //Left
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
    } 
    if( c == '0') //Stop
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
    }
      if( c == '5') //inc Speed
    {
     speed = speed + 30;
    }    
      if( c == '6' ) //dec Speed
    {
     speed = speed - 30;
    }
          if(c=='7'){
      digitalWrite(LED_PIN, HIGH);          
    }
      if(c == '8'){
      digitalWrite(LED_PIN, LOW);
    }
  }

}

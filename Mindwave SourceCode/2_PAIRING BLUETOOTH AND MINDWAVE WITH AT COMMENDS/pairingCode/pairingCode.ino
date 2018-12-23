/*
  *Configuration through AT Commands for HC-05
  *Pairing  Headset Neurosky Mindwave Mobile with Arduino
  *Commands:
  *   AT+UART=57600,0,0
  *   AT+ROLE=1
  *   AT+PSWD=0000    "1234"
  *   AT+CMODE=0
  *   AT+BIND=<Address>  ( 2471,89,E965B2 )
  *   AT+IAC=9E8B33
  *   AT+CLASS=0
  *   AT+INQM=1,9,48
  *   
  *   Lozano Ramirez Angel Ivan
  *   02.07.2018
*/


#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); //RXD,TXD
 
void setup(){
  BT.begin(38400);
  Serial.begin(38400);
}
 
void loop(){
  if( BT.available() ){
    Serial.write( BT.read() );
  }
 
  if( Serial.available() ){
     BT.write( Serial.read() );
  }
}

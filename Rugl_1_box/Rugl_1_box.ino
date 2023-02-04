#include <GyverNTC.h>
#include<SoftwareSerial.h>
boolean pol=0;
float te;
float a=39,b;


#define nag A4 //реле на переключ
#define po_pit A2 // вент и общ на модуль 
#define pover 7 // инд. раб. Все +темп
#define rx_b 3
#define tx_b 4
#define uprav 10



GyverNTC therm(A3, 10000, 3950);
SoftwareSerial softSerial(rx_b, tx_b); // RX, TX
void setup() {

   softSerial.begin(38400);
   softSerial.setTimeout(500);// общение через блютуз
    pinMode(pover,OUTPUT);
    pinMode(po_pit,OUTPUT);
    pinMode(nag,OUTPUT);
pinMode(uprav,OUTPUT);
digitalWrite(uprav,1);
softSerial.readString();
 while(!softSerial.available()){delay(200);}
 if(softSerial.available()){
  b=softSerial.parseInt();
if(b==255){
softSerial.print("pov off");
delay(2000);
digitalWrite(pover,0);
digitalWrite(po_pit,0);
digitalWrite(nag,0);
digitalWrite(uprav,0);

while(true);
}}
digitalWrite(po_pit, 1);
digitalWrite(pover,1);

}

void loop() {
 if(softSerial.available()){
  b=softSerial.parseInt();
if(b==255){
softSerial.print("pov off");
delay(2000);
digitalWrite(pover,0);
digitalWrite(po_pit,0);
digitalWrite(nag,0);
digitalWrite(uprav,0);

while(true);
}
  if (b<51 && b>19){
    a=b;

 softSerial.println("set:");
softSerial.println(a);
  }}
    te=(therm.getTempAverage());
  softSerial.println(te);
  if (te-1<a && pol==0 ){
        digitalWrite(nag,HIGH);
      pol=1;
      }
      else if(te+1>a && pol==1 ){
        digitalWrite(nag,LOW);
      pol=0;
      }
     // if(vk==1){digitalWrite(vent,LOW);digitalWrite(pover,HIGH);}
   //   else {digitalWrite(vent,HIGH);digitalWrite(pover,LOW);}
   delay(1500);
}

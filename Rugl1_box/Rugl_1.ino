#include <GyverNTC.h>
boolean pol=0;
float te;
float a,b;
boolean vk=0;

#define u1 6 // 1 and 4
#define u2 5 // 2 and 3
#define vent 7 // вентелятор 
#define pover 2 // инд. раб.



GyverNTC therm(A5, 10000, 3950);
void setup() {

   Serial.begin(9600);
   Serial.setTimeout(1500);// общение через блютуз
    pinMode(u1,OUTPUT);
    pinMode(u2,OUTPUT);
    pinMode(vent,OUTPUT);
    pinMode(pover,OUTPUT);
}

void loop() {
  digitalWrite(vent,HIGH);digitalWrite(pover,HIGH);
 if(Serial.available()){
  b=Serial.parseInt();
  if (b==0)vk=0;
  if (b<51 && b>19){
    a=b;

    Serial.println(a);
  }}
    te=(therm.getTempAverage());
  Serial.println(te);
  if (te-1<a && pol==0 ){
        digitalWrite(u2,LOW);
        digitalWrite(u1,HIGH);//нагрев
      pol=1;
      }
      else if(te+1>a && pol==1 ){
        digitalWrite(u1,LOW);//охлад
        digitalWrite(u2,HIGH);
      pol=0;
      }
     // if(vk==1){digitalWrite(vent,LOW);digitalWrite(pover,HIGH);}
   //   else {digitalWrite(vent,HIGH);digitalWrite(pover,LOW);}
   delay(1500);
}

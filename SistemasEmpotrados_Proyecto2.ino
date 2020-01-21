// falta descomentar para que no imprima VT y FOCO , falta agregar el sensor de c02, 
#include "DHTesp.h"
#define DHTpin 16            //D0 of NodeMCU is GPIO16
DHTesp dht;
// VARIABLES  ---------------
    
int ventiladorT = 4;          //GPIO04  -- D2
int foco = 5;                 //GPIO05  -- D1
int temperatura_limite = 30;
int humedad_limite = 50;  

//---------------------------

void setup()
{
  pinMode(foco,OUTPUT); 
  pinMode(ventiladorT,OUTPUT); 
  digitalWrite(ventiladorT,LOW);  
  Serial.begin(9600);
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17 
}
void loop(){
sensado();
controlaotomatico();
}
void sensado(){
  delay(5000);
  float h = dht.getHumidity();
  float t = dht.getTemperature();

//Serial.print(dht.getStatusString());
//  Serial.print("\t");
//  Serial.print(h, 1);
//  Serial.print("\t\t");
//  Serial.println(t, 1);

 Serial.println(t);
 Serial.println(h);
 
}

void controlaotomatico(){
   float h = dht.getHumidity();
   float t = dht.getTemperature();

 
if(t >temperatura_limite){
      digitalWrite (ventiladorT,HIGH);
      digitalWrite(ventiladorT,HIGH);
      digitalWrite(foco,HIGH);
//      Serial.println(">>FOCO OFF || VT ON<< ");
        }       
        else{
      digitalWrite(ventiladorT,LOW);
      digitalWrite(foco,LOW);
//      Serial.println(">>FOCO ON|| VT OFF<<<< ");
}
}

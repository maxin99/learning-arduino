#include <Arduino.h>

//This file includes a test to see how the ultrasonic sensor works.
//Piece: HC SR04

const int trigPin = 7;
const int echoPin = 6;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  long duracion;
  float distancia;

  //ASEGURAMOS TRIG EN LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Enviamos un pulso de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Medimos el tiempo del echo
  duracion = pulseIn(echoPin, HIGH);

  //Convertimos en distancia(cm)
  distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
  
  delay(500);

}
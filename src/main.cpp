#include <Arduino.h>

// --------- Pines del L298N ---------
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
const int ENB = 6;

//Prototipos de funciones
void engineAForward();
void engineBForward();
void advance();
void backwards();
void goLeft();
void goRight();
void stopEngines();

//Velocidad de prueba (0 -255)
int velocidad = 180;

void setup() {
  //Declaramos los pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  //Por seguirdad, todo parado
  stopEngines();

  //Espera breve para arranque estable
  delay(1000);
}


void loop() {
  //1- Probar motor A solo
  engineAForward();
  delay(2000);
  stopEngines();
  delay(1000);

  //2. Probar motor B solo
  engineBForward();
  delay(2000);
  stopEngines();
  delay(1000);

  //3. Ambos motores adelante
  advance();
  delay(2000);
  stopEngines();
  delay(1000);

  //4. Ambos motores atrás
  backwards();
  delay(2000);
  stopEngines();
  delay(1000);

  //5. Giro a la izquierda
  goLeft();
  delay(2000);
  stopEngines();
  delay(1000);

  //6. Giro a la derecha
  goRight();
  delay(2000);
  stopEngines();
  delay(1000);

}


// ------Funciones de movimiento ------

void engineAForward() {
  analogWrite(ENA, velocidad); //activamos motor A con velocidad
  analogWrite(ENB, 0); //paramos motor B

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void engineBForward() {
  analogWrite(ENA, 0); //PARAMOS motor A 
  analogWrite(ENB, velocidad); //activamos motor B con velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void advance() {
  analogWrite(ENA, velocidad); //PARAMOS motor A 
  analogWrite(ENB, velocidad); //activamos motor B con velocidad

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backwards() {
  analogWrite(ENA, velocidad); //PARAMOS motor A 
  analogWrite(ENB, velocidad); //activamos motor B con velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void goLeft(){
  analogWrite(ENA, velocidad); //PARAMOS motor A 
  analogWrite(ENB, velocidad); //activamos motor B con velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void goRight(){
  analogWrite(ENA, velocidad); //PARAMOS motor A 
  analogWrite(ENB, velocidad); //activamos motor B con velocidad

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopEngines() {
  analogWrite(ENA, 0); //PARAMOS motor A 
  analogWrite(ENB, 0); //activamos motor B con velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
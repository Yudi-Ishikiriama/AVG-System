#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h> 


Servo servo;

const int A1B = 8;//verde
const int A1A = 9;//azul
const int B1A = 13;//amarelo
const int B1B = 12;//roxo




int pinReed = 12;
int pinServo = 13;
const int speed = 50;


//Funções

void stopMotors()
{
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, HIGH);
  Serial.println("parou");
}

void moveForward()
{
  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
  Serial.println("frente");
}

void moveBackwards() {
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  digitalWrite(B1B, HIGH);
  digitalWrite(B1A, LOW);
  Serial.println("tras");
}

void turnLeft()
{
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
  Serial.println("esquerda");
}

void turnRight()
{
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  Serial.println("direita");
}

void motorbt(){
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, LOW);
  Serial.println("motorbt");
}
void motorbf(){
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
  Serial.println("motorbf");
}

void motora(){
  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
  digitalWrite(B1B, HIGH);
  digitalWrite(B1A, HIGH);
  Serial.println("motorafrente");
}

void motorat(){
  digitalWrite(A1B, HIGH);
  digitalWrite(A1A, LOW);
  digitalWrite(B1B, HIGH);
  digitalWrite(B1A, HIGH);
  Serial.println("motoratras");
}

void moveFork()
{
  servo.write(180);
  delay(1000);
  servo.write(0);
  delay(1000);
}

//Programa Principal

void setup()
{
  Serial.begin(9600);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
}

void loop()
{
  motorbt();
  
}
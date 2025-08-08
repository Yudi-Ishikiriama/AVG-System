#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h> 

#define pinTrig 4 // Ultrassom Trig
#define pinEcho 5 // Ultrassom Echo

Servo servo;

int pinMotorEsquerda = 9;
int pinFotoEsquerda = A1;

int pinMotorDireita = 10;
int pinFotoDireita = A2;

int pinReed = 12;
int pinServo = 13;

Ultrasonic ultrasonic(pinTrig, pinEcho);
int distance;
int pos;

//Funções

void stopMotors()
{
  digitalWrite(pinMotorEsquerda, LOW);
  digitalWrite(pinMotorDireita, LOW);
}

void moveForward()
{
  digitalWrite(pinMotorEsquerda, HIGH);
  digitalWrite(pinMotorDireita, HIGH);
}

void turnLeft()
{
  digitalWrite(pinMotorEsquerda, LOW);
  digitalWrite(pinMotorDireita, HIGH);
}

void turnRight()
{
  digitalWrite(pinMotorEsquerda, HIGH);
  digitalWrite(pinMotorDireita, LOW);
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
  pinMode(pinFotoEsquerda, INPUT);
  pinMode(pinFotoDireita, INPUT);
  pinMode(pinMotorEsquerda, OUTPUT);
  pinMode(pinMotorDireita, OUTPUT);
  servo.attach(pinServo);
  servo.write(0);
  Serial.begin(9600);
}

void loop()
{
  distance = ultrasonic.read();
  bool blocked = (distance < 15 || ((digitalRead(pinFotoEsquerda)) && (digitalRead(pinFotoDireita))));

  if (blocked)
  {
    Serial.println("Stop");
    stopMotors();
  }

  if (!blocked && !digitalRead(pinReed)) 
  {
    Serial.println("Local Encontrado");
    stopMotors();
    moveFork();
  }

  if (!blocked && (digitalRead(pinFotoEsquerda)) && !(digitalRead(pinFotoDireita)))
  {
    Serial.println("Esquerda");
    turnLeft();
  }
  
  if (!blocked && (digitalRead(pinFotoDireita)) && !(digitalRead(pinFotoEsquerda)))
  {
    Serial.println("Direita");
    turnRight();
  }

  if (!blocked && !(digitalRead(pinFotoEsquerda)) && !(digitalRead(pinFotoDireita)))
  {
    Serial.println("Segue");
    moveForward();
  }
  
  delay(250);
}
#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h> 

#define pinTrig 4 // Trig
#define pinEcho 5 // Echo

Servo servo;

int pinMotorEsquerda = 9;
int pinMotorDireita = 10;
int pinReed = 12;
int pinServo = 13;
int pinFotoEsquerda = A1;
int pinFotoDireita = A2;

Ultrasonic ultrasonic(pinTrig, pinEcho);
int distance;
int pos;

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
  if (distance < 15 || ((digitalRead(pinFotoEsquerda)) && (digitalRead(pinFotoDireita))))
  {
    Serial.println("Stop");
    digitalWrite(pinMotorEsquerda, LOW);
    digitalWrite(pinMotorDireita, LOW);
  }
  else if (!digitalRead(pinReed))
  {
    Serial.println("Local Encontrado");
    digitalWrite(pinMotorEsquerda, LOW);
    digitalWrite(pinMotorDireita, LOW);
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);
  }
  else if ((digitalRead(pinFotoEsquerda)) && !(digitalRead(pinFotoDireita)))
  {
    Serial.println("Esquerda");
    digitalWrite(pinMotorEsquerda, LOW);
    digitalWrite(pinMotorDireita, HIGH);
  }
  else if ((digitalRead(pinFotoDireita)) && !(digitalRead(pinFotoEsquerda)))
  {
    Serial.println("Direita");
    digitalWrite(pinMotorEsquerda, HIGH);
    digitalWrite(pinMotorDireita, LOW);
  }
  else
  {
    Serial.println("Continue");
    digitalWrite(pinMotorEsquerda, LOW);
    digitalWrite(pinMotorDireita, LOW);
  }
  delay(250);
}
#include <Arduino.h>
#include <Ultrasonic.h>

#define pt 4 // Trig
#define pe 5 // Echo

// Function declarations:
int pinMotorEsquerda = 9;
int pinMotorDireita = 10;
int pinFotoEsquerda = A1;
int pinFotoDireita = A2;

Ultrasonic ultrasonic(pt, pe);
int distance;

void setup()
{
  pinMode(pinFotoEsquerda, INPUT);
  pinMode(pinFotoDireita, INPUT);
  pinMode(pinMotorEsquerda, OUTPUT);
  pinMode(pinMotorDireita, OUTPUT);
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
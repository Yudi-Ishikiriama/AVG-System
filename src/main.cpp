#include <Arduino.h>
#include <Ultrasonic.h>

#define pt 4 //Trig
#define pe 5 //Echo

// put function declarations here:
int pinMotor = 9;
int pinFotoEsquerda = A1;
int pinFotoDireita = A2;

Ultrasonic ultrasonic(pt, pe);
int distance;

void setup() {
  pinMode(pinFotoEsquerda, INPUT);
  pinMode(pinFotoDireita, INPUT);
  pinMode(pinMotor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  if(distance < 15 || ((digitalRead(pinFotoEsquerda))&&(digitalRead(pinFotoDireita)))){
    Serial.println("Stop");
    digitalWrite(pinMotor, LOW);
  }
  else if((digitalRead(pinFotoEsquerda)) && !(digitalRead(pinFotoDireita))){
    Serial.println("Esquerda");
  }
  else if((digitalRead(pinFotoDireita)) && !(digitalRead(pinFotoEsquerda))){
    Serial.println("Direita");
  }
  else{
    Serial.println("Continue");
    digitalWrite(pinMotor, HIGH);
  }
  delay(250);
}

// put function definitions here:
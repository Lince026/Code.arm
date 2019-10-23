#include <Ultrasonic.h>
#define pino_trigger 6
#define pino_echo 7
Ultrasonic ultrasonic(pino_trigger, pino_echo);

int led13 = 13;
int led12 =  12;

float seno;
int frequencia;

void setup() {
  Serial.begin(9600);
  Serial.println("lendo dados do sensor....");
  pinMode(led13, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop() {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  noTone(9);
  if (cmMsec <= 35)
  {
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led12, HIGH);
    delay(100);
    digitalWrite(led13, LOW);
    delay(200);
    digitalWrite(led12, HIGH);
    delay(100);
    digitalWrite(led12, LOW);
    delay(100);
    tone(9, 262, 200); //DO
    delay(300);
    tone(9, 294, 300); //RE
    delay(300);
  }
  else(cmMsec >= 35);
  {
    noTone(9);
  }

}

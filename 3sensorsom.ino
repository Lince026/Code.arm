#include <Ultrasonic.h>
#define pino_trigger1 22
#define pino_trigger2 24
#define pino_trigger3 26
#define pino_echo1 23
#define pino_echo2 25
#define pino_echo3 27
#define lado 8.5
Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);
Ultrasonic ultrasonic3(pino_trigger3, pino_echo3);

void setup() {
  Serial.begin(19200);
  Serial.println("lendo dados do sensor....");
}


void loop() {
  float cmMsec1, inMsec1;
  long microsec1 = ultrasonic1.timing();
  cmMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  inMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::IN);
  Serial.print("Distancia em cm direita: ");
  Serial.print(cmMsec1);
  Serial.print(" - Distancia em polegadas direita: ");
  Serial.println(inMsec1);

  float cmMsec2, inMsec2;
  long microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  inMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::IN);
  Serial.print("Distancia em cm esquerda: ");
  Serial.print(cmMsec2);
  Serial.print(" - Distancia em polegadas esquerda: ");
  Serial.println(inMsec2);

  float cmMsec3, inMsec3;
  long microsec3 = ultrasonic3.timing();
  cmMsec3 = ultrasonic3.convert(microsec3, Ultrasonic::CM);
  inMsec3 = ultrasonic3.convert(microsec3, Ultrasonic::IN);
  Serial.print("Distancia em cm frente: ");
  Serial.print(cmMsec3);
  Serial.print(" - Distancia em polegadas frente: ");
  Serial.println(inMsec3);
}

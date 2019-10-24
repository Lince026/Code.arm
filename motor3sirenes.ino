#include <Ultrasonic.h>
#define pino_trigger1 22
#define pino_trigger2 24
#define pino_trigger3 26
#define pino_echo1 23
#define pino_echo2 25
#define pino_echo3 27
#define distancia_lado 15
#define distancia_frente 45
Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);
Ultrasonic ultrasonic3(pino_trigger3, pino_echo3);

int led13 = 13;
int led12 =  12;

float seno;
int frequencia;

//motor_A
int IN1 = 2 ;
int IN2 = 4 ;

//motor_B
int IN3 = 3 ;
int IN4 = 5 ;
void frente() {
  /*Inicio dos Estados do motor A*/
  ///direita frente
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //frente esquerda
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {
  //direita tras
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //tras esquerda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita() {
  //direita tras
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void esquerda() {
  //tras esquerda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void para() {
  //Freia direita
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  //Freia esquerda
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void sireneeluz() {
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
  tone(11, 2622, 200); //DO
  delay(300);
  tone(11, 2114, 300); //RE
  delay(300);
}
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  Serial.println("lendo dados do sensor....");
  pinMode(led13, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(11, OUTPUT);
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
  noTone(11);
    if (cmMsec3 <= distancia_frente){
    para();
  }
  else if (cmMsec1 <= distancia_lado){
    direita();
    sireneeluz();
  }
  else if (cmMsec2 <= distancia_lado){
    esquerda();
    sireneeluz();
  }
  else if (cmMsec3 >= 35){
   frente();
  }
  }
  

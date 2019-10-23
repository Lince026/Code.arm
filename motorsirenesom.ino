#include <Ultrasonic.h>
#define pino_trigger 6
#define pino_echo 7
#define distancia 20
Ultrasonic ultrasonic(pino_trigger, pino_echo);

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

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Serial.begin(9600);
  // Serial.println("lendo dados do sensor....");
  pinMode(led13, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Serial.print("Distancia em cm: ");
  //Serial.print(cmMsec);
  //Serial.print(" - Distancia em polegadas: ");
  //Serial.println(inMsec);
  noTone(11);
  if (cmMsec <= distancia)
  {
    esquerda();
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
  else (cmMsec >= distancia);
  {
    frente();
    noTone(11);
  }
}

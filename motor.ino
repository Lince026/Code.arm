/*Pinagem do arduino*/

//motor_A
int IN1 = 2 ;
int IN2 = 4 ;

//motor_B
int IN3 = 3 ;
int IN4 = 5 ;


//Inicializa Pinos
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

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
void loop() {
  //frente();
  //tras();
  //direita();
  //esquerda();
  //para();

}

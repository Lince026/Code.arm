// Define os pinos de utilização do Driver L298.
const int motorA1  = 2;    // Pin  5 of L293.
const int motorA2  = 3;    // Pin  6 of L293.
const int motorB1  = 4;   // Pin 10 of L293.
const int motorB2  = 5;   // Pin 9 of L293.

const int buzzer = 12 ;   // Define o Pino 13 como pino do Buzzer.

const int BTState = 2;    // Define o Pino 2 como o pino de comunicação do Bluetooth.

// Variáveis Úteis
int i = 0;
int j = 0;
int state_rec;
int vSpeed = 200;   // Define velocidade padrão 0 < x < 255.
char state;

void setup() {
  // Inicializa as portas como entrada e saída.
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);

  // Inicializa a comunicação serial em 9600 bits.
  Serial.begin(9600);
}

void loop() {
  // Para o carro quando a conexão com Bluetooth é perdida ou desconectada.
  if (digitalRead(BTState) == LOW) {
    state_rec = 'S';
  }

  // Salva os valores da variável 'state'
  if (Serial.available() > 0) {
    state_rec = Serial.read();
    state = state_rec;
    //   Serial.println(vSpeed);
  }

  // Altera a velocidade de acordo com valores especificados.
  if (state == '0') {
    vSpeed = 0;
  }
  else if (state == '4') {
    vSpeed = 100;
  }
  else if (state == '6') {
    vSpeed = 155;
  }
  else if (state == '7') {
    vSpeed = 180;
  }
  else if (state == '8') {
    vSpeed = 200;
  }
  else if (state == '9') {
    vSpeed = 230;
  }
  else if (state == 'q') {
    vSpeed = 255;
  }

  if (state != 'S') {
    Serial.print(state);
  }

  // Se o estado recebido for igual a 'F', o carro se movimenta para frente.
  if (state == 'F') {
    digitalWrite(motorB1, vSpeed);
    digitalWrite(motorA1, vSpeed);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB2, 0);
  }

    else if (state == 'I') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
    digitalWrite(motorA1, vSpeed); 
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 100);    
    digitalWrite(motorB2, 0);
  }

    else if (state == 'G') {   // Se o estado recebido for igual a 'G', o carro se movimenta para Frente Direita.
    digitalWrite(motorA1, 100); 
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, vSpeed);      
    digitalWrite(motorB2, 0);
  }

  else if (state == 'B') { // Se o estado recebido for igual a 'B', o carro se movimenta para trás.
    digitalWrite(motorA1, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, vSpeed);
    digitalWrite(motorA2, vSpeed);
  }

   else if (state == 'H') {  // Se o estado recebido for igual a 'H', o carro se movimenta para Trás Esquerda.
    digitalWrite(motorA1, 0);   
    digitalWrite(motorA2, vSpeed);
    digitalWrite(motorB1, 0); 
    digitalWrite(motorB2, 100);
  }
  
  else if (state == 'J') {  // Se o estado recebido for igual a 'J', o carro se movimenta para Trás Direita.
    digitalWrite(motorA1, 0);   
    digitalWrite(motorA2, 100);
    digitalWrite(motorB1, 0);   
    digitalWrite(motorB2, vSpeed);
  }

  else if (state == 'L') {   // Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, vSpeed);
    digitalWrite(motorB1, vSpeed);
    digitalWrite(motorB2, 0);
  }
  else if (state == 'R') {   // Se o estado recebido for igual a 'R', o carro se movimenta para direita.
    digitalWrite(motorA1, vSpeed);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, vSpeed);
  }
  else if (state == 'S') {   // Se o estado recebido for igual a 'S', o carro permanece parado.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, 0);
  }


  else if (state == 'V') { // Se o estado recebido for iguala 'V', aciona a buzina.
    if (j == 0) {
      tone(buzzer, 1000);
      j = 1;
    }
    else if (j == 1) {
      noTone(buzzer);
      j = 0;
    }
    state = 'n';
  }


}

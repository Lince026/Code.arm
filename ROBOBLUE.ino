/*-------------------------------------------------------
   CONTROLANDO CARRINHO COM ARDUINO, BLUETOOTH E ANDROID

   Desativar o modulo Bluetooth antes de fazer upload!

   www.binarycodec.blogspot.com
   Data: 16/06/2014
   v.1.0
  -------------------------------------------------------*/

char caracter;

void setup() {

  Serial.begin(9600);
  pinMode(2, OUTPUT); // Motor 1 - Direita
  pinMode(3, OUTPUT); // Motor 1 - Direita - Inverte sentido
  pinMode(4, OUTPUT); // Motor 2 - Esquerda
  pinMode(5, OUTPUT); // Motor 2 - Esquerda - Inverte sentido

}

void loop() {

  caracter = Serial.read();

  if (caracter == 'w') { // Para frente

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

  }

  if (caracter == 's') { // Re

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

  }

  if (caracter == 'a') { // Para esquerda

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

  }

  if (caracter == 'd') { // Para direita

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

  }

  if (caracter == 'e') { // Parar

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

  }

}

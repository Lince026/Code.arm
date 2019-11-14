#define pulso 9  //define la salida por donde se manda el pulso como 9
#define rebote 8 //define la salida por donde se recibe el rebote como 10
 
#define led_verde 13  //define led_verde = 13
#define led_naranja 12  //define led_naranja = 12
#define led_rojo 11  //define led_rojo = 11
 
#define SIN_PROBLEMA 100 //Distancia hasta la que consideramos el obstaculo alejado (de infinito a 100cm)
#define PRECAUCION 20  //Distancia que consideramos peligrosa y debemos movernos despacio
 
int distancia;  //crea la variable "distancia"
float tiempo;  //crea la variable tiempo (como float)
 
void setup()
{
  Serial.begin(9600);  //inicializa el puerto serie
  pinMode(pulso, OUTPUT); //Declaramos el pin 9 como salida (pulso ultrasonido)
  pinMode(rebote, INPUT); //Declaramos el pin 8 como entrada (recepción del pulso)
  pinMode(led_verde, OUTPUT); //declara led_verde como salida
  pinMode(led_naranja, OUTPUT);  //declara led_naranja como salida
  pinMode(led_rojo, OUTPUT);  //declara led_rojo como salida
}
 
void loop()
{
  digitalWrite(pulso,LOW); //Por cuestión de estabilización del sensor
  delayMicroseconds(5);
  digitalWrite(pulso, HIGH); //envío del pulso ultrasónico
  delayMicroseconds(10);
  tiempo = pulseIn(rebote, HIGH);  //funcion para medir el tiempo y guardarla en la variable "tiempo"
  distancia = 0.01715*tiempo; //fórmula para calcular la distancia
   
  if(distancia > SIN_PROBLEMA)  //si la distancia es mayor a la que consideramora SIN_PROBLEMA
  {
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_naranja, LOW);
    digitalWrite(led_rojo, LOW);
  }
  else if (distancia <= SIN_PROBLEMA && distancia > PRECAUCION) //si la distancia esta entre la que consideramos SIN_PROBLEMA y PRECAUCIÖN
  {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_naranja, HIGH);
    digitalWrite(led_rojo, LOW);
  }
  else  //si la distancia es menor de 30cm
  {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_naranja, LOW);
    digitalWrite(led_rojo, HIGH);
  }
  delay(10);
}

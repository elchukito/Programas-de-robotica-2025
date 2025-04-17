// sensores reflexivos
#define SENSORD 5
#define SENSORM 6
#define SENSORE 7

// motores
#define MOTORDF 3
#define MOTORDT 10
#define MONTOREF 11
#define MOTORET 9

void setup() {
  pinMode(SENSORD, INPUT);
  pinMode(SENSORM, INPUT);
  pinMode(SENSORE, INPUT);

  pinMode(MOTORD, OUTPUT);
  pinMode(MOTORE, OUTPUT);

  analogWrite(MOTORD, 0);
  analogWrite(MOTORE, 0);
}

void loop()
{

 bool estadoSD = digitalRead(SENSORD);
 bool estadoSM = digitalRead(SENSORM);
 bool estadoSE = digitalRead(SENSORE);

 // curva para esquerda
 if (estadoSD && !estadoSE)
 {
    analogWrite(MOTORD, 110);
    
    if (estadoSM)
     {
        analogWrite(MOTORE, 180);
     }
     else
     {
        analogWrite(MOTORE, 200);
     }
 }
 // curva para direita
 else if (!estadoSD && estadoSE)
 {
    analogWrite(MOTORD, 110);
    
    if (estadoSM)
     {
        analogWrite(MOTORD, 180);
     }
     else
     {
        analogWrite(MOTORD, 200);
     }
 }
 // segue reto
 else
 {
    analogWrite(MOTORD, 150);
    analogWrite(MOTORE, 150);
 }
}

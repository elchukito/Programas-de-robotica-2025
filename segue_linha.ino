// sensores reflexivos
#define SENSORD 5
#define SENSORM 6
#define SENSORE 7

// motores
#define MOTORDF 3
#define MOTORDT 11
#define MOTOREF 10
#define MOTORET 9

void setup() {
  pinMode(SENSORD, INPUT);
  pinMode(SENSORM, INPUT);
  pinMode(SENSORE, INPUT);

  pinMode(MOTORDF, OUTPUT);
  pinMode(MOTORDT, OUTPUT);
  pinMode(MOTOREF, OUTPUT);
  pinMode(MOTORET, OUTPUT);

  analogWrite(MOTORDF, 0);
  analogWrite(MOTOREF, 0);
  analogWrite(MOTORDT, 0);
  analogWrite(MOTORET, 0);
}

void loop()
{

 bool estadoSD = digitalRead(SENSORD);
 bool estadoSM = digitalRead(SENSORM);
 bool estadoSE = digitalRead(SENSORE);

 // curva para esquerda
 if (estadoSD && !estadoSE)
 {
    analogWrite(MOTOREF, 255);
    analogWrite(MOTORET, 0);
    analogWrite(MOTORDF, 50);
    analogWrite(MOTORDT, 0);
    
    if (estadoSM)
     {
        analogWrite(MOTORDF, 0);
     }
 }
 // curva para direita
 else if (!estadoSD && estadoSE)
 {
    analogWrite(MOTORDF, 255);
    analogWrite(MOTORDT, 0);
    analogWrite(MOTOREF, 50);
    analogWrite(MOTORET, 0);
    
    if (estadoSM)
     {
        analogWrite(MOTOREF, 0);
     }
 }
 // segue reto
 else
 {
    analogWrite(MOTORDF, 150);
    analogWrite(MOTOREF, 150);
    analogWrite(MOTORDT, 0);
    analogWrite(MOTORET, 0);
 }
}

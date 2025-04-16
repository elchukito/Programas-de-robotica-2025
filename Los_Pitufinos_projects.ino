// sensores reflexivos
#define SENSORD 13
#define SENSORM 12
#define SENSORE 11

// motores
#define MOTORD 6
#define MOTORE 5
void setup() {
  pinMode(SENSORD, INPUT);
  pinMode(SENSORM, INPUT);
  pinMode(SENSORE, INPUT);

  //pinMode(MOTORD, OUTPUT);
  //pinMode(MOTORE, OUTPUT);
  pinMode(MOTORD, OUTPUT);
  pinMode(MOTORE, OUTPUT);

  digitalWrite(MOTORD, LOW);
  digitalWrite(MOTORE, LOW);

  
}

void loop() {
 bool estadoSD = digitalRead(SENSORD);
 bool estadoSM = digitalRead(SENSORM);
 bool estadoSE = digitalRead(SENSORE);

 if (estadoSD && !estadoSE)
 {
    //analogWrite(MOTORD, 30);
    if (estadoSM)
     {
        //analogWrite(MOTORE, 90);
        digitalWrite(MOTORE, HIGH);
        digitalWrite(MOTORD, LOW);
     }
     else
     {
        //analogWrite(MOTORE, 120);
        digitalWrite(MOTORE, HIGH);
        digitalWrite(MOTORD, LOW);
     }
 }
 else if (!estadoSD && estadoSE)
 {
    //analogWrite(MOTORD, 30);
    if (estadoSM)
     {
        //analogWrite(MOTORD, 90);
        digitalWrite(MOTORD, HIGH);
        digitalWrite(MOTORE, LOW);
     }
     else
     {
        //analogWrite(MOTORD, 120);
        digitalWrite(MOTORD, HIGH);
        digitalWrite(MOTORE, LOW);
     }
 }
 else
 {
    //analogWrite(MOTORD, 90);
    //analogWrite(MOTORE, 90);
    digitalWrite(MOTORD, HIGH);
    digitalWrite(MOTORE, HIGH);
 }
}

const int p = A0;
const int rojo = 9;
const int azul = 10;
const int verde = 11;
const int boton = 2;

int potencia;
int fase =0;


void setup() {
  // put your setup code here, to run once:
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);

  pinMode(p, INPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
  digitalWrite(azul, 255);
  digitalWrite(verde, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if (fase == 0) {
    potencia = analogRead(p);
    potencia = map(potencia, 0, 1023, 0, 255);
    Serial.print(potencia);
    Serial.print("\n");
    delay(300);
    analogWrite(rojo, potencia);
    if (digitalRead(boton) == 1) {
      fase++;
      delay(1000);
      potencia = 255;
    }
  }
  if (fase == 1) {
     potencia = analogRead(p);
     potencia = map(potencia, 0, 1023, 0, 255);
     Serial.print(potencia);
     Serial.print("\n");
     delay(300);
    analogWrite(azul, potencia);
    if (digitalRead(boton) == 1) {
      fase++;
      delay(1000);
      potencia = 255;
    }
  }
  if (fase == 2) {
     potencia = analogRead(p);
     potencia = map(potencia, 0, 1023, 0, 255);
     Serial.print(potencia);
     Serial.print("\n");
     delay(300);
    analogWrite(verde, potencia);
    if (digitalRead(boton) == 1) {
      fase = 0;
      delay(1000);
      potencia = 255;
    }
  }
}

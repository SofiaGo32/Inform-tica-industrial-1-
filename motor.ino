int CW = 2;
int CCW = 3;
int V =4;
int valCW, valCCW, valV;
int velocidad = 6;
int OCW =5;
int OCCW = 7;
boolean cw,ccw;
void setup() {
  // put your setup code here, to run once:
  pinMode (CW, INPUT);
  pinMode (CCW, INPUT);
  pinMode (V, INPUT);
  pinMode (velocidad, OUTPUT);
  pinMode (OCW, OUTPUT);
  pinMode (OCCW, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valCW = digitalRead (CW);
  valCCW = digitalRead (CCW);
  valV = digitalRead (V);

 Serial.println(valV);



  if (valCW== HIGH) {
    digitalWrite(OCW, HIGH);
    digitalWrite(OCCW, LOW);
    
    } else if(valCCW==HIGH) {  
    digitalWrite(OCCW,HIGH);
    digitalWrite(OCW,LOW);
    
  }

  if (valV== HIGH){
     analogWrite(velocidad, 168);
    } else if(valV==LOW){
     analogWrite(velocidad, 84);
    }

  delay(100);
}

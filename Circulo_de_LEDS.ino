int LED[8]= {2,3,4,5,6,7,8,9};
int boton= 12;
int velocimetro= A0;
int velocidad;
int dp=0,d=0;
int i=0;
void setup() {
  // put your setup code here, to run once:
  pinMode( velocimetro, INPUT);
  pinMode( boton, INPUT);
  pinMode( LED[0], OUTPUT);
  pinMode( LED[1], OUTPUT);
  pinMode( LED[2], OUTPUT);
  pinMode( LED[3], OUTPUT);
  pinMode( LED[4], OUTPUT);
  pinMode( LED[5], OUTPUT);
  pinMode( LED[6], OUTPUT);
  pinMode( LED[7], OUTPUT);
  Serial.begin(9600);

 // digitalWrite(LED[3], HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  velocidad = map(analogRead(velocimetro),0,1023,100,1000);
  dp = digitalRead(boton);
  delay(50);
  if(dp==1){//Boton apretado
    d++; //CCW
  }
  if(d>1){
    d=0; //CW
  }
  
  if(d==1){//CCW
    if (i==7){
      digitalWrite(LED[0], LOW);
    }
    else{
     digitalWrite(LED[i+1],LOW); 
    }
      digitalWrite(LED[i],HIGH);
    i--;
  }else{//CW
    if (i==0){
      digitalWrite(LED[7], LOW);
    }
    else {
     digitalWrite(LED[i-1],LOW);   
    }
    digitalWrite(LED[i],HIGH);
    i++;
  }
  if(i>7){
    i=0;
  }
  if(i<0){
    i=7;
  }
  delay(velocidad);
}

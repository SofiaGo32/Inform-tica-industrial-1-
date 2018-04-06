int L1=2;//LED1 led de planta alta
int L2=3;//LED2 led de planta baja
int MS=6;//Motor subir
int MB=7;//Motor bajar
int BS=4;//Boton subir
int BB=5;//Boton bajar
int VBS,VBB; //valores de los botones (botón subir y botón bajar)
int c=0; //variable para restringir el movimiento del elevador al presionar los botones y para iniciar el elevador en planta baja al iniciar el programa
void setup() {
  // put your setup code here, to run once:
   pinMode(L1, OUTPUT);
   pinMode(L2, OUTPUT);
   pinMode(MS, OUTPUT);
   pinMode(MB, OUTPUT);
   pinMode(BS, INPUT);
   pinMode(BB, INPUT);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 VBS= digitalRead(BS); //Variable que guardará el valor que reciba de BS
 VBB= digitalRead(BB); //Variable que guardará el valor que reciba de BB
 if(c==0){
  digitalWrite(L2,HIGH); //condición para que el elevador inicie en planta baja
 }
 if(c!=1 && c!=0){
   if(VBS==HIGH){
    c=1;
    digitalWrite(L1,LOW); //led de planta alta apagado
    digitalWrite(L2,LOW); //led de planta baja apagado
    digitalWrite(MS,HIGH); //motor encendido
    delay(7000);
    digitalWrite(MS,LOW); //motor apagado
    digitalWrite(L2,HIGH); //led de planta baja encendido
   }
 } 
 if(c!=2){
   if(VBB==HIGH){
    c=2;
    digitalWrite(L1,LOW); // led de planta alta apagado
    digitalWrite(L2,LOW); //led de planta baja apagado
    digitalWrite(MB,HIGH); //motor encendido en la dirección opuesta
    delay(7000);
    digitalWrite(MB,LOW); //motor apagado
    digitalWrite(L1,HIGH); //led en posición de planta alta encendido
   }
 }
}

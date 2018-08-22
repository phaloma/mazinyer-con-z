
//Ctes
int s = 2;
int L1 = 5; int L2 = 6; //controladores izquierdo
int R1 = 9; int R2 = 10; //controladores derecho

int lU = 0; int lD = 0; // valores booleanos arriba-abajo
int lL = 0; int lR = 0; // valores boolenos izquierda-derecha
int lA = 0;

int ang = 0;//posicion inicial 
int angm = 0; int angM = 180;
int vel = 5;


 void setup() {
  Serial.begin (9600); //Iniciar el serial
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(13, OUTPUT); //LED
}

 void loop() {

digitalWrite(L1, HIGH); digitalWrite(L2, LOW);
digitalWrite(13, HIGH);
delay(2000);
digitalWrite(L2, HIGH); digitalWrite(L1, LOW);
digitalWrite(13, LOW);
delay(2000);

}//Loop

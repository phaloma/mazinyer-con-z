char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

//Ctes
int L1 = 5;
int L2 = 6;
int R1 = 9;
int R2 = 10;
int lU = 0;
int lD = 0;

void setup() {
  Serial.begin (9600); //Iniciar el serial
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(13, OUTPUT); //LED
}

void loop() {
  if(Serial.available() >= 1){
    char entrada = Serial.read();
    Serial.println(entrada);
    
     if(entrada == 'U'){
       lU = 1; lD = 0;
     }// if del caso "adelante"

    if(entrada == 'D'){
      lD = 1; lU = 0;
    }// if del caso "atras"

    if(entrada=='S'){
      lU = 0; lD = 0;
    }// if del caso "apagado"
  }//if para ver que est prendido

  //Que es lo que hara el robot
  if(lU == 1){
    analogWrite(L1, 100); analogWrite(L2, 0);
    analogWrite(R1, 255); analogWrite(R2, 0);
    delay(100);
    digitalWrite(13, LOW);
  }//if del up

  if(lD == 1){
    analogWrite(L1, 0); analogWrite(L2, 255);
    analogWrite(R1, 0); analogWrite(R2, 100);
    delay(100);
    digitalWrite(13, HIGH);
  }

  if(lU == 0 && lD == 0){
    digitalWrite(L1, LOW); digitalWrite(L2, LOW);
    digitalWrite(R1, LOW); digitalWrite(R2, LOW);
    digitalWrite(13,LOW);
  }
}//Loop

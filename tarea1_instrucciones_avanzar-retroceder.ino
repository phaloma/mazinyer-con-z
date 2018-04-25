char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

//Ctes
int L1 = 5;
int L2 = 6;
int R1 = 9;
int R2 = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600); //Iniciar el serial
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(13, OUTPUT); //LED
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available() >= 1){
    char entrada = Serial.read();
    Serial.println(entrada);
    if(entrada == 'H'){
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, LOW);
      digitalWrite(13, HIGH);
    }// if del caso "adelante"

    if(entrada == 'L'){
      digitalWrite(L2, HIGH);
      digitalWrite(L1, LOW);
      digitalWrite(R2, HIGH);
      digitalWrite(R1, LOW);
      digitalWrite(13, LOW);
    }// if del caso "atras"

    else{
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
      
    }// if del caso "apagado"
  }//if para ver que est prendido
}//Loop

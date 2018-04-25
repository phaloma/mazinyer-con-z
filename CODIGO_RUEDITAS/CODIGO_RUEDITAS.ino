char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

//Ctes
int L1 = 5;
int L2 = 6;
int R1 = 7;
int R2 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600); //Iniciar el serial
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite (L1, HIGH);
 digitalWrite (L2, LOW); 
 delay(4000);

 digitalWrite (L2, HIGH);
 delay(4000);
  
  }// if del caso "apagado"

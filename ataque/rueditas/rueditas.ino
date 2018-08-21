#include <Servo.h>
char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

//Ctes
int L1 = 5; int L2 = 6; //controladores izquierdo
int R1 = 9; int R2 = 10; //controladores derecho
int lU = 0; int lD = 0; // valores booleanos arriba-abajo
int lL = 0; int lR = 0; // valores boolenos izquierda-derecha
int ang = 0;//posicion inicial 
int lA = 0;
int angm = 0; int angM = 180;
Servo servomotor;

void setup() {
  Serial.begin (9600); //Iniciar el serial
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(13, OUTPUT); //LED
  servomotor.attach(9,600,2400);//servo en el pin9 &AP(min)=600 AP(max)=2400
}

void loop() {
  if(Serial.available() >= 1){
    char entrada = Serial.read();
    Serial.println(entrada);

    //DIRECCION 
     if(entrada == 'U'){
       lU = 1; lD = 0;
     }// if del caso "adelante"

    if(entrada == 'D'){
      lD = 1; lU = 0;
    }// if del caso "atras"

    if(entrada == 'L'){
       lL = 1; lR = 0;
     }// if del caso "izquierda"

     if(entrada == 'R'){
       lR = 1; lL = 0;
     }// if del caso "derecha"
     
    //ATAQUE
    if (entrada == 'A'){
      lA = 1;
      }

    //APAGAR MOTORES
    if(entrada=='S'){
      lU = 0; lD = 0; lR = 0; lL = 0; lA = 0;
    }// if del caso "apagado"

    
    
  }//if para ver que existe senal

  //Que es lo que hara el robot
  //U
  if(lU == 1 && lR == 0 && lL == 0){
    analogWrite(L1, 255); analogWrite(L2, 0);
    analogWrite(R1, 255); analogWrite(R2, 0);    
    digitalWrite(13, LOW);
  }//if del adelante

  //UR
  if(lU == 1 && lR == 1 && lL == 0){
    analogWrite(L1, 100); analogWrite(L2, 0);
    analogWrite(R1, 255); analogWrite(R2, 0); 
    digitalWrite(13, HIGH);
  }//if del adelante derecho

  //UL
  if(lU == 1 && lR == 0 && lL == 1){
    analogWrite(L1, 255); analogWrite(L2, 0);
    analogWrite(R1, 100); analogWrite(R2, 0); 
    digitalWrite(13, LOW);
  }//if del adelante izquierdo

  //R
  if(lR == 1 && lU == 0 && lD == 0){
    analogWrite(L1, 0); analogWrite(L2, 255);
    analogWrite(R1, 255); analogWrite(R2, 0); 
    digitalWrite(13, LOW);
  }//if del derecha

  //L
  if(lL == 1 && lU == 0 && lD == 0){
    analogWrite(L1, 255); analogWrite(L2, 0);
    analogWrite(R1, 0); analogWrite(R2, 255);
    digitalWrite(13, LOW);
  }//if del izquierdo

  //D
  if(lD == 1 && lR == 0 && lL == 0){
    analogWrite(L1, 0); analogWrite(L2, 255);
    analogWrite(R1, 0); analogWrite(R2, 255);
    digitalWrite(13, LOW);
  }//if del atrás

  //DR
  if(lD == 1 && lR == 1 && lL == 0){
    analogWrite(L1, 0); analogWrite(L2, 100);
    analogWrite(R1, 0); analogWrite(R2, 255);
    digitalWrite(13, LOW);
  }//if del atrás-derecha

  //DL
  if(lD == 1 && lR == 0 && lL == 1){
    analogWrite(L1, 0); analogWrite(L2, 255);
    analogWrite(R1, 0); analogWrite(R2, 100);
    digitalWrite(13, LOW);
  }//if del atrás-izquierda

  //S
  if(lU == 0 && lD == 0 && lR == 0 && lL == 0){
    analogWrite(L1, 0); analogWrite(L2, 0);
    analogWrite(R1, 0); analogWrite(R2, 0); 
    digitalWrite(13,LOW);
  }

  if(lA== 1){
    ang += 1;
    }

  if(lA == 0){
    ang -= 1;
    }
    
  ang=constrain(ang,angm,angM);//limitacion de los valores del angulo
  Serial.println(ang);  
  servomotor.write(ang);//se ingresa el valor "ang" al servo  
  delay(15);//por si las moscas  
   
}//Loop

#include <Servo.h>
char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

int ang=0;//posicion inicial 
int lA = 0;
Servo servomotor;

void setup() {
  
  Serial.begin (9600);//inicial e serial 
  servomotor.attach(9,600,2400);//servo en el pin9 &AP(min)=600 AP(max)=2400
}

void loop(){
  
  if(Serial.available() >= 1){ //detecta una entrada
    char entrada = Serial.read(); //lee el caracter del celular 
    Serial.println(entrada);

    lA = 0;
    
    if (entrada == 'U'){
      lA=1;
      }
   
   
  }//Leer el bt
  
  //acciones finales
  //Condicionales
  if(lA== 1){
    ang += 5;
    }

  else{
    ang-=5;
    }
    
  ang=constrain(ang,0,180);//limitacion de los valores del angulo
  
  Serial.println(ang);
      
   servomotor.write(ang);//se ingresa el valor "ang" al servo
   delay(5);//por si las moscas   
  }


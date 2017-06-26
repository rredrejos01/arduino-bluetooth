          char incomingByte;  // incoming data
const int  pinfrontLights = 12;      // LED pin
const int  pinbackLights = 13;
const int  motor_alante1 = 8;
const int  motor_alante2 = 7;
const int  motor_atras2 = 9;
const int  motor_atras1 = 10;
int velocidad_de_giro = 6;

void izquierda() {
    digitalWrite(motor_alante1, HIGH);
    digitalWrite(motor_alante2, LOW);
}
void derecha() {
    digitalWrite(motor_alante2, HIGH);
    digitalWrite(motor_alante1, LOW);
}
void alante() {
    digitalWrite(motor_atras1, HIGH);
    digitalWrite(motor_atras2, LOW);
}
void atras() {
    digitalWrite(motor_atras1, LOW);
    digitalWrite(motor_atras2, HIGH);
}
void parar() {
    digitalWrite(motor_alante1, LOW);
    digitalWrite(motor_alante2, LOW);
    digitalWrite(motor_atras2, LOW);
    digitalWrite(motor_atras1, LOW);
}
void alantederecha() {
    digitalWrite(motor_alante1, LOW);
    digitalWrite(motor_alante2, HIGH);
    digitalWrite(motor_atras1, HIGH);
    digitalWrite(motor_atras2, LOW);
}
void alanteizquierda() {
    digitalWrite(motor_alante1, HIGH);
    digitalWrite(motor_alante2, LOW);
    digitalWrite(motor_atras1, HIGH);
    digitalWrite(motor_atras2, LOW);
}
void atrasderecha() {
    digitalWrite(motor_alante1, LOW);
    digitalWrite(motor_alante2, HIGH);
    digitalWrite(motor_atras1, LOW);
    digitalWrite(motor_atras2, HIGH);
}
void atrasizquierda() {
    digitalWrite(motor_alante1, HIGH);
    digitalWrite(motor_alante2, LOW);
    digitalWrite(motor_atras1, LOW);
    digitalWrite(motor_atras2, HIGH);
}



 char command = 'S';
void setup() {
  Serial.begin(9600); // initialization
    pinMode(pinfrontLights, OUTPUT);
    pinMode(pinbackLights, OUTPUT);
    pinMode(velocidad_de_giro, OUTPUT);
    pinMode(motor_alante1, OUTPUT);
    pinMode(motor_alante2, OUTPUT);
    pinMode(motor_atras2, OUTPUT);
    pinMode(motor_atras1, OUTPUT);  
}
 
void loop() {

  if(Serial.available() > 0){
    incomingByte = Serial.read();
    
    //Luces delanteras
    switch(incomingByte){
      case('W'):
        digitalWrite(pinfrontLights, HIGH); //Luces delanteras encendiadas
        break;  
      case('w'):
        digitalWrite(pinfrontLights, LOW); //Luces delanteras apagadas
        break;
      //Luces traseras
  
      case('U'):
        digitalWrite(pinbackLights, HIGH); //Luces traseras encendidas    
        break;
      case('u'):
        digitalWrite(pinbackLights, LOW); //Luces traseras apagadas
        break;
      case('L'):
        izquierda();
        Serial.println("izquierda");
        break;
      case('R'):
        derecha();
        Serial.println("derecha");
        break;
      default:
        parar();
        break;
      case('F'):
        alante();
        break;
      case('B'):
        atras();
        break;
      case('J'):
        atrasderecha();
        break;
      case('I'):
        alantederecha();
        break;
      case('G'):
        alanteizquierda();
        break;
      case('H'):
        atrasizquierda();
        break;
      case('1'):
        analogWrite (velocidad_de_giro, 25);
        break;    
      case('2'):
        analogWrite (velocidad_de_giro, 51);
        break;      
      case('3'):
        analogWrite (velocidad_de_giro, 76);
        break;   
      case('4'):
        analogWrite (velocidad_de_giro, 102);
        break;      
      case('5'):
        analogWrite (velocidad_de_giro, 127);
        break;      
      case('6'):
        analogWrite (velocidad_de_giro, 153);
        break;     
      case('7'):
        analogWrite (velocidad_de_giro, 178);
        break;     
      case('8'):
       analogWrite (velocidad_de_giro, 204);
        break;  
      case('9'):
        analogWrite (velocidad_de_giro, 229);
        break; 
      case('q'):
        analogWrite (velocidad_de_giro, 255);
        Serial.println("entra en q");
        break;
      
      
    }
                
   }
  
  
  
  
}

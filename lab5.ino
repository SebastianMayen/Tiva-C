//juego de carreras con dos botones y uno de reinicio con contador de decadas de 8 bits
//Sebastian Mayen Davila 
// Laboratorio 5 Digital 2
#define LEDrojo RED_LED
#define LEDazul BLUE_LED
#define LEDverde GREEN_LED

int push1 = 31;
int push2 = 17;

int bandera = 0;
int banderawin = 0;
int contador1 = 0;
int contador2 = 0;
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LEDverde, OUTPUT); 
  pinMode(LEDazul, OUTPUT); 
  pinMode(LEDrojo, OUTPUT);  
  pinMode(push1, INPUT_PULLUP); 
  pinMode(push2, INPUT_PULLUP);
  pinMode(PD_0, OUTPUT);
  pinMode(PD_1, OUTPUT);
  pinMode(PD_2, OUTPUT);
  pinMode(PD_3, OUTPUT);
  pinMode(PE_1, OUTPUT);
  pinMode(PE_2, OUTPUT);
  pinMode(PE_3, OUTPUT);
  pinMode(PA_7, OUTPUT);
  
  pinMode(PB_5, OUTPUT);
  pinMode(PB_0, OUTPUT);
  pinMode(PB_1, OUTPUT);
  pinMode(PE_4, OUTPUT);
  pinMode(PE_5, OUTPUT);
  pinMode(PB_4, OUTPUT);
  pinMode(PA_5, OUTPUT);
  pinMode(PA_6, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (bandera == 0){
    contador1 = 0;
    contador2 = 0; 
  
    if (digitalRead(push1) == 0){
      digitalWrite(LEDverde, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(2000); 
      digitalWrite(LEDverde, LOW);    // turn the LED off by making the voltage LOW
      
      digitalWrite(LEDazul, HIGH);    // turn the LED off by making the voltage LOW
      delay(2000); 
      digitalWrite(LEDazul, LOW);    // turn the LED off by making the voltage LOW 
      
      digitalWrite(LEDrojo, HIGH);    // turn the LED off by making the voltage LOW
      delay(2000);     
      digitalWrite(LEDrojo, LOW);    // turn the LED off by making the voltage LOW 
      bandera = 1;
    }  
  }
  if(bandera == 1){
      if(digitalRead(push1) == 0){
        delay(500);
          digitalWrite(PB_5, HIGH);
            contador1++; 
          
        }
      if(digitalRead(push2) == 0){
        delay(500);
            contador2++; 
          
        } 
      if(contador1 == 0){
        digitalWrite(PD_0, LOW);
        digitalWrite(PD_1, LOW);
        digitalWrite(PD_2, LOW);
        digitalWrite(PD_3, LOW);
        digitalWrite(PE_1, LOW);
        digitalWrite(PE_2, LOW);
        digitalWrite(PE_3, LOW);
        digitalWrite(PA_7, LOW);
       }
       if(contador1 == 1){
        digitalWrite(PD_0, HIGH);
       }
       if(contador1 == 2){
        digitalWrite(PD_0, LOW);
        digitalWrite(PD_1, HIGH);
       }
       if(contador1 == 3){
        digitalWrite(PD_1, LOW);
        digitalWrite(PD_2, HIGH);
       }
       if(contador1 == 4){
        digitalWrite(PD_2, LOW);
        digitalWrite(PD_3, HIGH);
       }
      if(contador1 == 5){
        digitalWrite(PD_3, LOW);
        digitalWrite(PE_1, HIGH);
       }
      if(contador1 == 6){
        digitalWrite(PE_1, LOW);
        digitalWrite(PE_2, HIGH);
       }
       if(contador1 == 7){
        digitalWrite(PE_2, LOW);
        digitalWrite(PE_3, HIGH);
       }
       if(contador1 == 8){
        digitalWrite(PE_3, LOW);
        digitalWrite(PA_7, HIGH);
       }
       if(contador1 == 8){
        digitalWrite(PD_0, HIGH);
        digitalWrite(PD_1, HIGH);
        digitalWrite(PD_2, HIGH);
        digitalWrite(PD_3, HIGH);
        digitalWrite(PE_1, HIGH);
        digitalWrite(PE_2, HIGH);
        digitalWrite(PE_3, HIGH);
        digitalWrite(PA_7, HIGH); 
        banderawin = 1;
        while (banderawin == 1){
          if(digitalRead(push1) == 0){
            delay(500);
            banderawin = 0;
            bandera = 0; 
          
        }
          }  
       }


       
      if(contador2 == 0){
        digitalWrite(PB_5, LOW);
        digitalWrite(PB_0, LOW);
        digitalWrite(PB_1, LOW);
        digitalWrite(PE_4, LOW);
        digitalWrite(PE_5, LOW);
        digitalWrite(PB_4, LOW);
        digitalWrite(PA_5, LOW);
        digitalWrite(PA_6, LOW);
       }
       if(contador2 == 1){
        digitalWrite(PB_5, HIGH);
       }
       if(contador2 == 2){
        digitalWrite(PB_5, LOW);
        digitalWrite(PB_0, HIGH);
       }
       if(contador2 == 3){
        digitalWrite(PB_0, LOW);
        digitalWrite(PB_1, HIGH);
       }
       if(contador2 == 4){
        digitalWrite(PB_1, LOW);
        digitalWrite(PE_4, HIGH);
       }
       if(contador2 == 5){
        digitalWrite(PE_4, LOW);
        digitalWrite(PE_5, HIGH);
       }
       if(contador2 == 6){
        digitalWrite(PE_5, LOW);
        digitalWrite(PB_4, HIGH);
       }
       if(contador2 == 7){
        digitalWrite(PB_4, LOW);
        digitalWrite(PA_5, HIGH);
       }
       if(contador2 == 8){
        digitalWrite(PA_5, LOW);
        digitalWrite(PA_6, HIGH);
       }
       if(contador2 == 8){
        digitalWrite(PB_5, HIGH);
        digitalWrite(PB_0, HIGH);
        digitalWrite(PB_1, HIGH);
        digitalWrite(PE_4, HIGH);
        digitalWrite(PE_5, HIGH);
        digitalWrite(PB_4, HIGH);
        digitalWrite(PA_5, HIGH);
        digitalWrite(PA_6, HIGH); 
        banderawin = 1;
        while (banderawin == 1){
          if(digitalRead(push1) == 0){
            delay(500);
            banderawin = 0;
            bandera = 0; 
          
        }
          }   
       }   
    }
}

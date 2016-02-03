#define SENSOR 2
#define SAIDA_DIMMER 13

uint8_t x = 10; //numero de ciclos
uint8_t y = 1; //porcentagem, o que vai mudar

int8_t p;

uint8_t caso1 = 2*y - 2*x;
uint8_t caso2 = 2*y;

void setup(){
  pinMode(SENSOR, INPUT);
  pinMode(SAIDA_DIMMER, OUTPUT);
}
void loop(){

  
  p = 2*y - x;
  uint8_t i = 0;
  while(i<=9){
        if(p>=0){ 
          while(digitalRead(SENSOR)<0);
            p += caso1;
            digitalWrite(SAIDA_DIMMER, HIGH);
        }      
        else {
          digitalWrite(SAIDA_DIMMER, LOW);
          p += caso2;
        }
        i++;
    }
}

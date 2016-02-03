#define PINO_INTERRUPCAO 2
#define SAIDA_DIMMER 13

uint8_t x = 10; //numero de ciclos
uint8_t y = 2; //porcentagem, o que vai mudar
boolean sensor = 0; //definindo sensor = 0

int8_t p; //variavel do algoritimo
uint8_t i=0; //contagem

uint8_t caso1 = 2*y - 2*x;
uint8_t caso2 = 2*y;

void setup(){
  pinMode(SAIDA_DIMMER, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PINO_INTERRUPCAO), zero, FALLING); //função interrupção, (0= pino 2, altera a função interrupção, borda de subida)
}

void zero(){
  sensor = 1; //sensor = 1, passagem por zero
  i++;
}

void loop(){
  if(sensor == 1){
    if(i>9){
      i=0;
      p = 2*y - x;
    }  
    if(p>=0){
      p += caso1;
      digitalWrite(SAIDA_DIMMER, HIGH);
    }      
    else {
      digitalWrite(SAIDA_DIMMER, LOW);
      p += caso2;
    }
    sensor = 0;
  }

}



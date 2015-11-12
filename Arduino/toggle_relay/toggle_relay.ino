#define CLK  12  //pino 11 74hc595
#define LATCH 8  //pino 12 74hc585
#define DATA 11  //pino 14 74hc595

uint8_t byteenviar = 0;

void setup(){

  Serial.begin(9600);

  pinMode(DATA,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);

  enviar(byteenviar);
}

void loop(){
  if(Serial.available() > 0){
    uint8_t lednumero = Serial.read() - '0';   //conversao de char para int

    if(lednumero >= 0 && lednumero <=7 ){ //caso o usuario busque um led n valido
      byteenviar = byteenviar ^ (1 << lednumero); //operacao XOR para toggle
      enviar(byteenviar);
    }
    else{
      Serial.println("Digite novamente");
    }
  }
}
void enviar(){
  digitalWrite(LATCH,LOW);
  shiftOut(DATA,CLK,MSBFIRST,byteenviar);
  digitalWrite(LATCH,HIGH);
}















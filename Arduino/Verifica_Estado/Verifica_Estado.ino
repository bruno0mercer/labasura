#define DATA 11 //pino 9 74hc165
#define SHLD 8  //pino 1 74HC165
#define CLK 12  //pino 2 74HC165
#define CE 9    //pino 15 74hc165


void setup(){
  Serial.begin(9600);

  pinMode(SHLD,OUTPUT);
  pinMode(CE,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DATA,INPUT);

  digitalWrite(CLK,HIGH);
  digitalWrite(SHLD,HIGH);

}
void loop(){
  uint8_t chegando = readshift(); //chama a funçao para verificar os valores

  Serial.println("Os valores que estao chegando sao: " );
  printbyte(chegando);
  
  delay(1500);

}

byte readshift(){
  uint8_t recebe = 0;

                            //devido ao datasheet necessitamos desses valores nos pinos 
  digitalWrite(SHLD,LOW);  
  delay(5);                //delay devido ao datasheet
  digitalWrite(SHLD,HIGH);
  delay(5);

  digitalWrite(CLK,HIGH);//configuraçao devido ao datasheet
  digitalWrite(CE,LOW);
  recebe = shiftIn(DATA,CLK,MSBFIRST); //pega os valores
  digitalWrite(CE,HIGH);
  
  return recebe; //retorna para a funço loop um byte com os valores de cada "botao" que foi shiftado
}

void printbyte(uint8_t valor){

  for(uint8_t i =0; i<=7; i++){

    Serial.print(valor >> i & 1,BIN); //bit shift , fazendo operaçao  AND do nosso valor obtido no shift register com o byte 1
  }
   Serial.print("\n");

}






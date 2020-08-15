// Open Source
// Trabalhando com Display LCD com I2C

#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES
 
//Variável que armazena a posição lida 
//nos eixos do joystick
int joystick = 0;
 
//Atribuindo o pino analógico A0 a variável eixoX
int eixoX = A0;
 
//Atribuindo o pino analógico A1 a variável eixoY
int eixoY = A1;
 
//Atribuindo o pino digital 2 a variável eixoZ
int eixoZ = 13;
 
void setup() {
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  //Definindo eixoZ como um pino de entrada
  pinMode(eixoZ, INPUT);
 
  //Ativando o Serial Monitor que exibirá os
  //valores lidos no Joystick
  Serial.begin(9600);
}
 
void loop() {
  //Lê o valor do eixoX
  joystick = analogRead(eixoX);
 
  //imprime o valor do eixoX
  Serial.print("  X=");
  Serial.print(joystick);
  lcd.clear();
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print(" X="); //IMPRIME O TEXTO NO DISPLAY LCD
  lcd.print(joystick); //IMPRIME O TEXTO NO DISPLAY LCD
  
  //Lê o valor do eixoY
  joystick = analogRead(eixoY);
 
  //imprime o valor do eixoY 
  Serial.print("   Y=");
  Serial.print(joystick);
  lcd.print(" Y=");
  lcd.print(joystick);
 
  //Lê o valor do eixoZ
  joystick = digitalRead(eixoZ);
 
  //imprime o valor do eixoZ
  Serial.print("   Z=");
  Serial.println(joystick);
  lcd.print(" Z=");
  lcd.print(joystick);
 
  //espera 200 milisegundos. 
  //Se vc quiser aumentar a velocidade 
  //de leitura dos valores do joystick 
  //diminua o tempo de espera. Ex: delay(100);
  delay(200); 
}

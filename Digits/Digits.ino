#include <LedControl.h>

int DIN = 11;
int CS = 10;
int CLK = 9;

LedControl lc = LedControl (DIN,CLK,CS,0);
int x = 15;


void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,x);
  lc.clearDisplay(0);
}

void loop() {

  byte n0[8] = {B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100};
  byte n1[8] = {B00001000,B00011000,B00101000,B00001000,B00001000,B00001000,B00001000,B00111100};
  byte n2[8] = {B00011000,B00100100,B00100100,B00000100,B00001000,B00010000,B00100000,B00111100};
  byte n3[8] = {B00011000,B00100100,B00000100,B00001000,B00000100,B00100100,B00100100,B00011000};
  byte n4[8] = {B00000100,B00001100,B00010100,B00100100,B01000100,B11111111,B00000100,B00000100};
  byte n5[8] = {B00111100,B00100000,B00100000,B00111100,B00000010,B00000010,B00100010,B00011100};
  byte n6[8] = {B00011000,B00100100,B00100000,B00111000,B00100100,B00100100,B00100100,B00011000};
  byte n7[8] = {B00111100,B00000100,B00000100,B00001000,B00010000,B00010000,B00010000,B00010000};
  byte n8[8] = {B00111100,B01000010,B01000010,B00111100,B01000010,B01000010,B01000010,B00111100};
  byte n9[8] = {B00011000,B00100100,B00100100,B00011100,B00000100,B00000100,B00100100,B00011000};

  byte keys[12] = {n1,n2,n3,n4,n5,n6,n7,n8,n9,n0};
  
  printByte(n0);
  delay(1000);
  printByte(n1);
  delay(1000);
  printByte(n2);
  delay(1000);
  printByte(n3);
  delay(1000);
  printByte(n4);
  delay(1000);
  printByte(n5);
  delay(1000);
  printByte(n6);
  delay(1000);
  printByte(n7);
  delay(1000);
  printByte(n8);
  delay(1000);
  printByte(n9);
  delay(1000);
  
  lc.clearDisplay(0);
  delay(1000);
}

void printByte(byte chr[])
{
  int i = 0;
  for (i=0; i<8; i++)
  {
    lc.setRow(0,i,chr[i]);
  }
}

#include "LedControl.h"

int DIN = 10;
int CS = 9;
int CLK = 8;

LedControl lc = LedControl (DIN,CLK,CS,0);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);
}

void loop() {
  byte stage1[8] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
  byte stage2[8] = {B00000000,B00000000,B00111100,B00100100,B00100100,B00111100,B00000000,B00000000};
  byte stage3[8] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
  byte stage4[8] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
  byte stage5[8] = {B01111110,B10000001,B10000001,B10000001,B10000001,B10000001,B10000001,B01111110};
  byte stage6[8] = {B01100110,B10000001,B10000001,B00000000,B00000000,B10000001,B10000001,B01100110};
  byte stage7[8] = {B01100110,B10000001,B00000000,B00000000,B00000000,B00000000,B10000001,B01100110};
  byte stage8[8] = {B10000001,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000001};
  byte stage9[8] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  
  printByte(stage1);
  delay(50);
  printByte(stage2);
  delay(60);
  printByte(stage3);
  delay(100);
  printByte(stage4);
  delay(70);
  printByte(stage5);
  delay(80);
  printByte(stage6);
  delay(90);
  printByte(stage7);
  delay(80);
  printByte(stage8);
  delay(70);
  printByte(stage9);
  delay(300);
}

void printByte(byte chr[])
{
  int i = 0;
  for (i=0; i<8; i++)
  {
    lc.setRow(0,i,chr[i]);
  }
}

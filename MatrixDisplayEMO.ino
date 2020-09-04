#include "LedControl.h"

int DIN = 10;
int CS = 9;
int CLK = 8;

LedControl lc = LedControl (DIN,CLK,CS,0);
int x = 1;

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  lc.setIntensity(0,x);
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte emo[8] = {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
  byte hi[8] = {0x00,0xAE,0xA4,0xE4,0xA4,0xAE,0x00,0x00};
  byte right[8] = {B00000000,B00000100,B00000110,B11111111,B00000110,B00000100,B00000000,B00000000};
  byte pixel [8] = {B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
  byte yo [8] = {B00000000,B10100110,B10101001,B11101001,B01001001,B01000110,B00000000,B00000000};
  byte replay [8] = {B00111100,B01000010,B01000001,B11100001,B01000001,B00000001,B01000010,B00111100};

  lc.setIntensity(0,5);
  printByte(emo);
  delay(2000);

  /*for (float i=0;i<=15;i+=.5)
  {
    lc.setIntensity(0,i);
    printByte(hi);
    delay(10);
  }
  delay(2500);*/

  printByte(right);
  delay(2500);

  lc.setIntensity(0,5);
  printByte(pixel);
  delay(2000);

  lc.setIntensity(0,10);
  printByte(yo);
  delay(1500);

  printByte(replay);
  delay(2500);
}

void printByte(byte chr[])
{
  int i = 0;
  for (i=0; i<8; i++)
  {
    lc.setRow(0,i,chr[i]);
  }
}

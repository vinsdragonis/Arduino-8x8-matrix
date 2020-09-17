#include <Keypad.h>
#include <LedControl.h>

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8};

int DIN = 11;
int CS = 10;
int CLK = 9;

LedControl lc = LedControl (DIN,CLK,CS,0);
int x = 15;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,x);
  lc.clearDisplay(0);
}

void loop() {
  char key = keypad.getKey();

  byte emo[8] = {B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
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
  byte nAsterisk[8] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};
  byte nHash[8] = {B00100100,B00100100,B11111111,B00100100,B00100100,B11111111,B00100100,B00100100};

  byte keys[12] = {n1,n2,n3,n4,n5,n6,n7,n8,n9,n0,nAsterisk,nHash};
  
  if (key){
    //Serial.println(key);
    lc.setIntensity(0,15);

    if (key == '0')
      printByte(n0);
    if (key == '1')
      printByte(n1);
    if (key == '2')
      printByte(n2);
    if (key == '3')
      printByte(n3);
    if (key == '4')
      printByte(n4);
    if (key == '5')
      printByte(n5);
    if (key == '6')
      printByte(n6);
    if (key == '7')
      printByte(n7);
    if (key == '8')
      printByte(n8);
    if (key == '9')
      printByte(n9);
    if (key == '*')
      printByte(nAsterisk);
    if (key == '#')
      printByte(nHash);
    
    delay(500);
    lc.clearDisplay(0);
  }

  printByte(emo);
  delay(1);
}

void printByte(byte chr[])
{
  int i = 0;
  for (i=0; i<8; i++)
  {
    lc.setRow(0,i,chr[i]);
  }
}

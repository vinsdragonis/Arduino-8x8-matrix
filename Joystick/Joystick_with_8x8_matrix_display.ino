int UD = 0;
int LR = 0;
#include "LedControl.h"
LedControl lc=LedControl(8,10,9,1);
void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);
}
void loop() {
  UD = analogRead(A1);
  LR = analogRead(A0);
  char x_translate = map(LR, 1021, 0, 7, 0);
  char y_translate = map(UD, 1021, 0, 0, 7);  
  Serial.print("UD = ");
  Serial.print(UD, DEC);
  Serial.print(", LR = ");
  Serial.print(LR, DEC);
  Serial.print(", x = ");
  Serial.print(x_translate, DEC); 
  Serial.print(", y = ");
  Serial.println(y_translate, DEC); 
  lc.clearDisplay(0);
  lc.setLed(0,x_translate,y_translate,true);  
  delay(30);
}

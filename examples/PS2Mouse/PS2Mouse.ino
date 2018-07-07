/*
USB Pinout (Left to Right, USB symbol up)
4: GND
3: Clk
2: Data
1: Vcc
*/

#include "PS2Mouse.h"

PS2Mouse mouse(6,5);

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.print("Setup...");

  mouse.begin();
  Serial.println("complete!");
}

void loop(){
  uint8_t stat;
  int x,y;
  mouse.getPosition(stat,x,y);
  
  Serial.print(stat, BIN);
  Serial.print("\tx=");
  Serial.print(x, DEC);
  Serial.print("\ty=");
  Serial.println(y, DEC);
  
  delay(1000);  
}


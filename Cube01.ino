/*
 * File:    RandomPrimaries.ino
 * Version: 1.0
 * Author:  Jonathan Oxer (jon@freetronics.com)
 * License: GPLv3
 */

#include "SPI.h"
#include "Cube.h"

byte xPos;
byte yPos;
byte zPos;

rgb_t colours[3] = {RED, GREEN, BLUE};

Cube cube;

void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(); // Start on serial port 0 (USB) at 115200 baud
  cube.all(BLACK);
  //cube.set(1,3,3,GREEN);
  //cube.set(3,0,0,BLUE); //cube.set(3,0,0,RED) also turns on (0,1,0,RED) and vica verca
  //cube.set(3,0,0,RED);
  //cube.set(3,0,1,BLUE); //cube.set(3,0,1,RED) also turns on (0,1,1,RED) and vica verca 
  //cube.set(3,0,1,RED);
  //cube.set(3,0,2,BLUE); //cube.set(3,0,2,RED) also turns on (0,1,2,RED) and vica verca 
 // cube.set(3,0,2,RED);
  //cube.set(3,0,3,BLUE ); // turns on (0,1,3,RED) but not (3,0,3,RED)
  //cube.set(3,0,3,RED);
  // cube.set(3,0,3,RED); not working ANY COLOR
  // cube.set(3,2,1,RED); not working ANY COLOR
  //cube.set(1,1,2,GREEN);// not working GREEN
  //cube.set(2,3,2,GREEN);// not working GREEN
  /*
  for (int z=0;z<4;z++) {
    for (int y=0;y<4;y++) {
       for (int x=0;x<4;x++) { // (3,2,1,BLUE)
         cube.set(x,y,z,GREEN);
         delay(500);
      }
    }  
  }
  */
}

void stepThroughLEDs()
{
  int i = 0;
  int xPos = 0;
  int yPos = 0;
  int zPos = 0;

  while(zPos < 4)
  {
    yPos = 3;
    while(yPos > -1)
    {
      xPos = 0;
      while(xPos < 4)
      {
        cube.all(BLACK);
        cube.set(xPos, yPos, zPos, RED);
        xPos++;
        i++;
        delay(500);
      }
      yPos--;
    }
    zPos++;
  }
}

void boxUpDown()
{
  for (int x= 0; x<2; x++) {
  cube.all(YELLOW);
  cube.set(1,1,1,RED);
  cube.set(2,1,1,RED);
  cube.set(1,2,1,RED);
  cube.set(2,2,1,RED);
  cube.set(1,1,2,RED);
  cube.set(2,1,2,RED);
  cube.set(1,2,2,RED);
  cube.set(2,2,2,RED);
  delay(450);
  cube.all(RED);
  cube.set(1,1,1,YELLOW);
  cube.set(2,1,1,YELLOW);
  cube.set(1,2,1,YELLOW);
  cube.set(2,2,1,YELLOW);
  cube.set(1,1,2,YELLOW);
  cube.set(2,1,2,YELLOW);
  cube.set(1,2,2,YELLOW);
  cube.set(2,2,2,YELLOW);
  delay(450);
  }
}

void fadeWhite()
{
  for (byte i = 0; i < 255; i++)
  {
    cube.all(RGB(i, i, i));
    delay(3);
  }
  for (byte i = 255; i > 0; i--)
  {
    cube.all(RGB(i, i, i));
    delay(3);
  }
}

void cyclePlaneColours()
{
  for (byte i = 0; i < 4; i++)
  {
    cube.all(BLACK);
    cube.setplane(Z, i, RED);
    delay(400);
    cube.all(BLACK);
    cube.setplane(Z, i, GREEN);
    delay(400);
    cube.all(BLACK);
    cube.setplane(Z, i, BLUE);
    delay(400);
  }
}

void myCubeLine(byte x1, byte y1, byte z1, byte x2, byte y2, byte z2, rgb_t rgb)
{
  byte x;
  byte y; 
  byte z;
  x = x1;
  y = y1;
  z = z1;
  cube.set(x,y,z,rgb);  
  if (x < x2) x++;
  if (x > x2) x--;
  if (y < y2) y++;
  if (y > y2) y--;
  if (z < z2) z++;
  if (z > z2) z--;
  cube.set(x,y,z,rgb); 
  if (x < x2) x++;
  if (x > x2) x--;
  if (y < y2) y++;
  if (y > y2) y--;
  if (z < z2) z++;
  if (z > z2) z--;
  cube.set(x,y,z,rgb); 
  if (x < x2) x++;
  if (x > x2) x--;
  if (y < y2) y++;
  if (y > y2) y--;
  if (z < z2) z++;
  if (z > z2) z--;
  cube.set(x,y,z,rgb); 
}

void randomPastel()
{  
  cube.set(random(4), random(4), random(4), RGB(random(255), random(255), random(255)));
  delay(2);
}

void loop(void) {
  //return;
  int _delay = 300;  
  rgb_t rgb;
  rgb_t SILVER =  RGB(227, 228, 229);
  rgb = SILVER;
  for (int x= 0; x<10; x++) {
      cube.all(RED);
      myCubeLine(0,0,0,3,3,3,rgb);
      delay(_delay);
      cube.all(RED);
      myCubeLine(0,0,3,3,3,0,rgb);
       delay(_delay);
      cube.all(RED);
      myCubeLine(3,0,3,0,3,0,rgb);
       delay(_delay);
      cube.all(RED);
      myCubeLine(0,3,3,3,0,0,rgb);
      delay(_delay);
  }
  _delay = 150; 
  rgb = RGB(random(255), random(255), random(255));
  for (int x= 0; x<10; x++) {
      cube.all(BLACK);
      myCubeLine(0,0,0,3,3,3,rgb);
      delay(_delay);
      cube.all(BLACK);
      myCubeLine(0,0,3,3,3,0,rgb);
       delay(_delay);
      cube.all(BLACK);
      myCubeLine(3,0,3,0,3,0,rgb);
       delay(_delay);
      cube.all(BLACK);
      myCubeLine(0,3,3,3,0,0,rgb);
      delay(_delay);
      cube.all(BLACK);  
      rgb = RGB(random(255), random(255), random(255));
  }
  for (int x= 0; x<5; x++) {
  cube.all(RED);
  myCubeLine(0,0,0,3,0,0,SILVER);
  myCubeLine(3,0,0,3,3,0,SILVER);
  myCubeLine(3,3,0,0,3,0,SILVER);
  myCubeLine(0,3,0,0,0,0,SILVER);
  myCubeLine(0,0,3,3,0,3,SILVER);
  myCubeLine(3,0,3,3,3,3,SILVER);
  myCubeLine(3,3,3,0,3,3,SILVER);
  myCubeLine(0,3,3,0,0,3,SILVER);
  myCubeLine(0,0,0,0,0,3,SILVER);
  myCubeLine(3,0,0,3,0,3,SILVER);
  myCubeLine(3,3,0,3,3,3,SILVER);
  myCubeLine(0,3,0,0,3,3,SILVER);
  delay(1000);
  cube.all(BLACK);
  myCubeLine(0,0,0,3,0,0,SILVER);
  myCubeLine(3,0,0,3,3,0,SILVER);
  myCubeLine(3,3,0,0,3,0,SILVER);
  myCubeLine(0,3,0,0,0,0,SILVER);
  myCubeLine(0,0,3,3,0,3,SILVER);
  myCubeLine(3,0,3,3,3,3,SILVER);
  myCubeLine(3,3,3,0,3,3,SILVER);
  myCubeLine(0,3,3,0,0,3,SILVER);
  myCubeLine(0,0,0,0,0,3,SILVER);
  myCubeLine(3,0,0,3,0,3,SILVER);
  myCubeLine(3,3,0,3,3,3,SILVER);
  myCubeLine(0,3,0,0,3,3,SILVER);
  delay(200);
  }
  cube.all(BLACK);
  myCubeLine(0,0,0,3,0,0,BLUE);
  myCubeLine(3,0,0,3,3,0,BLUE);
  myCubeLine(3,3,0,0,3,0,BLUE);
  myCubeLine(0,3,0,0,0,0,BLUE);
  myCubeLine(0,0,3,3,0,3,BLUE);
  myCubeLine(3,0,3,3,3,3,BLUE);
  myCubeLine(3,3,3,0,3,3,BLUE);
  myCubeLine(0,3,3,0,0,3,BLUE);
  myCubeLine(0,0,0,0,0,3,BLUE);
  myCubeLine(3,0,0,3,0,3,BLUE);
  myCubeLine(3,3,0,3,3,3,BLUE);
  myCubeLine(0,3,0,0,3,3,BLUE);
  delay(5000);
  _delay = 10;
  _delay = 150;
  fadeWhite();
  boxUpDown();  
  boxUpDown();
  for (int x = 0;x <100;x++) {
     randomPastel();
     delay(10);
  };  
  for (int x= 0; x<5; x++) {
  cube.all(BLACK);  
  cube.setplane(Z, 3, RED); 
  delay(_delay); delay(_delay);
  cube.all(BLACK);
  cube.setplane(Z, 2, RED); 
  delay(_delay);
  cube.all(BLACK);
  cube.setplane(Z, 1, RED); 
  delay(_delay); 
  cube.all(BLACK);
  cube.setplane(Z, 0, SILVER); 
  delay(_delay); 
  cube.all(BLACK);
  cube.setplane(Z, 1, SILVER); 
  delay(_delay);
  cube.all(BLACK);
  cube.setplane(Z, 2, SILVER); 
  delay(_delay);
  }
}

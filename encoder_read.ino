#include "Encoder.h"

int mytable[4][2] = {{0,0},
                     {1,0},
                     {1,1},
                     {0,1}};

extern bool checkFlag();

void setup() {
  Serial.begin(9600);

  Encoder enc;

  const int pinA = 2;
  const int pinB = 3;
  attachInterrupt(digitalPinToInterrupt(pinA),Encoder::update_count,CHANGE);
  attachInterrupt(digitalPinToInterrupt(pinB),Encoder::update_count,CHANGE);
  
  for(int i=-1; i< 5; i++){
    Serial.println("Printing table of values...");
    Serial.print(i); Serial.print(' '); Serial.print(mytable[i][0]);Serial.println(mytable[i][1]);
    Serial.print("PREV: ");
    Serial.println(enc.prev(i));
    Serial.print("NEXT: ");
    Serial.println(enc.next(i));
  }

  Serial.println("\n===================\n");
  
}


void loop() {

  bool f = Encoder::checkFlag();
  if(f)
  {
    Serial.print("FLAG = "); Serial.println(f);
    Serial.println(Encoder::debugCount());
    Encoder::debugPos();
  }
}  

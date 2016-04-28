#include "Encoder.h"
#include <Arduino.h>

void Encoder::update_count()
{
  bool A = digitalRead(2); // need to replace with pinA
  bool B = digitalRead(3); // need to replace with pinB
  int next_step[2] = {enc_table[next(enc_pos)][0],enc_table[next(enc_pos)][1]};
  int prev_step[2] = {enc_table[prev(enc_pos)][0],enc_table[prev(enc_pos)][1]};

  //Serial.println("INTERRUPT TRIGGERED");
  
  if(A == enc_table[next(enc_pos)][0] && B == enc_table[next(enc_pos)][1]) {
    enc_count++;
    enc_pos = next(enc_pos);
    FLAG = true;
  }
  else if(A == enc_table[prev(enc_pos)][0] && B == enc_table[prev(enc_pos)][1]) {
    enc_count--;
    enc_pos = prev(enc_pos);
    FLAG = true;
  }
}

int Encoder::next(int i)
{
  if(i < 0 || i > 3) {
    Serial.println("Invalid input to enc_next function.");  
    return -1;
  }
  else
    return (i+1)%4;
}

int Encoder::prev(int i)
{ 
  if(i < 0 || i > 3) {
    Serial.println("Invalid input to enc_prev function.");  
    return -1;
  }
  if(i == 0) return 3;
  else
    return (i-1)%4;
}

int Encoder::debugCount(){
  return enc_count;
}

void Encoder::debugPos(){
  Serial.print("Position is ");Serial.print(enc_table[enc_pos][0]);Serial.println(enc_table[enc_pos][1]);
}

bool Encoder::checkFlag()
{
  if(FLAG == true)
  {
    FLAG = false;
    return true;
  }
  return false;
}


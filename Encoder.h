#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

/* Simple Encoder class to read from incremental encoders.
 * Uses Gray code specified in the table to incrementally step through cycle.
 * TODO: add interrupt routines that automatically handle encoder pulses with interrupts.
 * 
 * Daniel Sun, UCLA RoMeLa April 27, 2016
 */

static volatile bool FLAG = false;
static volatile int enc_count = 0; // count is absolute position we're at
static volatile int enc_pos = 0; // enc_pos is the position in the cycle
static constexpr int enc_table[4][2] = {{0,0},
                                        {1,0},
                                        {1,1},
                                        {0,1}};    


class Encoder 
{
  public:    
    static int next(int i);
    static int prev(int i);
    static void update_count();
    
    static int debugCount();
    static void debugPos();
    static bool checkFlag();
};


#endif

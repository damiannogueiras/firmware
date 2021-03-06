#ifndef _MOTION_H
#define _MOTION_H

#include <stdint.h>
#include "Gear.h"

#define HOWMANYLOOPS_FB_10 218 //how far does robota go, 1 to debug, 218 to one square 10cm
#define HOWMANYLOOPS_FB_15 327 // one square 15cm
#define HOWMANYLOOPS_LR 128 // right and left 90º
#define MAXCELL 6 //number of cells


class Motion
{
public:

  /**
   * Constructor
   */
   Motion();
   /**
    * forward movement squares
    * @param squares Amount of squares on board. Negative go back
    * return true if it was movement, false if outboard
    */
    bool movForward(int8_t squares);
    /**
     * back movement squares
     * @param squares Amount of squares on board
     */
    bool movBack(int8_t squares){
      return movForward(-squares);
    }
    /**
     * turn right-handed if param true or left-handed if param false
     * @param rightHanded if true turn right, if false turn left
     * return true if it was movement, false if outboard
     */
    void turn(bool rightHanded);
    /**
     * turn left handed
     */
    void turnLeft(){
      turn(false);
    }
    /**
     * turn right handed
     */
    void turnRight(){
      turn(true);
    }
    /**
     * stop robota
     */
    void stop();
    //movement X axis
    int steepX(int myCompass);
    //movement Y axis
    int steepY(int myCompass);
    // get and set private
    int getX();
    int getY();
    char getCardinal();
    void setX(int x);
    void setY(int y);
    void setCardinal(char compass);
    // to send i2c
    Gear gear;

private:
  //actual position on the board
  //init my position, right inf corner
  int _myPosition[2];
  // auxiliar position to check limit board
  int _myAuxPosition[2];
  // index of the cardinal point of my compass
  int _myCompass;
  //cardinal points
  const char _cardinal[4] = {'N','E','S','W'};
  //String _commands = "SFLBR";
  // signal + Forward, - Backward
  int8_t _signal;

};

#endif // _MOTION_H

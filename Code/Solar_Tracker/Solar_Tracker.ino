//Servo motor library
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Servo.h>
//Initialize variables


int topl1 = 0;
int topr1 = 0;
int botl1 = 0;
int botr1 = 0;

int topl2 = 0;
int topr2 = 0;
int botl2 = 0;
int botr2 = 0;

int topl3 = 0;
int topr3 = 0;
int botl3 = 0;
int botr3 = 0;

int topl4 = 0;
int topr4 = 0;
int botl4 = 0;
int botr4 = 0;

//my code below
Adafruit_ADS1115 ads1; // First ADS1115 for the (0x48) address object
Adafruit_ADS1115 ads2; // Second ADS1115 for the (0x49) address object
Adafruit_ADS1115 ads3;
Adafruit_ADS1115 ads4;

#define I2C_ADDRESS_1  0x48
#define I2C_ADDRESS_2  0x49
#define I2C_ADDRESS_3  0x50
#define I2C_ADDRESS_4  0x51

//Declare two servos
Servo servo_updown1;
Servo servo_rightleft1;
Servo servo_updown2;
Servo servo_rightleft2;
Servo servo_updown3;
Servo servo_rightleft3;
Servo servo_updown4;
Servo servo_rightleft4;

int threshold_value = 10;         //measurement sensitivity

void setup()
{
  Serial.begin(9600);                                //serial connection setup  //opens serial port, sets data rate to 9600 bps
  Serial.println("CLEARDATA");                       //clear all data that’s been place in already
  Serial.println("LABEL,t,voltage,current,power,Mode");   //define the column headings (PLX-DAQ command)

  ads1.begin();
  ads2.begin();
  ads3.begin();
  ads4.begin();
  servo_updown1.attach(2);            
  servo_rightleft1.attach(3);    
  servo_updown2.attach(4);            
  servo_rightleft2.attach(5);  
  servo_updown3.attach(6);            
  servo_rightleft3.attach(7);  
  servo_updown4.attach(8);            
  servo_rightleft4.attach(9);  
}

void loop()
{
  delay(50);
  automaticsolartracker1();
  delay(50);
  automaticsolartracker2();
  delay(50);
  automaticsolartracker3();
  delay(50);
  automaticsolartracker4();
  

}


void automaticsolartracker1() {

  //capturing analog values of each LDR
  topr1 = ads1.readADC_SingleEnded(0);
  topl1 = ads1.readADC_SingleEnded(1);
  botr1 = ads1.readADC_SingleEnded(2);
  botl1 = ads1.readADC_SingleEnded(3);

  // calculating average
  int avgtop1 = (topr1 + topl1) / 2;     //average of top LDRs
  int avgbot1 = (botr1 + botl1) / 2;     //average of bottom LDRs
  int avgleft1 = (topl1 + botl1) / 2;    //average of left LDRs
  int avgright1 = (topr1 + botr1) / 2;   //average of right LDRs

  //Get the different
  int diffelev1 = avgtop1 - avgbot1;      //Get the different average betwen LDRs top and LDRs bot
  int diffazi1 = avgright1 - avgleft1;    //Get the different average betwen LDRs right and LDRs left

  //left-right movement of solar tracker

  if (abs(diffazi1) >= threshold_value) {       //Change position only if light difference is bigger then the threshold_value
    if (diffazi1 > 0) {
      if (servo_rightleft1.read() < 180) {
        servo_rightleft1.write((servo_updown1.read() + 2));
      }
    }
    if (diffazi1 <  0) {
      if (servo_rightleft1.read() > 0) {
        servo_rightleft1.write((servo_updown1.read() - 2));
      }
    }
  }



  if (abs(diffelev1) >= threshold_value) {   //Change position only if light difference is bigger then thethreshold_value
    if (diffelev1 > 0) {
      if (servo_updown1.read() < 180) {
        servo_updown1.write((servo_rightleft1.read() - 2));
      }
    }
    if (diffelev1 <  0) {
      if (servo_updown1.read() > 0) {
        servo_updown1.write((servo_rightleft1.read() + 2));
      }
    }
  }
}

void automaticsolartracker2() {

  //capturing analog values of each LDR
  topr2 = ads2.readADC_SingleEnded(0);
  topl2 = ads2.readADC_SingleEnded(1);
  botr2 = ads2.readADC_SingleEnded(2);
  botl2 = ads2.readADC_SingleEnded(3);

  // calculating average
  int avgtop2 = (topr2 + topl2) / 2;     //average of top LDRs
  int avgbot2 = (botr2 + botl2) / 2;     //average of bottom LDRs
  int avgleft2 = (topl2 + botl2) / 2;    //average of left LDRs
  int avgright2 = (topr2 + botr2) / 2;   //average of right LDRs

  //Get the different
  int diffelev2 = avgtop2 - avgbot2;      //Get the different average betwen LDRs top and LDRs bot
  int diffazi2 = avgright2 - avgleft2;    //Get the different average betwen LDRs right and LDRs left

  //left-right movement of solar tracker

  if (abs(diffazi2) >= threshold_value) {       //Change position only if light difference is bigger then the threshold_value
    if (diffazi2 > 0) {
      if (servo_rightleft2.read() < 180) {
        servo_rightleft2.write((servo_updown2.read() + 2));
      }
    }
    if (diffazi2 <  0) {
      if (servo_rightleft2.read() > 0) {
        servo_rightleft2.write((servo_updown2.read() - 2));
      }
    }
  }



  if (abs(diffelev2) >= threshold_value) {   //Change position only if light difference is bigger then thethreshold_value
    if (diffelev2 > 0) {
      if (servo_updown2.read() < 180) {
        servo_updown2.write((servo_rightleft2.read() - 2));
      }
    }
    if (diffelev2 <  0) {
      if (servo_updown2.read() > 0) {
        servo_updown2.write((servo_rightleft2.read() + 2));
      }
    }
  }
}

void automaticsolartracker3() {

  //capturing analog values of each LDR
  topr3 = ads3.readADC_SingleEnded(0);
  topl3 = ads3.readADC_SingleEnded(1);
  botr3 = ads3.readADC_SingleEnded(2);
  botl3 = ads3.readADC_SingleEnded(3);

  // calculating average
  int avgtop3 = (topr3 + topl3) / 2;     //average of top LDRs
  int avgbot3 = (botr3 + botl3) / 2;     //average of bottom LDRs
  int avgleft3 = (topl3 + botl3) / 2;    //average of left LDRs
  int avgright3 = (topr3 + botr3) / 2;   //average of right LDRs

  //Get the different
  int diffelev3 = avgtop3 - avgbot3;      //Get the different average betwen LDRs top and LDRs bot
  int diffazi3 = avgright3 - avgleft3;    //Get the different average betwen LDRs right and LDRs left

  //left-right movement of solar tracker

  if (abs(diffazi3) >= threshold_value) {       //Change position only if light difference is bigger then the threshold_value
    if (diffazi3 > 0) {
      if (servo_rightleft3.read() < 180) {
        servo_rightleft3.write((servo_updown3.read() + 2));
      }
    }
    if (diffazi3 <  0) {
      if (servo_rightleft3.read() > 0) {
        servo_rightleft3.write((servo_updown3.read() - 2));
      }
    }
  }



  if (abs(diffelev3) >= threshold_value) {   //Change position only if light difference is bigger then thethreshold_value
    if (diffelev3 > 0) {
      if (servo_updown3.read() < 180) {
        servo_updown3.write((servo_rightleft3.read() - 2));
      }
    }
    if (diffelev3 <  0) {
      if (servo_updown3.read() > 0) {
        servo_updown3.write((servo_rightleft3.read() + 2));
      }
    }
  }
}

void automaticsolartracker4() {

  //capturing analog values of each LDR
  topr4 = ads4.readADC_SingleEnded(0);
  topl4 = ads4.readADC_SingleEnded(1);
  botr4 = ads4.readADC_SingleEnded(2);
  botl4 = ads4.readADC_SingleEnded(3);

  // calculating average
  int avgtop4 = (topr4 + topl4) / 2;     //average of top LDRs
  int avgbot4 = (botr4 + botl4) / 2;     //average of bottom LDRs
  int avgleft4 = (topl4 + botl4) / 2;    //average of left LDRs
  int avgright4 = (topr4 + botr4) / 2;   //average of right LDRs

  //Get the different
  int diffelev4 = avgtop4 - avgbot4;      //Get the different average betwen LDRs top and LDRs bot
  int diffazi4 = avgright4 - avgleft4;    //Get the different average betwen LDRs right and LDRs left

  //left-right movement of solar tracker

  if (abs(diffazi4) >= threshold_value) {       //Change position only if light difference is bigger then the threshold_value
    if (diffazi4 > 0) {
      if (servo_rightleft4.read() < 180) {
        servo_rightleft4.write((servo_updown4.read() + 2));
      }
    }
    if (diffazi4 <  0) {
      if (servo_rightleft4.read() > 0) {
        servo_rightleft4.write((servo_updown4.read() - 2));
      }
    }
  }



  if (abs(diffelev4) >= threshold_value) {   //Change position only if light difference is bigger then thethreshold_value
    if (diffelev4 > 0) {
      if (servo_updown4.read() < 180) {
        servo_updown4.write((servo_rightleft4.read() - 2));
      }
    }
    if (diffelev4 <  0) {
      if (servo_updown4.read() > 0) {
        servo_updown4.write((servo_rightleft4.read() + 2));
      }
    }
  }
}
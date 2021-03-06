#ifndef Catapult_h
#define Catapult_h

#include "Arduino.h"
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

class Catapult {

  public:

    Catapult(Adafruit_PWMServoDriver &servoDriver, int firePin, int armPin, int ballsPin, int platformPin);
    void Catapult::sweep (Adafruit_PWMServoDriver &servoDriver, int servoID, int originAngle, int destinationAngle, int speed);
    void Catapult::rest(Adafruit_PWMServoDriver &servoDriver );
    void Catapult::prepareToShoot(Adafruit_PWMServoDriver &servoDriver );
    void Catapult::shoot(Adafruit_PWMServoDriver &servoDriver );
    void Catapult::openGate(Adafruit_PWMServoDriver &servoDriver);
    void Catapult::closeGate(Adafruit_PWMServoDriver &servoDriver);
    void Catapult::feedBall(Adafruit_PWMServoDriver &servoDriver );
    void Catapult::stepScan(Adafruit_PWMServoDriver &servoDriver);


  private:
    int fireServoID;
    int armServoID;
    int ballServoID;
    int platformServoID;

    // i2c pwm values//
    //fire servo
    const int releasePulse  = 325;
    const int blockingPulse = 150;

    //arm servo
    const int armedPulse    = 270;
    const int disarmedPulse = 460;

    //balls servo
    const int feedBalls     = 390;
    const int stopBalls     = 435;

    //platform servo
    const int startScanPulse = 196;
    const int endScanPulse = 484;

    int currentFireServoPulse = 300;
    int currentArmServoPulse = 400;
    int currentBallServoPulse = 425;
    int currentPlatformServoPulse = 196;

    //Adafruit_PWMServoDriver servoDriver;
    int currentScanDirection = 1;
    int scanStep = 24;
};

#endif


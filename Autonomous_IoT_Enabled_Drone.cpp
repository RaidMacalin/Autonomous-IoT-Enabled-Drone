/* 
 * Project Autonomous-IoT-Enabled-Drone
 * Author: Raid Macalin
 * Date: Nov, 2024
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor -- 'follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);
// defining motor and engage pins
#define motorspeed1 S1
#define motor1CW S4 // clockwise direction pin
#define motor1CCW A5 // counter clockwise direction pin
#define motorspeed2 A2
#define motor2CW D5
#define motor2CCW D7

int CW = 1;
int CCW = 2;
// speed goes from 0 to 255
void motor(int motor, int speed, int direction ){ // function thats turns on motor, sets direction and speed
if (motor == 1){ // sets up motor 1/ left side motor
if (direction == 1){// sets the motor speed to clockwise
digitalWrite(motor1CW,HIGH); 
digitalWrite(motor1CCW,LOW);
}
if (direction == 2){ // sets motor speed to counter clockwise
digitalWrite(motor1CW,LOW);
digitalWrite(motor1CCW,HIGH);
}
analogWrite(motorspeed1,speed); // sets motor speed after setting up direction
}

if (motor == 2){ // sets up motor 2/ right side motor
if (direction == 1){ // sets the motor speed to clockwise
digitalWrite(motor2CW,HIGH);
digitalWrite(motor2CCW,LOW);
}
if (direction == 2){ // sets motor speed to counter clockwise
digitalWrite(motor2CW,LOW);
digitalWrite(motor2CCW,HIGH);
}
analogWrite(motorspeed2,speed); // sets motor speed after setting up direction
}
}
// setup() runs once, when the device is first turned on
void setup() {
pinMode(motorspeed1,OUTPUT); // initilize all motor pins
 pinMode(motor1CW,OUTPUT);
 pinMode(motor1CCW,OUTPUT);
 pinMode(motorspeed2,OUTPUT);
 pinMode(motor2CW,OUTPUT);
 pinMode(motor2CCW,OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
motor(1,100,1); // intializess motor 1 and 2 to move n same direction and speed
motor(2,100,1);
delay (3000);
motor(1,100,2); // changes motor 1 and 2 to opposite direction
motor(2,100,2);
delay (3000);
}

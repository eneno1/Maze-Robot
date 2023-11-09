#include <AFMotor.h>
//Conventional Forward is Backward
AF_DCMotor motor1(1);//Declares each motor as a variable
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int trigger_front = A0;
int echo_front = A1;

int trigger_left = A2;
int echo_left = A3;

int trigger_right = A4;
int echo_right = A5;


void setup() 
{
//Set initial speed of the motor & stop
  motor1.setSpeed(200); //motor on at a set speed
  motor1.run(RELEASE);// motor off
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);

  pinMode(trigger_front,OUTPUT);
  pinMode(echo_front,INPUT);

  pinMode(trigger_left,OUTPUT);
  pinMode(echo_left,INPUT);

  pinMode(trigger_right,OUTPUT);
  pinMode(echo_right,INPUT);
  
  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 88);
}

void stop()
{
  motor1.run(RELEASE);//Stops all motors
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void moveForward(int time)//All of the motors move forward at a set speed
{
  motor1.run(BACKWARD);//Conventional forward and backward are flipped
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  motor1.setSpeed(200); //each motor's speed is kept constant for a given time
  motor2.setSpeed(200);  
  motor3.setSpeed(200); 
  motor4.setSpeed(200);

  delay(time);

  motor1.setSpeed(0); //each motor's speed is set to zero
  motor2.setSpeed(0);  
  motor3.setSpeed(0); 
  motor4.setSpeed(0);
}

void moveBackward(int time)//All of the motors move forward at a set speed
{
  motor1.run(FORWARD);//Conventional forward and backward are flipped
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  motor1.setSpeed(200); //each motor's speed is kept constant for a given time
  motor2.setSpeed(200);  
  motor3.setSpeed(200); 
  motor4.setSpeed(200);

  delay(time);

  motor1.setSpeed(0); //each motor's speed is set to zero
  motor2.setSpeed(0);  
  motor3.setSpeed(0); 
  motor4.setSpeed(0);
}

void turnRight(int time)
{

//turn on front motors in opposite directions
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
 

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    
  
    delay(10);
  }


  delay(time);

}

void turnLeft(int time)
{

//turn on front motors in opposite directions
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
 

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
  
    delay(10);
  }


  delay(time);

}


void loop()
{
turnLeft(750);
stop();
  

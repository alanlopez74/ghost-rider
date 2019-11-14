#include <Servo.h>

byte throttle_pin = 9;
byte steering_pin = 3;
int cur_speed = 0;
int cur_pos = 90;

Servo throttle_servo;
Servo steering_servo;

void setup() {
    //Serial.begin(9600);
    throttle_servo.attach(throttle_pin);
    steering_servo.attach(steering_pin);
    
    throttle_servo.write(1500); // send stop signal
    
    delay(700);
}

void loop() {
    // set to 2/5 max speed
//    delay(6000);
    // cur_speed = 1700;
    // throttle_servo.writeMicroseconds(cur_speed);
    // cur_pos = 140;
    // steering_servo.write(cur_pos);
    // delay(4000);
//    
//    cur_speed = 0;
//    cur_pos = 90;
//    throttle_servo.write(cur_speed);
//    steering_servo.write(cur_pos);
    
    delay(2000);
    speed_up(100, 10);
//    turn_right(140, 10);
//    delay(2000);
//    turn_right(180, 10);
//    delay(2000);
//    turn_left(90, 10);
//    delay(1000);
//    turn_left(0, 10);
//    delay(3000);
//    speed_down(0,10);
//    turn_right(90,10);
//    delay(5000);
}

void turn_right(int position, int time_delay) {
  int pos_dif = position - cur_pos;
  if (position > cur_pos) {
    for (int i = 0; i < pos_dif; i += 10) {
      cur_pos += 10;
      steering_servo.write(cur_pos);
      delay(time_delay);
    }
  }
}

void turn_left(int position, int time_delay) {
  int pos_dif = cur_pos - position;
  if (position < cur_pos) {
    for (int i = 0; i < pos_dif; i += 10) {
      cur_pos -= 10;
      steering_servo.write(cur_pos);
      delay(time_delay);
    
    }
  }
}

void speed_up(int new_speed, int time_delay) {
  // Serial.println(cur_speed);
  // Serial.println(new_speed);
  int speed_dif = new_speed -cur_speed;
  if (new_speed > cur_speed) {
    for (int i = 0; i < speed_dif; i += 10) {
      cur_speed += 10;
      throttle_servo.write(cur_speed);
      delay(time_delay);
      // Serial.println(i);
      // Serial.println(cur_speed);
    }
  }
}

void speed_down(int new_speed, int time_delay) {
  //throttle_servo.writeMicroseconds(1500);
  int speed_dif = cur_speed - new_speed;
  if (new_speed < cur_speed) {
    for (int i = 0; i < speed_dif; i += 10) {
      cur_speed -= 10;
      throttle_servo.write(cur_speed);
      delay(time_delay);
    }
  }
}

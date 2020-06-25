#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

const int switchpin = 10;

int action = 7;
int switch_angle = 163;
int ready_angle = 30;
int pos = 0;

void setup() {
pinMode(switchpin,INPUT);
lidservo.attach(13);
armservo.attach(12);
flag.attach(11);
Serial.begin(9600);
// Servo Default Starting Position

armservo.write(ready_angle);
flag.write(50);
lidservo.write(90);
}

void loop() {

// Action Selection starting with 1
  int pin = digitalRead(switchpin);
  Serial.println(pin);
  if (pin)
  {
    if (action > 8)  action = 1;
    if (action == 1) action1();
    else if (action == 2) action2();
    else if (action == 3) action3();
    else if (action == 4) action4();
    else if (action == 5) action5();
    else if (action == 6) action6();
    else if (action == 7) action7();
    else if (action == 8) action8();
  
    Serial.println("action " + String(action) + " done!");
    action += 1;
  }
}

//The Following are actions that are chosen chronologically

void action1() {
  lidservo.write(20);
  delay(1000);
  armservo.write(switch_angle);
  delay(500); 
  armservo.write(ready_angle);
  delay(1000);
  lidservo.write(90);
  delay(1000);
}

void action2() {
  lidservo.write(50);
  delay(100);
  armservo.write(switch_angle);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
}

void action3() {
  for(pos = 90; pos > 20; pos -=1)
  {
    lidservo.write(pos);
    delay(50);
  }
  armservo.write(switch_angle);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
}

void action4() {
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(switch_angle);
  delay(2500);
  for(pos = switch_angle; pos > 90; pos -=1)
    {
      armservo.write(pos);
      delay(50);
    }
  lidservo.write(90);
  armservo.write(ready_angle);
}

void action5() {
  lidservo.write(50);
  delay(500);
  lidservo.write(90);
  delay(500);
  lidservo.write(50);
  delay(500);
  lidservo.write(90);
  delay(500);
  lidservo.write(50);
  delay(500);
  lidservo.write(90);
  delay(2500);
  lidservo.write(50);
  delay(100);
  armservo.write(switch_angle);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
}

void action6() {
  lidservo.write(50);
  delay(100);
  armservo.write(155);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(155);
  delay(250);
  armservo.write(50);
  delay(100);
  lidservo.write(90);
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(155);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
  delay(250);  
  lidservo.write(50);
  delay(100);
  armservo.write(switch_angle);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
}

void action7() {
  for(pos = 90; pos > 20; pos -=2)
    {
      lidservo.write(pos);
      delay(50);
    }
  for(pos = ready_angle; pos <= 90; pos +=2)
    {
      armservo.write(pos);
      delay(50);
    }
    armservo.write(switch_angle + 9);
      delay(200); 
    armservo.write(90);
  for(pos = 90; pos > ready_angle; pos -=2)
    {
      armservo.write(pos);
      delay(50);
    }
  for(pos = 20; pos < 90; pos +=2)
    {
      lidservo.write(pos);
      delay(50);
    }
  lidservo.write(90);
}

void action8() {
  if (digitalRead(switchpin) == HIGH)
  {
    delay(1000);
      for(pos = 90; pos > 20; pos -=2)
  {
    lidservo.write(pos);
    delay(50);
  }
      for(pos = 50; pos < 175; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  delay(250);
      for(pos = 175; pos > 125; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 125; pos < 175; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 175; pos > 125; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 125; pos < 175; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 175; pos > 125; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 125; pos < 175; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 175; pos > 125; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
        for(pos = 125; pos < 175; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  delay(250);
        for(pos = 175; pos > 50; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
   for(pos = 20; pos < 90; pos +=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  delay(2000);
      lidservo.write(50);
  delay(100);
  armservo.write(switch_angle);
  delay(250);
  armservo.write(ready_angle);
  delay(100);
  lidservo.write(90);
  }

}

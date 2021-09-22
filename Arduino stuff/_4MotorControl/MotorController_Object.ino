void Runmotor(int mn, int md){
  if (md==1){
    if(mn==1){
Motor1->run(FORWARD);
    }
if(mn==2){
Motor2->run(FORWARD);
    }
    if(mn==3){
Motor3->run(FORWARD);
    }
    if(mn==4){
Motor4->run(FORWARD);
    }
}
if (md==2){
    if(mn==1){
Motor1->run(BACKWARD);
    }
if(mn==2){
Motor2->run(BACKWARD);
    }
    if(mn==3){
Motor3->run(BACKWARD);
    }
    if(mn==4){
Motor4->run(BACKWARD);
    }
}
if (md==0){
    if(mn==1){
Motor1->setSpeed(0);
    }
if(mn==2){
Motor2->setSpeed(0);
    }
    if(mn==3){
Motor3->setSpeed(0);
    }
    if(mn==4){
Motor4->setSpeed(0);
    }
}
}

void turn_right(){
 Runmotor(1,1);
 Runmotor(2,0);
 Runmotor(3,0);
 Runmotor(4,1);
 delay(1333);
  Stop();
}

void turn_left(){
 Runmotor(1,0);
 Runmotor(2,2);
 Runmotor(3,1);
 Runmotor(4,0);
 delay(1333);
  Stop();
}

void forward(){
 Runmotor(1,1);
 Runmotor(2,2);
 Runmotor(3,1);
 Runmotor(4,1);
 delay(1000);
  Stop();
}

void backward(){
 Runmotor(1,2);
 Runmotor(2,1);
 Runmotor(3,2);
 Runmotor(4,2);
 delay(1000);
  Stop();
}
void turn_left2(){
 Runmotor(1,2);
 Runmotor(2,2);
 Runmotor(3,1);
 Runmotor(4,2);
 delay(2400);
  Stop();
}
void turn_right2(){
 Runmotor(1,1);
 Runmotor(2,1);
 Runmotor(3,2);
 Runmotor(4,1);
 delay(2400);
  Stop();
}

void Stop(){
Motor1->setSpeed(0);
  Motor2->setSpeed(0);
  Motor3->setSpeed(0);
  Motor4->setSpeed(0);
}

void Go(){
Motor1->setSpeed(100);
Motor2->setSpeed(100);
Motor3->setSpeed(100);
Motor4->setSpeed(100);
}

void Dance(){
forward(); //up
Go();
backward();
Go();
forward();  //up
Go();
backward();
delay(500);
Go();
backward(); //down
Go();
forward();
Go();
backward(); //down
Go();
forward();
Go();
turn_left2(); //left
Go();
turn_right2();
delay(500);
Go();
turn_right2();  //right
Go();
turn_left2();
delay(500);
Go();
turn_left2(); //left
Go();
turn_right2();
delay(500);
Go();
turn_right2();  //right
Go();
turn_left2();
Go();
backward(); //B
Go();
turn_left2(); //A
Go();
turn_left2();
Go();
turn_left2();
Go();
turn_left2();
}

void Speed_Trial(){
  //delay(5000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  turn_left2();
  delay(1000);
  Go();
  turn_right2();
  delay(1000);
  Go();
  backward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  Go();
  forward();
  delay(1000);
  //delay(10000);
  
}




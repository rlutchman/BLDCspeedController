int pwmBranch;//determined based on hall reading
int floatingBranch;//determined based on hall reading
int groundBranch;//determined based on hall reading
int hall_reading;
int y=0b00111000;
int potPin = 2;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor
int delay_high;

void setup() {
  // put your setup code here, to run once:
 // DDRD |= B00000111;//pins 0,1,2 are outputs
 pinMode (8, INPUT);
 pinMode(9, INPUT);
 pinMode(10, INPUT);
   pinMode(3, OUTPUT); 
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT); 
/* pinMode(1, OUTPUT);
    digitalWrite(1, LOW);*/
  pinMode(2, OUTPUT);
  
  pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1,OUTPUT);
  
        // digitalWrite(0, LOW);
 // Serial.begin(9600);
 // Serial.println("h");

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(1,HIGH);
  hall_reading=PINB;
 // Serial.println(hall_reading);

 // hall_reading &=y;//mask all but pins 3,4,5, which are the hall readings

 // Serial.println(hall_reading);

  switch(hall_reading){
    case 5:
      pwmBranch=3;
      
      floatingBranch=1;
      groundBranch=2;
      PORTD = B00101000;
    break;
    case 1:
      pwmBranch=3;
      floatingBranch=2;
      groundBranch=1;
      PORTD = B00110000;
    break;
     case 3:
     pwmBranch=2;
      floatingBranch=3;
      groundBranch=1;
      PORTD = B00110000;
    break;
     case 2:
     pwmBranch=2;
      floatingBranch=1;
      groundBranch=3;
      PORTD = B00011000;
    break;
     case 6:
      pwmBranch=1;
      floatingBranch=2;
      groundBranch=3;
      PORTD = B00011000;
    break;
     case 4:
      pwmBranch=1;
      floatingBranch=3;
      groundBranch=2;
      PORTD = B00101000;
    break;
    case 43:
      pwmBranch=3;
      
      floatingBranch=1;
      groundBranch=2;
    break;
    case 11:
      pwmBranch=3;
      floatingBranch=2;
      groundBranch=1;
    break;
     case 27:
     pwmBranch=2;
      floatingBranch=3;
      groundBranch=1;
    break;
     case 19:
     pwmBranch=2;
      floatingBranch=1;
      groundBranch=3;
    break;
     case 51:
      pwmBranch=1;
      floatingBranch=2;
      groundBranch=3;
    break;
     case 35:
      pwmBranch=1;
      floatingBranch=3;
      groundBranch=2;
    break;
     default:
    break;

  
    
  }/*
    Serial.println(hall_reading);
    Serial.print("floating branch is ");
      Serial.println(floatingBranch);
        Serial.print("ground branch is ");
      Serial.println(groundBranch);
        Serial.print("pwm branch is ");
      Serial.println(pwmBranch);
     
    Serial.println(PORTD);*/

    
      val = analogRead(potPin);    // read the value from the sensor
      delay_high=val;
      delay_high=map(delay_high,170, 871, 0 ,990); // map from .85V-4.25V input to 0 to 100% duty cycle
      pwmBranch=pwmBranch-1;
   // Serial.print("pwm branch is ");
    //  Serial.println(pwmBranch);
     
     // digitalWrite(0, HIGH);
      // delay(700);

    //   delay(1000);
    
      digitalWrite(pwmBranch, HIGH);
       delayMicroseconds(delay_high);
       digitalWrite(pwmBranch, LOW);
       delayMicroseconds(1000-delay_high);
       pwmBranch=pwmBranch+1;
           
     

}

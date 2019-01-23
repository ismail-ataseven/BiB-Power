
#define enA 9
int a = 100;
int b = 100;
int finalvalue = 230;
int actualpwm = 0;

void setup() {
  pinMode(enA, OUTPUT);
  Serial.begin(9600);
 // TCCR1B = TCCR1B & B11111000 | B00000010; // for PWM frequency of 3921.16 Hz
//   TCCR2B = TCCR2B & B11111000 | B00000011; // for PWM frequency of 980.39 Hz
  TCCR1B = TCCR1B & B11111000 | B00000011; // for PWM frequency of 490.20 Hz (The DEFAULT)
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255

if (pwmOutput>finalvalue){
    pwmOutput=finalvalue;

     if (1 <= (pwmOutput-actualpwm) ){
     actualpwm = actualpwm + 1;
     analogWrite(enA, actualpwm);
     delay(a);
      }

      else if (-1 >= (pwmOutput-actualpwm)){
      actualpwm = actualpwm - 1;
      analogWrite(enA, actualpwm);
      delay(b);
      }
}

else if (pwmOutput<finalvalue){
  
      if (1 <= (pwmOutput-actualpwm) ){
      actualpwm = actualpwm + 1;
      analogWrite(enA, actualpwm);
      delay(a);
      }

      else if(-1 >= (pwmOutput-actualpwm)){


           if (15 >actualpwm) {
           actualpwm = 0;
          analogWrite(enA, actualpwm);
          delay(a);
          }

          else if (-1 >= (pwmOutput-actualpwm)){
          actualpwm = actualpwm - 1;
          analogWrite(enA, actualpwm);
          delay(b);
          }
  
      }
}

else if (-1 < (pwmOutput-actualpwm) <1){
 analogWrite(enA, actualpwm);
 delay(100);
}

delay(100);
}

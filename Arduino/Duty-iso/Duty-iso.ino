
#define enA 9

  int finalvalue = 190;
  int actualpwm = 0;
void setup() {
  pinMode(enA, OUTPUT);
    Serial.begin(9600);
TCCR1B = TCCR1B & B11111000 | B00000010; // for PWM frequency of 3921.16 Hz

}
void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255


if (pwmOutput>finalvalue){
  pwmOutput=finalvalue;

   if (1 <= (pwmOutput-actualpwm) ){
  actualpwm = actualpwm + 1;
    analogWrite(enA, actualpwm);
  delay(100);
}

else if (-1 >= (pwmOutput-actualpwm)){
  actualpwm = actualpwm - 1;
    analogWrite(enA, actualpwm);
  delay(100);
}
}
if (pwmOutput<finalvalue){
  if (1 <= (pwmOutput-actualpwm) ){
  actualpwm = actualpwm + 1;
    analogWrite(enA, actualpwm);
  delay(100);
}

else if(-1 >= (pwmOutput-actualpwm)){
  actualpwm = actualpwm - 1;
    analogWrite(enA, actualpwm);
  delay(100);
  
}
}
if (-1 < (pwmOutput-actualpwm) <1){
    analogWrite(enA, actualpwm);
  delay(100);
}


  delay(100);

}

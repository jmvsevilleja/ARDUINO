int red = 11;
int button = 8;
unsigned long tepTimer ;

void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(button, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(button);
  
  int sensorValue = analogRead(A0);  
  int val=analogRead(1);        //Connect LM35 to analog pin and read  
  double temp = (double) val * (5/10.24);

  float percent = sensorValue;
  int dim = (percent/1023) * 255;
  //Serial.println(sensorValue);
  Serial.println(temp);

  if(state == LOW || temp>25){
     // digitalWrite(red, LOW);
      digitalWrite(red, LOW);
      //Serial.println(state);
      
  }else{
    //digitalWrite(red, HIGH);
     analogWrite(red, dim);
    delay(5);
   //Serial.println(state);
  
  }

  
 delay(100);
  
}

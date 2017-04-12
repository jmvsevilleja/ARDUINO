int red = 11;
int button = 8;

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
  // print out the value you read:
  //Serial.println(sensorValue);

  float percent = sensorValue;
  int dim = (percent/1023) * 255;
  //Serial.println(sensorValue);
    Serial.println(dim);
  if(state == LOW){
     // digitalWrite(red, LOW);
      digitalWrite(red, LOW);
      //Serial.println(state);
      
  }else{
    //digitalWrite(red, HIGH);
     analogWrite(red, dim);
   //Serial.println(state);
  
  }

  
 delay(100);
  
}

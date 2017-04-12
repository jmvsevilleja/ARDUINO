int red = 11;
int button = 8;
int buzzer = 7;

int toneVal;


void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(button, INPUT);
pinMode(buzzer, OUTPUT); 
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
  //Serial.println(dim);
       
       //generate sound of different frequencies by sinusoidal value            
       toneVal = 2000+((percent/1023)*1000);
  Serial.println(toneVal);
             
       //Set a frequency for Pin-out 8            
      
  if(state == LOW){
     // digitalWrite(red, LOW);
      digitalWrite(red, LOW);
      //Serial.println(state);
      
  }else{
    //digitalWrite(red, HIGH);
     analogWrite(red, dim);
    // tone(buzzer, toneVal);
    delay(5);
   //Serial.println(state);
  
  }

  
 delay(100);
  
}

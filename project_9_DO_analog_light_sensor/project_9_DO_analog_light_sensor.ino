/*
  Ambient Light controlled LED 
*/
int LED = 10;                     //Led pin
int sensor = 9;

void setup(){
     pinMode(LED,OUTPUT);
     pinMode(sensor, INPUT);     
     Serial.begin(9600);        
}

void loop(){
     //val = analogRead(0);         // read voltage value
     int reading = digitalRead(sensor);

     Serial.println(reading);        
     
     if(reading){                // if the value is less than 1000，LED turns off
          digitalWrite(LED,LOW);
     }else{                        // if the value is more than 1000，LED turns on
          digitalWrite(LED,HIGH);
     }
     delay(50);                   
}


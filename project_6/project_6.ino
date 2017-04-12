/*
   Alarm
*/
float sinVal;
int toneVal;
int red = 11;
int buzzer = 6;
int dim;

void setup(){
     pinMode(buzzer, OUTPUT);
     pinMode(red, OUTPUT);
     Serial.begin(9600);
}

void loop(){
     for(int x=0; x<180; x++){
            // convert degrees to radians then obtain value
            sinVal = (sin(x*(3.1412/180)));
            // generate a frequency from the sin value
            dim = int(sinVal * 255);              
            toneVal = 2000+(int(sinVal*1000));
          // tone(buzzer, toneVal);
           analogWrite(red, dim);
           Serial.println(sinVal);
           delay(50); 
     }   
}

int red = 11;
int button = 8;
//unsigned long tepTimer ;
int tiltInput = 3;     
unsigned char tiltTimer = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(button, INPUT);
pinMode(tiltInput, INPUT);   //configure tilt sensor as input mode 
Serial.begin(9600);
attachInterrupt(1, blink, HIGH);   
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(button);
  
  //int sensorValue = analogRead(A0);  
  //int tempValue = analogRead(A5);        //Connect LM35 to analog pin and read  
  //double tempState = (double) tempValue * (5/10.24);

  float percent = 1023;
  int dim = (percent/1023) * 255;
  //Serial.println(sensorValue);
  //Serial.println(temp);

  if(buttonState == LOW || tiltTimer!=0){
     // digitalWrite(red, LOW);
      tiltTimer = 0;
      digitalWrite(red, LOW);
      //Serial.println(state);
       delay(500); 
  }else{
    //digitalWrite(red, HIGH);
    analogWrite(red, dim);
    delay(5);
   //Serial.println(state);
  }
}

  

void blink(){                                    
  // interrupt function blink() 
  tiltTimer++;                                        
  //once trigger the interrupt, the state keeps increment 
  }

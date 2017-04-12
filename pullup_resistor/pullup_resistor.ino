int red = 12;
int button = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(button, INPUT); 
digitalWrite(red, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
int state = digitalRead(button);
  if(state == LOW){
      digitalWrite(red, LOW);
  }else{
    digitalWrite(red, HIGH);
  }
}

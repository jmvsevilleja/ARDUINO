// DHT code from:
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 6     // what pin we're connected to
int LED = 13;                     //Led pin
int lightSensor = 0;
int uvSensor = 3;
int soilSensor = 1;

// Uncomment whatever type you're using!
// #define DHTTYPE DHT11   // DHT 11 
 #define DHTTYPE DHT22   // DHT 22  (AM2302)
// #define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

// LCD RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
  Serial.begin(9600);
  
  pinMode(LED,OUTPUT);
  pinMode(lightSensor, INPUT);
  pinMode(soilSensor, INPUT);
       
  // set up the LCD's number of columns and rows:  
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  
  int lightReading = analogRead(lightSensor);
  int soilReading = analogRead(soilSensor);
  int uvReading = analogRead(uvSensor);//connect UV sensors to Analog 3 
  int soilPercentage = map(soilReading, 270, 550, 100, 0);
  
  int lightPercentage = map(lightReading, 0, 1023, 100, 0);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int humidReading = dht.readHumidity();
  int tempReading = dht.readTemperature();
  
  /*if(LightReading < 800){                 // If lower than 1000, turn off LED          
    digitalWrite(LED,HIGH);     
  }else{                                  // Otherwise turn on LED           
    digitalWrite(LED,LOW);   
  }*/
 


  if (isnan(tempReading) || isnan(humidReading)) {
    Serial.println("Failed to read from DHT");
  } else {
    
    // set the cursor to (0,0):
    lcd.setCursor(0, 0);

    lcd.print("T");
    lcd.print(tempReading);
    lcd.print("C");

    lcd.print(" H");
    lcd.print(humidReading);
    lcd.print("%");    
   
    lcd.print(" S");
    if(soilPercentage < 10)  lcd.print('0');
    lcd.print(soilPercentage);
    lcd.print("%");

    if(soilReading > 430){
      lcd.print(" D");
    }else{
      lcd.print(" W");
    }
    
    // set the cursor to (16,1):
    lcd.setCursor(0,1);

    lcd.print("L");
    if(lightPercentage < 10)  lcd.print('0');
    lcd.print(lightPercentage);
    lcd.print("%");
    
    lcd.print(" U");
    lcd.print(uvReading);  
    

  }
  
  
    delay(1000);
}


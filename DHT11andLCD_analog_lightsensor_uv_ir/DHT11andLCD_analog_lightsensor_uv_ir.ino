// DHT code from:
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain




// LCD RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
#include <SFE_TSL2561.h>
#include <Wire.h>
#include "DHT.h"



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SFE_TSL2561 light;

unsigned int delayTime;
int uvSensor = 1; //ANALOG
int soilSensor = 3; //ANALOG
int tempSensor = 6; //DIGITAL

// If gain = false (0), device is set to low gain (1X)
// If gain = high (1), device is set to high gain (16X)
boolean luxGain = 0;

DHT dht(tempSensor, DHT22);
  
void setup() {
  Serial.begin(9600);
  
  // set up the Soil sensor:  
  pinMode(soilSensor, INPUT);

         
  // set up the LCD's number of columns and rows:  
  lcd.begin(16,2);
  dht.begin();
  
  // set up the Luminosity IR sensor:  
  light.begin();

  unsigned char luxTime = 3;
  // If time = 3, use manual start / stop to perform your own integration
  light.setTiming(luxGain, luxTime, delayTime);
  light.setPowerUp();
}

void loop() {

  delayTime = 1000;
  light.manualStart();
  delay(delayTime);
  light.manualStop();  
  
  int soilReading = analogRead(soilSensor);
  int uvReading = analogRead(uvSensor);//connect UV sensors
  int soilPercentage = map(soilReading, 270, 550, 100, 0);
   
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int humidReading = dht.readHumidity();
  int tempReading = dht.readTemperature();
  
  double luxReading;    // Resulting lux value
  boolean luxGood;  // True if neither sensor is saturated
  
  unsigned int vlReading, irReading;

  //-----------------------------------

    // set the cursor to (0,0):
    lcd.setCursor(0, 0);
    
    //TEMPERATURE
    lcd.print("T");
    lcd.print(tempReading);
    lcd.print("C");
    
    //HUMIDITY
    lcd.print(" H");    
    lcd.print(humidReading);
    lcd.print("%");
    
    //SOIL
    if(soilReading > 270) {
        lcd.print(" S");
        if(soilPercentage < 10)  lcd.print('0');
        lcd.print(soilPercentage);
        lcd.print("%");
    
        if(soilReading > 430){
          lcd.print(" D");
        }else{
          lcd.print(" W");
        }
    }

    lcd.print("        ");    
    // set the cursor to (16,1):
    lcd.setCursor(0,1);
    //ULTRA VIOLET
    lcd.print("U");
    lcd.print(uvReading);  
    

    
   
    if (light.getData(vlReading,irReading)){

 
      int vlPercentage = map(vlReading, 0, 65535, 0, 99);
      int irPercentage = map(irReading, 0, 65535, 0, 99);
            
      //VISIBLE LIGHT
      lcd.print(" V");
      lcd.print(vlPercentage);
      //INFRAFRED
      lcd.print(" I");
      lcd.print(irPercentage);
          
      luxGood = light.getLux(luxGain, delayTime, vlReading, irReading, luxReading);

      
      //LUX
      if (luxGood){
        lcd.print(" L");
        lcd.print((int)luxReading);        
      }
     
      
    }

    lcd.print("        ");
}


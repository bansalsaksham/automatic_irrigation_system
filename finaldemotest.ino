
          //LIABRARIES
#include <dht.h>
#include <LiquidCrystal.h>
//#include <SoftwareSerial.h>


          //INITIALIZATION
//SoftwareSerial mySerial(8,13);
#define WATERPIN 9
#define READSOILPIN A0
#define MAXDRYNESS 600
#define DHT11_PIN 7
String str="";

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;


int flag=0;

void setup()
{ 
  //mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  pinMode(READSOILPIN, INPUT);
  pinMode(WATERPIN, OUTPUT);
    lcd.setCursor(6, 0);
  
    lcd.print("GEMS");
    Serial.println("GEMS MODERN ACADERMY GURGAON");     
  lcd.setCursor(4,1);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("WELCOMES YOU");
  Serial.println("WELCOME YOU");
  Serial.println("STRESS FREE FARMING");
  delay(2000);
 //gsmInit();
  lcd.clear();
  lcd.print("System Ready");
         

}

void loop()
{  
  lcd.begin(16, 2);

  int chk = DHT.read11(DHT11_PIN);
  int SensorValue = analogRead(READSOILPIN); //take a sample
     Serial.print(SensorValue); Serial.print(" - ");
    
      delay(1000);
   if(SensorValue >= MAXDRYNESS && flag ==0 ) 
     { 
         lcd.clear();
         Serial.println("DRY");
         lcd.setCursor(0, 0);
         lcd.print("DRY");
         delay(2000); 
         sendSMS("GEMS STRESS FREE FARMING       Motor Start");
         Serial.println("Soil dry start watering");
         delay(2000);
        lcd.clear();
        lcd.println("Start watering"); 
         digitalWrite(WATERPIN, HIGH);
         delay(2000);
     
         flag=1;

      }
  if(SensorValue < MAXDRYNESS && flag==1  )
    {  
         lcd.clear();
         Serial.println("SOIL MOIST");
         lcd.setCursor(0, 0);
         lcd.print("SOIL MOIST");    
          delay(2000);
       sendSMS("GEMS STRESS FREE FARMING      Motor Off");
          lcd.clear();
          delay(2000);
         Serial.println("Soil Moist stop watering");
         lcd.println("Stop watering"); 
         delay(2000);
         digitalWrite(WATERPIN, LOW);
         flag=0;
    
   } 
   
    
    lcd.clear();
    lcd.setCursor(0, 1);
    delay(2000);
    lcd.setCursor(0, 1);
   lcd.setCursor(0, 0);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0, 1);  
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
   delay(2000);

  

}

 void sendSMS(String msg)
{   lcd.clear();
  lcd.print("Sending SMS");
  //mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    //delay(1000);  // Delay of 1000 milli seconds or 1 second
  //mySerial.println("AT+CMGS=\"+919717312780\"\r"); 
  //delay(1000);
  //mySerial.println(msg);// The SMS text you want to send
   Serial.println("msg send");
  //delay(100);
  // mySerial.println((char)26);// ASCII code of CTRL+Z
 // delay(1000);
   lcd.clear();
   //mySerial.flush();

}  
void gsmInit()
{
  lcd.clear();
  lcd.print("Finding Module..");
  boolean at_flag=1;
  while(at_flag)
  {
    //mySerial.println("AT");
    //while(mySerial.available()>0)
    {
   //if(mySerial.find("OK"))
      at_flag=0;
    }
    delay(1000);
  }
  //mySerial.println("ATE0");
  lcd.clear();
  lcd.print("Finding Network..");
  boolean net_flag=1;
  while(net_flag)
  {
    //mySerial.println("AT+CPIN?");
    //while(mySerial.available()>0)
    {
      //if(mySerial.find("READY"))
      net_flag=0;
      break;
    }
    delay(1000);
  }
   //mySerial.println("AT+CNMI=2,2,0,0,0");
   delay(1000);
   //mySerial.println("AT+CMGF=1");
   delay(1000);
   //mySerial.println("AT+CSMP=17,167,0,0");
   lcd.clear();
   //mySerial.flush();
}

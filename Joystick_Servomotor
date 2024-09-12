// 조이스틱 모듈 + 서브모터
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER_PIN 8
#define SW_PIN 12
int echo =6;
int trig=7;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
 Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo,INPUT);
 pinMode(BUZZER_PIN,OUTPUT);
 pinMode(SW_PIN,INPUT_PULLUP);
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(5,0);
 lcd.print("Height");
}

void loop() {
  if(digitalRead(SW_PIN)==0)
  {
    float distance=0;
    for(int i=0; i<5; i++)
    {
      distance += ultraSonic();
      delay(100);
    }
    distance=distance/5.0;

    lcd.setCursor(5,1);
    lcd.print("   ");
    lcd.setCursor(5,1);
    lcd.print(distance);
    lcd.print("cm");
    digitalWrite(BUZZER_PIN,HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN,LOW);
    delay(100);
  }
}
float ultraSonic()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  unsigned long duration=pulseIn(echo,HIGH);

  float distanceCM=((34000*duration)/1000000)/2;

  return distanceCM;
}  

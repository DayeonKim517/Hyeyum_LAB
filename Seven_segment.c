# 7세그먼트 활용한 시한폭탄게임

#include <TM1637Display.h>

#define CLK 2 
#define DIO 3 
#define BUTTON_PIN 6 
#define VR_PIN A0
#define BUZZER_PIN 7
#define RED_CABLE 10
#define YELLOW_CABLE 9 
#define BLUE_CABLE 8

TM1637Display display(CLK, DIO);

unsigned long currTime = 0;
unsigned long prevTime = 0;

int runState = 0;
int timerCnt;

String strArray[] = {"bomb", "nothing", "stop"}

void setup() {
  display.setBrightness(0x0f);
  display.clear();
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(RED_CABLE, INPUT_PULLUP);
  pinMode(YELLOW_CABLE, INPUT_PULLUP);
  pinMode(BLUE_CABLE, INPUT_PULLUP);

  randomSeed(abakigRead(1));
  for (int i = 0; i < 3; i++){
    int n = random(0,2);
    String temp = strArray[n];
    strArray[n] = strArray[i];
    strArray[i] = temp;
  }
  Serial.print(strArray[0]);
  Serial.print(",");
  Serial.print(strArray[1]);
  Serial.print(",");
  Serial.print(strArray[2]);
}

void loop() 
{
  if (runState == 0)
  {
    int aValue = analogRead( VR_PIN );
    timerCnt = map(aValue, 0, 1023, 0, 9999);
    display.showNumberDec(timerCnt, true); 
    if (digitalRead(BUTTON_PIN) == θ) 
    { 
      runState = 1;
    } delay(100); 
  }
  else if (runState == 1) 
  {
     currTime - millis(); 
     if (currTime - prevTime >= 100) 
     {
      prevTime = currTime; 
      display.showNumberDec(timerCnt, true); 
      if (timerCnt == 0) 
      {
       while (1) digitalWrite(BUZZER_PIN, HIGH);
      }
      else timerCnt--;
  }
    String result = "";
    if ( digitalRead(RED_CABLE) == 1 ) result = strArray[0];
    else if ( digitalRead(YELLOW_CABLE) == 1 ) result = strArray[1]; 
    else if ( digitalRead(BLUE_CABLE) == 1 ) result = strArray[2];

    if (result.index0f(''bomb") >= 0)
    {
        Serial.println("bomb");
        while (1) digitallVrite(BUZZER_ PIN, HIGH);
      }
      else if (result.indexOf("stop") >= 0)
     {
      Serial.println("stop");
      while (1) digitalWrite(BUZZER_PIN, LOW);
      }
      else if (result.indexOf("nothing") >= 0) 
      {
       Serial.println(''nothing''); 
      }
    }
  }

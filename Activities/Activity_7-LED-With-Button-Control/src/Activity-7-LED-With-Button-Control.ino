
const int pinLED = 3;


const int resetButton = A0;
const int firstLvlButton = A1;
const int secondLvlButton = A2;
const int thirdLvlButton = A3;


bool prevState = false;


const unsigned long timeInterval = 200;
unsigned long prevTime = 0;



void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(115200);

}


void loop() {

  unsigned long currTime = millis();
 

  bool resetState = digitalRead(resetButton) > 1000 ;
  bool firstState = digitalRead(firstLvlButton) > 1000;
  bool secondState = digitalRead(secondLvlButton) > 1000;
  bool thirdState = digitalRead(thirdLvlButton) > 1000;


  bool currState = resetState || firstState || secondState || thirdState;


  bool turnOnState = firstState || secondState || thirdState;

  if (currState == true && prevState == false)
  {


    if (currTime - prevTime >= timeInterval)
    {

      Serial.print("The value of OUTPUT to the LED is: ");

    
      prevTime = currTime;


      if (turnOnState)
      {

        if (firstState)
        {
          analogWrite(pinLED, 85);
          Serial.println("85");
        }

        else if (secondState)
        {
          analogWrite(pinLED, 170);
          Serial.println("170");
        }


        else if (thirdState)
        {
          analogWrite(pinLED, 255);
          Serial.println("255");
        }
      }

      else if (resetState == true)
      {
        analogWrite(pinLED, 0);
        Serial.println("0");
      }
    }
 
  }

  prevState = currState;


}

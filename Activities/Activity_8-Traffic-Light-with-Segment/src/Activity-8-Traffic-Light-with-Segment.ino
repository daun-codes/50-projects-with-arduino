
/* ------------------------------------
  ACTIVITY 8 - TRAFFIC LIGHT WITH 7 SEGMENT
--------------------------------------*/


// Traffic Light Led
#define greenLed 2
#define orangeLed 3
#define redLed 4


const int segPins[7] = {5, 6, 7, 8, 9, 10, 11};


// Traffic Light Segment

const byte digits[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};


unsigned long prevTime = 0;
unsigned long prevSegmentTime = 0;


// For LEDs

int counter = 0;
int greenTime = 6000;
int redTime = 9000;
int orangeTime = 3000;


// For Segments

int gTime = 6;
int rTime = 9;
int oTime = 3;
int countdown = 1000;

bool GreenShown = false;




void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);

  for (int i = 0; i < 7; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }


  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(orangeLed, LOW);

}

void updateTrafficLight(unsigned long currSegmentTime);
void showDigit(int value);



void loop() {
  unsigned long currTime = millis();
  unsigned long currSegmentTime = millis();


  if (counter == 0 && currTime - prevTime >= 1000)
  {
    showDigit(0);

    if (currTime - prevTime >= countdown)
    {
      counter = 1;
      GreenShown = !GreenShown;
      prevTime = currTime;
    }
    
    
    
  }

  else if (counter == 1 && currTime - prevTime >= redTime)
  {
    showDigit(0);

    if (currTime - prevTime >= countdown + redTime)
    {
      counter = 2;
      GreenShown = !GreenShown;
      prevTime = currTime;
      rTime = 9;
    }
    

  }


  else if (counter == 2 && currTime - prevTime >= orangeTime)
  {

    if (GreenShown)
    {

      showDigit(0);

      if (currTime - prevTime >= countdown + orangeTime)
      {
        counter = 1;
        GreenShown = !GreenShown;
        prevTime = currTime;
        oTime = 3;
      }
      
    }

    else {

      showDigit(0);

      if (currTime - prevTime >= countdown + orangeTime)
      {
        counter = 3;
        GreenShown = !GreenShown;
        prevTime = currTime;
        oTime = 3;
      }

    }

  
  }

  else if (counter == 3 && currTime - prevTime >= greenTime )
  {

    showDigit(0);
    if (currTime - prevTime >= countdown + greenTime)
    { 
      counter = 2;
      prevTime = currTime;
      gTime = 6;
    }
  }


  updateTrafficLight(currSegmentTime);
}



void updateTrafficLight(unsigned long currSegmentTime)
{ 

  if (counter == 0)
  {
    
    showDigit(0);

  }

  else if (counter == 1)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(orangeLed, LOW);
  

    if (currSegmentTime - prevSegmentTime >= countdown)
    { 
      if (rTime >= 0)
      {
        showDigit(rTime);
        rTime--;
        prevSegmentTime = currSegmentTime;
      }

    
    }

  }

  else if (counter == 2) 
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(orangeLed, HIGH);

    if (currSegmentTime - prevSegmentTime >= countdown)
    { 
      if (oTime >= 0)
      {
        showDigit(oTime);
        oTime--;
        prevSegmentTime = currSegmentTime;
      }

      
    }

  }

  else if (counter == 3)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(orangeLed, LOW);

    if (currSegmentTime - prevSegmentTime >= countdown)
    { 
      if (gTime >= 0)
      {
        showDigit(gTime);
        gTime--;
        prevSegmentTime = currSegmentTime;
      }
      
    }

  }

}

void showDigit(int value)
{
  
  for (int i = 0; i < 7; i++) 
  {
    digitalWrite(segPins[i], digits[value][i]);
  }


}

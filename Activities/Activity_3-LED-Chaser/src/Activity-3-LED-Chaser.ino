/* -------------------------------------------------------------
  ACTIVITY 3 - NEW LED CHASER WITH POWER OFF LAST STATE FEATURE
----------------------------------------------------------------*/


/* ========================================


Old Features
-- The 5 Leds are running back and forth but when powered off the LED will always starts to the right 
-- There is no power off last state


New Features
-- Power off last state is implemented to make the 5 LEDS stop and start from the last state
-- The 5 Leds are running back and forth with the power off last state


============================================ */


// Set the pin number to actual led color

const int buttonPin = A0;
const int redLed =    2;   
const int yellowLed = 4;
const int blueLed =   7;
const int vioLed =    8;
const int greenLed = 12;

// This is for us to track the time and manipulate our blinking led

unsigned long prevTime = 0;



// This is used to track the state of the button
int buttonState = 0;
int lastButtonState = 0;
bool ledState = false;


// Define the time interval
const unsigned int timeInterval = 100;



// Set the pattern to default state
int patternIndex = 255;
bool patternRunning;




// Define the pattern using a 2D array
const int pattern[8][5] =
{
  {1, 0, 0, 0, 0},    // 0
  {0, 1, 0, 0, 0},    // 1
  {0, 0, 1, 0, 0},    // 2
  {0, 0, 0, 1, 0},    // 3
  {0, 0, 0, 0, 1},    // 4
  {0, 0, 0, 1, 0},    // 5
  {0, 0, 1, 0, 0},    // 6
  {0, 1, 0, 0, 0},    // 7

};


int lastStep = 255;     // This is used to track the last step of the pattern


void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(vioLed, OUTPUT);
  pinMode(greenLed, OUTPUT);



  // Setting the initial state of the LED to OFF
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(vioLed, LOW);
  digitalWrite(greenLed, LOW);


}

void loop() {

    // Read the state of the button from the analog pin
    buttonState = analogRead(buttonPin);


    if (buttonState >= 1023 && lastButtonState == 0)
    {
      ledState = !ledState;
      delay(200); // Delay to prevent multiple presses



      // If the ledState is true, start the pattern

      if (ledState)
      {
        if (lastStep != 255) {
          patternIndex = lastStep;
          patternRunning = true;
          setPattern(patternIndex);
          prevTime = millis();
        }

        else {
          patternIndex = 0;
          patternRunning = true;
          setPattern(patternIndex);
          prevTime = millis();
        }

      }


      // If the ledState is false, stop the pattern
      else 
      {
        patternRunning = false;
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, LOW);
        digitalWrite(blueLed, LOW);
        digitalWrite(vioLed, LOW);
        digitalWrite(greenLed, LOW);
      }

    }


  // If the pattern is running

  if (patternRunning)
  {
    
    unsigned long currTime = millis();



    // If the current time is greater than the previous time plus the time interval then change the pattern back to the default = 0

    if (currTime - prevTime >= timeInterval)
    {
      prevTime = currTime;

      patternIndex++;

      if (patternIndex >= 8)
      {
        patternIndex = 0;
      }


      setPattern(patternIndex);
    }
  }


  // Update the last button state

  lastButtonState = buttonState;

}



// Function to set the pattern
void setPattern(int step)
{
  digitalWrite(redLed, pattern[step][0]);
  digitalWrite(yellowLed, pattern[step][1]);
  digitalWrite(blueLed, pattern[step][2]);
  digitalWrite(vioLed, pattern[step][3]);
  digitalWrite(greenLed, pattern[step][4]);

  lastStep = step;
  
}
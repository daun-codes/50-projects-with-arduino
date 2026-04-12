/* ------------------------------------
  ACTIVITY 3 - LED CHASER / KNIGHT RIDER
--------------------------------------*/



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
int patternIndex = 0;
bool patternRunning;




// Define the pattern using a 2D array
const int pattern[11][5] =
{
  {1, 0, 0, 0, 0},    // 0
  {1, 1, 0, 0, 0},    // 1
  {0, 1, 1, 0, 0},    // 2
  {0, 0, 1, 1, 0},    // 3
  {0, 0, 0, 1, 1},    // 4
  {0, 0, 0, 0, 1},    // 5
  {0, 0, 0, 1, 1},    // 6
  {0, 0, 1, 1, 0},    // 7
  {0, 1, 1, 0, 0},    // 8
  {1, 1, 0, 0, 0},    // 9
  {0, 0, 0, 0, 0},    // 10
};


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
        patternIndex = 0;
        patternRunning = true;
        setPattern(patternIndex);
        prevTime = millis();

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

      if (patternIndex >= 11)
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
}

























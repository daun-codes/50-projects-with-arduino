const int pinLED = 2; 

unsigned long prevTime = 0;

// Declaring the time for each pattern
const int shortBlinkTime = 300;
const int longBlinkTime = 900;

// Declaring the frequency of each pattern
const int shortBlinkTick = 3;
const int longBlinkTick = 3;


int resetTicker = 0;
const int resetTimer = 2000; // for reset timer


bool highState = false;       // To be used as a toggle when conditions are met
bool prevHighState = false;   // To detect if there was a transition 

int counter = 0; // To swicth to a different state 

void setup() {
  pinMode(pinLED, OUTPUT);

  Serial.begin(9600);


  Serial.println("SOS Morse Code Blinker");
}

void loop() {
  unsigned long currTime = millis(); // We still used millis() function to ensure the system is still running.

  if (counter == 0 && (currTime - prevTime) >= shortBlinkTime)  // The first counter condition will require the system to loop for 300 ms first before it will pass
  {

    highState = !highState;     // toggle the highState variable everytime the system loop for about 300 ms
    prevTime = currTime;        // assign the value of the current time to the previous time to be used for another iteration.
  }
  else if (counter == 1 && (currTime - prevTime) >= longBlinkTime)  // The second counter condition will require the system to loop for 900 ms first before it can go through
  {
    highState = !highState;   // toggle it and assign, the same as before
    prevTime = currTime;
  }



  else if (counter == 2 && (currTime - prevTime) >= shortBlinkTime) // same as the first counter condition
  {
    highState = !highState;
    prevTime = currTime;
  }

  else if (counter == 3 && (currTime - prevTime) >= resetTimer)     // This is when the system completed all of the pattern and will take a reset before running the pattern again
  {

    highState = !highState;
    prevTime = currTime;
    counter = 0;          // Make the counter defaulted to its original value

  
  }


  // At the end of the loop, updateMorseBlinker will be called to check if the conditions were met
  updateMorseBlinker();

  prevHighState = highState;  // save the current state to the previous state that will be used to detect if there was a transition


}

void updateMorseBlinker() {
  
  //  Mag-trigger ISANG BESES lang — kapag nag-transition sa HIGH
  bool risingEdge = (highState == true && prevHighState == false);
  


  // If the conditions were true, the LED will be turn ON and the printed character on the monitor will show.
  if (risingEdge && highState == true)
  { 

    // First condition 
    if (counter == 0) {

      if (resetTicker >=  shortBlinkTick) 
      {
        counter++;
        resetTicker = 0;
      }

      else
      {
        digitalWrite(pinLED, HIGH);
        Serial.print(".");
        resetTicker++;
      }

    }

    // Second Condition
    else if (counter == 1) 
    {
      

      if (resetTicker >= longBlinkTick) 
      {
        counter++;
        resetTicker = 0;
      }
      else 
      {
        digitalWrite(pinLED, HIGH);
        Serial.print("-");
        resetTicker++;
      }
    }


    // Third Condition

    else if (counter == 2) {

      // This first if statement will be asked first to check if the resetTicker already bypass the number of shortBlinkTick and will exit from this loop
      if (resetTicker >= shortBlinkTick) 
      {
        
        Serial.println("\n");
        Serial.println("______________________");
        Serial.println("Morse Pattern Restart");
        Serial.println("______________________");
        counter++;
        resetTicker = 0;
        
        
      
      }
      else
      {
        digitalWrite(pinLED, HIGH);
        Serial.print(".");
        resetTicker++;
      }
      
      
    }

  }
  
  else if (highState == false)
  {
    digitalWrite(pinLED, LOW);
  }

}
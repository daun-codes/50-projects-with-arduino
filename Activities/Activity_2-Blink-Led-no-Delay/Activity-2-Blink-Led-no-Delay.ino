/*------------------------------------- 
  Activity 2 - Blink LED no Display
---------------------------------------*/
// We are going to use millis() function to get the time and manipulate  our blinking led
// Using millis will give us the output of every 1000 ms or 1 second 


int counter = 0;  // Using counter to track the state of the LED
unsigned long prevTime = 0; // Using prevTime to track the time


const unsigned long greenTime = 1000; // Setting the time for the green LED
const unsigned long redTime = 1000; // Setting the time for the red LED

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  
  

  // Setting the initial state of the LED to OFF
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  
}



void loop()
{
  unsigned long currTime = millis();
  
  // 
  if (counter == 0 && (currTime - prevTime) >= greenTime)
  {
    digitalWrite(2, HIGH);
    digitalWrite(7, LOW);
    counter = 1; // set the counter to 1 to indicate that the first LED is ON
  
    
    prevTime = currTime;
    

   	 
  }
  
  else if (counter == 1 && (currTime - prevTime) >= redTime)
    
  {
   	digitalWrite(7, HIGH);
    digitalWrite(2, LOW);
    counter = 0; // set the counter to 0 to go back to the initial state
    

    
    prevTime = currTime;
    
    

  }
  
}

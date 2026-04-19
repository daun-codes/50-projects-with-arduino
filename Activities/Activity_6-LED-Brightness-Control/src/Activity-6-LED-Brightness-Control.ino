/* ------------------------------------
  ACTIVITY 6 - LED BRIGHTNESS CONTROL
--------------------------------------*/


// Setting the pin for the LED
const int pinLED = 9;


unsigned long prevTime = 0; // Using prevTime to track the time

int counter = 0; // Using counter to track the state of the LED

const int timeInterval = 100; // Setting the time interval

const int pauseInterval = 2000; // Setting the pause interval

int iterator = 0; // Using iterator to track the brightness



void setup() {

  pinMode(pinLED, OUTPUT);

  analogWrite(pinLED, 0);
  Serial.begin(115200);     // Setting the baud rate for the serial monitor

}

void loop() {
  


  unsigned long currTime = millis();

  // The first counter condition will require the system to loop for 100 ms first before it will pass
  
  if (counter == 0 && (currTime - prevTime) >= timeInterval)
  {
   
    if (iterator < 256)
    {

      if ((currTime - prevTime) >= timeInterval)
      {
        analogWrite(pinLED, iterator);

        
        
        prevTime = currTime;

      }

      Serial.print("The value of [i] is: ");
      Serial.println(iterator);


      iterator++;
      
    }

    else if (iterator > 255)
    {
      Serial.println("\nTurning ON LED ends here...");
      Serial.println("___________________________\n");

      counter = 1;
    }
  }

  else if (counter == 1 && (currTime - prevTime) >= timeInterval)
  {
  
    if (iterator > 0)
    {
      if ((currTime - prevTime) >= timeInterval)
      {
        analogWrite(pinLED, iterator);

        


        prevTime = currTime;

      }

      Serial.print("The value of [i] is: ");
      Serial.println(iterator);


      iterator--;
      
    }

    else if (iterator == 0)
    {
      Serial.println("\nTurning OFF LED ends here...");
      Serial.println("___________________________\n");
      analogWrite(pinLED, iterator);

      counter++;  
      iterator++;
    }
  }

  else if (counter == 2 && (currTime - prevTime) >= pauseInterval)
  {

    prevTime = currTime;
    counter = 0;

  }
}

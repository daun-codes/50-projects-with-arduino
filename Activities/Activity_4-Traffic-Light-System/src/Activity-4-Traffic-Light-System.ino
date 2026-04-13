/* ------------------------------------
  ACTIVITY 4 - TRAFFIC LIGHT SYSTEM
--------------------------------------*/


// Setting the time for each traffic light
const unsigned int greenTime = 10000;
const unsigned int redTime = 1000;
const unsigned int yellowTime = 3000;


// Setting the pins for the digital and analog leds
const int D_firstLEDs[] = {2, 4, 7};
const int D_secondLEDs[] = {8, 12, 13};


const int A_firstLEDs[] = {3, 5, 6};
const int A_secondLEDs[] = {9, 10, 11};


// Setting the counter
int counter = 0;

// Setting the previous time to track the time without using delay
unsigned long prevTime = 0;


void setup() {


  // declare pin modes through the loop
  for (int i = 0; i < 4; i++)
  {

    pinMode(D_firstLEDs[i], OUTPUT);
    pinMode(D_secondLEDs[i], OUTPUT);
    pinMode(A_firstLEDs[i], OUTPUT);
    pinMode(A_secondLEDs[i], OUTPUT);
    
  }



}


// the loop function runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currTime = millis();


  if (counter == 0 && (currTime - prevTime) >= greenTime)
  {
    counter = 1;
    prevTime = currTime;

  }

  else if (counter == 1 && (currTime - prevTime) >= yellowTime)
  {
    counter = 2;
    prevTime = currTime;
  }

  else if  (counter == 2 && (currTime - prevTime) >= redTime)
  {
    counter = 3;
    prevTime = currTime;
  }

  else if (counter == 3 && (currTime - prevTime) >= greenTime)
  {
    counter = 4;
    prevTime = currTime;

  }

  else if (counter == 4 && (currTime - prevTime) >= yellowTime)
  {
    counter = 5;
    prevTime = currTime;

  }

  else if (counter == 5 && (currTime - prevTime) >= redTime )
  {
    counter = 0;
    prevTime = currTime;
  }

  updateTrafficLight();



}

// Function to update the traffic light
void updateTrafficLight()
{ 

  // Resetting the digital and analog leds everytime the function is called to ensure the leds are off before they are turned on

  for (int i = 0; i< 4; i++)
  {
    digitalWrite(D_firstLEDs[i], LOW);
    digitalWrite(D_secondLEDs[i], LOW);
    analogWrite(A_firstLEDs[i], LOW);
    analogWrite(A_secondLEDs[i], LOW);
  }

  if (counter == 0)
  {
    digitalWrite(D_firstLEDs[0], HIGH);
    digitalWrite(D_secondLEDs[0], HIGH);

    digitalWrite(A_firstLEDs[2], HIGH);
    digitalWrite(A_secondLEDs[2], HIGH);
  }


  else if (counter == 1)
  {
    digitalWrite(D_firstLEDs[1], HIGH);
    digitalWrite(D_secondLEDs[1], HIGH);

    digitalWrite(A_firstLEDs[2], HIGH);
    digitalWrite(A_secondLEDs[2], HIGH);
  }

  else if (counter == 2)
  {
    digitalWrite(D_firstLEDs[2], HIGH);
    digitalWrite(D_secondLEDs[2], HIGH);

    digitalWrite(A_firstLEDs[2], HIGH);
    digitalWrite(A_secondLEDs[2], HIGH);
  }



  else if (counter == 3)
  {
    digitalWrite(D_firstLEDs[2], HIGH);
    digitalWrite(D_secondLEDs[2], HIGH);

    digitalWrite(A_firstLEDs[0], HIGH);
    digitalWrite(A_secondLEDs[0], HIGH);
  }

  else if (counter == 4)
  {
    digitalWrite(D_firstLEDs[2], HIGH);
    digitalWrite(D_secondLEDs[2], HIGH);

    digitalWrite(A_firstLEDs[1], HIGH);
    digitalWrite(A_secondLEDs[1], HIGH);
  }

  else if (counter == 5)
  {
    digitalWrite(D_firstLEDs[2], HIGH);
    digitalWrite(D_secondLEDs[2], HIGH);

    digitalWrite(A_firstLEDs[2], HIGH);
    digitalWrite(A_secondLEDs[2], HIGH);
  }

  
  
}














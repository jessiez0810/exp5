#include <AccelStepper.h>
#include <MultiStepper.h>



// Define a stepper and the pins it will use
AccelStepper stepper1(AccelStepper::DRIVER, 9, 8);
AccelStepper stepper2(AccelStepper::DRIVER, 11, 10);

int pos = 1000;
MultiStepper steppers;

int Distance;
int sensorPin=5;
int startposition;
int endposition;

void setup()
{ 
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(1000);
  
    stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(1000);

    steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);


  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {

Distance=pulseIn(sensorPin,HIGH);
    Serial.print("Distance:");
  Serial.println(Distance);

  long positions[2]; // Array of desired stepper positions

  if(Distance<=200){
    startposition= 2000;
    endposition=-2000;
    }
else if(Distance<=700){
    startposition= 500;
    endposition=-500;
  }
    else{
      startposition= 0;
    endposition=0;
      }
 
  positions[0] = startposition;
  positions[1] = startposition;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
 // delay(1000);
  
  // Move to a different coordinate
  positions[0] = endposition;
  positions[1] = endposition;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  //delay(1000);

  
  
}

// Copyright (C) 2016 Julia Kubik <http://juliakubik.com>
#define BREAK_POINT 250
#define TRIGGER_SIZE 3
int sonarPin = 9;
int glassPin = 8;
int numberOfTriggers = TRIGGER_SIZE;
long seenDistances[TRIGGER_SIZE];

void setup() {
  pinMode(sonarPin, INPUT);
  pinMode(glassPin, OUTPUT);
  // set the privacy glass circuit to on therefore transparent
  analogWrite(glassPin, 255);
  for (int i=0; i <= numberOfTriggers; i++) {
    // Fill the distances buffer with elements.
    seenDistances[i] = (pulseIn(sonarPin, HIGH) / 147) * 2.54;
  }
}

bool distancesAre(bool highOrLow) {
  // if highOrLow == true then look for distances greater than BREAK_POINT
  // if highOrLow == false then look for distances less than BREAK_POINT
  int count = 0;
  for (int i=0; i < numberOfTriggers; i++) {
    if ((highOrLow == true) and (seenDistances[i] > BREAK_POINT)) {
      count++;
    }
    if (highOrLow == false and seenDistances[i] <= BREAK_POINT) {
      count++;
    }
  }
  if (count == 3) {
    return true;
  } else {
    return false;
  }
}

void loop() {
  // left shift the buffer and add a new element
  for (int i=0; i < numberOfTriggers; i++) {
    if (i == (numberOfTriggers - 1)) {
      seenDistances[i] = (pulseIn(sonarPin, HIGH) / 147) * 2.54;
    } else {
      seenDistances[i] = seenDistances[i+1];
    }
  }
  if (distancesAre(true)) {
    // e.g. all high then we want to keep the glass transparent
    analogWrite(glassPin, 255);
  } else if (distancesAre(false)) {
    // e.g. all low then we want the glass to be opaque
    analogWrite(glassPin, 0);
  }
}

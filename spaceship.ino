int switchState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  
  randomSeed(analogRead(0));
  
  welcomeBlink();
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } 
  else
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  
  delay(random(50, 500));
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(random(50, 500));
}

void welcomeBlink() {
  int ledNumber = 0;
  for(int i = 0 ; i < 100 ; i++) {
    
    int randNumber = random(2);
    ledNumber = generateLedNumber(ledNumber);
  
    digitalWrite(ledNumber, randNumber);
    delay(50);
  }
}

int generateLedNumber(int previousLedNumber) {
  int nextLedNumber = 0;
  while (previousLedNumber == nextLedNumber) {
    nextLedNumber = random(3, 6);
  }
  return nextLedNumber;
}

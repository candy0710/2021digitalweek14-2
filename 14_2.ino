int sensorValue = 0;
int ledDimming = 0;
int pwmPin = 9;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
  pinMode(pwmPin, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(A0);
  Serial.print("PhotoResistor Read = ");
  Serial.println(sensorValue);
  
  ledDimming = map(sensorValue, 500, 923, 0, 255);
  if(ledDimming <0) ledDimming = 0;

  Serial.print("led Dimming = ");
  Serial.println(ledDimming);
  
  analogWrite(pwmPin, ledDimming);
  delay(100); // Wait for 100 millisecond(s)
}
int sensorPin = A0;
int red = 0;
int green = 0;
int blue = 0;

int led1 = 2;
int led2 = 3;
int led3 = 4;

int led4 = 8;
//The red,green,blue values have to be adjusted due to the fact that the LED's are of different
//  brightness.

int val1 = -12;//Use this to adjust the red value
int val2 = -4;//Use this to adjust the green value
int val3 = -18;//Use this to adjust the blue value

int sensorValue = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT); //Red LED
  pinMode(led2, OUTPUT); //Green LED
  pinMode(led3, OUTPUT); //Blue LED
  pinMode(led4, OUTPUT); //Detection LED
}

void loop() {
  digitalWrite(led1, HIGH);
  sensorValue = analogRead(sensorPin);
  red = (sensorValue / 10) + val1;
  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  sensorValue = analogRead(sensorPin);
  green = (sensorValue / 10) + val2;
  delay(100);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  sensorValue = analogRead(sensorPin);
  blue = (sensorValue / 10) + val3;
  delay(100);
  digitalWrite(led3, LOW);
  Serial.print("Blue: ");
  Serial.println(blue);
  Serial.print("Red: ");
  Serial.println(red);
  Serial.print("Green: ");
  Serial.println(green);
    
//  if (blue > 13 and blue < 17 and green > 13 and green < 17 and red > 13 and red < 17) {
//    digitalWrite(led4, HIGH);
//    delay(1000);
//
//  }
//  else {
//    digitalWrite(led4, LOW);
//  }
}



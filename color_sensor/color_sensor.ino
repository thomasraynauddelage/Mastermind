int sensorPin = A0;
int red = 0;
int green = 0;
int blue = 0;

int led_red = 2;
int led_green = 3;
int led_blue = 4;

//The red,green,blue values have to be adjusted due to the fact that the LED's are of different
//  brightness.

int val1 = -12;//Use this to adjust the red value
int val2 = 50;//Use this to adjust the green value
int val3 = -18;//Use this to adjust the blue value

int sensorValue = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(led_red, OUTPUT); //Red LED
  pinMode(led_green, OUTPUT); //Green LED
  pinMode(led_blue, OUTPUT); //Blue LED
}

void loop() {
  digitalWrite(led_red, HIGH);
  sensorValue = analogRead(sensorPin);
  red = (sensorValue);
  delay(100);
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  sensorValue = analogRead(sensorPin);
  green = (sensorValue);
  delay(100);
  digitalWrite(led_green, LOW);
  digitalWrite(led_blue, HIGH);
  sensorValue = analogRead(sensorPin);
  blue = (sensorValue);
  delay(100);
  digitalWrite(led_blue, LOW);
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



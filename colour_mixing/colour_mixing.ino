int green = 2;
int red = 3;
int blue = 4;


void setup() {
  pinMode(green, OUTPUT); // green
  pinMode(red, OUTPUT); // red
  pinMode(blue, OUTPUT); // blue
  Serial.begin(9600);

}

void loop() {
  //white
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  Serial.println("WHITE");
  delay(4000);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  //purple
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  Serial.println("PURPLE");
  delay(4000);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  //yellow
  digitalWrite(green, HIGH);
  Serial.println("YELLOW");
  delay(4000);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  //green
  digitalWrite(green, HIGH);
  Serial.println("GREEN");
  delay(4000);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  //red
  digitalWrite(red, HIGH);
  Serial.println("RED");
  delay(4000);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);


  //blue
  digitalWrite(blue, HIGH);
  Serial.println("BLUE");
  delay(4000);


}

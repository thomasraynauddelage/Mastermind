int green = 2;
int red = 3; 
int blue = 4;


void setup() {
  pinMode(green,OUTPUT); // green
  pinMode(red,OUTPUT); // red
  pinMode(blue,OUTPUT); // blue
  
}

void loop() {
  //white
  digitalWrite(green,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  
  delay(1000);
  
  //purple
  digitalWrite(green,LOW); 
  //digitalWrite(red,HIGH); red 
  //digitalWrite(blue,HIGH); blue
  delay(1000);

  //yellow
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  delay(1000);

  //light blue
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
  delay(1000);

  //red
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(1000);

  //green
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(1000);

  //blue
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(1000);
  
  

}


const int buttonPin = 15;     // the number of the pushbutton pin
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    Serial.println("1");
    
  } else {
    Serial.println("0");
    
  }

}

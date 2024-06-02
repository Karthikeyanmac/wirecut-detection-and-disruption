const int buttonPin = 2;    // Pin connected to the push button
const int ledPinIntact = 13; // Pin connected to the first LED (wire intact)
const int ledPinCut = 12;   // Pin connected to the second LED (wire cut)
const int relayPin = 11;    // Pin connected to the relay module

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for the button pin
  pinMode(ledPinIntact, OUTPUT);    // Set ledPinIntact as output
  pinMode(ledPinCut, OUTPUT);       // Set ledPinCut as output
  pinMode(relayPin, OUTPUT);        // Set relayPin as output
  digitalWrite(ledPinIntact, HIGH); // Initially, the first LED should be on (indicating wire is intact)
  digitalWrite(ledPinCut, LOW);     // Initially, the second LED should be off
  digitalWrite(relayPin, LOW);      // Initially, the relay should be off
  Serial.begin(9600);               // Start serial communication
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Read the state of the button

  if (buttonState == LOW) { // Button pressed (wire cut)
     digitalWrite(ledPinIntact, HIGH);  // Turn on the intact LED
    digitalWrite(ledPinCut, LOW);      // Turn off the cut LED
    digitalWrite(relayPin, LOW);       // Turn off the relay
    Serial.println("Wire intact.");
  } else { // Button not pressed (wire intact)
    digitalWrite(ledPinIntact, LOW);   // Turn off the intact LED
    digitalWrite(ledPinCut, HIGH);     // Turn on the cut LED
    digitalWrite(relayPin, HIGH);      // Turn on the relay
    Serial.println("Wire cut!");
  }
  delay(1000); // Add a small delay for stability
}
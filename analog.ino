// Define the pins for the joystick connections
const int xAxisPin = A0; // Analog input pin for X-axis
const int yAxisPin = A1; // Analog input pin for Y-axis
const int buttonPin = 9; // Digital input pin for pushbutton
const int greenLed = 6;  // LED pin
const int redLed = 4;    // Red LED pin

// Threshold untuk mendeteksi posisi joystick
const int threshold = 100; // Nilai ambang batas (0-1023)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);  // Perbaikan: OUTPUT (bukan OUTOUT), dan gunakan koma
  Serial.begin(9600);
  Serial.println("Joystick Test Started");
  
  // Test green LED
  for(int i = 0; i < 3; i++) {
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(500);
  }  // Perbaikan: Tambah kurung kurawal penutup
  
  // Test red LED
  for(int i = 0; i < 3; i++) {
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
    delay(500);
  }
}

void loop() {
  // Read the joystick position values
  int xPosition = analogRead(xAxisPin);
  int yPosition = analogRead(yAxisPin);
  int buttonState = digitalRead(buttonPin);
  
  // Print joystick values
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState == LOW ? "PRESSED" : "RELEASED");
  
  // Kontrol LED berdasarkan posisi joystick
  if(xPosition < threshold) {
    digitalWrite(greenLed, HIGH);
  } else {
    digitalWrite(greenLed, LOW);
  }  // Perbaikan: Tambah kurung kurawal penutup
  
  if(yPosition < threshold) {
    digitalWrite(redLed, HIGH);
  } else {
    digitalWrite(redLed, LOW);
  }
  
  delay(100);
}

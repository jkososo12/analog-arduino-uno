// Konfigurasi pin Analog Module
const int xAxisPin = A0; // Analog input untuk sumbu X (Horizontal)
const int yAxisPin = A1; // Analog input untuk Y (Vertikal)
const int joystickPin = 9; // Pin Digital untuk tombol, terhubung ke pin nomor 9 pada Arduino
const int threshold = 100; // Nilai ambang batas (0-1023)

// Konfigurasi pin komponen led
const int ledHijau = 6;  // Pin digital untuk lampu led warna Hijau, terhubung ke pin nomor 6 pada Arduino
const int ledMerah = 4; // Pin digital untuk lampu led warna Merah, terhubung ke pin nomor 4 pada Arduino

void setup() {
  // Konfigurasi I/O untuk setiap komponen
  pinMode(joystickPin, INPUT_PULLUP); // Menetapkan bahwa variable joystick adalah INPUT 
  pinMode(ledHijau, OUTPUT); // Menetapkan bahwa variable led hijau adalah OUTPUT
  pinMode(ledMerah, OUTPUT); // Menetapkan bahwa variable led merah adalah OUTPUT
  
  // Konfigurasi serial print untuk catatan Joystick
  Serial.begin(9600); 
  Serial.println("Joystick Terhubung");
}

void loop() {
  // Konfigurasi variable untuk membaca nilai posisi setiap sumbu joystick dan status tekan joystick
  int xPosition = analogRead(xAxisPin);
  int yPosition = analogRead(yAxisPin);
  int buttonState = digitalRead(joystickPin);
  
  // Print joystick values
  Serial.print("Sumbu X: ");
  Serial.print(xPosition);
  Serial.print("\t Sumbu Y: ");
  Serial.print(yPosition);
  Serial.print("\t | Button: ");
  Serial.println(buttonState == LOW ? "DITEKAN" : "TIDAK DITEKAN");
  
  // Kontrol LED berdasarkan posisi joystick
  if(xPosition < threshold) {
    digitalWrite(lampuHijau, HIGH);
  } else {
    digitalWrite(lampuHijau, LOW);
  }  // Perbaikan: Tambah kurung kurawal penutup
  
  if(yPosition < threshold) {
    digitalWrite(ledMerah, HIGH);
  } else {
    digitalWrite(ledMerah, LOW);
  }
  
  delay(100);
}

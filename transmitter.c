#define LED_PIN 1  // TX0 pin
char message[] = "EV BEHIND";  // Message to transmit
void setup() {
  Serial.begin(38400);  // Initialize serial communication for debug output
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Setup complete");  // Debug output
}

void loop() {
  Serial.println("ev behind ");  // Debug output
  for (int i = 0; message[i] != '\0'; i++) {
    // Convert character to binary (assuming ASCII)
    char byte = message[i];
    for (int j = 7; j >= 0; j--) {
      int bit = (byte >> j) & 1;
      // Simulate light pulse using LED
      digitalWrite(LED_PIN, bit);
      delayMicroseconds(1000); // Adjust pulse width based on desired baud rate
      digitalWrite(LED_PIN, LOW);
      delayMicroseconds(1000); // Adjust inter-symbol time
    }
  }
  delay(1000); // Delay between transmissions (optional)
  Serial.println("alert ");  // Debug output
}

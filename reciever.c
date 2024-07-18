receivedString);

    if (receivedString.length() > 0) { // Check if there's valid data to print
      Serial.print("Data received and displayed on LCD: ");
      Serial.println(receivedString);
      delay(10000);

      // Display received data on Serial Monitor
      Serial.print("Received: ");
      Serial.println(receivedString);
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No data received");

    Serial.println("No data received from Serial");
  }
}

bool isPrintableAscii(char c) {
  return (c >= 32 && c <= 126); // Printable ASCII characters range from 32 to 126
}

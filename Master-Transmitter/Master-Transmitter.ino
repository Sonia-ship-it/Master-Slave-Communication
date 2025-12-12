#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); 
char buffer[100]; 
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Type your message:");
}

void loop() {
  int i = 0;
  while (BT.available()) {
    char c = BT.read();
    if (c == '\n') break;
    buffer[i++] = c;
  }
  if (i > 0) {
    buffer[i] = '\0';
    Serial.print("Message: ");
    Serial.println(buffer);
  }

  i = 0;
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') break;
    buffer[i++] = c;
  }
  if (i > 0) {
    buffer[i] = '\0';
    BT.println(buffer);
  }
}

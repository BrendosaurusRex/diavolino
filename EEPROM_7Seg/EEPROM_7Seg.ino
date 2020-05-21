/*
* ====================================================================
* Brendon Barrios | May 20, 2020
* ====================================================================
*/
const char Data[] = {0,13,2,3,4,5,6,7};
const byte Addr[] = {8,9,10,11};
#define OE 12

void setup() {
  // put your setup code here, to run once:

  for(int n = 0; n < 8; n++) {
    pinMode(Data[n], INPUT); // Configure Data pins as output
    }

  for(int i = 0; i < 4; i++) {
    pinMode(Addr[i], OUTPUT); // Configure Address pins as input
    }
  digitalWrite(OE, HIGH);
  pinMode(OE, OUTPUT); // Set Output Enable pin as output

  Serial.begin(57600); // Initialize Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:

  // Count from 0-16 in binary & parse each bit to config the address
  for(byte x = 0; x < 16; x++) {

    // Parse bits
    byte a0 = bitRead(x, 0);
    byte a1 = bitRead(x, 1);
    byte a2 = bitRead(x, 2);
    byte a3 = bitRead(x, 3);

    // Configure each address since implemented in binary
    if(a0 == 1) {
      digitalWrite(Addr[0], HIGH);
    }
    else {
      digitalWrite(Addr[0], LOW);
    }
    
    if(a1 == 1) {
      digitalWrite(Addr[1], HIGH);
    }
    else {
      digitalWrite(Addr[1], LOW);
    }
    
    if(a2 == 1) {
      digitalWrite(Addr[2], HIGH);
    }
    else {
      digitalWrite(Addr[2], LOW);
    }
    
    if(a3 == 1) {
      digitalWrite(Addr[3], HIGH);
    }
    else {
      digitalWrite(Addr[3], LOW);
    }
    
    digitalWrite(OE, LOW);
    delay(100);

    // Read Data pins and print to Serial Monitor
    for(int i = 7; i >= 0; i--) {
      int pin = digitalRead(Data[i]);
      Serial.print(pin);
      delay(100);
    }
    
  digitalWrite(OE, HIGH);
  Serial.println();    
  }
}

/*
* ====================================================================
* Brendon Barrios | May 20, 2020
* ====================================================================
*/
const char Data[] = {0,13,2,3,4,5,6,7};
const byte Addr[] = {8,9,10,11};
#define OE 12

void setup() {
  // To run once:

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

  // Count from 0-16 & parse into bits to config the address
  for(int x = 0; x < 16; x++) {
    
    int a[4]; // Initialize byte array
    
    // Parse bits into byte array
    for(int b = 0; b < 4; b++) {
      a[b] = bitRead(x, b);       
    }

    // Configure each address since implemented in binary
    for(int num = 0; num < 4; num++) {
      if(a[num] == 1) {
        digitalWrite(Addr[num], HIGH);
      }
      else {
        digitalWrite(Addr[num], LOW);
      }
    }

    digitalWrite(OE, LOW); // Enable Output
    delay(100);

    // Read Data pins and print to Serial Monitor
    for(int i = 7; i >= 0; i--) {
      int pin = digitalRead(Data[i]);
      Serial.print(pin);
      //delay(100); // prints each bit slower
    }
    
    delay(250); // prints faster
  digitalWrite(OE, HIGH);
  Serial.println();    
  }
}

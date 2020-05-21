const char Data[] = {0,1,2,3,4,5,6,7};
const char Addr[] = {0,1,2,3};
#define OE 12

void setup() {
  // put your setup code here, to run once:

  for(int n = 0; n < 8; n++) {
    pinMode(Data[n], INPUT); // Configure Data pins as output
    }

  for(int i = 0; i < 4; i++) {
    pinMode(Addr[i], OUTPUT); // Configure Address pins as input
    }

  pinMode(OE, OUTPUT); // Set Output Enable pin as output

  Serial.begin(57600); // Initialize Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i < 16; i++) {
    i = byte(i);
    Serial.print(i);
    }
  Serial.println();
}

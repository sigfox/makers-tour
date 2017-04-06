void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("AT$RC\n");
  delay(100);
  Serial.println("AT$SF=0123CAFE\n");
}

void loop() {
  
  
}


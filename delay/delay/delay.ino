int cont = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Contador: ");
  Serial.println(cont);
  cont++;
  delay(1000);
}

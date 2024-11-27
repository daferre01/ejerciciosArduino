void setup() {
  Serial.begin(9600);
}
int cont=0;
void loop() {
  Serial.println(cont);
  cont++;
  delay(1000);
}

int cont = 0;                
unsigned long previousMillis = 0;
const long interval = 1000;
void setup() {
  Serial.begin(9600);
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  
    Serial.println(cont);
    cont++;                          
  }
}

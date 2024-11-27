int cont = 0;             
unsigned long milliseg;      
unsigned long previousMillis = 0;
const long intervalo = 1000;

void setup() {
  Serial.begin(9600);
  milliseg = millis();
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervalo) {
    previousMillis = currentMillis;  
    Serial.println(cont);
    cont++;                          
  }
}

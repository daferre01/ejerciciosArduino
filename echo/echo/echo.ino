
void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    char texto = Serial.read();
    if(texto >='A' && texto <='Z'){
      texto=texto+32;
    }else if(texto >='a' && texto <='z'){
      texto=texto-32;
    }else{
      texto=texto;
    }
    Serial.write(texto);
  }
}
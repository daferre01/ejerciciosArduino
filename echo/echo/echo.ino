String texto = "";
String texto_final = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  texto = Serial.readStringUntil('\n');
  texto_final = "";
  for (int i = 0; i < texto.length(); i++) {
    char letra = texto.charAt(i);
    if (letra >= 97 && letra <= 122) {
      texto_final += (char)(letra - 32);
    } else if (letra >= 65 && letra <= 90) {
      texto_final += (char)(letra + 32);
    } else {
      texto_final += letra;
    }
  }
  Serial.println(texto_final);
}

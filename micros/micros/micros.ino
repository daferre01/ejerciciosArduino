int ctr1=0;
int ctr2=0;
unsigned long tiempo=0;
unsigned long intervalo = 100000;

void setup() {
  Serial.begin(9600);
  tiempo = micros();
}
void loop() {
  if (micros() - tiempo >= intervalo) {
    for (int i = 0; i <= 20; i++) {
      ctr1++;
      mostrar(ctr1, ctr2);
    }
    ctr2++;
    mostrar(ctr1, ctr2);
    ctr1 -= ctr2;
    tiempo = micros();
  }
}
void mostrar(int ctr1,int ctr2){
  Serial.print("C1: ");
  Serial.print(ctr1);
  Serial.print(" C2: ");
  Serial.println(ctr2);
}
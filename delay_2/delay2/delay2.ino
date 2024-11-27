void setup() {
  Serial.begin(9600);
}
int ctr1=0;
int ctr2=0;

void loop() {
  for(int i=0;i<=20;i++){
    ctr1++;
    mostrar(ctr1,ctr2);
    delay(100);
  }
  ctr2++;
  mostrar(ctr1,ctr2);
  ctr1-=ctr2;
}
void mostrar(int ctr1,int ctr2){
  Serial.print("C1: ");
  Serial.print(ctr1);
  Serial.print(" C2: ");
  Serial.println(ctr2);
}
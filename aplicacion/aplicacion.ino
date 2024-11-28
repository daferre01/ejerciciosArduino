#include <stdint.h>

int estado = 1;
uint64_t intervalo = 1000;
uint64_t ultimaEjecucion = 0;
bool activo = false;
bool alterno = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  mostrarAyuda();
}

void loop() {
  procesarComando();
  if (activo) {
    publicar();
  }
}

void mostrarAyuda() {
  Serial.println("Comandos:");
  Serial.println("H o h (help): Muestra este menu.");
  Serial.println("START o start: Inicia la publicacion.");
  Serial.println("STOP o stop: Detiene la publicacion.");
  Serial.println("TIME o t: Cambia la frecuencia (1-10 Hz).");
  Serial.println("MODE o m: Cambia entre fijo y alterno.");
}

void procesarComando() {
  if (Serial.available() > 0) {
    String entrada = Serial.readString();
    entrada.trim();
    entrada.toUpperCase();

    if (entrada == "H") {
      mostrarAyuda();
    } else if (entrada == "START") {
      iniciar();
    } else if (entrada == "STOP") {
      detener();
    } else if (entrada == "TIME") {
      cambiarTiempo();
    } else if (entrada == "MODE") {
      cambiarModo();
    } else {
      Serial.println("Comando desconocido.");
    }
  }
}

void iniciar() {
  activo = true;
  Serial.println("Inicio.");
}

void detener() {
  activo = false;
  Serial.println("Detenido.");
}

void cambiarTiempo() {
  Serial.println("Frecuencia (1-10):");
  while (Serial.available() == 0);
  int frecuencia = Serial.parseInt();
  if (frecuencia >= 1 && frecuencia <= 10) {
    intervalo = 1000 / frecuencia;
    Serial.print("Frecuencia: ");
    Serial.print(frecuencia);
    Serial.println(" Hz.");
  } else {
    Serial.println("Invalido.");
  }
}

void cambiarModo() {
  alterno = !alterno;
  Serial.println(alterno ? "Modo alterno." : "Modo fijo.");
}

void publicar() {
  uint64_t ahora = millis();
  if (ahora - ultimaEjecucion >= intervalo) {
    ultimaEjecucion = ahora;
    if (alterno) {
      estado = 1 - estado;
    }
    Serial.println(estado);
  }
}


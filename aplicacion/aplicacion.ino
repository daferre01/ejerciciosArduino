#include <stdint.h>

int valorEstado = 1;
uint64_t tiempoPublicacion = 1000;
uint64_t marcaTiempo = 0;
bool publicando = false;
bool alternarValor = false;

void setup() {
  Serial.begin(9600);
  esperarConexionSerie();
  inicializar();
}

void loop() {
  procesarComandos();
  if (publicando) {
    manejarPublicacion();
  }
}

void esperarConexionSerie() {
  while (!Serial) {
    ; 
  }
  delay(500); 
}

void inicializar() {
  mostrarOpciones();
}

void procesarComandos() {
  if (Serial.available() > 0) {
    String entrada = Serial.readString();
    entrada.trim();
    entrada.toUpperCase();

    if (entrada == "H") {
      mostrarOpciones();
    } else if (entrada == "INICIAR") {
      activarPublicacion();
    } else if (entrada == "DETENER") {
      detenerPublicacion();
    } else if (entrada == "FRECUENCIA") {
      ajustarFrecuencia();
    } else if (entrada == "CAMBIAR") {
      cambiarModo();
    } else {
      Serial.println("Comando desconocido. Usa 'H' para ver opciones.");
    }
  }
}

void manejarPublicacion() {
  uint64_t tiempoActual = millis();
  if (tiempoActual - marcaTiempo >= tiempoPublicacion) {
    marcaTiempo = tiempoActual;

    if (alternarValor) {
      valorEstado = 1 - valorEstado;
    }
    Serial.println(valorEstado);
  }
}

void mostrarOpciones() {
  Serial.println("=== Menú de comandos ===");
  Serial.println("H: Mostrar este menú.");
  Serial.println("INICIAR: Comenzar a enviar datos.");
  Serial.println("DETENER: Detener el envío de datos.");
  Serial.println("FRECUENCIA: Ajustar la frecuencia de envío (1 a 10 Hz).");
  Serial.println("CAMBIAR: Alternar entre modo fijo y alternativo.");
}

void activarPublicacion() {
  publicando = true;
  Serial.println("Publicación activada.");
}

void detenerPublicacion() {
  publicando = false;
  Serial.println("Publicación detenida.");
}

void ajustarFrecuencia() {
  Serial.println("Introduce la frecuencia deseada (1 a 10 Hz):");
  while (Serial.available() == 0);

  int frecuencia = Serial.parseInt();
  if (frecuencia >= 1 && frecuencia <= 10) {
    tiempoPublicacion = 1000 / frecuencia;
    Serial.print("Frecuencia configurada: ");
    Serial.print(frecuencia);
    Serial.println(" Hz.");
  } else {
    Serial.println("Valor no válido. Usa un número entre 1 y 10.");
  }
}

void cambiarModo() {
  alternarValor = !alternarValor;
  if (alternarValor) {
    Serial.println("Modo alternativo activado. El valor cambiará entre 0 y 1.");
  } else {
    Serial.println("Modo fijo activado. El valor se mantendrá en 1.");
  }
}

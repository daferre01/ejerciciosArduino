# Ejercicios Microcontroladores

Este repositorio contiene una serie de ejercicios diseñados para practicar la programación de microcontroladores, específicamente utilizando **Arduino**. Cada ejercicio está organizado en una carpeta con su respectivo código, que incluye explicaciones y configuraciones necesarias.

---

## Ejercicios

### **1. hello_world**
- **Descripción:** Imprime "Hello world" continuamente en el monitor serie.
- **Propósito:** Introducción al uso del monitor serie en Arduino.

---

### **2. delay**
- **Descripción:** 
  - Incrementa un contador e imprime su valor en el monitor serie cada segundo.
  - Utiliza la función `delay()` para gestionar el tiempo.
- **Propósito:** Familiarización con funciones básicas de temporización.

---

### **3. delay_2**
- **Descripción:**
  - Incrementa dos contadores de forma independiente:
    - **ctr1:** Se incrementa 10 veces por segundo.
    - **ctr2:** Se incrementa 1 vez cada 2 segundos.
  - Al incrementar `ctr2`, su valor se resta del contador `ctr1`.
  - Imprime ambos contadores en el formato: `C1: {ctr1} C2: {ctr2}`.
  - Utiliza la función `delay()` para gestionar los tiempos.
- **Propósito:** Práctica avanzada de temporización y lógica.

---

### **4. millis**
- **Descripción:** 
  - Repite el ejercicio 2 utilizando la función `millis()` en lugar de `delay()`.
- **Propósito:** Comprender el uso de temporizadores no bloqueantes para mejorar la eficiencia.

---

### **5. micros**
- **Descripción:**
  - Repite el ejercicio 3 utilizando la función `micros()` en lugar de `delay()`.
- **Propósito:** Uso de temporizadores de alta precisión para tareas concurrentes.

---

### **6. echo**
- **Descripción:**
  - Recibe datos a través del puerto serie.
  - Reenvía los datos cambiando las mayúsculas por minúsculas y viceversa.
- **Propósito:** Introducción al manejo de datos serie y procesamiento de cadenas.

---

### **7. Línea de comandos**
- **Descripción:** Implementa una aplicación de línea de comandos a través del puerto serie del microcontrolador. Comandos soportados:
  - `H` o `h` (help): Muestra el menú de ayuda.
  - `START` o `start`: Publica un valor cada segundo por el puerto serie.
  - `STOP` o `stop`: Detiene la publicación.
  - `T` o `t` (time): Cambia el periodo de publicación entre 1 y 10 veces por segundo.
  - `M` o `m` (mode): Cambia entre dos modos:
    - **Fijo:** Mantiene siempre el mismo valor (por defecto `1`).
    - **Alternativo:** Alterna entre `0` y `1` en cada publicación.
- **Propósito:** Comprender el diseño de sistemas interactivos con múltiples modos y comandos.

---

## Cómo usar este repositorio
1. **Clona el repositorio:**
   ```bash
   git clone https://github.com/tuusuario/ejercicios_microcontroladores.git
   cd ejercicios_microcontroladores

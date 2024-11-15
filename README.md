LABORATORIO 9
Este programa implementa diferentes técnicas para resolver colisiones en tablas hash, incluyendo prueba lineal, prueba cuadrática, doble direccionamiento hash y encadenamiento.

 - Compilar el programa con el siguiente comando: g++ laboratorio9.cpp -o laboratorio9.exe
 - Ejecutar el programa: ./laboratorio9.exe {L|C|D|E}

Uso del programa:
  1. Al ejecutar el programa, selecciona un método de resolución de colisiones (L, C, D, o E).
  2. Ingresa pares de clave (entero) y valor (cadena) para llenar la tabla hash. Usa -1 como clave para terminar la inserción.
  3. La tabla hash se imprimirá automáticamente después de cada inserción:
      - En el caso de encadenamiento, se mostrará la lista enlazada para cada índice.
  4. Para buscar un elemento, ingresa la clave deseada. El programa mostrará el índice y el valor asociado si se encuentra.

Nota: 
  - Prueba Lineal (L): Resuelve colisiones desplazándose secuencialmente.
  - Prueba Cuadrática (C): Usa desplazamientos cuadráticos para evitar clustering.
  - Doble Dirección Hash (D): Combina dos funciones hash para calcular el siguiente índice.
  - Encadenamiento (E): Almacena los valores colisionados en una lista enlazada.
  - La tabla tiene un tamaño fijo de 20 elementos.

Antonia Rojas (2024)

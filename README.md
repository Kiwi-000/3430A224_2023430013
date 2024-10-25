LABORATORIO 7
Este programa implementa el algoritmo de Prim para encontrar el árbol de expansión mínima en un grafo.

Herramientas necesarias:
Graphviz: Instalar y agregar la carpeta bin de Graphviz a la variable de entorno PATH para generar el grafo visual en formato PNG.

- Compilar el programa: g++ laboratorio7.cpp -o lab7.exe
- Ejecutar el programa: ./lab7.exe
    
Uso del programa:
  1. Ingresa el número de nodos del grafo.
  2. Proporciona la matriz de distancias entre los nodos, usando -1 para representar distancias infinitas.
  3. El programa imprimirá la matriz y calculará el árbol de expansión mínima, mostrando las aristas y sus pesos.
  4. Se generarán archivos .dot y .png para el grafo original y el árbol de expansión mínima.
   
Notas:
- Los archivos generados se guardan en el mismo directorio donde se ejecuta el programa.
- El programa ha sido desarrollado y probado en un entorno Windows; la apertura automática de imágenes puede no funcionar en otros sistemas operativos.



Antonia Rojas (2024)

LABORATORIO 6
Este programa implementa el algoritmo de Dijkstra para calcular las distancias mínimas entre los nodos de un grafo. 

- Herramientas necesarias:
    Graphviz: Instalar y agregar la carpeta bin de Graphviz a la variable de entorno PATH para poder generar el grafo visual en formato PNG

- Compilar el programa con el siguiente comando:
    g++ laboratorio6.cpp -o lab6.exe
- Ejecutar el programa:
    ./lab6.exe
  
- Uso del programa:
Al ejecutar el programa, se te pedirá ingresar la matriz de distancias entre los nodos. La matriz es de tamaño 5x5, y debes usar -1 para representar distancias infinitas (es decir, cuando no hay conexión entre dos nodos). Luego, selecciona un nodo de origen entre los siguientes: 'a', 'b', 'c', 'd', 'e'. El programa aplicará el algoritmo de Dijkstra desde el nodo origen seleccionado y mostrará las distancias mínimas hacia los otros nodos. Se generará un archivo grafo.txt que describe el grafo en formato DOT. El archivo grafo.png se generará automáticamente y se abrirá en el visor de imágenes de Windows.

- Notas:
  * El archivo grafo.txt y grafo.png se generan en el mismo directorio en el que se ejecuta el programa.
  * El programa ha sido desarrollado y probado en un entorno Windows. La apertura automática de la imagen grafo.png podría no funcionar en otros sistemas operativos.

Antonia Rojas (2024)

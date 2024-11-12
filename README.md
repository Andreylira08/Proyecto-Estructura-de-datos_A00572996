# Proyecto: VIDEOJUEGO IMPLEMENTANDO ALGORITMOS VISTOS EN CLASE
Este proyecto tendrá la finalidad de desarrollar un videojuego implementado algoritmos y conceptos vistos en clase, con el objetivo de vincular una de las pasiones del alumno con temas que sean de utilidad para la trayectoria profesional Sera un juego estilo speedrun, en donde se almacenaran los tiempos registrados, se ordenaran de menor a mayor (Cambios) Tambien se podra ver el inventario del juego donde ambos estaran dentro de listas.
## Descripción del avance 1
En este avance de proyecto se seleccion e implemento un algoritmo de ordenamiento, se implemento el inventario y los usuarios a los que se busca usar como datos para implementar el algoritmo de ordenamiento

## Descripción del avance 2
Debido a limitaciones de tiempo y motivos personales, el concepto del proyecto se ha ajustado a una implementación más sencilla, pero se conserva el objetivo inicial. Se sustituyó el algoritmo de ordenamiento original por Merge Sort para mejorar la eficiencia y optimización del código, utilizando listas como estructura de datos, lo que permite manejar grandes volúmenes de información de manera eficaz para los jugadores. Además, se implementó la funcionalidad para exportar los datos ordenados a un archivo .txt, junto con un método de búsqueda que facilita encontrar información específica basada en el nombre y el usuario del jugador
## Descripción del avance 3

En este avance se cumple el ultimo requisitos del proyecto: importar archivo .txt, modificarlo dentro del código y exportarlo con las modificaciones realizadas que se realizaron.

### Cambios sobre el primer avance
1. **Se cambio el proyecto de unreal engine 5 a visual code:** En un principio se buscaba realizar un videojuego utilizado algoritmos y estructuras de datos con el motor gráfico unreal engine pero debido a temas de tiempo y personales se tomo la decisión de implementar el proyecto pero en un concepto mas básico para poder cumplir con las fechas de entrega

2. **Cambio de Selection sort a Merge sort:** Se realizó un cambio en el algoritmo de ordenamiento, sustituyendo Selection Sort por Merge Sort. Esta modificación se hizo con el objetivo de mejorar la eficiencia y el rendimiento del código, ya que Merge Sort tiene una complejidad temporal de O(n log n), lo que lo hace más adecuado para manejar grandes volúmenes de datos en comparación con Selection Sort, que tiene una complejidad de O(n²).

### Cambios sobre el segundo avance
1. Se implemento la funcionalidad de importar archivos para poder ordenarlos y sobrescribirlos para poder exportarlo con las nuevas modificaciones realizadas
2. Se agrego la funcion de poner nuevos datos a la lista del archivo importado para despues volverlo a ordenar y exportarlo con la nueva información como un archivo completamente nuevo

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp -o ` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
El programa requiere dos tipos de datos de entrada si se quieren importar archivos para ordenar se requiere que sea en formato .txt y tenga la siguiente estructura:
(Nota: la carpeta ya cuenta con un archivo con el que se importan datos, se llama "crónometro_import.txt" o "inventario_import.txt")

1. **Cronómetros:** Una lista de objetos Cronometro con el siguiente formato: 
    Nombre de usuario(string),Fecha (string, en formato DD/MM/AAAA), Horas (int), minutos(int), Segundos(int). 
    
    Ejemplo:

    Cronometro("Alice", "10/10/2024", 4, 30, 30)
    Cronometro("Bob", "11/10/2024", 2, 15, 0)
    Cronometro("Charlie", "12/10/2024", 1, 15, 50)


2. **Inventarios:** Una lista de objetos Inventario con el siguiente formato: 

    Nombre del objeto(string),(string: "Legendario", "Epico", "Raro", "Normal", "Comun"), Duración(int), Tipo (string: "Arma", "Defensa", "Comida", "Utilidad"), ID(int). 

    Ejemplo: 
    
    Inventario("Espada", "Legendario", 30, "Arma", 1)
    Inventario("Escudo", "Epico", 30, "Defensa", 2)
    Inventario("Palo", "Normal", 10, "Arma", 7)


## Descripción de las salidas del avance de proyecto

**Tiempos ordenados:** El programa ordena los cronómetros por los tiempos (horas, minutos y segundos) y muestra la lista ordenada de los tiempos de todos los jugadores en consola.

**Inventario ordenado por ID:** El programa ordena los inventarios por su ID y muestra el inventario ordenado en consola.

**Búsqueda de cronómetro por nombre:** El usuario puede buscar un cronómetro específico por el nombre de usuario. Si el cronómetro se encuentra, se muestra la información de dicho cronómetro; si no, se muestra un mensaje de error.

**Búsqueda de inventario por tipo:** El usuario puede buscar los objetos del inventario por su tipo (por ejemplo, "Arma", "Defensa"). El programa muestra todos los objetos que coincidan con el tipo buscado.

**Exportar cronómetros e inventario a archivo:** El programa permite exportar los cronómetros e inventarios ordenados a un archivo .txt, donde cada línea contiene los datos de un cronómetro o del inventario.


## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Principalmente en el primer avance se implemento el selection sort por su sencillez, pero después de la revisión y volver a evaluar el código se llego a la conclusión que lo sencillo no siempre es lo mejor, es por eso que se decidio cambiar al merge sort ya que la principal ventaja de usar Merge Sort es su eficiencia consistente, que es particularmente útil cuando se manejan grandes conjuntos de datos. Su tiempo de ejecución es generalmente de O(n * log n), lo que lo hace significativamente más rápido que algoritmos de ordenación simples como Bubble Sort o Insertion Sort, especialmente en listas grandes.

Ordenamiento de tiempos con Merge sort cuenta con una complejidad de O(n log (n)) lo que lo hace mejor que la mayoria de los algoritmos de ordenamiento. La gran mayoria de sus implementaciones son estables,lo que significa que el orden relativo de elementos iguales es el mismo en la entrada y la salida. También se tomo en cuenta el peor de los casos y el mejor de los casos en donde ambos se mantienen como O(n log (n)) ya que como se requiere el famoso dividir y conquistar incluso cuando el arreglo ya está ordenado, la complejidad temporal en el mejor caso sigue siendo O(n log n), al igual que en los casos promedio y peor. Esto nos es útil a la hora de trabajar con grandes volumenes de datos como en nuestro caso que son tiempos de cronómetro, nombre, fechas ya que siempre mantendra la misma velocidad y constancia. 

Analizando con mas profundidad el algoritmo de ordenamiento del merge nos vamos a la parte en la que el algoritmo divide por partes la lista para al final fusionarla, este es la complejidad de dichas funciones: 

Dividir: O(log n) — En cada nivel de recursión, los datos se dividen a la mitad, lo cual ocurre en logaritmo de 𝑛 niveles.

Fusionar: O(n) — En cada nivel de recursión, se realiza la operación de fusión, que toma tiempo proporcional al número de elementos a fusionar.

Merge Sort es un algoritmo de ordenación estable, lo que significa que si dos elementos tienen el mismo valor, conserva el orden original en que aparecen. Esto es crucial en situaciones donde el orden de los elementos iguales debe mantenerse, en nuestro caso es lo que necesitamos ya que en un videojuego es normal contar con items de inventario repetidos por lo que este tipo de orden es necesario para nuestro código



#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

La estructura de datos que se implementa en este código es una lista doblemente enlazada que permite la inserción y eliminación de elementos en cualquier parte de la lista en tiempo constante O(1), pero las operaciones de acceso a elementos requieren tiempo lineal 𝑂(𝑛). El programa implementa dos métodos principales de búsqueda: búsqueda por nombre de usuario en los cronómetros y búsqueda por tipo en el inventario pero la lista no permite acceso directo a los elementos (como en los vectores o arreglos), por lo que para acceder a un elemento es necesario recorrer la lista por lo que su complejidad es de 0(n).



#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

En el programa, además de las estructuras de datos y algoritmos , se ejecutan otras operaciones dentro del ciclo principal y en cada opción del menú. La complejidad del ciclo principal depende de la cantidad de veces que el usuario interactúe con el menú. En general, podemos considerar que el ciclo tiene una complejidad lineal en función del número de iteraciones del usuario. 

Las **primeras dos opciones del menu** son parte del algoritmo de ordenamiento merge por lo que su complejidad es de O(n log n) 

La **búsqueda de un cronómetro por nombre y buscar inventario por ID** , se realiza una búsqueda lineal en la lista de cronómetros o la lista inventarios según su respectiva opción que se escogio, ambas opciones cuentan con una complejidad de O(n), donde n es el número de cronómetros o listas.

**Exportar archivos** 

 Exportar las listas cronómetro o inventario a un archivo implica recorrer la lista y escribir cada cronómetro en el archivo, lo cual tiene una complejidad de O(n) ya que se esta escribiendo linea por linea para generar el archivo.

 **Importar archivos** 

 La operación de leer el archivo es O(n), donde n es el número de líneas del archivo, ya que se lee cada línea del archivo, después nuestro código pregunta la opcion de agregar un dato a la lista esto cuenta con una complejidad de 0(1) ya que siempre lo agregara al final de la lista, para terminar el codigo ordenara los datos obteniendo la misma complejidad que el merge sort mencionada anteriormente. Por lo tanto la complejidad de esta funcionalidad es de O(n log n)
 


 **Complejidad final del programa** 

 Para determinar la complejidad final de nuestro programa únicamente necesitamos ver cual fue la complejidad mas dominante de nuestro programa, en este caso contamos con que los algoritmos de ordenamiento cuentan con mayor complejidad por lo que nuestro proyecto final cuenta con una complejidad de O(n log n) 

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Después de cambiar de metodo de ordenamiento de Selection Sort, se realizo una investigación mas profundo y se llego a la decision que la opción más adecuadas para este tipo de tareas es el algoritmo Merge Sort, ya que ofrece un rendimiento de O(n log n) en el peor de los casos y tiene la ventaja de ser estable, es decir, mantiene el orden relativo de los elementos que son iguales en base al criterio de ordenamiento.


#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para este proyecto, se utilizan varias estructuras de datos que son apropiadas para las tareas que se requieren
La estructura de datos elegida para almacenar tanto los cronómetros como los inventarios es la lista doblemente enlazada de la STL de C++ (std::list)La lista doblemente enlazada es eficiente para agregar o eliminar elementos en cualquier parte de la lista, lo cual puede ser útil si se planea modificar la colección en tiempo de ejecución.Dado que el acceso a los elementos es secuencial, es ideal cuando se requiere recorrer toda la lista para operaciones como ordenamiento o exportación, que es precisamente lo que se necesita en este caso.

La lista tiempos almacena objetos de tipo Cronometro y de tipo Inventario, que incluyen datos como el nombre del usuario, la fecha y el tiempo (en horas, minutos y segundos) o en el caso de inventario  contienen información como el nombre del objeto, la rareza, la duración, el tipo y el ID.


### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

El código que se presenta cuenta con una opción de busqueda que permitira buscar los datos de los tiempos record y del inventario en base al nombre del usuario y del tipo de objeto que se busca

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El código cuenta con la funcionalidad para poder importar archivos con datos que son compatibles para primero preguntar si desea agregar mas datos a los que se importaron,despues los vuelve a ordenar, para después preguntar si quiere exportar los nuevos datos importados y ordenados en un archivo .txt llamado "NUEVOcronometros_ordenados.txt" (ya se mencionó en el punto anterior la estructura necesaria con el que es compatible para poder importar una lista de datos a este código) 



### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

El código exporta el archivo en formato CSV (separado por comas), lo que permitirá que los datos sean fácilmente legibles y manipulables, tanto para el programa como para cualquier otro software que los lea. 
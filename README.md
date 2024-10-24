# VIDEOJUEGO IMPLEMENTANDO ALGORITMOS VISTOS EN CLASE
Este proyecto tendrá la finalidad de desarrollar un videojuego implementado algoritmos y conceptos vistos en clase, con el objetivo de vincular una de las pasiones del alumno con temas que sean de utilidad para la trayectoria profesional
Sera un juego estilo speedrun, en donde se almacenaran los tiempos registrados, se ordenaran de menor a mayor (Cambios) Tambien se podra ver el inventario del juego donde ambos estaran dentro de listas.
# SICT0301B: Evalúa los componentes

## Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa (Cambios) .

Ordenamiento de tiempos con Merge sort cuenta con una complejidad de O(log (n)) lo que lo hace mejor que la mayoria de los algoritmos de ordenamiento. La gran mayoria de sus implementaciones son estables,lo que significa que el orden relativo de elementos iguales es el mismo en la entrada y la salida. También se tomo en cuenta el peor de los casos y el mejor de los casos en donde ambos se mantienen como O(log (n)) ya que como se requiere el famoso dividir y conquistar incluso cuando el arreglo ya está ordenado, la complejidad temporal en el mejor caso sigue siendo O(n log n), al igual que en los casos promedio y peor. Esto nos es útil a la hora de trabajar con grandes volumenes de datos como en nuestro caso que son tiempos de cronómetro, nombre, fechas ya que siempre mantendra la misma velocidad y constancia. Además, Merge Sort es un algoritmo estable, lo que significa que mantendrá el orden relativo de los elementos con tiempos iguales. 

# SICT0302B: Toma decisiones

## Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente. (Cambios)
Utilice Merge sort para poder ordenar tiempos de cronómetro. Decidí escoger Merge sort ya que necesito que los menores tiempo registrado se almacene en los primeros lugares y se ordenen de menor a mayor. Este algoritmo fue implementado por su , buen rendimiento, y poco requerimiento de memoria en listas con datos no muy grandes. 

## Selecciona una estructura de datos adecuada al problema y la usa correctamente. (Cambios)
Se implementaron listas para almacenar nuestros datos ya que podremos agregar o quitar elementos a las listas y tambien podemos recorrer secuencialmente la lista para poder escoger un valor en específico o mostrar todas las tablas de datos

# SICT0303: Implementa acciones científicas"


## Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.(Cambios)

El código que se presenta cuenta con una opción de busqueda que permitira buscar los datos de los tiempos record y del inventario en base al nombre del usuario y del tipo de objeto que se busca

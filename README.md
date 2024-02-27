# OpenMP C++
Parallel programming with C++


## 1. Dado el siguiente algoritmo, calcular la solución paralela:  

![App Screenshot](https://i.imgur.com/tkL6xlS.jpeg)    

### a) Paralelizar usando OpenMP.
Se añade un return al main, y también sentencias para imprimir por pantalla (cuando el vector es relativamente pequeño) los vectores. También hemos añadido la funcionalidad de 
arrojar los resultados a un txt que será de gran utilidad par leer los datos y extraer conclusiones. 

Para hacer la paralelización se ha usado el pragma #pragma omp parallel  for para el bucle for. 
Con estas sentencias ya vemos podemos concluir que para tamaños de muestra de vecetor mayores de 325mil elementos funciona mejor en paralelo: 
INICIO ******************************************************************  
Para tamaño de vector de 325000 elementos: 
SECUENCIAL: Tiempo transcurrido 17716micro segundos 
PARALELO: Tiempo transcurrido 15809micro segundos 
 *********** CONCLUSIONES *********************** 
PARALELO: se obtiene mejor rendimiento con un tiempo de 15809micro segundos frente a 17716micro segundos 

### b) Medir el overhead añadido por los constructores de OpenMP a la ejecución del programa: 
#### b.1) Tiempo mínimo que añade la creación/destrucción de una región paralela, en función del número de hilos generados
Para medir lo que supone la creación de una región, vamos a añadir una región vacía para calcular el tiempo que supone construirla.  
La meteremos en un bucle for que aumente en cada iteración el número de hilos aumentará. 
Pondremos una marca de tiempo antes y después para al final hacer la medición de tiempos que guardaremos en un vector (incrementoTiempos(hilosMax)). La variable hilosMax representa el 
número máximo de hilos que en nuestro caso es de 24. 
Podemos ver el resultado en el txt generado: 

INICIO ******************************************************************  
Para tamaño de vector de 400000 elementos: 
SECUENCIAL:Tiempo transcurrido 21717micro segundos 
PARALELO: Tiempo transcurrido 16616micro segundos 
 *********** CONCLUSIONES *********************** 
PARALELO: se obtiene mejor rendimiento con un tiempo de 16616micro segundos frente a 21717micro segundos 
Con un numero de hilos = 1 el incremento de tiempo es 1998 micro segundos 
Con un numero de hilos = 2 el incremento de tiempo es 2068 micro segundos 
Con un numero de hilos = 3 el incremento de tiempo es 1025 micro segundos 
Con un numero de hilos = 4 el incremento de tiempo es 1524 micro segundos 
Con un numero de hilos = 5 el incremento de tiempo es 2231 micro segundos 
Con un numero de hilos = 6 el incremento de tiempo es 2586 micro segundos 
Con un numero de hilos = 7 el incremento de tiempo es 3237 micro segundos 
Con un numero de hilos = 8 el incremento de tiempo es 3965 micro segundos 
Con un numero de hilos = 9 el incremento de tiempo es 4199 micro segundos 
Con un numero de hilos = 10 el incremento de tiempo es 4747 micro segundos 
Con un numero de hilos = 11 el incremento de tiempo es 5480 micro segundos 
Con un numero de hilos = 12 el incremento de tiempo es 5821 micro segundos 
Con un numero de hilos = 13 el incremento de tiempo es 7400 micro segundos 
Con un numero de hilos = 14 el incremento de tiempo es 6916 micro segundos 
Con un numero de hilos = 15 el incremento de tiempo es 7313 micro segundos 
Con un numero de hilos = 16 el incremento de tiempo es 8074 micro segundos 
Con un numero de hilos = 17 el incremento de tiempo es 8755 micro segundos 
Con un numero de hilos = 18 el incremento de tiempo es 9356 micro segundos 
Con un numero de hilos = 19 el incremento de tiempo es 9667 micro segundos 
Con un numero de hilos = 20 el incremento de tiempo es 11045 micro segundos 
Con un numero de hilos = 21 el incremento de tiempo es 12624 micro segundos 
Con un numero de hilos = 22 el incremento de tiempo es 12315 micro segundos 
Con un numero de hilos = 23 el incremento de tiempo es 13669 micro segundos 
Con un numero de hilos = 24 el incremento de tiempo es 12667 micro segundos 


#### b.2) Coste de una barrera de sincronización en función del número de hilos que se sincronizan.
Colocamos ahora una barrera para ver la comparativa con los resultados anteriores. 

INICIO ******************************************************************  
Para tamaño de vector de 500000 elementos: 
SECUENCIAL:Tiempo transcurrido 26887micro segundos 
PARALELO: Tiempo transcurrido 16170micro segundos 
 *********** CONCLUSIONES *********************** 
PARALELO: se obtiene mejor rendimiento con un tiempo de 16170micro segundos frente a 26887micro segundos 
Con un numero de hilos = 1 eel incremento de tiempo de crear la región paralela es 1149 micro segundos 
Con un numero de hilos = 1 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 2 eel incremento de tiempo de crear la región paralela es 2643 micro segundos 
Con un numero de hilos = 2 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 3 eel incremento de tiempo de crear la región paralela es 994 micro segundos 
Con un numero de hilos = 3 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 4 eel incremento de tiempo de crear la región paralela es 1534 micro segundos 
Con un numero de hilos = 4 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 5 eel incremento de tiempo de crear la región paralela es 1989 micro segundos 
Con un numero de hilos = 5 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 6 eel incremento de tiempo de crear la región paralela es 3201 micro segundos 
Con un numero de hilos = 6 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 7 eel incremento de tiempo de crear la región paralela es 3222 micro segundos 
Con un numero de hilos = 7 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 8 eel incremento de tiempo de crear la región paralela es 3682 micro segundos 
Con un numero de hilos = 8 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 9 eel incremento de tiempo de crear la región paralela es 4835 micro segundos 
Con un numero de hilos = 9 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 10 eel incremento de tiempo de crear la región paralela es 4994 micro segundos 
Con un numero de hilos = 10 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 11 eel incremento de tiempo de crear la región paralela es 5293 micro segundos 
Con un numero de hilos = 11 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 12 eel incremento de tiempo de crear la región paralela es 5924 micro segundos 
Con un numero de hilos = 12 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 13 eel incremento de tiempo de crear la región paralela es 6734 micro segundos 
Con un numero de hilos = 13 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 14 eel incremento de tiempo de crear la región paralela es 7192 micro segundos 
Con un numero de hilos = 14 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 15 eel incremento de tiempo de crear la región paralela es 8176 micro segundos 
Con un numero de hilos = 15 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 16 eel incremento de tiempo de crear la región paralela es 8142 micro segundos 
Con un numero de hilos = 16 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 17 eel incremento de tiempo de crear la región paralela es 8909 micro segundos 
Con un numero de hilos = 17 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 18 eel incremento de tiempo de crear la región paralela es 9575 micro segundos 
Con un numero de hilos = 18 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 19 eel incremento de tiempo de crear la región paralela es 10098 micro segundos 
Con un numero de hilos = 19 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 20 eel incremento de tiempo de crear la región paralela es 11327 micro segundos 
Con un numero de hilos = 20 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 21 eel incremento de tiempo de crear la región paralela es 11350 micro segundos 
Con un numero de hilos = 21 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 22 eel incremento de tiempo de crear la región paralela es 11882 micro segundos 
Con un numero de hilos = 22 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 23 eel incremento de tiempo de crear la región paralela es 12853 micro segundos 
Con un numero de hilos = 23 el incremento de tiempo de poner una barrera es 0 micro segundos 
Con un numero de hilos = 24 eel incremento de tiempo de crear la región paralela es 13644 micro segundos 
Con un numero de hilos = 24 el incremento de tiempo de poner una barrera es 0 micro segundos 


Por los resultados que vemos no tiene coste una barrera para el tiempo final. Pero hay que tener en cuenta que he puesto el reloj justo antes de crear la barrera y justo después. 

Así que añadiremos al código que muestre en pantalla un mensaje simple y el resultado es el mismo. 

 
### b.3) Coste de entrar y salir de una sección crítica
Para el apartado c seguimos con un procedimiento similar pero añadiendo una sección crítica vacía donde observamos el mismo comportamiento imprimiendo mensaje dentro del código de la 
sección (como si no produjera incremento de tiempo)  

## 2. Calcular la media de los valores alojados en una matriz.
Para hacer la media de una matriz lo que se ha planteado es recorrer con un FOR la matriz que hemos definido como un array de dos dimensiones (matriz[][]) e ir sumando el valor almacenado 
en una variable que sería el total de la suma. Por último dividimos este total por el número de elementos y tenemos de ese modo la media de los valores. 

Con este planteamiento sencillo al principio realizábamos manualmente la inserción de los elementos pero claro, para dimensiones mayores supone un tiempo que sería impensable para sacar 
suficientes valores que nos pudieran arrojar conclusiones por ello el siguiente paso fue rellenar estas matrices de forma aleatoria con un número del 1 al 10 en cada uno de sus elementos. 

Por otro lado el programa tras introducir las dimensiones de la matriz lo que realiza es el cálculo de la media y medición de los tiempos programándolo estrictamente de manera secuencial y 
después lo que hace es lo mismo pero preparándolo para su optimización en paralelo. 

La estrategia utilizada para programarlo en paralelo ha sido la siguiente: 
Declaramos el inicio de la programación en paralelo con el pragma para el bucle for, teniendo en cuenta que la variable “total” donde se realizarán las sumas deben acceder todos los hilos que entren al bucle para añadir un valor sumado y no haya Ray traces que hagan que se produzcan valores inesperados y erróneos al sobre escribir un hilo la información almacenada. Cuando las matrices son de tamaño pequeño como por ejemplo 9x9 hemos presentado el código para que muestre por pantalla (y por fichero ya que todos los resultados los arrojamos a un txt) qué hilo 
añade un número al monto total almacenado en “total” y de ese modo poder comprobar visualmente el número real de hilos que ha intervenido en la operación. Esto no lo realizamos para 
tamaños mayores ya que además de convertirse en ininteligible, las operaciones de escritura tanto en ventana como en fichero penalizaría en cierto modo el rendimiento del procesamiento en 
paralelo así que hemos preferido omitirlo. 
Como última particularidad de este bucle for, cuando llegamos al último elemento de la matriz el hilo que entre será el que imprima por pantalla el total de hilos que han intervenido en la sección paralelizada. Es importante decir que no todos ellos necesariamente participan en el bucle for añadiendo valores a la suma total pero aún así participan en la sección paralelizada. 

### c) Analizar el rendimiento para diferentes tamaños de matriz y número de hilos
Tras diversas ejecuciones podemos manifestar que para tamaños de matriz inferiores a 100x100 
se producen mejores rendimientos ejecutando de manera secuencial: 

Así por ejemplo, una salida a nuestro fichero txt nos muestra: 
Nuestra matriz es: 100*100 
Calculo por proceso SECUENCIAL:  
SECUENCIAL: El total de la matriz es 50305 y la media es 5 
SECUENCIAL: Tiempo transcurrido 1373micro segundos 
 ***************************************************************************  
Calculo por proceso PARALELO:  
Un total de 24 hilos  
PARALELO: El total de la matriz es 50305 y la media es 5 
PARALELO: Tiempo transcurrido 39737micro segundos 
 *********** CONCLUSIONES *********************** 
SECUENCIAL: se obtiene mejor rendimiento para matriz de [100][100] con un tiempo de 
1373micro segundos frente a 39737micro segundos 
Para comprobar y sacar conclusiones acerca del número de hilos, veamos primero la salida de 
una matriz 9x9: 
***************************************************************************  
 ***************************************************************************  
Nuestra matriz es: 9*9 
578971413 
189937985 
533829885 
856967594 
856569543 
756989895 
791777962 
859246578 
194681138 

 

Calculo por proceso SECUENCIAL:  
SECUENCIAL:  El total de la matriz es 481 y la media es 5 
SECUENCIAL: Tiempo transcurrido 372micro segundos 
 ***************************************************************************  
Calculo por proceso PARALELO:  
El hilo [8] ha introducido el valor de 5 al total  
El hilo [0] ha introducido el valor de 8 al total  
El hilo [3] ha introducido el valor de 1 al total  
El hilo [1] ha introducido el valor de 7 al total  
El hilo [5] ha introducido el valor de 5 al total  
El hilo [2] ha introducido el valor de 7 al total  
El hilo [0] ha introducido el valor de 5 al total  
El hilo [3] ha introducido el valor de 8 al total  
El hilo [1] ha introducido el valor de 5 al total  
El hilo [5] ha introducido el valor de 3 al total  
El hilo [2] ha introducido el valor de 8 al total  
El hilo [0] ha introducido el valor de 6 al total  
El hilo [3] ha introducido el valor de 9 al total  
El hilo [1] ha introducido el valor de 6 al total  
El hilo [5] ha introducido el valor de 3 al total  
El hilo [2] ha introducido el valor de 9 al total  
El hilo [0] ha introducido el valor de 9 al total  
El hilo [3] ha introducido el valor de 9 al total  
El hilo [1] ha introducido el valor de 9 al total  
El hilo [5] ha introducido el valor de 8 al total  
El hilo [2] ha introducido el valor de 7 al total  
El hilo [0] ha introducido el valor de 6 al total  
El hilo [3] ha introducido el valor de 3 al total  
El hilo [1] ha introducido el valor de 8 al total  
El hilo [5] ha introducido el valor de 2 al total  
El hilo [2] ha introducido el valor de 1 al total  
El hilo [0] ha introducido el valor de 7 al total  
El hilo [3] ha introducido el valor de 7 al total  
El hilo [1] ha introducido el valor de 9 al total  
El hilo [5] ha introducido el valor de 9 al total  
El hilo [2] ha introducido el valor de 4 al total  
El hilo [0] ha introducido el valor de 5 al total  
El hilo [3] ha introducido el valor de 9 al total  
El hilo [1] ha introducido el valor de 8 al total  
El hilo [5] ha introducido el valor de 8 al total  
El hilo [2] ha introducido el valor de 1 al total  
El hilo [0] ha introducido el valor de 9 al total  
El hilo [3] ha introducido el valor de 8 al total  
El hilo [1] ha introducido el valor de 9 al total  
El hilo [5] ha introducido el valor de 8 al total  
El hilo [2] ha introducido el valor de 3 al total  
El hilo [2] ha introducido el valor de 4 al total  
El hilo [2] ha introducido el valor de 5 al total  
El hilo [2] ha introducido el valor de 8 al total  
El hilo [4] ha introducido el valor de 7 al total  
El hilo [6] ha introducido el valor de 8 al total  
El hilo [7] ha introducido el valor de 5 al total  
El hilo [7] ha introducido el valor de 1 al total  
El hilo [8] ha introducido el valor de 5 al total  
El hilo [4] ha introducido el valor de 5 al total  
El hilo [7] ha introducido el valor de 9 al total  
El hilo [8] ha introducido el valor de 6 al total  
El hilo [4] ha introducido el valor de 9 al total  
El hilo [7] ha introducido el valor de 4 al total  
El hilo [8] ha introducido el valor de 5 al total  
El hilo [4] ha introducido el valor de 2 al total  
El hilo [7] ha introducido el valor de 6 al total  
El hilo [8] ha introducido el valor de 6 al total  
El hilo [4] ha introducido el valor de 4 al total  
El hilo [7] ha introducido el valor de 8 al total  
El hilo [8] ha introducido el valor de 9 al total  
El hilo [4] ha introducido el valor de 6 al total  
El hilo [7] ha introducido el valor de 1 al total  
El hilo [8] ha introducido el valor de 5 al total  
El hilo [4] ha introducido el valor de 5 al total  
El hilo [7] ha introducido el valor de 1 al total  
El hilo [8] ha introducido el valor de 4 al total  
El hilo [4] ha introducido el valor de 7 al total  
El hilo [7] ha introducido el valor de 3 al total  
El hilo [8] ha introducido el valor de 3 al total  
El hilo [8] ha introducido el valor de 8 al total  
El hilo [8] ha introducido el valor de 5 al total  
El hilo [8] ha introducido el valor de 8 al total  
El hilo [8] ha introducido el valor de 9 al total  
El hilo [6] ha introducido el valor de 1 al total  
El hilo [6] ha introducido el valor de 7 al total  
El hilo [6] ha introducido el valor de 7 al total  
El hilo [6] ha introducido el valor de 7 al total  
El hilo [6] ha introducido el valor de 9 al total  
El hilo [6] ha introducido el valor de 6 al total  
El hilo [6] ha introducido el valor de 2 al total  
Un total de 24 hilos 
PARALELO: El total de la matriz es 481 y la media es 5 
PARALELO: Tiempo transcurrido 139295micro segundos 
 *********** CONCLUSIONES *********************** 
SECUENCIAL: se obtiene mejor rendimiento para matriz de [9][9] con un tiempo de 372micro segundos frente a 139295micro segundos 

Podemos apreciar que intervienen en el bucle sólo los hilos 0,1,2,3,4,5,6,7 y 8 mientras que tenemos 24 hilos creados en paralelo. Para tamaños mayores no hemos podido ejecutar el programa 
ya que al introducir la matriz mayor de 100 se queda ejecutando sin continuar (o eso o tarda demasiado para realizar un estudio óptimo). Aún así la conclusión es clara y la efectividad de la paralelización se puede ver en el siguiente ejercicio donde se han realizado grandes cantidades de cálculos que muestran cuándo sobrepasa la efectividad del paralelo a la ejecución secuencial. 
 
## 3. Obtener una aproximación numérica del valor de pi usando la regla del trapecio
![App Screenshot](https://i.imgur.com/az9gWWR.jpeg)    
 La regla del trapecio es un método numérico que se basa en la subdivisión de intervalos en los que en cada uno hace una aproximación a la función descrita arriba que relaciona la longitud de un arco de un círculo y su radio. De este modo se subdivide el intervalo [0,1] en un número finito de subintervalos y en cada uno de ellos se calcula el valor de dicha función. La suma total de cada una de estas áreas será el valor o la aproximación de π. 

Nuestro planteamiento: 
Al igual que el ejercicio anterior realizamos el cálculo de manera paralela y secuencial con toma de datos sobre los tiempos de ejecución, número de hilos y valores de π (comprobamos si los resultados son iguales porque deberían serlo). 
Para la paralelización usamos el pragma for con reducción en la variable “sum” que es donde almacenamos de cada hilo el resultado de la operación 4.0 / (1 + x * x) 
De esta manera nos aseguramos evitar un ray trace en esta variable que pueda arrojar resultados erróneos. 

Medición de los tiempos: 
Para la medición de los tiempos hemos hecho uso de omp_get_wtime(). Podríamos haberlo realizado como en los ejercicios anteriores pero también quisimos probarlo y parece más sencillo 
de utilizar:  https://www.openmp.org/spec-html/5.0/openmpsu160.html 

Análisis de rendimiento: 
Para este análisis veremos el resultado arrojado para extraer las conclusiones: 

***************************************************************************  
 ***************************************************************************  
 para N = 10 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1399259889 
El tiempo de ejecución fue: 0.0247557999 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 5.9798519778 
El tiempo de ejecución fue: 0.0013164000 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 100 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415759869 
El tiempo de ejecución fue: 0.0021331001 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2531519738 
El tiempo de ejecución fue: 0.0012013998 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 1000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415924869 
El tiempo de ejecución fue: 0.0020601000 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2801849738 
El tiempo de ejecución fue: 0.0011924000 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 10000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926519 
El tiempo de ejecución fue: 0.0093949998 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2828853038 
El tiempo de ejecución fue: 0.0019915001 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 100000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926536 
El tiempo de ejecución fue: 0.0137211999 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2831553071 
El tiempo de ejecución fue: 0.0058574001 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 1000000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926536 
El tiempo de ejecución fue: 0.0059239999 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2831823072 
El tiempo de ejecución fue: 0.0390623999 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 10000000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926536 
El tiempo de ejecución fue: 0.0332058000 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2831850072 
El tiempo de ejecución fue: 0.2830502999 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 100000000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926536 
El tiempo de ejecución fue: 0.1962186999 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2831852772 
El tiempo de ejecución fue: 1.9882595001 segundos 
 ***************************************************************************  
 ***************************************************************************  
 para N = 1000000000 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO EN PARALELO: Aproximación de pi con regla del trapecio: 3.1415926536 
El tiempo de ejecución fue: 1.6704891000 segundos 
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
EJECUTADO SECUENCIAL: Aproximación de pi con regla del trapecio: 6.2831853042 
El tiempo de ejecución fue: 18.8564798001 segundos 
 ***************************************************************************  
 *************************************************************************** 
 
Análisis de rendimiento: 
Hemos subrayado en amarillo el punto cuando la paralelización empieza a ser óptima. Ésta se 
produce cuando el número de polígonos es de 1 millón (N = 1.000.000 ).  

 

Podemos suponer que se producirían resultados similares en el ejercicio anterior para matrices de 1000x1000 o quizás de tamaño inferior. 

## 4. Ordenamiento por selección paralelizado 
El algoritmo de selección busca el elemento más pequeño en la lista y lo coloca en la primera posición. Luego, busca el siguiente elemento más pequeño y lo coloca en la segunda posición, y 
así sucesivamente. 
Para realizar la compartativa entre la ejecución secuencial y paralela, se ha resuelto de ambos modos, guardando también los resultados en un archivo de texto txt. 

La estrategia utilizada ha sido realizar el ordenamiento una serie de veces de manera iterativa en las que cada vez se crea un array relleno de manera aleatoria con valores del 1 al 100 y se realiza el requerido ordenamiento llamando a una función. Si bien esto complica a priori la elección de dónde colocar las directivas de openPm para hacer el paralelizado así que por ese motivo y para que quedara más limpio el código, se ha creado dos funciones: 
OrdenacionPorSeleccionParalelo() y OrdenacionPorSeleccionSecuencial(). 

Ambos métodos realizan propiamente el ordenamiento del siguiente modo: 
Recorremos el arreglo de enteros mediante el uso de dos variables, por un lado recorremos el array mediante la ayuda de la variable “i” y cada vez que pasamos a la posición siguiente recorreremos con la variable “j” para realizar la comparación con los elementos siguientes. Así de este modo podremos, si por ejemplo estamos en la posición 5 de un array y aquí se encuentra un 3, gracias a j podremos recorrer las posiciones 6 hasta n-1 y comprobar que no hay un número inferior (o sí, procediendo entonces a asignar a “minIndex” el valor de “j”). 

Para realizar el paralelizado hemos realizado una región paralela con #pragma omp parallel y ya los resultados arrojaban buenos valores. Como estábamos llamando dentro de la región a una 
función testeamos a realizar un #pragma omp for dentro de la misma función además de la región inicial. Los valores eran prácticamente iguales pero además se producían errores de ejecución. 

Como conclusión, como vemos en una de las salidas de la aplicación se puede apreciar que para arrays de gran tamaño el proceso secuencial no tiene un rendimiento óptimo: 

***************************************************************************  
 ***************************************************************************  
 - SECUENCIAL - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
para tamanio de Array: 10 - tiempo de ejecucion: 4.69992e-06  segundos 
para tamanio de Array: 100 - tiempo de ejecucion: 2.68999e-05  segundos 
para tamanio de Array: 1000 - tiempo de ejecucion: 0.0015576  segundos 
para tamanio de Array: 10000 - tiempo de ejecucion: 0.137937  segundos 
para tamanio de Array: 100000 - tiempo de ejecucion: 12.9575  segundos 
 - - PARALELO - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
para tamanio de Array: 10 - tiempo de ejecucion: 3.7998e-06  segundos 
para tamanio de Array: 100 - tiempo de ejecucion: 2.40002e-05  segundos 
para tamanio de Array: 1000 - tiempo de ejecucion: 0.000466  segundos 
para tamanio de Array: 10000 - tiempo de ejecucion: 0.000488  segundos 
para tamanio de Array: 100000 - tiempo de ejecucion: 2.10013e-06  segundos 
para tamanio de Array: 1000000 - tiempo de ejecucion: 0.0004219  segundos 

En estos casos el paralelizado juega un papel fundamental ya que este algoritmo para tamaños grandes, ejecutado de manera secuencial no se comporta demasiado bien. 

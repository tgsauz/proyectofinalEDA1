# proyectofinalEDA1
Proyecto final ALCOBENDAS para Estructura de Datos y Algoritmos I - 2023 - PROMOCIONADA NOTA FINAL 8 ~ 

PROYECTO FINAL
Programa para el manejo del archivo alcobendas.bin
Carrera:
Tecnicatura en Desarrollo de Software
Materia:
Estructura de Datos y Algoritmos I
Año:
2023

Profesores:
Ing. Gustavo Pascual y Ing. Nahuel Tello
Alumno: Tomás Eleazar Gandulfo
Dni: [REDACTADO]
Comisión: 319
Días: Martes
Turno: Noche

Introducción

El archivo principal sobre el que está basado el código se llama alcobendas. Este archivo
está escrito en binario y está compuesto en forma de estructura de datos llamado “comuna”.
La estructura toma esta forma:

struct comuna
{
  char periodo[TAM1];
  char descripcion[TAM2];
  char mujeres[TAM1];
  char hombres[TAM1];
  char total[TAM1];
};

(“TAM1” hace referencia a un valor de 10 y “TAM2” a un valor de 30).

El programa realizado se creó con la intención de brindarle al usuario una forma de
visualizar la información dentro del archivo, buscar instancias específicas por número de
estructura o por periodo al igual que brindarle una forma de editar los contenidos del archivo
de manera ordenada, agregar nuevas instancias de la estructura “comuna” y en caso de
necesitarlo exportar el contenido del archivo a un archivo texto.

Al inicializar el programa, se imprime un menú en la pantalla en el cual se le solicita al
usuario ingresar un número dependiendo la opción que desee. En caso ingresar un carácter
diferente a lo especificado o que se ocurra un error al ingresar el carácter este menú se
vuelve a imprimir y solicita un dato correcto nuevamente.


Dentro del programa existen 3 para poder visualizar el contenido del archivo:

CASO 1, CASO 2 y CASO 6

El CASO 1, consiste en una impresión por pantalla de todas las instancias que existen en el
archivo, desde la primera que se lee hasta la última.

(El punto débil de esta funcionalidad es que al haber muchas instancias no se logran visualizar todas ya que la
pantalla tiene cierta cantidad de caracteres que puede almacenar, sólo se podrán visualizar las últimas que
entren en la pantalla.)

El CASO 2, consiste en una búsqueda de una instancia específica según su ordenamiento
dentro del archivo. El programa tiene las instancias “enumeradas” según su orden de
primera a última lo que le permite ingresar un número de instancia, por ejemplo la instancia
nº 420 y visualizar la misma.

(El punto débil de esta funcionalidad es que si el usuario no conoce exactamente cuál es la instancia de la
estructura que desea puede llevar demasiado tiempo para buscarla, en caso de utilizar este caso para eso.)
Finalmente el CASO 6, este caso consiste en una búsqueda de todas las instancias que
posean un mismo dato periodo que el ingresado por el usuario para realizar la búsqueda,
este caso resulta útil al tener que revisar varias instancias de un mismo periodo anual.

(El punto débil de la funcionalidad es que si el dato periodo que desea buscar se ingresa de manera errónea o es
diferente a como está en el archivo, no mostrará resultados.)


Edición del archivo


Luego tenemos las funciones de edición del archivo las cuales consisten:

CASO 3 Y CASO 4

El CASO 3, este caso consiste en la selección de una instancia específica, (De la misma
manera que el CASO 2), para luego permitirle al usuario editar los contenidos de la misma
instancia.

(El punto débil es que no se le restringe al usuario una forma específica de ingresar las cadenas de caracteres
por ende puede agregar información errónea a los datos de la estructura.)

El CASO 4, consiste en darle una forma al usuario de agregar nuevas instancias al archivo.

(Posee el mismo punto débil que el caso anterior, por otro lado, no se le permite al usuario agregar instancias en
lugares específicos del archivo por ende siempre las nuevas instancias se escribirán al final del mismo.)

Exportación del archivo


Por último queda el CASO 5.

Este caso está hecho con la intención de brindarle al usuario una manera de exportar el
archivo binario en el que se encuentra la información a un archivo de texto, enumerando las
instancias por orden de escritura. Esto resulta útil ya que permite tener la información en
acceso rápido sin necesidad de un programa que lo pueda traducir.


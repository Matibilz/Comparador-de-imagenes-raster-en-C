#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define filas 10 //Orden matriz fila
#define columnas 10 //Orden matriz columna
/*
ANÁLISIS:
El programa debe analizar 2 imagenes (matrices de datos) para saber que tan similares son, para esto se darán 2 opciones al usuario:
	1. Realizar la comparación mediante lectura de archivos de texto, en este caso se realizará con un ejemplo que estará definido con anterioridad. Para este caso se crearán las siguientes funciones:
		- Función principal, que se encarga de declarar las matrices y ejecutar las funciones adicionales. Además en esta función 'main', el usuario ingresará el largo de las matrices.
		- Función que permita leer los archivos de texto que contienen las imegenes (matrices).
		- Función que permita imprimir las matrices leídas de los archivos de texto. Se imprimirán cuadros con el color correspondiente.
		- Función que permita combinar ambas imagenes en una sola matriz. Para esto se tendrá en cuenta que tan similares son cada casilla de la matriz 1 con cada casilla de la matriz 2:
			Si son iguales.
			Si son diferentes.
			Si son semi-equivalente (celeste-blanco o celeste-azul).
		- Función que transforme la matriz combinada a una matriz con valores numéricos para cada casilla según corresponda:
			Si es B = 1.
			Si es A = 0.
			Si es C = 0.5.
		Además en esta misma función, ser calculará el índice de similaridad que se calcula sumando todos los valores de la matriz combinada.

	2. Realizar la comparación mediante 2 imagenes ingresadas manualmente por el usuario, para este caso se crearán las siguiente funciones:
		- Función principal, que se encarga de declarar las matrices y ejecutar las funciones adicionales. Además en esta función 'main', el usuario ingresará el largo de las matrices.
		- 2 funciones que permita al usuario ingresar las matrices. El usuario deberá ingresar los carácteres 'B', 'A' o 'C' (Blanco, Azul o Celeste) para ir rellenando las matrices.
		- 2 funciones que impriman cada una de las matrices anteriormente ingresadas por el usuario. Esta función deberá imprimir las matrices, con cuadros del color que corresponda.
		- Función en la que ambas matrices ingresadas por el usuario se unan; para esto tendremos en cuenta que tan similares son cada casilla (ixj) con la de la otra matriz (ixj);
			Si son iguales.
			Si son diferentes.
			Si son semi-equivalente (celeste-blanco o celeste-azul).
		- Función en la que la matriz en la que se combinaron las imagenes ingresadas por el usuario, las casillas tendrán valores numericos segun corresponda;
			Si es B = 1.
			Si es A = 0.
			Si es C = 0.5.
		Además en esta misma función, ser calculará el índice de similaridad que se calcula sumando todos los valores de la matriz combinada.

Name: Funcion LeerImagen1
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Si se ha elegido la opcion de apertura mediante archivo, entonces la primera matriz se rellena con el texto que contenga la imagen1.txt.*/
void LeerImagen1(char I1[filas][columnas]){
	int i,j;
	char c;
	FILE * Imagen1 = fopen("imagen1.txt", "r"); //Abre un archivo del disco para lectura o escritura
	if(Imagen1 == NULL){ //Si no existe imagen_1
		printf("Archivo no valido\nRevise el nombre del archivo o si la ubicacion es correcta.\n");
		exit(2);
	}
	else{//Itera y crear la primera imagen
		for(i=0; i<filas; i++){
			for(j=0; j<columnas; j++){
				c = fgetc(Imagen1); //Un caracter de la cadena de texto de la imagen 1, avanza al siguiente caracter y repetir proceso.
				I1[i][j] = c;
				fflush(stdin);}
		}
	}
	fclose(Imagen1); //Cierra el archivo.
}
/* Name: Funcion LeerImagen2
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 19-12-22 23:39
Description: Si se ha elegido la opcion de apertura mediante archivo, entonces la primera matriz se rellena con el texto que contenga la imagen1.txt.*/
void LeerImagen2(char I2[filas][columnas]){
	int i,j;
	char c;
	FILE * Imagen2 = fopen("imagen2.txt", "r");
	if(Imagen2 == NULL){//Si no existe imagen_2
		printf("Archivo no valido\nRevise el nombre del archivo o si la ubicacion es correcta.\n");
		exit(2);
	}
	else{
		for(i=0; i<filas; i++){
			for(j=0; j<columnas; j++){
				fflush(stdin);
				c = fgetc(Imagen2);
				I2[i][j] = c;
				fflush(stdin);
			}
		}
	}
	fclose(Imagen2);
}
/* Name: Funcion ImprimirImagen
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Imprime la matrice en pantalla. Se utiliza una sola función para imprimir ambas ya que se cambia el parametro de entrada.*/
void ImprimirImagen(char I[filas][columnas]){
	int i,j;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int celeste=11, blanco= 15, azul=9, grisc=7; //Variable cuantitativa para el dato rastrer, uso de condicionales para colorear la posición segun los datos entregados.
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(I[i][j] == 'A'){ //Si la posicion contiene una 'A'.
				SetConsoleTextAttribute(hConsole, azul); //Asginar color especifico a un texto.
				printf("%c%c", 219, 219);
			}
			else if(I[i][j] == 'C'){//Si la posicion contiene una 'C'.
				SetConsoleTextAttribute(hConsole, celeste);
				printf("%c%c", 219, 219);
			}
			else if(I[i][j] == 'B'){//Si la posicion contiene una 'B'.
				SetConsoleTextAttribute(hConsole, blanco);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
		}
		printf("\n");
	}
}
/* Name: Funcion UnirImagenes
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Combina las imagenes en una sola matriz, teniendo en cuenta los grados de similitud que representa cada color. Imprime la matriz combinada.*/
void UnirImagenes(char I1[filas][columnas], char I2[filas][columnas], char I3[filas][columnas]){
	int i,j;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int celeste=11, blanco= 15, azul=9, grisc=7; //Variable cuantitativa para el dato rastrer, uso de condicionales para colorear la posición segun los datos entregados.
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(I1[i][j] == 'B'){ //Si posicion de la matriz 1 es 'B'
				if(I1[i][j] == I2[i][j]){ //Y si imagen 1 es igual a Matriz 2 en una posicion en especifico.
					I3[i][j] = 'B'; //Asignar a la tercera matriz el caracter 'B' en una posicion en especifico.
				}else if (I2[i][j] == 'A'){ //Si el valor que contiene en la posicion de la matriz dos es igual a 'A', asignar 'A' a la tercera imagen en una posicion en especifico.
					I3[i][j] = 'A';
				}else if (I2[i][j] == 'C'){ //Si el valor que contiene en la posicion de la matriz dos es igual a 'C', asignar 'C' a la tercera imagen en una posicion en especifico.
					I3[i][j] = 'C';
				}
			}else if(I1[i][j] == 'C'){ //Si posicion de la matriz 1 es 'C'
				if(I1[i][j] == I2[i][j]){ //Y si imagen 1 es igual a Matriz 2 en una posicion en especifico.
					I3[i][j] = 'B';
				}else if(I2[i][j] == 'B'){ //Si el valor que contiene en la posicion de la matriz dos es igual a 'B', asignar 'A' a la tercera imagen en una posicion en especifico.
					I3[i][j] = 'C';
				}else if(I2[i][j] == 'A'){
					I3[i][j] = 'C';
				}
			}else if(I1[i][j] == 'A'){
				if(I1[i][j] == I2[i][j]){ //Y si imagen 1 es igual a Matriz 2 en una posicion en especifico.
					I3[i][j] = 'B';
				}else if(I2[i][j] == 'B'){ //Si el valor que contiene la posicion de la matriz dos es igual a 'B', asignar 'A' a la tercera imagen en una posicion en especifico.
					I3[i][j] = 'A';
				}else if(I2[i][j] == 'C'){
					I3[i][j] = 'C';
				}
			}
		}
	}
	//Iterar y desplegar en pantalla el color del texto según el valor del caracter que se tenga en una posicion de la matriz_3/imagen_3.
	for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            if(I3[i][j] == 'C'){
				SetConsoleTextAttribute(hConsole, celeste);
            	printf("%c%c", 219, 219);
			}
			else if(I3[i][j] == 'A'){
				SetConsoleTextAttribute(hConsole, azul);
            	printf("%c%c", 219, 219);
			}
			else if(I3[i][j] == 'B'){
				SetConsoleTextAttribute(hConsole, blanco);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
        }
        printf("\n");
    }
    printf("\n");
}
/* Name: Funcion CalcularSimilitud
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Asigna a cada color su grado de similitud. Imprime una matriz con estos valores y calcula el índice de similaridad
(sumatoria de todos los valores).*/
void CalcularSimilitud(char I3[filas][columnas], float I4[filas][columnas]){
	int i,j;
	float suma=0; //Inicializar una variable auxiliar para contener el valor de la suma que es el total de la suma de valores ("pesos") asignados a cada caracter.
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(I3[i][j] == 'B'){ //Si el caracter es b, asignar 1 a la posicion.
				I4[i][j] = 1;
				suma+=I4[i][j];
			}
			else if(I3[i][j] == 'C'){
				I4[i][j] = 0.5;
				suma+=I4[i][j];
			}
			else if(I3[i][j] == 'A'){ // Si el valor es a, asignar 0 a la posicion.
				I4[i][j] = 0;
				suma+=I4[i][j];
			}
		}
	}
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int celeste=11, blanco= 15, azul=9, grisc=7;
	for(i=0; i<filas; i++){ //Imprimir matriz con sus respectivos pesos y asociados a un color en especifico en la rubrica entregada.
		for(j=0; j<columnas; j++){
			if(I4[i][j]==1){
    		SetConsoleTextAttribute(hConsole, blanco);
			printf("[%.1f]", I4[i][j]);
   			SetConsoleTextAttribute(hConsole, grisc);
			}
			if(I4[i][j]==0){
    		SetConsoleTextAttribute(hConsole, azul);
			printf("[%.1f]", I4[i][j]);
   			SetConsoleTextAttribute(hConsole, grisc);
			}
			if(I4[i][j]==0.5){
    		SetConsoleTextAttribute(hConsole, celeste);
			printf("[%.1f]", I4[i][j]);
    		SetConsoleTextAttribute(hConsole, grisc);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf(" %c Indice de similitud:\n\n",175);
	printf(" %.1f\n\n", suma); //Mostramos el indice de similitud mediante la variable suma.
    SetConsoleTextAttribute(hConsole, blanco); //Referencia.
	printf(" %c%c = 1\n", 219, 219);
	SetConsoleTextAttribute(hConsole, celeste);
	printf(" %c%c = 0.5\n", 219,219);
	SetConsoleTextAttribute(hConsole, azul);
	printf(" %c%c = 0\n", 219,219);
	SetConsoleTextAttribute(hConsole, grisc);
}
/* Name: Funcion CrearArchivo
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 20-12-22 02:16
Description: Crea un archivo donde se guarda la imagen comparativa.*/
void CrearArchivo(char I3[filas][columnas]){
	int i,j;
	FILE * ImagenesUnidas = fopen("ImagenComparativa.txt", "w"); //Crear un archivo que contiene las imagenes comparadas, mostrando la union de ambas y mostrando que tan parecidas son.
	if(ImagenesUnidas == NULL ){
		printf("El archivo no se pudo crear correctamente\nIntente nuevamente");
		exit(2);
	}
	else{
		for(i=0; i<filas; i++){
			for(j=0; j<columnas; j++){
				fprintf(ImagenesUnidas, "%c", I3[i][j]);  //Imprimir la imagen.
			}
		}
		printf("La imagen comparativa se ha guardado correctamente\n");
	}
	fclose(ImagenesUnidas);
}


/*Funciones de ingreso de imagenes manual.
Name: Funcion LeerMatriz1
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Lee la primera matriz ingresada manualmente por el usuario.*/
void LeerMatriz1(int max, char M1[max][max]){
	int i, j;
	printf(" %c Ingrese los valores de la primera matriz:\n", 175);
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			//printf("%d-%d",i,j);
			scanf("%c", &M1[i][j]); //Ingresar los caracteres a la primera matriz
			fflush(stdin);
		}
	}
}
/* Name: Funcion LeerMatriz2
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Lee la segunda matriz ingresada manualmente por el usuario.*/
void LeerMatriz2(int max, char M2[max][max]){
	int i, j;
	printf(" %c Ingrese los valores de la segunda matriz:\n", 175);
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			//printf("%d-%d",i,j);
			scanf("%c", &M2[i][j]);
			fflush(stdin); //Vaciar buffer.
		}
	}
}
/* Name: Funcion ImprimirMatriz1
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Imprime la primera matriz ingresada por el usuario.*/
void ImprimirMatriz1(int max, char M1[max][max]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i,j;
	int celeste=11, blanco= 15, azul=9, grisc=7; //Variable cuantitativa para el dato rastrer, uso de condicionales para colorear la posición segun los datos entregados.
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			if(M1[i][j] == 'A'){
				SetConsoleTextAttribute(hConsole, azul);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
			else if(M1[i][j] == 'C'){//Si el caracter es 'C' imprimir el color celeste para casilla.
				SetConsoleTextAttribute(hConsole, celeste);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
			else if(M1[i][j] == 'B'){
				SetConsoleTextAttribute(hConsole, blanco);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
		}
		printf("\n");
	}
	printf("\n");
}
/* Name: Funcion ImprimirMatriz2
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Imprime la segunda matriz ingresada por el usuario.*/
void ImprimirMatriz2(int max, char M2[max][max]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i,j;
	int celeste=11, blanco= 15, azul=9, grisc=7;
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			if(M2[i][j] == 'A'){
				SetConsoleTextAttribute(hConsole, azul); //Si el caracter es 'A' imprimir el color celeste para casilla.
				printf("%c%c", 219, 219);
			}
			else if(M2[i][j] == 'C'){
				SetConsoleTextAttribute(hConsole, celeste);
				printf("%c%c", 219, 219);
			}
			else if(M2[i][j] == 'B'){
				SetConsoleTextAttribute(hConsole, blanco);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
		}
		SetConsoleTextAttribute(hConsole, grisc);
		printf("\n");
	}
	printf("\n");
}
/* Name: Funcion UnirMatrices
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Combina las imagenes en una sola matriz, teniendo en cuenta los grados de similitud que representa cada color. Imprime la matriz combinada.*/
void UnirMatrices(int max, char M1[max][max], char M2[max][max],  char M3[max][max]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i,j;
	int celeste=11, blanco= 15, azul=9, grisc=7; 
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			if(M1[i][j] == 'C'){ //Si el caracter de una posicion en especifico es 'C' de la primera matriz, entonces
				if(M1[i][j] == M2[i][j]){ //Si el caracter de la posicion de la primera matriz es igual al de la segunda entonces
					M3[i][j] = 'C'; //Asignar 'C' a una posicion en especifico de la tercera matriz
				}else if (M2[i][j] == 'A'){ //Pero si el caracter de la segunda posicion es 'A', entonces
					M3[i][j] = 'C'; //Asignar 'C' a una posicion en especifico de la tercera matriz
					}else if (M2[i][j] == 'B'){ //Si el caracter de la segunda posicion es 'B', entonces
						M3[i][j] = 'C'; //Asignar 'C' a una posicion en especifico de la tercera matriz
					}

			}else if(M1[i][j] == 'B'){ //Si el caracter de una posicion en especifico es 'B' de la primera matriz, entonces
				if(M1[i][j] == M2[i][j]){ //Si el caracter de la posicion de la primera matriz es igual al de la segunda entonces
					M3[i][j] = 'B';
					}else if(M2[i][j] == 'C'){
						M3[i][j] = 'C';
					}else if(M2[i][j] == 'A'){ //Si el caracter de la segunda posicion es 'A', entonces
						M3[i][j] = 'A';  //Asignar 'A' a una posicion en especifico de la tercera matriz
					}
					
			}else if(M1[i][j] == 'A'){ //Si el caracter de una posicion en especifico es 'A' de la primera matriz, entonces
				if(M1[i][j] == M2[i][j]){ //Si el caracter de la posicion de la primera matriz es igual al de la segunda entonces
						M3[i][j] = 'B';
					}else if(M2[i][j] == 'C'){
						M3[i][j] = 'C';
					}else if(M2[i][j] == 'B'){
						M3[i][j] = 'A';
				}
			}
		}
	}

	for(i=0; i<max; i++){ //Iteracion y asignacion de color al texto segun sus caracteres
		for(j=0; j<max; j++){
			if(M3[i][j] == 'A'){
				SetConsoleTextAttribute(hConsole, azul);
				printf("%c%c", 219, 219);
			}
			else if(M3[i][j] == 'C'){
				SetConsoleTextAttribute(hConsole, celeste);
				printf("%c%c", 219, 219);
			}
			else if(M3[i][j] == 'B'){
				SetConsoleTextAttribute(hConsole, blanco);
				printf("%c%c", 219, 219);
				SetConsoleTextAttribute(hConsole, grisc);
			}
		}
		SetConsoleTextAttribute(hConsole, grisc);
		printf("\n");
	}
	printf("\n");
}
/* Name: Funcion MatrizNumerica
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Asigna a cada color su grado de similitud. Imprime una matriz con estos valores y calcula el índice de similaridad (sumatoria de todos los valores).*/
void MatrizNumerica(int max, char M3[max][max], float M4[max][max]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	int celeste=11, blanco= 15, azul=9, grisc=7;
	float suma;
	for(i=0; i<max; i++){
        for(j=0; j<max; j++){
            if(M3[i][j] == 'B'){
                M4[i][j]=1;
            }

            if(M3[i][j] == 'A'){
                M4[i][j]=0;
            }

            if(M3[i][j] == 'C'){
                M4[i][j]=0.5;
            }
        }
    }
    for(i=0; i<max; i++){
        for(j=0; j<max; j++){
            if(M4[i][j]==1){
    		SetConsoleTextAttribute(hConsole, blanco);
			printf("[%.1f]", M4[i][j]);
   			SetConsoleTextAttribute(hConsole, grisc);
			}
			if(M4[i][j]==0){
    		SetConsoleTextAttribute(hConsole, azul);
			printf("[%.1f]", M4[i][j]);
   			SetConsoleTextAttribute(hConsole, grisc);
			}
			if(M4[i][j]==0.5){
    		SetConsoleTextAttribute(hConsole, celeste);
			printf("[%.1f]", M4[i][j]);
    		SetConsoleTextAttribute(hConsole, grisc);
			}
        }
        SetConsoleTextAttribute(hConsole, grisc);
        printf("\n");
    }
    printf("\n");
    for(i=0; i<max; i++){
    	for(j=0; j<max; j++){
    		suma += M4[i][j];
		}
	}
	printf(" %c Indice de similaridad:\n\n", 175);
	printf(" %.1f\n\n", suma);
    SetConsoleTextAttribute(hConsole, blanco);
	printf(" %c%c = 1\n", 219, 219);
	SetConsoleTextAttribute(hConsole, celeste);
	printf(" %c%c = 0.5\n", 219,219);
	SetConsoleTextAttribute(hConsole, azul);
	printf(" %c%c = 0\n", 219,219);
	SetConsoleTextAttribute(hConsole, grisc);
}

/* Name: Funcion main
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Crear la imagen la cual es la union de ambas matrices de caracteres o archivo de texto.
*/
void CrearArchivo2(int max, char M3[max][max]){
	int i,j;
	FILE * ImagenesUnidas = fopen("ImagenesUnidas.txt", "w");
	if(ImagenesUnidas == NULL ){
		printf("El archivo no se pudo crear correctamente\n");
		printf("Intente nuevamente.\n");
		exit(1);
	}
	else{
		printf("La imagen comparativa se ha guardado correctamente\n");
		printf("En el archivo creado.\n");
		for(i=0; i<filas; i++){
			for(j=0; j<columnas; j++){
				fprintf(ImagenesUnidas, "%c", M3[i][j]);
				fflush(stdin);
			}
		}
	}
	fclose(ImagenesUnidas);
}
/* Name: Funcion main
Copyright: GNU
Author: Felipe Acuña. Benjamín Cisternas. Matías González.
Date: 17-12-22 16:30
Description: Función principal que despliega un menú para seleccionar el método de lectura de imagenes. Se encarga de llamar a las demás funciones.*/
int main() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i,j;
	int celeste=11, blanco= 15, azul=9, grisc=7, morado=5;
	int opcion, imagenc;
	sleep(1);
	SetConsoleTextAttribute(hConsole, morado);
	printf("----------------------------------------------------------\n");
	printf("|");
	SetConsoleTextAttribute(hConsole, grisc);
	printf("  Ingrese el metodo de lectura de imagenes desea usar:  ");
	SetConsoleTextAttribute(hConsole, morado);
	printf("|\n");
	printf("|                                                        |\n");
	printf("| ");
	SetConsoleTextAttribute(hConsole, grisc);
	printf("1.- Mediante lectura de archivo                        ");
	SetConsoleTextAttribute(hConsole, morado);
	printf("|\n");
	printf("| ");
	SetConsoleTextAttribute(hConsole, grisc);
	printf("2.- Mediante ingreso manual                            ");
	SetConsoleTextAttribute(hConsole, morado);
	printf("|\n");
	printf("|                                                        |\n");
	printf("----------------------------------------------------------\n");
	SetConsoleTextAttribute(hConsole, grisc);
	do{
		printf("\nOpcion a ingresar: ");
		scanf("%d", &opcion);
		if(opcion != 1 && opcion != 2){
			printf("Ingrese una opcion valida ( 1 - 2 )\n");
		}
	}while(opcion != 1 && opcion != 2);
	
	if(opcion==1){
		sleep(1);
		printf("\n %c Ha seleccionado la opcion de lectura de archivo\n\n", 175);
		sleep(2);
		printf(" %c Recuerde que los archivos de las imagenes deben contener:\n\n", 175);
		printf("    - Nombres de los archivos: imagen1.txt - imagen2.txt\n");
		printf("    - Deben encontrarse en la misma carpeta que el programa\n");
		printf("    - La imagen debe estar escrita de izquierda a derecha\n");
		printf("    - Con las siguientes referencias:\n");
		printf("    - Blanco ( B ) - Celeste ( C ) - Azul ( A )\n\n");
		sleep(2);

		char I1[filas][columnas];
		char I2[filas][columnas];
		char I3[filas][columnas];
		float I4[filas][columnas];

		sleep(1);
		printf(" %c Leyendo los archivos ingresados...\n", 175);
		sleep(3);

		LeerImagen1(I1);
		LeerImagen2(I2);

		printf("\n %c Sus archivos han sido leidos correctamente.\n", 175);
		sleep(1);
		printf("   %c Imprimiendo las imagenes leidas...\n\n", 175);
		sleep(2);
		printf(" %c Imagen 1:\n\n", 175);
		ImprimirImagen(I1);
		sleep(1);
		printf("\n %c Imagen 2:\n\n", 175);
		ImprimirImagen(I2);
		sleep(1);
		printf("\n %c A continuacion, se uniran ambas imagenes y se calculara la similitud\n\n", 175);
		sleep(2);
		printf(" %c Imagenes unidas:\n\n", 175);
		UnirImagenes(I1,I2,I3);
		sleep(1);
		printf(" %c Matriz de las imagenes con sus grados de similitud: \n\n", 175);
		CalcularSimilitud(I3,I4);
		sleep(1);
		printf("Desea guardar la imagen comparativa en un archivo?\n");
		do{
		printf("1 = Si\n2 = No\n");
		scanf("%d", &imagenc);
			if(imagenc== 1)
				CrearArchivo(I3);
		}while(imagenc!=1 && imagenc!=2);
	}
	else if(opcion==2){
		int max;
		printf("\n %c Ha seleccionado el ingreso manual de las imagenes.\n\n", 175); //Pedimos el largo de la matriz
		sleep(1);
		do{
			printf(" %c Ingrese el largo de su matriz cuadrada:\n", 175);
			scanf(" %d", &max);
			fflush(stdin);
			if(max<1){
				printf("%c Ingrese un numero mayor que 0\n", 175);
			}
		}while (max<1);
		SetConsoleTextAttribute(hConsole, morado); //Printeamos la información necesaria que deberia saber el usuario
		printf("-----------------------------------------------------------------\n");
		printf("|");
		SetConsoleTextAttribute(hConsole, grisc);
		printf(" Ingrese los valores de la matriz con caracteres en mayusculas ");
		SetConsoleTextAttribute(hConsole, morado);
		printf("|\n");
		printf("|");
		SetConsoleTextAttribute(hConsole, grisc);
		printf(" Blanco ( B ) - Celeste ( C ) - Azul ( A ) ]                   ");
		SetConsoleTextAttribute(hConsole, morado);
		printf("|\n");
		printf("-----------------------------------------------------------------\n");
		SetConsoleTextAttribute(hConsole, grisc);

		char M1[max][max]; //Definimos Matrices (Imágenes)
		char M2[max][max];
		char M3[max][max];
		float M4[max][max];
		
		LeerMatriz1(max, M1); //Funciones para leer ambas matrices
		LeerMatriz2(max, M2);
		sleep(2);
		printf("\n %c Imprimiendo las imagenes ingresadas...\n\n", 175);
		sleep(3);
		printf(" %c Imagen 1:\n\n", 175);
		ImprimirMatriz1(max, M1); //Funciones para Imprimir ambas matrices
		printf(" %c Imagen 2:\n\n", 175);
		ImprimirMatriz2(max, M2);
		sleep(1);
		printf(" %c A continuacion, se uniran ambas imagenes y se calculara la similitud\n\n", 175);
		sleep(2);
		printf(" %c Imagenes unidas:\n\n", 175);
		UnirMatrices(max, M1, M2,M3); //Funcion para unir la Primera y Segunda matriz en una sola e imprimir la tercera matriz
		sleep(1);
		printf(" %c Matriz de las imagenes con sus grados de similitud: \n\n", 175);
		MatrizNumerica(max, M3, M4); //Asignacion de valores numericos a la nueva matriz para calcular el indice de similitud
		sleep(1);
		printf("Desea guardar la imagen comparativa en un archivo?\n");
		do{
		printf("1 = Si\n2 = No\n");
		scanf("%d", &imagenc);
			if(imagenc== 1)
				CrearArchivo2(max, M3);
		}while(imagenc!=1 && imagenc!=2);
	}

	return 0;
}

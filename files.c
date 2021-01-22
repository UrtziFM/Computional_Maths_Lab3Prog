/*
Implementa un algoritmo que se encarguen de abrir, leer, almacenar y modificar la información de un archivo secuencial en el que se almacena información de los libros de una biblioteca.
La información de cada uno de los libros que se tiene que almacenar es: Titulo, Autor, Editorial, Año de Edicion, ISBN y Numero de Paginas
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h>
#include <string.h>

#define LIBRARY "books.txt"
#define length 100

//Defining neccesary structures 
typedef struct book {
    int reference;
    char title[length];
    char writer[length];
    char publishingHouse[length];
    int year;
    long ISBN;
    int pages;
} Book;

void mainMenu();
void insertMenu();
void deleteMenu();
void modifyMenu();
void searchMenu();

/* Funciones para manejar el archivo directamente */
Book *getBook(int *n); /* Obtiene un vector dinámico de productos */
char validateBook(int referenceBook, Book *book); /* Busca si existe el producto en el archivo de productos */
char insertBook(Book book); /* Inserta el producto al final del archivo */
char deleteBook(int referenceBook); /* Eliminar el producto de código codigoProducto del archivo */
char modifyBook(Book book); /* Modifica el producto en el archivo */
 

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {

    int option;
 
        do {
    
            printf("\nMain Menu\n");
            printf("\n[1]. Create a New Book\n");
            printf("\n[2]. Show Library\n");
            printf("\n[3]. Modify a Book\n");
            printf("\n[4]. Delete a Book\n");
            printf("\n[5]. Exit\n");
            printf("\nInsert here your option: [ ]\n");
            scanf("%d", &option);
    
            switch (option) {
    
                case 1:
                    insertMenu();
                    break;
    
             //   case 2:
             //       showBooks();
             //       break;
    
               // case 3:
                 //   modifyBook();
                   // break;
    
                //case 4:
                  //  deleteBook();
                   // break;
    
            } 
        }while (option != 5);
}

void insertMenu(){
	Book book;
	int referenceBook = 0;
 
            /* Se pide el código del producto a insertar */
            printf("\nBook Reference: ");
            scanf("%d", &referenceBook);
    
            /* Se verifica que el producto no haya sido almacenado anteriormente */
            if (!validateBook(referenceBook, &book)) {
    
                book.reference = referenceBook;
    
                /* Se piden los demás datos del producto a insertar */
                printf ("\nIntroduce Book's Title:\n");
                    fgets (book.title, length, stdin);
                printf ("\nIntroduce Book's Writer:\n");
                    fgets (book.writer, length, stdin);
                printf ("\nIntroduce Book's Publishing House:\n");
                    fgets (book.publishingHouse, length, stdin);
                printf ("\nIntroduce Book's Year:\n");
                    scanf("%d", &book.year);
                printf ("\nIntroduce Book's ISBN:\n");
                    scanf("%ld", &book.ISBN);
                printf ("\nIntroduce Book's pages:\n");
                    scanf("%d", &book.pages);
    
                /* Se inserta el producto en el archivo */
                if (insertBook(book)) {
                    printf("\nThe book has been added correctly\n");
    
                } else {
                    printf("\nSomething goes wrong, sorry\n");
                }
            } else {
                /* El producto ya existe, no puede ser insertado. */
                printf("\nThis book reference %d already exist.\n", referenceBook);
            }
}

char validateBook(int referenceBook, Book *book)
{
	FILE *file;
	char exist;
 
	/* Abre el archivo en modo lectura */
	file = fopen("books.txt", "rb");
 
	if (file == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		exist = 0;
 
	} else {
		exist = 0;
 
		/* Se busca el producto cuyo código coincida con codigoProducto */
		fread(&(*book), sizeof(*book), 1, file);
		while (!feof(file)) {
			if ((*book).reference == referenceBook) {
				exist = 1;
				break;
			}
			fread(&(*book), sizeof(*book), 1, file);
		}
 
		/* Cierra el archivo */
		fclose(file);
	}
 
	return exist;
}
 

char insertBook(Book book) {
	FILE *file;
	char insert;
 
	/* Abre el archivo para agregar datos al final */
	file = fopen("books.txt", "ab");	/* Añade datos al final. Si el archivo no existe, es creado */
 
	if (file == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		insert = 0;
 
	} else {
		fwrite(&book, sizeof(book), 1, file);
		insert = 1;
 
		/* Cierra el archivo */
		fclose(file);
	}
 
	return insert;
}
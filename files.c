/*
Implementa un algoritmo que se encarguen de abrir, leer, almacenar y modificar la información de un archivo secuencial en el que se almacena información de los libros de una biblioteca.
La información de cada uno de los libros que se tiene que almacenar es: Titulo, Autor, Editorial, Año de Edicion, ISBN y Numero de Paginas
*/

#include <stdio.h>
#include <stdlib.h>

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

void createBook() {
    Book b[10] = {
    for (i = 0; i < 10; i++){
        printf ("\nIntroduce Book's Title:\n");
            fgets (b[i].title, length, stdin);
        printf ("\nIntroduce Book's Writer:\n");
            fgets (b[i].writer, length, stdin);
        printf ("\nIntroduce Book's Publishing House:\n");
            fgets (b[i].publishingHouse, length, stdin);
        printf ("\nIntroduce Book's Year:\n");
            scanf("%d", &b[i].year);
        printf ("\nIntroduce Book's ISBN:\n");
            scanf("%ld", &b[i].ISBN);
        printf ("\nIntroduce Book's pages:\n");
            scanf("%d", &b[i].pages);
       while(getchar() != '\n'); // cleaning entry buffer
        }
    }
    
    FILE *pf = fopen(LIBRARY, "ab");
    if (pf) {
        fwrite(b, sizeof(Book), 10, pf);
        fclose(pf);
    }
}

void readBook() {
    Book book;
    FILE *pf = fopen(LIBRARY, "rb");
    if (pf) {
        while (fread(&book, sizeof(Book), 1, pf)) {
            printf ("Reference: %d\n\tTitle: %s\n\tWriter: %s\n\tPublishing House: %s\n\tYear: %d\n\tISBN: %ld\n\tPages: %d\n\t\n",
                    book.reference,
                    book.title,
                    book.writer,
                    book.publishingHouse,
                    book.year,
                    book.ISBN,
                    book.year);
        }
    }
}

int main() {
    createBook();
    // Mostramos el contenido que ha quedado guardado:
    readBook();
    return 0;
}
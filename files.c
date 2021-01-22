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
    long ISBN[10];
    char title[length];
    char writer[length];
    char publishingHouse[length];
    int year[4];
    int pages[5];
} Book;

//Defining main functions
void mainMenu();
void showMenu();
void insertMenu();
void modifyMenu();
void deleteMenu();

//Defining handling functions
Book *getBook(int *n); //it gets a book from vector
char validateBook(int referenceBook, Book *book); //validate if reference exist
char insertBook(Book book); //insert the book
char deleteBook(int referenceBook); 
char modifyBook(Book book); 
 

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {

    int option;
 
        do {
    
            printf("\nMain Menu\n");
            printf("\n[1]. Show Library\n");
            printf("\n[2]. Create a New Book\n");
            printf("\n[3]. Modify a Book\n");
            printf("\n[4]. Delete a Book\n");
            printf("\n[5]. Exit\n");
            printf("\nInsert here your option: [ ]\n");
            scanf("%d", &option);
    
            switch (option) {
    
                case 1:
                    showMenu();
                    break;
    
                case 2:
                    insertMenu();
                    break;
    
                case 3:
                    modifyMenu();
                    break;
    
                case 4:
                    deleteMenu();
                    break;
    
            } 
        }while (option != 5);
}

void showMenu() {
	Book *books;
	int totalBooks;
 
	books = getBook(&totalBooks); 
 
	if (totalBooks == 0) {
		printf("\nThis file is empty\n");
		getchar();
 
	} else {
		/* Se recorre el vector dinámico de productos */
		for (int i = 0; i < totalBooks; i++) {
			if (books[i].reference != -1) {
				printf("%d %s %s %s \n", books[i].reference, books[i].title, books[i].writer, books[i].publishingHouse);
                printf("%d", books[i].year);
			}
		}
	}
}
 

void insertMenu(){
	Book book;
	int referenceBook = 0;
 
            printf("\nBook Reference: ");
            scanf("%d", &referenceBook);
    
            if (!validateBook(referenceBook, &book)) {
    
                book.reference = referenceBook;
    
                printf ("\nIntroduce Book's ISBN:\n");
                    scanf("%ld", book.ISBN);
                while(getchar() != '\n'); // cleaning entry buffer
                printf ("\nIntroduce Book's Title:\n");
                    fgets (book.title, length, stdin);
                    book.title[strcspn(book.title, "\r\n")]= 0; // this function avoid line break of fgets
                printf ("\nIntroduce Book's Writer:\n");
                    fgets (book.writer, length, stdin);
                    book.writer[strcspn(book.writer, "\r\n")]= 0; // this function avoid line break of fgets
                printf ("\nIntroduce Book's Publishing House:\n");
                    fgets (book.publishingHouse, length, stdin);
                    book.publishingHouse[strcspn(book.publishingHouse, "\r\n")]= 0; // this function avoid line break of fgets
                printf ("\nIntroduce Book's Year:\n");
                    scanf("%d", book.year);
                while(getchar() != '\n'); // cleaning entry buffer
                printf ("\nIntroduce Book's pages:\n");
                    scanf("%d", book.pages);
                while(getchar() != '\n'); // cleaning entry buffer
    
                if (insertBook(book)) {
                    printf("\nThe book has been added correctly\n");
    
                } else {
                    printf("\nSomething goes wrong, sorry\n");
                }
            } else {
                printf("\nThis book reference %d already exist.\n", referenceBook);
            }
}

void deleteMenu() {
	Book book;
	int referenceBook;
 
		printf("\nBook Reference: ");
		scanf("%d", &referenceBook);
 
		if (validateBook(referenceBook, &book)) {
            if(deleteBook(referenceBook)){
                printf("\nThis reference book has been deleted: %d\n", referenceBook);
            } else {
			    printf("\nThis reference book it can't be deleted\n");
            }
		} else {
			printf("\nThis reference %d book doesn't exist.\n", referenceBook);
		}
}

void modifyMenu() {
    Book book;
	int referenceBook;
 
		printf("\nCódigo de producto: ");
		scanf("%d", &referenceBook);
 
		if (validateBook(referenceBook, &book)) {
 
            printf("\nInsert here new ISBN \n");
            scanf("%ld", book.ISBN);
            while(getchar() != '\n'); // cleaning entry buffer
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
			printf("\nInsert here new title\n");
            fgets (book.title, length, stdin);
            book.title[strcspn(book.title, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new writer\n");
            fgets (book.writer, length, stdin);
            book.writer[strcspn(book.writer, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new publishing house\n");
            fgets (book.publishingHouse, length, stdin);
            book.publishingHouse[strcspn(book.publishingHouse, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new year\n");
            scanf("%d", book.year);
            while(getchar() != '\n'); // cleaning entry buffer
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new pages \n");
            scanf("%d", book.pages);
            while(getchar() != '\n'); // cleaning entry buffer
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
		} else {
			printf("\nThis reference %d book doesn't exist.\n", referenceBook);
		}
}
	
 

char validateBook(int referenceBook, Book *book) {
	FILE *file;
	char exist;
 
	file = fopen("books.txt", "rb");
 
	if (file == NULL) { 
		exist = 0;
	} else {
		exist = 0;
 
		fread(&(*book), sizeof(*book), 1, file);
		while (!feof(file)) {
			if ((*book).reference == referenceBook) {
				exist = 1;
				break;
			}
			fread(&(*book), sizeof(*book), 1, file);
		}
 		fclose(file);
	}
	return exist;
}
 
char insertBook(Book book) {
	FILE *file;
	char insert;
 
	file = fopen("books.txt", "ab");	
 
	if (file == NULL) { 
		insert = 0;
 
	} else {
		fwrite(&book, sizeof(book), 1, file);
		insert = 1;

		fclose(file);
	}
 
	return insert;
}

char deleteBook(int referenceBook) {
	FILE *file;
	FILE *aux;
	Book book;
	char del;
 
	file = fopen("books.txt", "r+b");	
 
	if (file == NULL) { 
		del = 0;
 
	} else {
		del = 0;
		fread(&book, sizeof(book), 1, file);
		while (!feof(file)) {
			if (book.reference == referenceBook) {
				fseek(file, ftell(file) - sizeof(book), SEEK_SET);
				book.reference = -1;
				fwrite(&book, sizeof(book), 1, file);
				del = 1;
				break;
			}
			fread(&book, sizeof(book), 1, file);
		}

		fclose(file);
	}
 
	return del;
}

char modifyBook(Book book) {
	FILE *file;
    Book booky;
	char modify;
 
	file = fopen("books.txt", "rb+");
 
	if (file == NULL) { 
		modify = 0;
 
	} else {
		modify = 0;
		fread(&booky, sizeof(booky), 1, file);
		while (!feof(file)) {
			if (booky.reference == book.reference) {
				fseek(file, ftell(file) - sizeof(book), SEEK_SET);
				fwrite(&book, sizeof(book), 1, file);
				modify = 1;
				break;
			}
			fread(&booky, sizeof(booky), 1, file);
		}
 
		fclose(file);
	}
 
	return modify;
}

Book *getBook(int *n) {
	FILE *file;
	Book book;
	Book *books; 
	int i;
 
	file = fopen("books.txt", "rb");
 
	if (file == NULL) { 
		*n = 0; 
		books = NULL;
 
	} else {
 
		fseek(file, 0, SEEK_END); 
		*n = ftell(file) / sizeof(Book); 
		books = (Book *)malloc((*n) * sizeof(Book)); 
 
		fseek(file, 0, SEEK_SET); 
		fread(&book, sizeof(book), 1, file);
		i = 0;
		while (!feof(file)) {
			books[i++] = book;
			fread(&book, sizeof(book), 1, file);
		}
 
		fclose(file);
	}
 
	return books;
}
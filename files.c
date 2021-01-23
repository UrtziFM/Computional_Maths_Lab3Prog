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
 

int main() { //simple main function, we are using defined functions to interact with user requirements
    mainMenu();
    return 0;
}

void mainMenu() {  //this user interface

    int option;
 
        do {  //getting user selection 
    
            printf("\nMain Menu\n");
            printf("\n[1]. Show Library\n");
            printf("\n[2]. Create a New Book\n");
            printf("\n[3]. Modify a Book\n");
            printf("\n[4]. Delete a Book\n");
            printf("\n[5]. Exit\n");
            printf("\nInsert here your option: [ ]\n\n");
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
        }while (option != 5); // exit when option is 5
}

void showMenu() { // we are getting books
	Book *books; // it is a vector
	int totalBooks; // we define a variable to know if there is any book in the vector 
 
	books = getBook(&totalBooks); //calling handling function to get books
 
	if (totalBooks == 0) {
		printf("\nThis file is empty\n");
		getchar();
 
	} else {
		for (int i = 0; i < totalBooks; i++) { //showing each book information 
			if (books[i].reference != -1) {
				printf("\nReference: %d \n\tISBN: %ld \tTitle:%s\n", books[i].reference, *books[i].ISBN, books[i].title);
				printf("\tWriter:%s \tPublishingHouse:%s\n" , books[i].writer, books[i].publishingHouse);
                printf("\tYear:%d \tPages:%d\n", *books[i].year, *books[i].pages);
			}
		}
	}
}
 

void insertMenu(){  // we are introducing a book
	Book book;
	int referenceBook = 0; // this is going to be the variable for book's reference 
 
            printf("\nBook Reference: ");
            scanf("%d", &referenceBook);
    
            if (!validateBook(referenceBook, &book)) { // we are calling to handling function to validate if this reference already exist
    
                book.reference = referenceBook; // we identify user reference with the structure
    
                printf ("\nIntroduce Book's ISBN [10 digits]:\n");
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
                printf ("\nIntroduce Book's Year [4 digits]:\n");
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

void deleteMenu() {  // It wasn't in the exercise requirements but it is helpful to manage a Library
	Book book;
	int referenceBook;
 
		printf("\nBook Reference: ");
		scanf("%d", &referenceBook);
 
		if (validateBook(referenceBook, &book)) {  // we are calling to handling function to validate if this reference already exist
            if(deleteBook(referenceBook)){  // we are calling to handling function to delete a book
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
 
		if (validateBook(referenceBook, &book)) { // we are calling to handling function to validate if this reference already exist
 
            printf("\nInsert here new ISBN or old again\n");
            scanf("%ld", book.ISBN);
            while(getchar() != '\n'); // cleaning entry buffer
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
			printf("\nInsert here new title or old again\n");
            fgets (book.title, length, stdin);
            book.title[strcspn(book.title, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new writer or old again\n");
            fgets (book.writer, length, stdin);
            book.writer[strcspn(book.writer, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new publishing house or old again\n");
            fgets (book.publishingHouse, length, stdin);
            book.publishingHouse[strcspn(book.publishingHouse, "\r\n")]= 0; // this function avoid line break of fgets
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new year or old again\n");
            scanf("%d", book.year);
            while(getchar() != '\n'); // cleaning entry buffer
			if (modifyBook(book)) {
					printf("\nDone\n");
				} else {
                    printf("Impossible to modify");
                }
            printf("\nInsert here new pages or old again \n");
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
	
 

char validateBook(int referenceBook, Book *book) { // defining handling function to validate if this reference already exist
	FILE *file;
	char exist;
 
	file = fopen("books.txt", "rb"); //opening file
 
	if (file == NULL) { //handling if the file exist or not
		exist = 0;
	} else {
		exist = 0;
 
		fread(&(*book), sizeof(*book), 1, file); //reading file
		while (!feof(file)) {
			if ((*book).reference == referenceBook) { // here is where we are validating if the book exist or not
				exist = 1;
				break;
			}
			fread(&(*book), sizeof(*book), 1, file);
		}
 		fclose(file); // always we have to close file if we have opened it, better to avoid mistakes
	}
	return exist; // now we know if this reference exist or not
}
 
char insertBook(Book book) {  // defining handling function to insert a book
	FILE *file;
	char insert;
 
	file = fopen("books.txt", "ab"); //opening file
 
	if (file == NULL) { // if the file doesn't exist we can insert anything, we can't open
		insert = 0; 
 
	} else {
		fwrite(&book, sizeof(book), 1, file); // writing file 
		insert = 1;

		fclose(file); // always we have to close file if we have opened it, better to avoid mistakes
	}
 
	return insert;
}

char deleteBook(int referenceBook) { // defining handling function to delete a book
	FILE *file;
	Book book;
	char del;
 
	file = fopen("books.txt", "r+b");	
 
	if (file == NULL) { //handling if the file exist or not
		del = 0;
 
	} else {
		del = 0;
		fread(&book, sizeof(book), 1, file);
		while (!feof(file)) {
			if (book.reference == referenceBook) {
				fseek(file, ftell(file) - sizeof(book), SEEK_SET); // we are getting first pointer in the file and the position of it
				book.reference = -1;
				fwrite(&book, sizeof(book), 1, file);
				del = 1;
				break;
			}
			fread(&book, sizeof(book), 1, file);
		}

		fclose(file); // always we have to close file if we have opened it, better to avoid mistakes
	}
 
	return del;
}

char modifyBook(Book book) { // defining handling function to delete a book
	FILE *file;
    Book booky; // defining the modified book 
	char modify;
 
	file = fopen("books.txt", "rb+");
 
	if (file == NULL) { //handling if the file exist or not
		modify = 0;
 
	} else {
		modify = 0;
		fread(&booky, sizeof(booky), 1, file);
		while (!feof(file)) {
			if (booky.reference == book.reference) {
				fseek(file, ftell(file) - sizeof(book), SEEK_SET); // we are getting first pointer in the file and the position of it
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

Book *getBook(int *n) { //getting a book from the vector
	FILE *file;
	Book book;
	Book *books; 
	int i;
 
	file = fopen("books.txt", "rb");
 
	if (file == NULL) { //handling if the file exist or not
		*n = 0; 
		books = NULL;
 
	} else {
 
		fseek(file, 0, SEEK_END); // we are getting first pointer in the file and the position of it
		*n = ftell(file) / sizeof(Book); 
		books = (Book *)malloc((*n) * sizeof(Book)); 
 
		fseek(file, 0, SEEK_SET); // we are getting first pointer in the file and the position of it
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
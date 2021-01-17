// Defining all libraries we are going to use and inside them which functions (I Have learnt it is helpful to know what it for, where it comes from)
#include <string.h>  // strcpy() interesting library for handle string
#include <ctype.h> // strcasecmp () useful librayu for handle capital letters issue ordering
#include <stdio.h>      // printf()
#include <math.h>       // ceil()
#include <stdlib.h>     // rand(), srand()
#include <time.h>       // time()

// Definition of rows and columns size (3 x 3) of matrix
#define rows 3 // First exercise Matrix rows
#define colms 3 // Fisrt exercise Matriz columns
#define length 30 // Second exercise 
#define length_w 20 // Third exercise
#define n_words 10 // Third exercise total words

//Defining neccesary structures 
typedef struct address {
    char country[length];
    char city[length];
    char street[length];
    int number;
    int flat;
    char letter[length];
} Address;

// nested structure
typedef struct person {
    char name[length];
    char surname1[length];
    char surname2[length];
    int age;
    struct address address_person;
} Person;

struct person p; // we use p instance here

// Third exercise structure
typedef struct abcde {
    char word[length_w];
} Abcde;

struct abcde w[length_w]; // we use w instance here and a pointer to keep memory space

// Global variables for exercises

double matrixA[rows][colms];
double matrixB[rows][colms];
char option1;

char aux[length_w]; // auxiliar string

int Array_Max;
int tallTree;
int i,j;
char option; // this is a exercise selector 
char option1; // this is a calculator operation selector

// Global definition of functions which are going to used then to make operations
// Remember we are using real numbers so, we need define functions variables as double

void matrixUser (double [rows][colms]); // this is the function which ask to the user the matrix 
void showMatrix (double [rows][colms]); // this the function which will show to the user selected matrix
void sumMatrix (double [rows][colms], double [rows][colms]); // this the function which will sum both matrix
void restMatrix (double [rows][colms], double [rows][colms]); // this the function which will rest both matrix
void prodMatrix (double [rows][colms], double [rows][colms]); // this the function which will get the product both matrix
void showPerson (struct person); // this the function which will print user given personal information

void printTree(char* matrix , int m, int n){ // Global function, it prints our tree matrix 
    for (int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            printf("%c", *(matrix + i*Array_Max + j));
        }
        printf("\n");
    }
}


int main() {

     do {
        printf( "--Choose an exercise to review-- \n\n" );
        printf( "1. exercise \n");
        printf( "2. exercise \n");
        printf( "3. exercise \n");
        printf( "4. exercise \n");
        printf( "5) Exit \n\n" );

        do {
            printf( "Introduce an exercise (1-5): \n\n"); // Filter user choosen operation
            scanf( " %c", &option);

        } while ( option < '1' || option > '5' ); // It has to be between 1-6

         switch ( option ){

             case '1':  
                        // Asking the user first matrix
                        printf("\nPlease, Enter your first matrix of 3 rows and columns \n");
                        matrixUser(matrixA);
                        // Asking the user second matrix
                        printf("Please, Enter your second matrix of 3 rows and columns \n");
                        matrixUser(matrixB);
                        // Showing to the user selected matrix A & B 
                        showMatrix(matrixA);
                        showMatrix(matrixB);
    
                                do {
                                    printf( "\n--Choose an operation to do-- \n\n" );
                                                printf( "1) Sum two matrix \n");
                                                printf( "2) Rest two matrix \n");
                                                printf( "3) Multiply two matrix \n");
                                                printf( "4) Exit \n\n" );
                                    do {
                                        printf( "Introduce an option (1-4): \n"); // Filter user choosen operation
                                        scanf( " %c", &option1);
                                        } while ( option1 < '1' || option1 > '4' ); // It has to be between 1-4
                                    
                                    switch ( option1 ){

                                        case '1':  // Matrix's Sum
                                                    printf("\n This is the sum of your selected matrix \n");
                                                    sumMatrix(matrixA, matrixB);
                                                    break;
                                        case '2':  // Matrix' Rest
                                                    printf("\n This is the rest of your selected matrix \n");
                                                    restMatrix(matrixA, matrixB);
                                                    break;
                                        case '3':   // Matrix' product
                                                    printf("\n This is the product of your selected matrix \n");
                                                    prodMatrix(matrixA, matrixB);
                                        } 
                                    } while ( option1 != '4' ); // Option 4: exit from the matrix operation machine
                                    break;

             case '2': 
                        // Asking user personal information
                        printf( "\nPlease, introduce your name here: \n" );
                        fgets(p.name, 30, stdin); // as there is a scanf() in the first exercise, we are letting in the in stream the previous blank (repeat function is a trick)
                        fgets(p.name, 30, stdin); // better use fgets function here to avoid blanks in some names 
                        p.name[strcspn(p.name, "\r\n")]= 0; // this function avoid line break of fgets
                        printf( "Please, introduce your first surname here: \n" );
                        fgets(p.surname1, 30, stdin);
                        p.surname1[strcspn(p.surname1, "\r\n")]= 0;
                        printf( "Please, introduce your second surname here: \n" );
                        fgets(p.surname2, 30, stdin);
                        p.surname2[strcspn(p.surname2, "\r\n")]= 0;
                        printf( "Please, introduce your country: \n" );
                        fgets(p.address_person.country, 30, stdin ); // we nesting in the structures of person and address
                        p.address_person.country[strcspn(p.address_person.country, "\r\n")]= 0;
                        printf( "Please, introduce your city: \n" );
                        fgets(p.address_person.city, 30, stdin); 
                        p.address_person.city[strcspn(p.address_person.city, "\r\n")]= 0;
                        printf( "Please, introduce your street: \n" );
                        fgets(p.address_person.street, 30, stdin);
                        p.address_person.street[strcspn(p.address_person.street, "\r\n")]= 0;
                        printf( "Please, introduce your street number: \n" );
                        scanf( " %d", &p.address_person.number );
                        printf( "Please, introduce your flat number: \n" );
                        scanf( " %d", &p.address_person.flat );
                        printf( "Please, introduce your flat letter: \n" );
                        scanf( " %s", p.address_person.letter );
                        printf( "Please, introduce your age here: \n" );
                        scanf( " %d", &p.age );

                        showPerson(p); //calling function with the instance
                        break;

              case '3':
                        // Asking user 10 words

                        //Now we need a bucle for to get user's ten words:
                        for (int i = 0; i < 10; i++) {
                            printf("\nPlease introduce your %i word here: ", i+1);
                            scanf(" %s", w[i].word);

                            while(getchar() != '\n'); // cleaning entry buffer

                        }

                        // Now we are going to order our words/strings
                        int total_words = n_words; // ten words
                        int i, j, k; // define different counters
                        int lowercase; //variable for comparaing lowercase
                        for(i = 0; i < total_words-1; i++) { // initiate burble 
                            
                            k=i;
                            strcpy(aux, w[i].word); // function to copy temporaly in auxiliar string our words, handling transitions 
                            for(j=i+1; j<total_words; j++) {
                                lowercase = strcasecmp(w[j].word, aux); // great function to handle capital letters problems
                                if(lowercase < 0) {
                                    k=j;
                                    strcpy(aux, w[j].word);
                                }
                            }
                            strcpy(w[k].word,w[i].word);
                            strcpy(w[i].word,aux);
                        }

                        for (i = 0; i < total_words; i++) {
                            printf("The word %i is %s \n", i, w[i].word); // now iterating to show ordered words

                        } break;
                 
                 case '4': 
                            //Drawing a Christmas Tree
                            srand(time(NULL)); // We are reactivating random lights with this seed function, avoiding repeating in each try from user get the same output

                            do {
                                printf ("\nHello user! Give me a number over 3 and I will drawn a christmas tree for you \n");
                                scanf ("%d", &tallTree); //reading user inputs
                                } while (tallTree < 3); //at least we need 4 levels to draw correctly a christmas tree 

                            int trunkTree = ceil((double)(tallTree)/4); // using ceil function we are helping to have correct dimensions of the trunk, easier than in the first lab. 
                            int totalTree  = tallTree + trunkTree;
                            int widthTree = 2*tallTree-1; // we can use maths to calculate width and tall proportional relationship in a tree.
                            
                            char tree[totalTree][widthTree]; // this is a our matrix, initializated without prefixed rows and columns, as it was asked in the last class 
                            Array_Max = widthTree;

                                for (i = 0; i < tallTree; i++) { 

                                    for(j = 0; j < widthTree; j++ ){
                                        tree[i][j] = ' ';
                                        }

                                    if(i==0) {
                                            tree[i][tallTree-1] = '+';  // you always need a Christ' Star light on the top of a Tree.  
                                            } else {
                                            tree[i][tallTree-1] = '*';  // Drawing rest of the tree
                                            }
                                        
                                        for(j = 0; j < i; j++ ){   // Drawing rest of the tree
                                            tree[i][tallTree-1-j-1] = '*';
                                            tree[i][tallTree-1+j+1] = '*';
                                                }
                                            
                                        if(i>0) { // now we randomize lights 
                                    
                                        int dots = 2*(i+1)-1; // total dots by level
                                        int lightposition = rand() % (dots+1); // rand() function give us position of the light randomize module dots+1 (pair)

                                        if(lightposition != 0) { // drawing lights... if there are lights (!=0) 
                                        int halftree = ceil((double)(dots)/2); // taking to start counting half of the tree level where we are drawing
                                        int lightsituation = lightposition - halftree;  // from this halftree, get the right (>0) or left (<0) situation  

                                        tree[i][tallTree-1+lightsituation] = '+';
                                            } 
                                        }
                                    }        
                                            
                                        for(; i < totalTree; i++) { // drawing the trunk
                
                                        for( int j = 0; j < widthTree; j++ ){ // first empty drawn
                                            tree[i][j] = ' ';
                                            }
                                            tree[i][tallTree-1] = 'M';  // finally trunk drawn
                                        }
                                        
                            printTree((char*)tree, totalTree, widthTree);
                            printf("\nThere here is, your desired christmas tree, happy new year my friend!!\n");
                            break;
         }

         } while ( option != '5' ); // Option 5: exit 
                                

    return 0;
}

void matrixUser(double Matrix[rows][colms]) {
    int row;
    int colm;
    printf("\n");
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < colms; colm ++) {
            printf("Position %d - %d :", row, colm);
            scanf(" %lf", &Matrix[row][colm]); //validate float
        }
    }
    printf("\n");
}

void showMatrix(double Matrix[rows][colms]) {
    int row;
    int colm;
    printf("\n");
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < rows; colm ++) {
            printf("%6.1lf", Matrix[row][colm]); //we are using only 1 decimal, and separeting them to see better 
        }
    printf("\n");
    }
}

void sumMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (row = 0; row < rows; row ++) { //iterating through rows
        for (colm = 0; colm < colms; colm ++) { //iterating through columns
            result[row][colm] = matrixA[row][colm] + matrixB[row][colm];
        }
    }
    showMatrix(result);
}

void restMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (row = 0; row < rows; row ++) {
        for (colm = 0; colm < colms; colm ++) {
            result[row][colm] = matrixA[row][colm] - matrixB[row][colm];
        }
    }
    showMatrix(result);
}

void prodMatrix (double matrixA[rows][colms], double matrixB[rows][colms]) {
    int row;
    int colm;
    double result[rows][colms];
    for (int colB = 0; colB < colms; colB ++) { //first iterate through column of second matrix
        for (int rowA = 0; rowA < rows; rowA ++) { //then iterate through rows of first matrix
            int sum = 0;
            for (int colA = 0; colA < colms; colA++) { //now we have to get columns of first matrix to convert in row of second matrix
                sum += matrixA[rowA][colA] * matrixB[colA][colB]; // iterating in first matrix into second matrix column to sum result
            }
            
            result[rowA][colB] = sum;
        }
    }
    showMatrix(result);
}

void showPerson (struct person data){ //defining fnction
    printf("\nThere is your personal information: \n %s %s %s \nyour address is:\n %s %d - %dº%s, %s (%s)\nand you are: \n%d years old\n\n",
    data.name, data.surname1, data.surname2, data.address_person.street, data.address_person.number, data.address_person.flat, data.address_person.letter, 
    data.address_person.city, data.address_person.country, data.age);
}
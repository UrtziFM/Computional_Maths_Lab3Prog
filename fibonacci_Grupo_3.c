/*
Implementa un algoritmo de tipo iterativo para calcular la serie de Fibonacci y a continuación construir una función recursiva para resolver la serie de Fibonacci.
Fib(0) = Fib(1) = 1
Fib(n) = Fib(n − 1) + Fib(n − 2)
*/
#include <stdio.h>
#include <stdlib.h>

int number;

long fibonacci(long required) {  // This function is the algorithm to calculate fibonacci sequence, argument will be required position in the sequence
    long next = 1, current = 0, aux = 0; //we are creating 3 variables to iterate in our bucle
    for (long n = 1; n <= required; n++) { //we are creating here a burble with an auxiliar space to copy meanwhile each iteration is done
        aux = current;
        current = next;
        next = next + aux;
    }
    return current; //current position depending of required position of the sequence
}

long fibonacciRecursive(long required) {  // This is function call it's self as a recursive function to get user input and bring needed calculations of fibonacci function
    if (required < 2){ // If user input is lower than 2 there aren't calculation to do, you get same number as required
        return required;
    }else return fibonacciRecursive(required - 1) + fibonacciRecursive(required - 2); //see it, here we are calling recursive function twice 
}


int main () {
    printf("\nWhat n of the fibonacci sequence do you want?\n"); //We want to  interact with our user to get a number
    scanf("%d", &number);
    if(number < 40){  //Here we are limiting a little bit, there is a risk to get a stack overflow because of needed iterations
        unsigned long fibonaccinumber = fibonacciRecursive(number); //calling fibonaccinumber function
        printf("\nRequired fibonacci number on the serie is: %ld \n", fibonaccinumber);
    }else{
        printf("Be careful, this number sequence can create a stack overflow");
    }
}



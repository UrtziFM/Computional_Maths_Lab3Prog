/*Implementa un algoritmo de tipo iterativo para calcular la serie de Fibonacci y a continuación construir una función recursiva para resolver la serie de Fibonacci.
Fib(0) = Fib(1) = 1
Fib(n) = Fib(n − 1) + Fib(n − 2)
*/
#include <stdio.h>
#include <stdlib.h>

long fibonacci(long required, int print) {
    long next = 1, current = 0, aux = 0;
    for (long n = 1; n <= required; n++) {
       // if (print)
       //     printf("%ld, ", current);
        aux = current;
        current = next;
        next = next + aux;
    }
    //if (print)
    //    printf("%ld", current);
    return current;
}

long fibonacciRecursive(long required) {
    if (required < 2)
        return required;
    return fibonacciRecursive(required - 1) + fibonacciRecursive(required - 2);
}


int main () {
//    fibonacci(20, 1);
unsigned long fibonacciDe10 = fibonacciRecursive(20);
printf("Required fibonacci number on the serie is: %ld", fibonacciDe10);
}



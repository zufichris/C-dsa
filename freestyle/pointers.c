#include <stdio.h>
#include <stdlib.h>  // For malloc (we’re giving memory some love!)

/*
   Binary to Decimal Extravaganza:
   For instance, 24:
   - 24 / 2 = 12, remainder 0
   - 12 / 2 = 6, remainder 0
   - 6 / 2 = 3, remainder 0
   - 3 / 2 = 1, remainder 1
   - 1 / 2 = 0, remainder 1
   Reverse those remainders (11000) and voila—24 in decimal!

   Fun Facts:
   - 1 Byte = 8 bits
   - int   = 4 Bytes
   - float = 4 Bytes
   - char  = 1 Byte
*/

int sum(int*, int*);  // Function prototype using pointer parameters

int main(){
    /*
       Welcome to the Pointer Party!
       a:  our star variable holding 10
       p:  pointer to a
       q:  pointer to p
       r:  triple pointer (points to q—yeah, we’re extra!)
    */
    int a = 10;
    int *p = &a;
    int **q = &p;
    int ***r = &q;  // r now correctly points to q

    printf("Value of [a] = %d, [*p] = %d, [**q] = %d, [***r] = %d\n", a, *p, **q, ***r);

    // Summing two numbers with pointer pizzazz:
    int b = 11;
    int result = sum(&a, &b);
    printf("Sum is %d\n", result);

    // Void pointer magic: they can point to anything!
    void *voidPointer;
    int integerValue = 10;
    voidPointer = &integerValue;  // Now pointing to an int
    printf("Value via void pointer (int): %d\n", *(int*)voidPointer);

    // Now for a char—declare your character first!
    char charactervalue = 'Z';
    voidPointer = &charactervalue;
    printf("Value via void pointer (char): %c\n", *(char*)voidPointer);

    // Dynamic memory allocation: giving a NULL pointer a purpose!
    int *allocatedInt = (int*)malloc(sizeof(int));
    if (allocatedInt == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    *allocatedInt = a;  // Assign value of 'a' to our freshly allocated memory
    printf("Allocated integer value: %d\n", *allocatedInt);
    free(allocatedInt);  // Always clean up your memory—no leaks allowed!

    // Function pointer fun: because even functions deserve pointers!
    int (*functionPtr)(int*, int*) = &sum;
    result = functionPtr(&a, &b);
    printf("Sum using function pointer: %d\n", result);

    return 0;
}

// Sum function that adds two integers (via pointers, of course)
int sum(int *a, int *b){
    return *a + *b;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 70;
    var = var + 50;
    var  += 50;
    printf("Variable is: %i\n", var);
    var /= 2;
    printf("Variable is: %i\n", var);
    var /= 2;
    printf("Variable is: %i\n", var);
    int remainder = var % 5;
    printf("Remainder is: %i\n", remainder);
    remainder++;
    printf("Incremented remainder is: %i\n", remainder);
    return 0;
}

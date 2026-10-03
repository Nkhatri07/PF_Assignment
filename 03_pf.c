#include<stdio.h>

int main()
{
    int n, i=0;
    printf("ENter the number:\n");
    scanf("%d", &n);
    while(n !=0)
    {
        n = n/10;
        i++;
    }
printf("Number of digits are: %d\n", i);
    return 0;
}
#include<stdio.h>

int main()
{
int n, d=0, i=0;
printf("ENter a number:\n");
scanf("%d", &n);
while(n != 0)
{
    d = n % 10;
    i = i + d;
    n = n/10;

}
printf("Sum of digits is %d", i);

    return 0;
}
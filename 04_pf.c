#include<stdio.h>

int main()
{
    
for(int n=0;n <= 10;n++)
{
    if(n % 3 == 0)
    continue;
for(int i=0;i <= 10;i++)

    printf("%d * %d = %d\n", n, i, n*i);
}
    return 0;

}
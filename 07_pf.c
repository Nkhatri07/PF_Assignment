#include<stdio.h>

int main()
{
int a,b,c,d,e,n=0;
printf("ENter the requested floor1:\n");
scanf("%d", &a);
if(a>n)
{
    printf("Moving up.\n");
} else if(a<n)
{
    printf("Moving down");
} else if(a==n)
{
    printf("Doors opening.\n");
}
 n=a;
printf("Enter the requested floor2;\n");
scanf("%d", &b);
if(b>n)
{
    printf("Moving up.\n");
} else if(b<n)
{
    printf("Moving down.\n");
}else if(b==n)
{
    printf("Doors opening.\n");
}
n=b;
printf("ENter the requested floor3:\n ");
scanf("%d", &c);
if(c>n)
{
    printf("Moving up.\n");
} else if(c<n)
{
    printf("Moving down.\n");
} else if(c==n)
{
    printf("Doors opening.\n");
}
n=c;
printf("ENter the requested floor4:\n");
scanf("%d", &d);
if(d>n)
{
    printf("Moving up.\n");
} else if(d<n)
{
    printf("Moving down.\n");
} else if(d==n)
{
    printf("Doors opening.\n");
}
n=d;
printf("Enter the requested floor5:\n");
scanf("%d", &e);
if(e>n)
{
    printf("Moving up.\n");
} else if(e<n)
{
    printf("Moving down.\n");
} else if(e==n)
{
    printf("Doors opening.\n");
}
n=e;
    return 0;
}
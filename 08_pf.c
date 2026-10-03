#include <stdio.h>

int main()
{
    int marks1, marks2, marks3, marks4, marks5;
    float average;
    printf("ENter your marks out of 100:\n");
    printf("Enter your marks in subject 1:\n");
    scanf("%d", &marks1);
    printf("Enter your marks in subject 2:\n");
    scanf("%d", &marks2);
    printf("Enter your marks in subject 3:\n");
    scanf("%d", &marks3);
    printf("Enter your marks in subject 4:\n");
    scanf("%d", &marks4);
    printf("Enter your marks in subject 5:\n");
    scanf("%d", &marks5);
    if ((marks1 < 0 || marks1 > 100) || (marks2 < 0 || marks2 > 100) ||
        (marks3 < 0 || marks3 > 100) || (marks4 < 0 || marks4 > 100) || (marks5 < 0 || marks5 > 100))
    {
        printf("Enter valid marks (between 0 and 100).\n");
    }
    average = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;
    printf("Your average is %f. \n", average);
    if (marks1 > 33 && marks2 > 33 && marks3 > 33 && marks4 > 33 && marks5 > 33)
    {
        if (average >= 80 && average <= 100)
        {
            printf("You have passed with distinction!\n");
        }
        else if (average >= 60 && average < 80)
        {
            printf("Pass.\n");
        }
        else if (average < 60)
        {

            printf("fail due to below average.\n");
        }
    }
    else
    {
        printf("FAil due to subject deficiency.\n");
    }
    return 0;
}
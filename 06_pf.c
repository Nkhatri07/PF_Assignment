#include <stdio.h>

int main()
{
    int guest, room_type, season, stay;
    float discount, bill1 = 0, bill2 = 0, revenue;

    printf("Enter the Guest no:\n");
    scanf("%d", &guest);

    if (guest == 1)
    {
        printf("Enter the season (1. peak 2. peak-off):\n");
        scanf("%d", &season);

        if (season == 1)
        {
            printf("Select the room type (1. Standard 2. Deluxe 3. Suite):\n");
            scanf("%d", &room_type);

            if (room_type == 1)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 5000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 5000;
                }
            }
            else if (room_type == 2)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 8000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 8000;
                }
            }
            else if (room_type == 3)
            {
                printf("Enter the number of nights to stay:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 12000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 12000;
                }
            }
        }
        else if (season == 2)
        {
            printf("Select the room type (1. Standard 2. Deluxe 3. Suite):\n");
            scanf("%d", &room_type);

            if (room_type == 1)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 3000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 3000;
                }
            }
            else if (room_type == 2)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 5000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 5000;
                }
            }
            else if (room_type == 3)
            {
                printf("Enter the number of nights to stay:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill1 = stay * 8000;
                    discount = bill1 * 0.10;
                    bill1 = bill1 - discount;
                }
                else
                {
                    discount = 0;
                    bill1 = stay * 8000;
                }
            }
        }
    }

    if (guest == 2)
    {
        printf("Enter the season (1. peak 2. peak-off):\n");
        scanf("%d", &season);

        if (season == 1)
        {
            printf("Select the room type (1. Standard 2. Deluxe 3. Suite):\n");
            scanf("%d", &room_type);

            if (room_type == 1)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 5000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 5000;
                }
            }
            else if (room_type == 2)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 8000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 8000;
                }
            }
            else if (room_type == 3)
            {
                printf("Enter the number of nights to stay:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 12000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 12000;
                }
            }
        }
        else if (season == 2)
        {
            printf("Select the room type (1. Standard 2. Deluxe 3. Suite):\n");
            scanf("%d", &room_type);

            if (room_type == 1)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 3000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 3000;
                }
            }
            else if (room_type == 2)
            {
                printf("Enter the number of nights:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 5000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 5000;
                }
            }
            else if (room_type == 3)
            {
                printf("Enter the number of nights to stay:\n");
                scanf("%d", &stay);

                if (stay > 7)
                {
                    bill2 = stay * 8000;
                    discount = bill2 * 0.10;
                    bill2 = bill2 - discount;
                }
                else
                {
                    discount = 0;
                    bill2 = stay * 8000;
                }
            }
        }
    }

    revenue = bill1 + bill2;

    printf("Revenue is %.2f", revenue);

    return 0;
}

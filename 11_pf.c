#include <stdio.h>

int main()
{
    int N, i;
    int zoneA = 0, zoneB = 0, zoneC = 0;
    int accepted = 0, rejected = 0;
    int cars = 0, bikes = 0, vans = 0;

    char vehicle, category, permit, emergency;
    int spaces, assigned = 0;
    char zone;
    char reason[100];

    printf("Enter number of vehicles: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("\n========== Vehicle %d ==========\n", i);

        assigned = 0;
        reason[0] = '\0';

        /* Vehicle Type Validation */
        do
        {
            printf("Enter vehicle type (C-Car, B-Bike, V-Van): ");
            scanf(" %c", &vehicle);

            if (vehicle != 'C' && vehicle != 'B' && vehicle != 'V')
                printf("Invalid vehicle type! Enter again.\n");

        } while (vehicle != 'C' && vehicle != 'B' && vehicle != 'V');


        /* Category Validation */
        do
        {
            printf("Enter user category (F-Faculty, S-Student, G-Visitor): ");
            scanf(" %c", &category);

            if (category != 'F' && category != 'S' && category != 'G')
                printf("Invalid category! Enter again.\n");

        } while (category != 'F' && category != 'S' && category != 'G');


        /* Permit Validation */
        do
        {
            printf("Has valid parking permit? (Y/N): ");
            scanf(" %c", &permit);

            if (permit != 'Y' && permit != 'N')
                printf("Invalid permit value! Enter again.\n");

        } while (permit != 'Y' && permit != 'N');


        /*
           Emergency status is required when permit is invalid.
        */
        if (permit == 'N')
        {
            do
            {
                printf("Is it an emergency vehicle? (Y/N): ");
                scanf(" %c", &emergency);

                if (emergency != 'Y' && emergency != 'N')
                    printf("Invalid value! Enter again.\n");

            } while (emergency != 'Y' && emergency != 'N');
        }
        else
        {
            emergency = 'N';
        }


        /* Determine required parking spaces */
        if (vehicle == 'V')
            spaces = 2;
        else
            spaces = 1;


        /*
           EMERGENCY VEHICLE
           Emergency vehicles can enter without a permit.
           They are assigned according to their category.
        */
        if (emergency == 'Y')
        {
            if (category == 'F')
            {
                if (zoneA + spaces <= 20)
                {
                    zoneA += spaces;
                    zone = 'A';
                    assigned = 1;
                }
                else
                {
                    sprintf(reason, "No available space in Zone A");
                }
            }
            else if (category == 'S')
            {
                if (zoneB + spaces <= 40)
                {
                    zoneB += spaces;
                    zone = 'B';
                    assigned = 1;
                }
                else
                {
                    sprintf(reason, "No available space in Zone B");
                }
            }
            else
            {
                if (zoneC + spaces <= 15)
                {
                    zoneC += spaces;
                    zone = 'C';
                    assigned = 1;
                }
                else
                {
                    sprintf(reason, "No available space in Zone C");
                }
            }
        }


        /*
           NORMAL VEHICLE
        */
        else
        {
            if (permit == 'N')
            {
                sprintf(reason, "Invalid permit");
            }
            else
            {
                /* FACULTY */
                if (category == 'F')
                {
                    if (vehicle == 'C' || vehicle == 'B')
                    {
                        if (zoneA + 1 <= 20)
                        {
                            zoneA++;
                            zone = 'A';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "No available space in Zone A");
                        }
                    }
                    else if (vehicle == 'V')
                    {
                        if (zoneA + 2 <= 20)
                        {
                            zoneA += 2;
                            zone = 'A';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "No available space for van in Zone A");
                        }
                    }
                }


                /* STUDENT */
                else if (category == 'S')
                {
                    if (vehicle == 'C' || vehicle == 'B')
                    {
                        if (zoneB + 1 <= 40)
                        {
                            zoneB++;
                            zone = 'B';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "No available space in Zone B");
                        }
                    }
                    else if (vehicle == 'V')
                    {
                        /*
                           Student van:
                           Try Zone B first.
                           If Zone B unavailable, redirect to Zone C.
                        */
                        if (zoneB + 2 <= 40)
                        {
                            zoneB += 2;
                            zone = 'B';
                            assigned = 1;
                        }
                        else if (zoneC + 2 <= 15)
                        {
                            zoneC += 2;
                            zone = 'C';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "No suitable zone for student van");
                        }
                    }
                }


                /* VISITOR */
                else if (category == 'G')
                {
                    if (vehicle == 'C' || vehicle == 'B')
                    {
                        if (zoneC + 1 <= 15)
                        {
                            zoneC++;
                            zone = 'C';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "No available space in Zone C");
                        }
                    }
                    else if (vehicle == 'V')
                    {
                        /*
                           Visitor van requires TWO spaces.
                        */
                        if (zoneC + 2 <= 15)
                        {
                            zoneC += 2;
                            zone = 'C';
                            assigned = 1;
                        }
                        else
                        {
                            sprintf(reason, "Less than two spaces available in Zone C");
                        }
                    }
                }
            }
        }


        /* Process Result */
        if (assigned == 1)
        {
            accepted++;

            if (vehicle == 'C')
                cars++;
            else if (vehicle == 'B')
                bikes++;
            else if (vehicle == 'V')
                vans++;

            printf("\nVehicle ACCEPTED\n");
            printf("Assigned Zone: Zone %c\n", zone);

            if (zone == 'A')
                printf("Remaining capacity: %d\n", 20 - zoneA);
            else if (zone == 'B')
                printf("Remaining capacity: %d\n", 40 - zoneB);
            else
                printf("Remaining capacity: %d\n", 15 - zoneC);
        }
        else
        {
            rejected++;

            printf("\nVehicle REJECTED\n");
            printf("Reason: %s\n", reason);
        }
    }


    /* ================= SUMMARY ================= */

    printf("\n\n========================================\n");
    printf("        SMART PARKING SUMMARY\n");
    printf("========================================\n");

    printf("Total vehicles processed : %d\n", N);
    printf("Total accepted vehicles  : %d\n", accepted);
    printf("Total rejected vehicles  : %d\n", rejected);

    printf("\nSuccessfully parked:\n");
    printf("Cars  : %d\n", cars);
    printf("Bikes : %d\n", bikes);
    printf("Vans  : %d\n", vans);

    printf("\nZone A (Faculty):\n");
    printf("Occupied          : %d\n", zoneA);
    printf("Remaining capacity: %d\n", 20 - zoneA);

    printf("\nZone B (Students):\n");
    printf("Occupied          : %d\n", zoneB);
    printf("Remaining capacity: %d\n", 40 - zoneB);

    printf("\nZone C (Visitors):\n");
    printf("Occupied          : %d\n", zoneC);
    printf("Remaining capacity: %d\n", 15 - zoneC);


    /* Highest Occupancy */
    printf("\nZone with highest occupancy: ");

    if (zoneA > zoneB && zoneA > zoneC)
        printf("Zone A (%d vehicles/spaces)\n", zoneA);
    else if (zoneB > zoneA && zoneB > zoneC)
        printf("Zone B (%d vehicles/spaces)\n", zoneB);
    else if (zoneC > zoneA && zoneC > zoneB)
        printf("Zone C (%d vehicles/spaces)\n", zoneC);
    else
        printf("There is a tie between zones.\n");


    /* Entire Campus Full */
    if (zoneA == 20 && zoneB == 40 && zoneC == 15)
        printf("\nEntire campus parking facility is FULL.\n");
    else
        printf("\nEntire campus parking facility is NOT FULL.\n");

    printf("========================================\n");

    return 0;
}
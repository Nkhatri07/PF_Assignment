#include <stdio.h>

int main()
{
    char vehicle, member, disabled, station;
    int currentBattery, requiredBattery;
    int requiredCharging;
    float parkingHours;
    int time;

    float chargingRate = 0;
    float chargingCost = 0;
    float parkingCost = 0;
    float chargingDiscount = 0;
    float parkingDiscount = 0;
    float totalBill = 0;

    int emergency = 0;
    int priority = 0;
    int offPeak = 0;

    printf("Enter vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicle);
    printf("Enter current battery percentage: ");
    scanf("%d", &currentBattery);
    printf("Enter required charging percentage: ");
    scanf("%d", &requiredBattery);
    printf("Enter parking duration (hours): ");
    scanf("%f", &parkingHours);
    printf("Enter current time (0-23): ");
    scanf("%d", &time);
    printf("Membership (Y/N): ");
    scanf(" %c", &member);
    printf("Disabled priority (Y/N): ");
    scanf(" %c", &disabled);
    printf("Charging station available? (Y/N): ");
    scanf(" %c", &station);
    if (station == 'N' || station == 'n')
    {
        if (vehicle == 'H' || vehicle == 'h')
        {
            printf("\nCharging unavailable - Parking only.\n");
        }
        else
        {
            printf("\nNo charging slot available.\n");
        }
        return 0;
    }
    if (vehicle == 'H' || vehicle == 'h')
    {
        if (currentBattery >= 40)
        {
            printf("\nVehicle does not qualify for EV charging.\n");
            return 0;
        }
    }    
    requiredCharging = requiredBattery - currentBattery;
    if (requiredCharging <= 0)
    {
        printf("\nNo charging required.\n");
        return 0;
    }
    if (currentBattery <= 15 && requiredBattery >= 80)
    {
        emergency = 1;
        priority = 1;
    }
    else if ((disabled == 'Y' || disabled == 'y') ||
             ((member == 'Y' || member == 'y') &&
              currentBattery <= 30))
    {
        priority = 2;
    }
    else
    {
        priority = 3;
    }
    if (time < 17 || time > 22)
    {
        offPeak = 1;
        chargingRate = 35;
    }
    else
    {
        offPeak = 0;
        chargingRate = 50;
    }
    chargingCost = requiredCharging * chargingRate;
    if (emergency == 0)
    {
        if (offPeak == 1)
        {
            if (member == 'Y' || member == 'y')
            {
                chargingDiscount = chargingCost * 0.20;
            }
        }
        else
        {
            chargingDiscount = chargingCost * 0.10;
        }
    }

    chargingCost = chargingCost - chargingDiscount;
    if (parkingHours <= 2)
    {
        parkingCost = 200;
    }
    else if (parkingHours <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }
    if (disabled == 'Y' || disabled == 'y')
    {
        parkingDiscount = parkingCost;
    }
    else if (member == 'Y' || member == 'y')
    {
        parkingDiscount = parkingCost * 0.20;
    }

    parkingCost = parkingCost - parkingDiscount;
    totalBill = chargingCost + parkingCost;
    printf("\n========== EV CHARGING SUMMARY ==========\n");

    if (vehicle == 'E' || vehicle == 'e')
        printf("Vehicle Type: Electric Vehicle\n");
    else
        printf("Vehicle Type: Hybrid Vehicle\n");

    printf("Current Battery: %d%%\n", currentBattery);
    printf("Required Charging: %d%%\n", requiredCharging);
    if (priority == 1)
        printf("Charging Priority: Emergency Charging\n");
    else if (priority == 2)
        printf("Charging Priority: Priority Charging\n");
    else
        printf("Charging Priority: Normal Charging\n");
    if (offPeak == 1)
        printf("Charging Time: Off-Peak\n");
    else
        printf("Charging Time: Peak\n");
    printf("Charging Rate: Rs %.2f per unit\n", chargingRate);
    printf("Charging Discount: Rs %.2f\n", chargingDiscount);
    printf("Charging Cost: Rs %.2f\n", chargingCost);
    printf("Parking Discount: Rs %.2f\n", parkingDiscount);
    printf("Parking Cost: Rs %.2f\n", parkingCost);
    printf("Total Bill: Rs %.2f\n", totalBill);
    if (parkingHours > 8)
    {
        printf("Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("Standard parking duration.\n");
    }

    return 0;
}
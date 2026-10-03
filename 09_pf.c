#include<stdio.h>

int main()
{
int quantity;
float price, discount_percentage, tax_percentage, subtotal, discount, tax, discounted_amount, final_bill;
printf("Quantity of prodeucts purchased:\n");
scanf("%d", &quantity);
printf("Price per item:\n");
scanf("%f", &price);
printf("DIscount percentage:\n");
scanf("%f", &discount_percentage);
printf("Tax percentage:\n");
scanf("%f", &tax_percentage);
if(quantity<=0)
{
    printf("Enter the valid quantity!");
    return 0;
}
if (price<0)
{
   printf("Enter the valid price!");
   return 0;
}
if(discount_percentage<0 || discount_percentage>=100)
{
    printf("Enter the valid discount!");
    return 0;
}
if(tax_percentage<0)
{
    printf("ENter the valid tax percentage!");
    return 0;
}
subtotal = quantity*price;
discount = (subtotal*discount_percentage)/100;
discounted_amount = subtotal - discount;
tax = (discounted_amount*tax_percentage)/100;
final_bill = discounted_amount + tax;
printf("======================================================================\n");
printf("                                                                      \n");
printf("                            FINAL BILL                                \n");
printf("                                                                      \n");
printf("======================================================================\n");
printf("  SUBTOTAL             :                 %f\n", subtotal);
printf("  DISCOUNT              :                 %f\n", discount);
printf("  TAX                   :                 %f\n", tax);
printf("  FINAL BILL            :                  %f\n", final_bill);
    return 0;
}                                                                                                               
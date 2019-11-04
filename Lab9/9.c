#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //Task 2
    unsigned monthlyFee, minutePriceIncreased, usedMinutes;
    const unsigned freeMinutes = 499;

    printf("=== Task 2 ===\n");
    printf("Enter normal monthly fee: ");
    scanf("%u", &monthlyFee);
    printf("Enter increased price for each minute: ");
    scanf("%u", &minutePriceIncreased);
    printf("Enter used minutes: ");
    scanf("%u", &usedMinutes);

    unsigned result = monthlyFee;

    if ((int)(usedMinutes - freeMinutes) > 0) {
        result += minutePriceIncreased * (usedMinutes - freeMinutes);
    }

    printf("Total cost is %u\n", result);

    //Task 5
    printf("=== Task 5 ===\n");

    double amount, rate;
    unsigned period;

    printf("Enter the initial amount of money: ");
    scanf("%lf", &amount);
    printf("Enter the interest rate (%%): ");
    scanf("%lf", &rate);
    printf("Enter the period of the deposit: ");
    scanf("%u", &period);

    rate /= 100;
    for (int i = 1; i <= period; i++) {
        amount *= 1 + rate / 12;
        printf("The amount on the month %u is %f\n", i, amount);
    }

    return 0;
}
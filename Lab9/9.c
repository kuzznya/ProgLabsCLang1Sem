#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //Task 2
    unsigned monthlyFee, minutePriceIncreased, usedMinutes;
    const unsigned freeMinutes = 499;

    printf("=== Task 2 ===");
    printf("Enter normal monthly fee: ");
    scanf("%u", &monthlyFee);
    printf("Enter increased price for each minute: ");
    scanf("%u", &minutePriceIncreased);
    printf("Enter used minutes");
    scanf("%u", &usedMinutes);

    unsigned result = monthlyFee;

    if (usedMinutes - freeMinutes > 0) {
        result += minutePriceIncreased * (usedMinutes - freeMinutes);
    }

    printf("Total cost is %u", result);

    return 0;
}
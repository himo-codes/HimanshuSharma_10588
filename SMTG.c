#define _CONSOLE
#include <stdio.h>

int main() {
    int num, sum;

    // Step 1 & 2: Read and store the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Step 8 & 9: Repeat until single digit is obtained
    while (num > 9) {
        sum = 0;

        // Step 3, 4, 5: Extract digits and add them
        while (num > 0) {
            sum = sum + (num % 10);
            num = num / 10;
        }

        // Step 6 & 7: Assign sum to num for next iteration
        num = sum;
    }

    // Step 10: Print final result
    printf("Digital Root is: %d\n", num);

    return 0;
}

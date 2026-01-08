#define _CONSOLE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char buf[10010];

    printf("Enter a number: ");
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    /* trim trailing newline/carriage returns */
    size_t len = strlen(buf);
    while (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r')) {
        buf[--len] = '\0';
    }

    /* skip optional sign */
    size_t start = 0;
    if (buf[0] == '+' || buf[0] == '-') start = 1;

    /* validate contains at least one digit */
    int has_digit = 0;
    for (size_t i = start; i < len; ++i) if (isdigit((unsigned char)buf[i])) { has_digit = 1; break; }
    if (!has_digit) { printf("Invalid input\n"); return 0; }

    /* special-case all zeros */
    int all_zero = 1;
    for (size_t i = start; i < len; ++i) if (buf[i] != '0') { all_zero = 0; break; }
    if (all_zero) { printf("Digital Root is: 0\n"); return 0; }

    /* compute digital root by summing digits repeatedly; supports arbitrarily long inputs */
    while (1) {
        long sum = 0;
        for (size_t i = start; i < len; ++i) {
            if (isdigit((unsigned char)buf[i])) sum += buf[i] - '0';
        }

        if (sum <= 9) {
            printf("Digital Root is: %ld\n", sum);
            break;
        }

        /* convert sum back into buf for next iteration */
        int written = snprintf(buf, sizeof(buf), "%ld", sum);
        if (written <= 0) return 0;
        len = (size_t) written;
        start = 0; /* now buf contains only digits */
    }

    return 0;
}

#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Roman numeral values and symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 
                    50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", 
                       "L", "XL", "X", "IX", "V", "IV", "I"};

    // Allocate enough space (max length for 3999 is 15 chars)
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0';  // start with empty string

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}

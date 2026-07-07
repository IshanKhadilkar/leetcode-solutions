#include <string.h>

int longestPalindrome(char* s) {
    int freq[128] = {0};  // ASCII covers both uppercase and lowercase

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    int length = 0;
    int hasOdd = 0;

    for (int i = 0; i < 128; i++) {
        length += (freq[i] / 2) * 2;  // add pairs
        if (freq[i] % 2 == 1) {
            hasOdd = 1;  // at least one odd count
        }
    }

    if (hasOdd) {
        length += 1;  // one odd can sit in the middle
    }

    return length;
}
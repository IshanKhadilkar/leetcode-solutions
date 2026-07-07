#include <string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count length of the last word
    int wordLen = 0;
    while (i >= 0 && s[i] != ' ') {
        wordLen++;
        i--;
    }

    return wordLen;
}
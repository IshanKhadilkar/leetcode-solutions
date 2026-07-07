#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    // Start with the first string as the prefix
    char* prefix = strs[0];
    int prefixLen = strlen(prefix);

    // Compare with each string
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefixLen = j;  // shorten prefix length
        if (prefixLen == 0) {
            char* empty = (char*)malloc(1);
            empty[0] = '\0';
            return empty;
        }
    }

    // Allocate result string
    char* result = (char*)malloc(prefixLen + 1);
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';
    return result;
}

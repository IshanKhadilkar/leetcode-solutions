#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    if (len == 0) return true;

    // Allocate stack with size equal to string length
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;  // push
        } else {
            if (top == -1) {   // stack empty, invalid
                free(stack);
                return false;
            }
            char open = stack[top--];  // pop
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);  // stack should be empty
    free(stack);
    return valid;
}

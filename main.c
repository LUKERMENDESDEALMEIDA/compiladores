#include <stdio.h>
#include <ctype.h>

#define OPERATOR 1
#define NUMBER 2

int main() {
    int token;
    char ch;

    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            continue;
        } else if (isdigit(ch)) {
            ungetc(ch, stdin);
            int value;
            scanf("%d", &value);
            printf("NUMBER: %d\n", value);
            token = NUMBER;
        } else if (ch == '+') {
            printf("OPERATOR: +\n");
            token = OPERATOR;
        } else if (ch == '-') {
            printf("OPERATOR: -\n");
            token = OPERATOR;
        } else if (ch == '*') {
            printf("OPERATOR: *\n");
            token = OPERATOR;
        } else if (ch == '/') {
            printf("OPERATOR: /\n");
            token = OPERATOR;
        } else {
            printf("ERROR\n");
            token = 0;
        }
    }

    return 0;
}

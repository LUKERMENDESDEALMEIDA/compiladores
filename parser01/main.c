#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Token {
    Mais,
    Menos,
    Indeterminado,
	Inteiro,
	Real
};

struct TokenVector {
    enum Token *tokens;
    int size;
};

struct TokenVector tokenizar(char *s);
int is_digit(char c);




struct TokenVector obter_tokens(char *s) {
    struct TokenVector result;
    result.tokens = malloc(sizeof(enum Token));
    result.size = 0;
    char *c = s;

    while (*c != '\0') {
        switch (*c) {
            case ' ':
                c++;
                break;
            case '+':
                c++;
                result.tokens = realloc(result.tokens, (result.size + 1) * sizeof(enum Token));
                result.tokens[result.size++] = Mais;
                break;
            case '-':
                c++;
                result.tokens = realloc(result.tokens, (result.size + 1) * sizeof(enum Token));
                result.tokens[result.size++] = Menos;
                break;
            default:
                if (is_digit(*c)) {
                    while (is_digit(*c)) {
                        c++;
                    }
                    if (*c == '.') {
                        c++;
                        while (is_digit(*c)) {
                            c++;
                        }
                    }
                    result.tokens = realloc(result.tokens, (result.size + 1) * sizeof(enum Token));
                    result.tokens[result.size++] = Real;
                } else {
                    result.tokens = realloc(result.tokens, (result.size + 1) * sizeof(enum Token));
                    result.tokens[result.size++] = Indeterminado;
                    c++;
                }
                break;
        }
    }

    return result;
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char *s = "+-x 123 45.6";
    struct TokenVector tokens = obter_tokens(s);
    printf("TOKENS: ");
    for (int i = 0; i < tokens.size; i++) {
        switch (tokens.tokens[i]) {
            case Mais:
                printf("Mais ");
                break;
            case Menos:
                printf("Menos ");
                break;
            case Indeterminado:
                printf("Indeterminado ");
                break;
            case Inteiro:
                printf("Inteiro ");
                break;
            case Real:
                printf("Real ");
                break;
        }
    }
    printf("\n");
    free(tokens.tokens);
    return 0;
}
//struct Termo* parseTermo(char* input) {
 //   struct Termo* termo = malloc(sizeof(struct Termo));
  //  termo->num1 = NULL;
 //   termo->num2 = NULL;
 //   struct Token* num1 = parseNumero(input);
 //   if (num1) {
  //      termo->num1 = num1;
  //      if (strncmp(input, "+", 1) == 0) {
  //          input += 1;
  //          struct Token* num2 = parseNumero(input);
 //           if (num2) {
   //             termo->num2 = num2;
   //             struct Token* soma = malloc(sizeof(struct Token));
//                soma->type = Soma;
 //               soma->lexeme = "+";
  //              termo->num1 = soma;
  //          } else {
  //              free(termo->num1);
  //              free(termo);
   //             return NULL;
  //          }
  //      }
  //  }
 //   return termo;
//}}
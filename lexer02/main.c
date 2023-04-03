
#include <stdio.h>




// Definição dos tokens
%token NUMBER
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token POWER

%%

// Expressões regulares para cada token
"+"     { return PLUS; };
"-"     { return MINUS; };
"*"     { return TIMES; };
"/"     { return DIVIDE; };
"**"    { return POWER; }

// Expressão regular para números inteiros e decimais
//[0-9]+(\.[0-9]+)?   { yylval = atof(yytext); return NUMBER; }

// Ignorar espaços em branco e tabulações
//[ \t]   ;

//.       { printf("Caractere ilegal '%s'\n", yytext); }

//%%

int main(void) {
//   yyin = stdin; // ler a entrada do console

    // Loop para reconhecer os tokens
    while (1) {
        int token = yylex();
        if (token == 0) {
            break;
        } else if (token == PLUS) {
            printf("PLUS\n");
        } else if (token == MINUS) {
            printf("MINUS\n");
        } else if (token == TIMES) {
            printf("TIMES\n");
        } else if (token == DIVIDE) {
            printf("DIVIDE\n");
        } else if (token == POWER) {
            printf("POWER\n");
        } else if (token == NUMBER) {
            printf("NUMBER: %f\n", yylval);
        }
    }

    return 0;
}

%{
#include <stdio.h>
%}

%option noyywrap

// Definição dos tokens
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token POWER
%token INT
%token FLOAT

%%

// Expressões regulares para cada token
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return TIMES; }
"/"     { return DIVIDE; }
"**"    { return POWER; }

// Expressão regular para números inteiros
[0-9]+  { yylval = atoi(yytext); return INT; }

// Expressão regular para números reais
[0-9]*\.[0-9]+  { yylval = atof(yytext); return FLOAT; }

// Ignorar espaços em branco e tabulações
[ \t]   ;

.       { printf("Caractere ilegal '%s'\n", yytext); }

%%

int main(void) {
    yyin = stdin; // ler a entrada do console

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
        } else if (token == INT) {
            printf("INT: %d\n", yylval);
        } else if (token == FLOAT) {
            printf("FLOAT: %f\n", yylval);
        }
    }

    return 0;
}

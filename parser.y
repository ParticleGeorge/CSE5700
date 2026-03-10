%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

%token INT RETURN IF ELSE IDENTIFIER NUMBER
%token EQ NE LE GE AND OR
%left '+' '-'
%left '*' '/'
%left EQ NE
%left '<' '>'
%left AND OR

%%
program:
    | program statement
    ;

statement:
      INT IDENTIFIER ';'                { /* int declarations */ }
    | IDENTIFIER '=' expression ';'     { /* assignments */ }
    | RETURN expression ';'             { /* return statements */ }
    ;

expression:
      NUMBER
    | IDENTIFIER
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | '(' expression ')'
    ;

%%

int main() {
    yyparse();
    printf("Complete.\n");
    return 0;
}

int yyerror(const char *s) 
{
    fprintf(stderr, "error: %s\n", s);
    return 0;
}
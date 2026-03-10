%{
#include "parser.tab.h"
%}

%%

[ \t]+               ; /* ignore space */
"/*"                 { comment(); }
"//"                 { comment(); }
"if"                 { return IF; }
"else"               { return ELSE; }
"int"                { return INT; }
"return"             { return RETURN; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
[0-9]+               { return NUMBER; }
";"                  { return ';'; }
"("                  { return '('; }
")"                  { return ')'; }
"{"                  { return '{'; }
"}"                  { return '}'; }
"+"                  { return '+'; }
"-"                  { return '-'; }
"*"                  { return '*'; }
"/"                  { return '/'; }
"<"                  { return '<'; }
">"                  { return '>'; }
"="                  { return '='; }
"=="                 { return EQ; }
"!="                 { return NE; }
"<="                 { return LE; }
">="                 { return GE; }
"&&"                 { return AND; }
"||"                 { return OR; }
.                    { return *yytext; }

%%

int yywrap() 
{
    return 1;
}

void comment() 
{ 
    char a;
    while ((a = input()) != 0 && a != '\n');
} // this was necessary for handling comments





%option yylineno
%{  
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>   
#include "defs.h"
int yywrap();
%}

%%
"if"			return IF;
"else"			return ELSE;
"while"			return WHILE;
"return"		return RETURN;
"void"			return VOID;
"int"			return INT;
"float"			return FLOAT;
"++"			return INC; 
"--"			return DEC;
"+"				return PLUS;     
"-"				return MINUS;     
"*"				return MULTIPLY;     
"/"				return DIVIDE;    
"<"				return LT;   
"<="			return LTEQ; 
">"				return GT;     
">="			return GTEQ; 
"=="			return EQEQ; 
"!="			return NEQ; 
"="				return EQ;     
("[")			return LSQUARE;
("]")			return RSQUARE;
("{")			return LBRACE;
("}")			return RBRACE;
";"				return SEMICOLON;
","				return COMMA;
"("				return LBRACKET;
")"				return RBRACKET;
[0-9]+ 			return INTVALUE;
[0-9]+\.[0-9]+	return FLOATVALUE;
[a-zA-Z][a-zA-Z0-9_]*	return IDENTIFIER;
\'[a-zA-Z]\'		return CHARVALUE;
\".*\"	return STRING;
. 				;
[ \n\t]				;

%%

int yywrap(void)
{
	return 1;
}
%option yylineno
%{  
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "y.tab.h"
int yywrap();
int line_number =1;
%}

%%

"void"			return VOID;
"int"			return INT;
"float"			return FLOAT;
"string"		return STRING;
"char"			return CHAR;
"boolean"		return BOOLEAN;

"if"			return IF;
"else"			return ELSE;
"while"			return WHILE;
"return"		return RETURN;
"for"	return FOR;

"+"			return PLUS;     
"-"			return MINUS;     
"*"			return MULTIPLY;     
"/"			return DIVIDE; 


"++"			return INC; 
"--"			return DEC;
"<"				return LT;   
"<="			return LTEQ; 
">"				return GT;     
">="			return GTEQ; 
"=="			return EQEQ; 
"!="			return NEQ; 
"="				return EQ;
"&&"			return AND_AND;
"||"			return OR_OR;
"!" 			return NOT; 
    
"["			return LSQUARE;
"]"		return RSQUARE;
"{"			return LBRACE;
"}"			return RBRACE;
";"				return SEMICOLON;
","				return COMMA;
"("				return LBRACKET;
")"				return RBRACKET;
":" 			return COLON;
"break" 		return BREAK;
"default" 		return DEFAULT;


"switch"		return SWITCH;
"case"			return CASE;
"do"			return DO;
"true" 			return TRUE;
"false"			return FALSE;


[0-9]+ 			return INTVALUE;
[0-9]+\.[0-9]+		return FLOATVALUE;
[a-zA-Z][a-zA-Z0-9_]*	return IDENTIFIER;
\'[a-zA-Z]\'		return CHARVALUE;
\".*\"			return STRINGVALUE;



[\/\*][.]*[\/\*]	return COMMENT;

\n				{line_number++;}
[\t|\f|\r|\v]*			;

. 				;

%%

int yywrap(void)
{
	return 1;
}

%option yylineno
%{  
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "y.tab.h"
int yywrap();
%}

%%

"void"			{yylval.stringVal="void";}return VOID;
"int"			{yylval.stringVal="int";}return INT;
"float"			{yylval.stringVal="float";}return FLOAT;
"string"		{yylval.stringVal="string";}return STRING;
"boolean"		{yylval.stringVal="boolean";}return BOOLEAN;

"if"			return IF;
"else"			return ELSE;
"while"			return WHILE;
"return"		return RETURN;
"for"			return FOR;

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


[0-9]+ 			{yylval.floatVal=atof(yytext); }return INTVALUE;
[0-9]+\.[0-9]+		{yylval.floatVal=atof(yytext); } return FLOATVALUE;
[a-zA-Z][a-zA-Z0-9_]*	{yylval.stringVal=strdup(yytext);} return IDENTIFIER;
\".*\"			{yylval.stringVal=strdup(yytext);} return STRINGVALUE;




[\/\*][.]*[\/\*]	return COMMENT;

\n				{yylineno++;};
[ \t|\f|\r|\v]+			;

. 				;

%%

int yywrap(void)
{
	return 1;
}

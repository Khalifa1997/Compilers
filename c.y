%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *fp;
%}
//Hi ashraf 5
%token INT FLOAT CHAR VOID SEMICOLON RETURN STRING
%token FOR WHILE 
%token IF ELSE
%token RBRACE LBRACE RBRACKET IDENTIFIER LBRACKET



%union {
  int intVal;
  char charVal;
  float floatVal;
  char* stringVal;
}
%token <charVal>  CHARVALUE
%token <intVal>   INTVALUE
%token <floatVal> FLOATVALUE
%token <strVal> STRINGVALUE



%right EQ NOT INC DEC
%left PLUS MULTIPLY MINUS DIVIDE AND_AND OR_OR
%left EQEQ LTEQ GT GTEQ LT NEQ
%%

start:Declaration
	;

/* Declaration block */
Declaration: Type IDENTIFIER SEMICOLON
  | Type IDENTIFIER EQ Assignment SEMICOLON
	| IDENTIFIER EQ Assignment SEMICOLON
	| IDENTIFIER INC SEMICOLON
	| IDENTIFIER DEC SEMICOLON
	| error	
	;

AnyValue: INTVALUE
		| FLOATVALUE
		| STRINGVALUE
		| CHARVALUE
		;
/* Assignment block */
Assignment: IDENTIFIER PLUS Assignment
	| IDENTIFIER MINUS Assignment
	| IDENTIFIER MULTIPLY Assignment
	| IDENTIFIER DIVIDE Assignment	
	| AnyValue PLUS Assignment
	| AnyValue MINUS Assignment
	| AnyValue MULTIPLY Assignment
	| AnyValue DIVIDE Assignment
	| LBRACKET Assignment RBRACKET
	| MINUS LBRACKET Assignment RBRACKET
	| MINUS AnyValue
	| MINUS IDENTIFIER
	| AnyValue
	| IDENTIFIER
	;


Stmt:	WhileStmt
	| Declaration
	| ForStmt
	| IfStmt
	;

/* Type Identifier block */
Type:	INT 
	| FLOAT
	| CHAR
	| STRING
	| VOID 
	;

/* Loop Blocks */ 
WhileStmt: WHILE LBRACKET Expr RBRACKET LBRACE Stmt RBRACE
	;

/* For Block */
ForStmt: FOR LBRACKET Expr SEMICOLON Expr SEMICOLON Expr RBRACKET Stmt 
       | FOR LBRACKET Expr RBRACKET Stmt 
	;

/* IfStmt Block */
IfStmt: IF LBRACKET Expr RBRACKET RBRACE Stmt LBRACE
	|IF LBRACKET Expr RBRACKET RBRACE Stmt LBRACE ELSE RBRACE Stmt LBRACE
	;


Operations: EQEQ
					| GT
					| LT
					| GTEQ
					| LTEQ
					| NEQ
					;
/*Expression Block*/
Expr:	
	| Expr Operations Expr
	| Expr AND_AND Expr
	| Expr OR_OR Expr
	| NOT LBRACKET Expr RBRACKET
	| Assignment
	;
%%
#include "lex.yy.c"

int count=0;
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");
	
	fclose(yyin);
    return 0;
}
         
yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         

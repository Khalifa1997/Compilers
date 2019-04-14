%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *fp;
%}

%token INT FLOAT CHAR VOID
%token FOR WHILE 
%token IF ELSE PRINTF 
%token STRUCT 
%token NUM ID
%token INCLUDE
%token DOT

%union {
  int INTVALUE;
  char CHARVALUE;
  float FLOATVALUE;
  string charVal;
}
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%%

start:Declaration
	;

/* Declaration block */
Declaration: Type IDENTIFIER SEMICOLON
    | Type IDENTIFIER EQ Assignment SEMICOLON
	| IDENTIFIER EQ Assignment SEMICOLON
	| error	
	;

/* Assignment block */
Assignment: IDENTIFIER PLUS Assignment
	| IDENTIFIER MINUS Assignment
	| IDENTIFIER MULTIPLY Assignment
	| IDENTIFIER DIVIDE Assignment	
	| INTVALUE PLUS Assignment
	| INTVALUE MINUS Assignment
	| INTVALUE MULTIPLY Assignment
	| INTVALUE DIVIDE Assignment
	| LBRACKET Assignment RBRACKET
	| MINUS LBRACKET Assignment RBRACKET
	| MINUS INTVALUE
	| MINUS IDENTIFIER
	| INTVALUE
	| IDENTIFIER
	;


StmtList:	StmtList Stmt
	|
	;
Stmt:	WhileStmt
	| Declaration
	| ForStmt
	| IfStmt
	| PrintFunc
	| ';'
	;

/* Type Identifier block */
Type:	INT 
	| FLOAT
	| CHAR
	| STRING
	| VOID 
	;

/* Loop Blocks */ 
WhileStmt: WHILE LBRACKET Expr RBRACKET Stmt  
	| WHILE LBRACKET Expr RBRACKET CompoundStmt 
	;

/* For Block */
ForStmt: FOR LBRACKET Expr SEMICOLON Expr SEMICOLON Expr RBRACKET Stmt 
       | FOR LBRACKET Expr SEMICOLON Expr SEMICOLON Expr RBRACKET CompoundStmt 
       | FOR LBRACKET Expr RBRACKET Stmt 
       | FOR LBRACKET Expr RBRACKET CompoundStmt 
	;

/* IfStmt Block */
IfStmt : IF LBRACKET Expr RBRACKET 
	 	Stmt 
	;

/* Print Function */
PrintFunc : PRINTF LBRACKET Expr RBRACKET ';'
	;

/*Expression Block*/
Expr:	
	| Expr LE Expr 
	| Expr GE Expr
	| Expr NE Expr
	| Expr EQ Expr
	| Expr GT Expr
	| Expr LT Expr
	| Assignment
	| ArrayUsage
	;
%%
#include"lex.yy.c"
#include<ctype.h>
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

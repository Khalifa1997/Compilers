%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *fp;
%}
%token INT FLOAT CHAR VOID SEMICOLON RETURN STRING DEFAULT
%token FOR WHILE 
%token IF ELSE
%token RBRACE LBRACE RBRACKET IDENTIFIER LBRACKET
%token SWITCH CASE COLON BREAK BOOLEAN LSQUARE RSQUARE COMMA DO TRUE FALSE COMMENT
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

start:Declarations
	;
Declarations: Declaration | Declarations Declaration
;

/* Declaration block */
Declaration: Type IDENTIFIER SEMICOLON
    | Type IDENTIFIER EQ Assignment SEMICOLON
	| IDENTIFIER EQ Assignment SEMICOLON
	| IDENTIFIER INC SEMICOLON
	| IDENTIFIER DEC SEMICOLON
	| Stmt
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



/*Expression Block*/
Expr:	
	Expr EQEQ Expr
	| Expr GT Expr
	| Expr GTEQ Expr
	| Expr LT Expr
	| Expr LTEQ Expr
	| Expr NEQ Expr
	| Expr AND_AND Expr
	| Expr OR_OR Expr
	| NOT LBRACKET Expr RBRACKET
	| Assignment
	;


Stmt:	WhileStmt
	| ForStmt
	| IfStmt
	| SS
	;

/* Type Identifier block */
Type:	INT 
	| FLOAT
	| CHAR
	| STRING
	| VOID 
	;

/* Loop Blocks */ 
WhileStmt: WHILE LBRACKET Expr RBRACKET LBRACE Declarations RBRACE
	;

/* For Block */
ForStmt: FOR LBRACKET CustomExprForFirst SEMICOLON Expr SEMICOLON CustomExprForThird RBRACKET LBRACE Declaration RBRACE  
	;
CustomExprForFirst: Type IDENTIFIER EQ Assignment
					| IDENTIFIER EQ Assignment
					;
CustomExprForThird:IDENTIFIER INC
									|IDENTIFIER DEC
									|IDENTIFIER INC EQ AnyValue
									|IDENTIFIER INC EQ IDENTIFIER
									|IDENTIFIER DEC EQ AnyValue
									|IDENTIFIER DEC EQ IDENTIFIER
									|IDENTIFIER MULTIPLY EQ AnyValue
									|IDENTIFIER MULTIPLY EQ IDENTIFIER
									|IDENTIFIER DIVIDE EQ AnyValue
									|IDENTIFIER DIVIDE EQ IDENTIFIER
									;
/* IfStmt Block */
IfStmt: IF LBRACKET Expr RBRACKET LBRACE Declarations RBRACE
	|IF LBRACKET Expr RBRACKET LBRACE Declarations RBRACE ELSE LBRACE Declarations RBRACE
	;


/*Switch Case Block*/

SS: SWITCH LBRACKET IDENTIFIER RBRACKET LBRACE B RBRACE 
	;
B: Cas | Cas Cas;

Cas :CASE Assignment COLON Declarations BREAK SEMICOLON
  | BREAK SEMICOLON
	| CASE Assignment COLON BREAK SEMICOLON
	| DEFAULT COLON Declarations BREAK SEMICOLON
	| DEFAULT COLON BREAK SEMICOLON
	;


%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

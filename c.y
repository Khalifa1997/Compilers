%{
#include <stdio.h>
#include <stdlib.h>
#include "symboltable.c"
extern FILE *fp;
%}
%token INT FLOAT CHAR VOID IDENTIFIER SEMICOLON RETURN STRING DEFAULT
%token FOR WHILE 
%token IF ELSE
%token RBRACE LBRACE RBRACKET LBRACKET
%token SWITCH CASE COLON BREAK BOOLEAN LSQUARE RSQUARE COMMA DO TRUE FALSE COMMENT
%union {
  int intVal;
  char charVal;
  float floatVal;
  char* stringVal;
}
%token <stringVal>  CHARVALUE
%token <intVal>   INTVALUE
%token <floatVal> FLOATVALUE
%token <stringVal> STRINGVALUE
%type <stringVal> Type
%type <stringVal> IDENTIFIER
%type <floatVal> MathAssignment
%type <floatVal> ExprAssignment
%type<stringVal> StringAnyValue
%type<floatVal> MathAnyValue



%type <stringVal> STRING
%type <stringVal> FLOAT
%type <stringVal> INT
%type <stringVal> VOID
%type <stringVal> CHAR




%right EQ NOT INC DEC
%left PLUS MULTIPLY MINUS DIVIDE AND_AND OR_OR
%left EQEQ LTEQ GT GTEQ LT NEQ
%%

start:Declarations
	;
Declarations: Declaration | Declarations Declaration
;

/* Declaration block */
Declaration: Type IDENTIFIER SEMICOLON { declare_variable($1, $2); }
    | Type IDENTIFIER EQ MathAssignment SEMICOLON  {declare_and_intialize($1, $2, $4);}
	| Type IDENTIFIER EQ StringAnyValue SEMICOLON {declare_initString($1,$2, $4);}
	| IDENTIFIER EQ MathAssignment SEMICOLON  {assignValue($1,$3);}
	| IDENTIFIER EQ StringAnyValue SEMICOLON	{assignValuetoString($1, $3);}
	| IDENTIFIER EQ STRING LBRACKET IDENTIFIER RBRACKET SEMICOLON {assignValuetoString($1,getStringValue($5));}
	| Type IDENTIFIER EQ STRING LBRACKET IDENTIFIER RBRACKET SEMICOLON {declare_initString($1,$2,getStringValue($6));}
	| IDENTIFIER INC SEMICOLON { printf("increemt"); IncrementValue($1);}
	| IDENTIFIER DEC SEMICOLON  
	| Stmt
	/*| error */	
	;

/* Assignment block */
MathAssignment: IDENTIFIER PLUS MathAssignment  {$$ = getValue($1) + $3;}
	| IDENTIFIER MINUS MathAssignment {$$ = getValue($1) - $3;}
	| IDENTIFIER MULTIPLY MathAssignment {$$ = getValue($1) * $3;}
	| IDENTIFIER DIVIDE MathAssignment {$$ = getValue($1) / $3;}
	| MathAnyValue PLUS MathAssignment
	| MathAnyValue MINUS MathAssignment
	| MathAnyValue MULTIPLY MathAssignment
	| MathAnyValue DIVIDE MathAssignment
	| LBRACKET MathAssignment RBRACKET {$$ = $2;}
	| LBRACKET MathAssignment RBRACKET PLUS MathAssignment {$$ = $2 + $5;}
	| LBRACKET MathAssignment RBRACKET MINUS MathAssignment {$$ = $2 - $5;}
	| LBRACKET MathAssignment RBRACKET MULTIPLY MathAssignment {$$ = $2 * $5;}
	| LBRACKET MathAssignment RBRACKET DIVIDE MathAssignment {$$ = $2 / $5;}
	| MINUS LBRACKET MathAssignment RBRACKET {$$ = -$3;}
	| MINUS LBRACKET MathAssignment RBRACKET PLUS MathAssignment {$$ = -$3 + $6;}
	| MINUS LBRACKET MathAssignment RBRACKET MINUS MathAssignment {$$ = -$3 - $6;}
	| MINUS LBRACKET MathAssignment RBRACKET MULTIPLY MathAssignment {$$ = -$3 * $6;}
	| MINUS LBRACKET MathAssignment RBRACKET DIVIDE MathAssignment {$$ = -$3 / $6;}
	| MINUS MathAnyValue {$$ = -$2;}
	| MINUS IDENTIFIER  {$$ = - (getValue($2));}
	| MathAnyValue {$$ = $1;}
	| IDENTIFIER {$$ = getValue($1);}
	;

MathAnyValue: INTVALUE {$$ = $1;}
		| FLOATVALUE {$$ = $1;}
		;

StringAnyValue:  STRINGVALUE  {$$ = $1;}
		| CHARVALUE {$$ = $1;}
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
	| LBRACKET Expr RBRACKET
	| LBRACKET Expr RBRACKET PLUS Expr
	| LBRACKET Expr RBRACKET MINUS Expr
	| LBRACKET Expr RBRACKET MULTIPLY Expr
	| LBRACKET Expr RBRACKET DIVIDE Expr
	| ExprAssignment
	;

ExprAssignment:IDENTIFIER PLUS ExprAssignment {$$ = getValue($1) + $3;}
	| IDENTIFIER MINUS ExprAssignment {$$ = getValue($1) - $3;}
	| IDENTIFIER MULTIPLY ExprAssignment {$$ = getValue($1) * $3;}
	| IDENTIFIER DIVIDE ExprAssignment	 {$$ = getValue($1) / $3;}
	| MathAnyValue PLUS ExprAssignment
	| MathAnyValue MINUS ExprAssignment
	| MathAnyValue MULTIPLY ExprAssignment
	| MathAnyValue DIVIDE ExprAssignment
	| MINUS LBRACKET ExprAssignment RBRACKET {$$ = -$3;}
	| MINUS MathAnyValue	{$$ = -$2;}
	| MINUS IDENTIFIER	 {$$ = - (getValue($2));}
	| MathAnyValue
	| IDENTIFIER {$$ = getValue($1);}
	;


Stmt:	WhileStmt
	| ForStmt
	| IfStmt
	| DoWhileStmt
	| SS
	;

/* Type Identifier block */
Type:	INT {$$ = $1;}
	| FLOAT {$$ = $1;}
	| CHAR {$$ = $1;}
	| STRING {$$ = $1;}
	| VOID  {$$ = $1;}
	;

/* Loop Blocks */ 
WhileStmt: WHILE LBRACKET Expr RBRACKET LBRACE Temp1 RBRACE
	;
Temp1 : Declarations | Declarations BREAK SEMICOLON | BREAK SEMICOLON;

DoWhileStmt: DO LBRACE Temp1 RBRACE WHILE LBRACKET Expr RBRACKET SEMICOLON
             ;

/* For Block */
ForStmt: FOR LBRACKET CustomExprForFirst SEMICOLON Expr SEMICOLON CustomExprForThird RBRACKET LBRACE Temp1 RBRACE  
	;

CustomExprForFirst: Type IDENTIFIER EQ MathAssignment {declare_and_intialize($1, $2, $4);}
					| IDENTIFIER EQ MathAssignment  {assignValue($1,$3);}
					;
CustomExprForThird:IDENTIFIER INC
									|IDENTIFIER DEC
									|IDENTIFIER INC EQ MathAnyValue
									|IDENTIFIER INC EQ IDENTIFIER
									|IDENTIFIER DEC EQ MathAnyValue
									|IDENTIFIER DEC EQ IDENTIFIER
									|IDENTIFIER MULTIPLY EQ MathAnyValue
									|IDENTIFIER MULTIPLY EQ IDENTIFIER
									|IDENTIFIER DIVIDE EQ MathAnyValue
									|IDENTIFIER DIVIDE EQ IDENTIFIER
									;
/* IfStmt Block */
IfStmt: IF LBRACKET Expr RBRACKET LBRACE Temp1 RBRACE
	|IF LBRACKET Expr RBRACKET LBRACE Temp1 RBRACE ELSE LBRACE Temp1 RBRACE
	;


/*Switch Case Block*/

SS: SWITCH LBRACKET IDENTIFIER RBRACKET LBRACE B RBRACE 
	;
B: Cas | Cas Cas;

Cas :CASE MathAssignment COLON Declarations BREAK SEMICOLON
|CASE StringAnyValue COLON Declarations BREAK SEMICOLON
  	| BREAK SEMICOLON
	| CASE MathAssignment COLON BREAK SEMICOLON
		| CASE StringAnyValue COLON BREAK SEMICOLON
	| DEFAULT COLON Declarations BREAK SEMICOLON
	| DEFAULT COLON BREAK SEMICOLON
	;


%%
main()
{
 return(yyparse());
printSemanticErrors();
printSymbolTable();
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

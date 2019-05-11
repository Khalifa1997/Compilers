%{
#include <stdio.h>
#include <stdlib.h>
#include "symboltable.c"
extern FILE *fp;
%}
%token INT FLOAT VOID IDENTIFIER SEMICOLON RETURN STRING DEFAULT
%token FOR WHILE 
%token IF ELSE
%token RBRACE LBRACE RBRACKET LBRACKET
%token SWITCH CASE COLON BREAK BOOLEAN LSQUARE RSQUARE COMMA DO TRUE FALSE COMMENT
%union {
  int intVal;
  float floatVal;
  char* stringVal;
}

%token <floatVal>   INTVALUE
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
    | Type IDENTIFIER EQ MathAssignment SEMICOLON  { 	if(strcmp($1,"int") ==0 || strcmp($1,"float") ==0 ) 
															declare_and_intialize($1, $2, $4);
															else {
															printf("Type mismatch");
															printf("\n");}
															}
	| Type IDENTIFIER EQ StringAnyValue SEMICOLON { if(strcmp($1,"string") == 0) 
														declare_initString($1,$2,$4);
														else 
														{printf("Type mismatch");
														printf("\n"); }
														}

	| IDENTIFIER EQ MathAssignment SEMICOLON  { if(strcmp(getDataType($1),"int") == 0 || strcmp(getDataType($1),"float") == 0 )
													 assignValue($1,$3);
													 else {
															printf("Type mismatch");
															printf("\n");}
															}
	| IDENTIFIER EQ StringAnyValue SEMICOLON	{ if(strcmp(getDataType($1),"string") == 0 )
												assignValuetoString($1, $3);
												 else 
															{printf("Type mismatch");
															printf("\n");}
															}
	| IDENTIFIER EQ STRING LBRACKET IDENTIFIER RBRACKET SEMICOLON {if(strcmp(getDataType($1),"string") == 0 )
															assignValuetoString($1,getStringValue($5));
															 else 
															 {
															printf("Type mismatch");
															printf("\n");} 
																	}
	| Type IDENTIFIER EQ STRING LBRACKET IDENTIFIER RBRACKET SEMICOLON { if(strcmp($1,"string") == 0)
																		declare_initString($1,$2,getStringValue($6));
																		 else 
																		 {
															printf("Type mismatch");
															printf("\n");}
															}
	| IDENTIFIER INC SEMICOLON { if(strcmp($1,"int") ==0 || strcmp($1,"float") ==0 )IncrementValue($1);
										else  
										{printf("Type mismatch");
															printf("\n");}
									}
	| IDENTIFIER DEC SEMICOLON  {if(strcmp($1,"int") ==0 || strcmp($1,"float") ==0) DecrementValue($1);
										else  
										{printf("Type mismatch");
															printf("\n");}
															}
	| Stmt
	/*| error */	
	;

/* Assignment block */


 MathAssignment: MathAssignment PLUS MathAssignment  { $$ = $1 + $3;}
	| MathAssignment MINUS MathAssignment {$$ = $1  - $3;}
	| MathAssignment MULTIPLY MathAssignment {$$ = $1  * $3;}
	| MathAssignment DIVIDE MathAssignment {$$ = $1  / $3;}
	| LBRACKET MathAssignment RBRACKET {$$ = ($2);}
	| MINUS MathAnyValue {$$ = - $2 ;}
	| MINUS IDENTIFIER  {$$ = - (getValue($2));}
	| MathAnyValue {$$ = $1;}
	| IDENTIFIER { int scopeornot =0;
					scopeornot = isinScope($1);
				
					if(scopeornot !=500)
						{
							if(strcmp(symbol[getIndex($1)].type,"int") == 0|| strcmp(symbol[getIndex($1)].type,"float") ==0 )
							$$ = (int)symbol[getIndex($1)].value;
							else {printf("Not compatible types");
								printf("\n");
							}
						
						}
					else if (scopeornot == 500) {
						printf("out of scope");
						printf("\n");
						}
				}
	;


MathAnyValue: INTVALUE {$$ = $1;}
		| FLOATVALUE {$$ = $1;}
		;

StringAnyValue: STRINGVALUE  {$$ = $1;}
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
	| MathAnyValue PLUS ExprAssignment {$$ = $1 + $3;}
	| MathAnyValue MINUS ExprAssignment {$$ = $1 - $3;}
	| MathAnyValue MULTIPLY ExprAssignment {$$ = $1 * $3;}
	| MathAnyValue DIVIDE ExprAssignment {$$ = $1 / $3;}
	| MINUS LBRACKET ExprAssignment RBRACKET {$$ = -$3;}
	| MINUS MathAnyValue	{$$ = -$2;}
	| MINUS IDENTIFIER	 {$$ = - (getValue($2));}
	| MathAnyValue {$$ = $1;}
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
	| STRING {$$ = $1;}
	;

/* Loop Blocks */ 
WhileStmt: WHILE LBRACKET Expr RBRACKET LBRACE  {curlyBraceIsOpened();}
Temp1 RBRACE {curlyBraceIsClosed();} 
	;
Temp1 : Declarations | Declarations BREAK SEMICOLON | BREAK SEMICOLON | ;

DoWhileStmt: DO LBRACE 
{curlyBraceIsOpened();} Temp1 RBRACE {curlyBraceIsClosed();}  WHILE LBRACKET Expr RBRACKET SEMICOLON
             ;

/* For Block */
ForStmt: FOR {curlyBraceIsOpened();}  LBRACKET CustomExprForFirst SEMICOLON Expr SEMICOLON CustomExprForThird RBRACKET LBRACE
  Temp1 RBRACE  {curlyBraceIsClosed();}
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
IfStmt: IF LBRACKET Expr RBRACKET LBRACE {curlyBraceIsOpened();} Temp1 RBRACE {curlyBraceIsClosed();} 
ELSE LBRACE  {curlyBraceIsOpened();}  Temp1 RBRACE {curlyBraceIsClosed();} 
	;


/*Switch Case Block*/

SS: SWITCH LBRACKET IDENTIFIER RBRACKET LBRACE {curlyBraceIsOpened();}  B RBRACE  {curlyBraceIsClosed();} 
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

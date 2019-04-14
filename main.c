#include <stdio.h>
#include "defs.h"
extern int yylex();  // gets token id
extern int yylineno; // has token line number
extern char *yytext; // has token value

int main(void)
{
	int token;
	token = yylex();
	while (token)
	{
		//token = yylex();
		if (token != INTVALUE && token != CHARVALUE && token != STRING)
		{
			printf("Expected a value at line %d but found %s \n", yylineno, yytext);
			return 1;
		}
		token = yylex();
	}
	printf("Done!\n");
	return 0;
}
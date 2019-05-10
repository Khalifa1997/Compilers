#define nsyms 100
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
extern int yylineno;
extern char *yytext;
int noOfIdentifiers = 0;
int Scope = 0;
int noOfErrors = 0;
char *semanticerrors[100];

void printSymbolTable();
void declare_variable(char *datatype, char *ID);
bool isDuplicate(char *datatype, char *ID);
void declare_and_intialize(char *datatype, char *ID, float IntialValue);
void declare_initString(char *datatype, char *ID, char *IntialValue);
bool varExists(char *ID);
bool varIntialized(char *ID);
void curlyBraceIsOpened();
void curlyBraceIsClosed();
bool isinScope(char *ID);
int getIndex(char *ID);
char *getDataType(char *ID);
float getValue(char *ID);
void printSemanticErrors();
void assignValue(char *ID, float value);
void assignValuetoString(char *ID, char *value);
char* getStringValue(char *ID);
void IncrementValue(char*ID);
void DecrementValue(char*ID);

struct symbol
{
    char *name;
    char *type;
    float value;
    char *stringValue;
    bool isintialized;
    int Scope;
} symbol[100];
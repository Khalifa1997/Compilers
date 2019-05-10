#include "symboltable.h"
void printSymbolTable()
{
    int i;
    for (i = 0; i < noOfIdentifiers; i++)
    {
        printf("type: %s , name: %s, value:%f, stringVal: %s \n", symbol[i].type, symbol[i].name, symbol[i].value, symbol[i].stringValue);
    }
}
bool isDuplicate(char *datatype, char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (strcmp(ID, symbol[i].name) == 0)
        {
            return true;
        }
    }
    return false;
}
void declare_variable(char *datatype, char *ID)
{
    if (noOfIdentifiers < 99)
    {
        if (isDuplicate(datatype, ID))
        {

            printf("\nError found Line: %d : \n Duplicate identifier '%s' found.\n", yylineno, ID);
            char c[100] = "\nERROR ON LINE :   ";
            strcat(c, itoa_customized(yylineno));
            strcat(c, "\nDuplicate identifier found:  ");
            strcat(c, ID);
            strcat(c, "\0");
            strcpy(semanticerrors[noOfErrors], c);
            noOfErrors++;
            return;
        }

        symbol[noOfIdentifiers].type = datatype;
        symbol[noOfIdentifiers].name = ID;
        symbol[noOfIdentifiers].isintialized = false;
        symbol[noOfIdentifiers].Scope = Scope;
        noOfIdentifiers++;
    }
    else
    {
        printf("\n Memory Overflow");
        char c[100] = "\n Memory Overflow";
        strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
}
void declare_and_intialize(char *datatype, char *ID, float val)
{
    if (noOfIdentifiers < 99)
    {
        if (isDuplicate(datatype, ID))
        {
            printf("\nError found Line: %d : \n Duplicate identifier '%s' found.\n", yylineno, ID);
            char c[100] = "\nERROR ON LINE :   ";
            strcat(c, itoa_customized(yylineno));
            strcat(c, "\nDuplicate identifier found:  ");
            strcat(c, ID);
            strcat(c, "\0");
            strcpy(semanticerrors[noOfErrors], c);
            noOfErrors++;
            return;
        }
        else
        {

            symbol[noOfIdentifiers].name = ID;
            symbol[noOfIdentifiers].isintialized = true;
            symbol[noOfIdentifiers].Scope = Scope;
            if (strcmp(datatype, "float") == 0)
            {
                symbol[noOfIdentifiers].type = "float";
                symbol[noOfIdentifiers].value = val;
            }
            else if (strcmp(datatype, "int") == 0)
            {
                symbol[noOfIdentifiers].type = "int";
                symbol[noOfIdentifiers].value = (int)val;
            }
            noOfIdentifiers++;
        }
    }
}
void declare_initString(char *datatype, char *ID, char *val)
{

    if (noOfIdentifiers < 99)
    {
        if (isDuplicate(datatype, ID))
        {
            printf("\nError found Line: %d : \n Duplicate identifier '%s' found.\n", yylineno, ID);
            char c[100] = "\nERROR ON LINE :   ";
            strcat(c, itoa_customized(yylineno));
            strcat(c, "\nDuplicate identifier found:  ");
            strcat(c, ID);
            strcat(c, "\0");
            strcpy(semanticerrors[noOfErrors], c);
            noOfErrors++;
            return;
        }
        else
        {
            strcpy(symbol[noOfIdentifiers].stringValue, val);
            symbol[noOfIdentifiers].isintialized = true;
            symbol[noOfIdentifiers].name = ID;
            symbol[noOfIdentifiers].Scope = Scope;
            symbol[noOfIdentifiers].type = datatype;
            noOfIdentifiers++;
        }
    }
}
bool varExists(char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (strcmp(symbol[i].name, ID) == 0)
        {
            return true;
        }
    }
    return false;
}
bool varIntialized(char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (strcmp(symbol[i].name, ID) == 0 && symbol[i].isintialized == true)
        {
            return true;
        }
    }
    return false;
}
void curlyBraceIsOpened()
{
    Scope++;
}
void curlyBraceIsClosed()
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].Scope == Scope && Scope != 0)
        {
            symbol[i].Scope = -1;
        }
    }

    Scope--;
}
bool isinScope(char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].name == ID && symbol[i].Scope == Scope)
        {
            return true;
        }
    }
    return false;
}
int getIndex(char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].name == ID)
        {
            return i;
        }
    }
    return -1;
}
char *getDataType(char *ID)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].name == ID)
        {
            return symbol[i].type;
        }
    }
    return "";
}
void printSemanticErrors()
{
    for (int i = 0; i < noOfErrors; i++)
    {
        char *newstr = malloc(strlen(semanticerrors[i]) + 2);
        strcat(newstr, semanticerrors[i]);
        strcat(newstr, "\n");
        printf(newstr);
    }
}
void assignValue(char *ID, float value)
{

    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].name = ID)
        {
            symbol[i].value = value;
        }
    }
}
void assignValuetoString(char *ID, char *value)
{
    for (int i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].name = ID)
        {
            strcpy(symbol[i].stringValue, value);
        }
    }
}
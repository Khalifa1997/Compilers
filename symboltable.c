#include "symboltable.h"


 char* itoa_customized(int number){
   static char buffer[33];
   snprintf(buffer, sizeof(buffer), "%d", number);
   return buffer;
}

void unusedvariables()
{
  int i;
  for(i=0;i<noOfIdentifiers;i++)
  {
    if(symbol[i].isintialized==0)
    {
        char c[100] = "\nSemantic Error: unused variable : ";
        strcat(c,symbol[i].name);
        strcat(c,"\0");
        // strcpy(semanticerrors[noOfErrors],c);
        noOfErrors ++; 
    }
  }
}


void printSemanticErrors()
{
int count=0;
  unusedvariables();
  int i;
  for(i=0; i <= noOfErrors; i++)
  {
    printf("\n '%s' \n",(char*)semanticerrors[i]);
count++;
  }
if(count==0)
{
printf("No error");
}
}


void printSymbolTable()
{
    int i;
    for (i = 0; i < noOfIdentifiers; i++)
    {
        if(symbol[i].Scope != -1)
        printf("type: %s , name: %s, value:%f, stringVal: %s, Scope: %i \n", symbol[i].type, symbol[i].name, symbol[i].value, symbol[i].stringValue,symbol[i].Scope);
    }
}
bool isDuplicate(char *datatype, char *ID)
{
    int i ;
    for (i = 0; i < noOfIdentifiers; i++)
    {
        if (strcmp(ID, symbol[i].name) == 0 && symbol[i].Scope != symbol[getIndex(ID)].Scope)
        {
            return true;
        }
    }
    return false;
}
void declare_variable(char *datatype, char *ID)
{
    printf("Declaring Variable : ");
printf("\n");
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
    //        // strcpy(semanticerrors[noOfErrors], c);
            noOfErrors++;
            return;
        }
        symbol[noOfIdentifiers].type = datatype;
        symbol[noOfIdentifiers].name = ID;
        symbol[noOfIdentifiers].isintialized = false;
        symbol[noOfIdentifiers].Scope = Scope;
        symbol[noOfIdentifiers].stringValue = " ";
        noOfIdentifiers++;
        printSymbolTable();
    }
    else
    {
        printf("\n Memory Overflow");
        char c[100] = "\n Memory Overflow";
        // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
}
void declare_and_intialize(char *datatype, char *ID, float val)
{
    printf("Declaring and intializing : ");
    printf("\n");
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
            // strcpy(semanticerrors[noOfErrors], c);
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
   printSymbolTable(); 
}

void declare_initString(char *datatype, char *ID, char *val)
{
    printf("Declaring String : ");
printf("\n");
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
            // strcpy(semanticerrors[noOfErrors], c);
            noOfErrors++;
            return;

        }
        else
        {
            //// strcpy(symbol[noOfIdentifiers].stringValue, val);
            symbol[noOfIdentifiers].stringValue = val;
            symbol[noOfIdentifiers].isintialized = true;
            symbol[noOfIdentifiers].name = ID;
            symbol[noOfIdentifiers].Scope = Scope;
            symbol[noOfIdentifiers].type = datatype;
            noOfIdentifiers++;
            printSymbolTable();
        }
    }
}
bool varExists(char *ID)
{
   int i ;
    for (i=0; i < noOfIdentifiers; i++)
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
    int i ;
    for (i = 0; i < noOfIdentifiers; i++)
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
    int i ;
    for (i = 0; i < noOfIdentifiers; i++)
    {
        if (symbol[i].Scope == Scope && Scope != 0)
        {
            symbol[i].Scope = -1;
        }
    }

    Scope--;

}

int isinScope(char *ID)
{
    int index = 0;
    index =getIndex(ID);
     int j=0;
     j= Scope;
      int i =0;
      for(j = Scope ; j >=0 ; j--)
      {
   for (i = 0; i < noOfIdentifiers; i++)
         {
         
            if (strcmp(symbol[i].name,ID) == 0  && symbol[i].Scope == j)
            {
                 return i;
            }
         }
         }
    return 500; //not found
}


int getIndex(char *ID)
{

    int i ;
    for ( i = 0; i < noOfIdentifiers; i++)
    {
        

        if(strcmp(ID,symbol[i].name) ==0)
        {
            return i;

        }
    }
    return -1;
}

char *getDataType(char *ID)
{
    int i ;
    for ( i = 0; i < noOfIdentifiers; i++)
    {
        if (strcmp(symbol[i].name,ID)==0 )
        {
            return symbol[i].type;
        }
    }
    return "no";
}


int isDeclared(char* ID){
int i;
for(i=0; i<noOfIdentifiers; i++){
  if(strcmp(symbol[i].name,ID) == 0){
    return 1;
  }
}
    return 0;
}

void assignValue(char *ID, float value)
{
  printf("Assigning: ");
  printf("\n");
  
    if (isDeclared(ID) == false)
    {
        printf("vaiable not declared ");
        printf("\n");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }

   int scopeornot = isinScope(ID);

    if (isinScope(ID) == 500)
    {
        printf("out of scope ");
        printf("\n");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable doesn't exist in scope:  ");
        strcat(c, ID);
        strcat(c, "\0");
//// // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
        if(strcmp(symbol[scopeornot].type,"float") == 0)
            symbol[scopeornot].value = (float)value;
            else if((strcmp(symbol[scopeornot].type,"int") == 0))
            symbol[scopeornot].value = (int)value;
            else
            {
                char c[100] = "\nError on line ";
                strcat(c, itoa_customized(yylineno));
                strcat(c, "\nType mismatch! variable ");
                strcat(c, ID);
                strcat(c, "of type ");
                strcat(c, symbol[scopeornot].type);
                strcat(c, "cannot be assigned this value ");
                strcat(c, "\0");
               // // // strcpy(semanticerrors[noOfErrors], c);
                noOfErrors++;
            }

            if (!symbol[scopeornot].isintialized)
            {
                symbol[scopeornot].isintialized = true;
            }
            printSymbolTable();

}
void assignValuetoString(char *ID, char *value)
{
printf("Assigning String : ");
printf("\n");
   int index =0;
   index = getIndex(ID) ;

    if (isDeclared(ID) == false)
    {
        printf("vaiable not declared ");
        printf("\n");
        // yyerror("UnDeclared Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }

int scopeornot = 0;
scopeornot = isinScope(ID);
    if (scopeornot == 500)
    {
        printf("out of scope ");
        printf("\n");
        yyerror("out of scope Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable doesn't exist in scope:  ");
        strcat(c, ID);
        strcat(c, "\0");
      //  // // strcpy(semanticerrors[noOfErrors], c);
         noOfErrors++;
        return;
    }

   
    symbol[scopeornot].stringValue = value;
    symbol[scopeornot].isintialized = true;


    printSymbolTable();
}


float getValue(char *ID)
{
     if (isDeclared(ID) == false)
    {
        printf("vaiable not declared ");
        printf("\n");
        // yyerror("UnDeclared Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }



    if(varIntialized(ID) == false)
    {
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable not initialized:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
  
   int index = 0;
   index = getIndex(ID);

    if(index != -1)
    {
   char* ID_datatype = getDataType(ID);
      if(strcmp(ID_datatype,"string") == 0 || strcmp(ID_datatype,"char") == 0 || strcmp(ID_datatype,"boolean") == 0)
      {
          char c[100] = "\nERROR ON LINE :   ";
          strcat(c,itoa_customized(yylineno));
          strcat(c,"\ncannot use variable ");
          strcat(c,ID);
          strcat(c,"of type ");
          strcat(c,ID_datatype);
          strcat(c,"in a mathematical or logical expression ");
          strcat(c,"\0");
          // // strcpy(semanticerrors[noOfErrors],c);
          noOfErrors ++;  
      }
else{
        return symbol[index].value;
}
      
    }
      
}




char* getStringValue(char*ID)
{

    if (isDeclared(ID) == false)
    {
       printf("vaiable not declared ");
        printf("\n");
        // yyerror("UnDeclared Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }

    if (isinScope(ID) == 500)
    {
        //yyerror("out of scope Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable doesn't exist in scope:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }

    if(varIntialized(ID) == false)
    {
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable not initialized:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }

   
   
   int index = getIndex(ID);
   
    if(index != -1)
    {
   char* ID_datatype = getDataType(ID);
      if(strcmp(ID_datatype,"int") == 0 || strcmp(ID_datatype,"float") == 0 )
      {
          char c[100] = "\nERROR ON LINE :   ";
          strcat(c,itoa_customized(yylineno));
          strcat(c,"\ncannot use variable ");
          strcat(c,ID);
          strcat(c,"of type ");
          strcat(c,ID_datatype);
          strcat(c,"in a mathematical or logical expression ");
          strcat(c,"\0");
          // // strcpy(semanticerrors[noOfErrors],c);
          noOfErrors ++;  
      }
else{
        return symbol[index].stringValue;
}
      
    }
    
}







void IncrementValue(char*ID)
{
   int index=0;
index = getIndex(ID);
printf(" Incrementing ");

printf("\n");

     if (isDeclared(ID) == false)
    {
        printf("vaiable not declared ");
        printf("\n");
        // yyerror("UnDeclared Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        //// // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }


  if(varIntialized(ID) == false)
    {

        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable not initialized:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
    
int scopeornot = 0;
scopeornot = isinScope(ID);

    if (scopeornot == 500)
    {
        //yyerror("out of scope Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable doesn't exist in scope:  ");
        strcat(c, ID);
        strcat(c, "\0");
        //// // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }



    symbol[scopeornot].value = symbol[scopeornot].value+1;
    printSymbolTable();
    return;
    

}

void DecrementValue(char*ID)
{
int index=0;
index = getIndex(ID);

printf(" Decrementing ");

printf("\n");


     if (isDeclared(ID) == false)
    {
        printf("vaiable not declared ");
        printf("\n");
        // yyerror("UnDeclared Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\nUndeclared variable:  ");
        strcat(c, ID);
        strcat(c, "\0");
        //// // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }


  if(varIntialized(ID) == false)
    {

        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable not initialized:  ");
        strcat(c, ID);
        strcat(c, "\0");
        // // strcpy(semanticerrors[noOfErrors], c);
        noOfErrors++;
        return;
    }
    
int scopeornot = 0;
scopeornot = isinScope(ID);

    if (scopeornot == 500)
    {
        //yyerror("out of scope Variable!");
        char c[100] = "\n Error on line ";
        strcat(c, itoa_customized(yylineno));
        strcat(c, "\n Variable doesn't exist in scope:  ");
        strcat(c, ID);
        strcat(c, "\0");
        //// // strcpy(semanticerrors[noOfErrors], c);
        printf("out of scope ");
        printf("\n");


        noOfErrors++;
        return;
    }



    symbol[scopeornot].value = symbol[scopeornot].value-1;
    printSymbolTable();
    return;
    


}
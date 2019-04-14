/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    VOID = 261,
    SEMICOLON = 262,
    RETURN = 263,
    STRING = 264,
    DEFAULT = 265,
    FOR = 266,
    WHILE = 267,
    IF = 268,
    ELSE = 269,
    RBRACE = 270,
    LBRACE = 271,
    RBRACKET = 272,
    IDENTIFIER = 273,
    LBRACKET = 274,
    SWITCH = 275,
    CASE = 276,
    COLON = 277,
    BREAK = 278,
    CHARVALUE = 279,
    INTVALUE = 280,
    FLOATVALUE = 281,
    STRINGVALUE = 282,
    EQ = 283,
    NOT = 284,
    INC = 285,
    DEC = 286,
    PLUS = 287,
    MULTIPLY = 288,
    MINUS = 289,
    DIVIDE = 290,
    AND_AND = 291,
    OR_OR = 292,
    EQEQ = 293,
    LTEQ = 294,
    GT = 295,
    GTEQ = 296,
    LT = 297,
    NEQ = 298
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define CHAR 260
#define VOID 261
#define SEMICOLON 262
#define RETURN 263
#define STRING 264
#define DEFAULT 265
#define FOR 266
#define WHILE 267
#define IF 268
#define ELSE 269
#define RBRACE 270
#define LBRACE 271
#define RBRACKET 272
#define IDENTIFIER 273
#define LBRACKET 274
#define SWITCH 275
#define CASE 276
#define COLON 277
#define BREAK 278
#define CHARVALUE 279
#define INTVALUE 280
#define FLOATVALUE 281
#define STRINGVALUE 282
#define EQ 283
#define NOT 284
#define INC 285
#define DEC 286
#define PLUS 287
#define MULTIPLY 288
#define MINUS 289
#define DIVIDE 290
#define AND_AND 291
#define OR_OR 292
#define EQEQ 293
#define LTEQ 294
#define GT 295
#define GTEQ 296
#define LT 297
#define NEQ 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "c.y" /* yacc.c:1909  */

  int intVal;
  char charVal;
  float floatVal;
  char* stringVal;

#line 147 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

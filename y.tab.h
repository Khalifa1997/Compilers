/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    BOOLEAN = 279,
    LSQUARE = 280,
    RSQUARE = 281,
    COMMA = 282,
    DO = 283,
    TRUE = 284,
    FALSE = 285,
    COMMENT = 286,
    CHARVALUE = 287,
    INTVALUE = 288,
    FLOATVALUE = 289,
    STRINGVALUE = 290,
    EQ = 291,
    NOT = 292,
    INC = 293,
    DEC = 294,
    PLUS = 295,
    MULTIPLY = 296,
    MINUS = 297,
    DIVIDE = 298,
    AND_AND = 299,
    OR_OR = 300,
    EQEQ = 301,
    LTEQ = 302,
    GT = 303,
    GTEQ = 304,
    LT = 305,
    NEQ = 306
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
#define BOOLEAN 279
#define LSQUARE 280
#define RSQUARE 281
#define COMMA 282
#define DO 283
#define TRUE 284
#define FALSE 285
#define COMMENT 286
#define CHARVALUE 287
#define INTVALUE 288
#define FLOATVALUE 289
#define STRINGVALUE 290
#define EQ 291
#define NOT 292
#define INC 293
#define DEC 294
#define PLUS 295
#define MULTIPLY 296
#define MINUS 297
#define DIVIDE 298
#define AND_AND 299
#define OR_OR 300
#define EQEQ 301
#define LTEQ 302
#define GT 303
#define GTEQ 304
#define LT 305
#define NEQ 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "c.y" /* yacc.c:1909  */

  int intVal;
  char charVal;
  float floatVal;
  char* stringVal;

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

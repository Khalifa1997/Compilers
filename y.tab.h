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
    VOID = 260,
    IDENTIFIER = 261,
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
    LBRACKET = 273,
    SWITCH = 274,
    CASE = 275,
    COLON = 276,
    BREAK = 277,
    BOOLEAN = 278,
    LSQUARE = 279,
    RSQUARE = 280,
    COMMA = 281,
    DO = 282,
    TRUE = 283,
    FALSE = 284,
    COMMENT = 285,
    INTVALUE = 286,
    FLOATVALUE = 287,
    STRINGVALUE = 288,
    EQ = 289,
    NOT = 290,
    INC = 291,
    DEC = 292,
    PLUS = 293,
    MULTIPLY = 294,
    MINUS = 295,
    DIVIDE = 296,
    AND_AND = 297,
    OR_OR = 298,
    EQEQ = 299,
    LTEQ = 300,
    GT = 301,
    GTEQ = 302,
    LT = 303,
    NEQ = 304
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define IDENTIFIER 261
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
#define LBRACKET 273
#define SWITCH 274
#define CASE 275
#define COLON 276
#define BREAK 277
#define BOOLEAN 278
#define LSQUARE 279
#define RSQUARE 280
#define COMMA 281
#define DO 282
#define TRUE 283
#define FALSE 284
#define COMMENT 285
#define INTVALUE 286
#define FLOATVALUE 287
#define STRINGVALUE 288
#define EQ 289
#define NOT 290
#define INC 291
#define DEC 292
#define PLUS 293
#define MULTIPLY 294
#define MINUS 295
#define DIVIDE 296
#define AND_AND 297
#define OR_OR 298
#define EQEQ 299
#define LTEQ 300
#define GT 301
#define GTEQ 302
#define LT 303
#define NEQ 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "c.y" /* yacc.c:1909  */

  int intVal;
  float floatVal;
  char* stringVal;

#line 158 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

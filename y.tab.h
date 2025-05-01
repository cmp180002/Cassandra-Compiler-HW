/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KWPROGRAM = 258,               /* KWPROGRAM  */
    KWCALL = 259,                  /* KWCALL  */
    KWFUNCTION = 260,              /* KWFUNCTION  */
    KWGLOBAL = 261,                /* KWGLOBAL  */
    KWINT = 262,                   /* KWINT  */
    KWSTRING = 263,                /* KWSTRING  */
    SEMICOLON = 264,               /* SEMICOLON  */
    LPAREN = 265,                  /* LPAREN  */
    RPAREN = 266,                  /* RPAREN  */
    LBRACE = 267,                  /* LBRACE  */
    RBRACE = 268,                  /* RBRACE  */
    NUMBER = 269,                  /* NUMBER  */
    ADDOP = 270,                   /* ADDOP  */
    COMMA = 271,                   /* COMMA  */
    EQUALS = 272,                  /* EQUALS  */
    KWWHILE = 273,                 /* KWWHILE  */
    KWDO = 274,                    /* KWDO  */
    KWIF = 275,                    /* KWIF  */
    KWTHEN = 276,                  /* KWTHEN  */
    KWELSE = 277,                  /* KWELSE  */
    KWRETURNVAL = 278,             /* KWRETURNVAL  */
    RELOP = 279,                   /* RELOP  */
    LBRACKET = 280,                /* LBRACKET  */
    RBRACKET = 281,                /* RBRACKET  */
    KWLOCAL = 282,                 /* KWLOCAL  */
    ID = 283,                      /* ID  */
    STRING = 284                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KWPROGRAM 258
#define KWCALL 259
#define KWFUNCTION 260
#define KWGLOBAL 261
#define KWINT 262
#define KWSTRING 263
#define SEMICOLON 264
#define LPAREN 265
#define RPAREN 266
#define LBRACE 267
#define RBRACE 268
#define NUMBER 269
#define ADDOP 270
#define COMMA 271
#define EQUALS 272
#define KWWHILE 273
#define KWDO 274
#define KWIF 275
#define KWTHEN 276
#define KWELSE 277
#define KWRETURNVAL 278
#define RELOP 279
#define LBRACKET 280
#define RBRACKET 281
#define KWLOCAL 282
#define ID 283
#define STRING 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parser.y"
 
   int ival;  // for most scanner tokens
   char* str; // tokens that need a string, like ID and STRING
   struct astnode_s * astnode; // for all grammar nonterminals

#line 131 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

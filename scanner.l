/****
* Cassandra Palmer | 800908441
* CS 466 | Spring 2025 | 4/17/25
* Compiler 6: Local variables, parameters, and arrays  
*
* Lex scanner for basic compiler
****/

/****** Header definitions ******/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// The ifndef below allows this scanner definition to be
// used either with a yacc generated parser or all by
// itself (if LEXONLY is defined)
#ifndef LEXONLY
// definitions are auto-created by yacc so just include them
#include "y.tab.h"
extern int debug; // declared and set in parser.y
#else
// we must have explicit definitions for standalone mode
typedef union { int ival; char* str; } yystype;
#define YYSTYPE yystype
yystype yylval;
#define KWPROGRAM      1
#define LBRACE         2
#define RBRACE         3
#define KWCALL         4
#define ID             5
#define LPAREN         6
#define STRING         7
#define RPAREN         8
#define SEMICOLON      9
#define KWFUNCTION     10
#define NUMBER         11
#define COMMA          12
#define ADDOP		   13
#define EQUALS  	   14
#define KWGLOBAL	   15
#define KWINT		   16
#define KWSTRING       17
#define KWWHILE		   18
#define KWDO		   19
#define KWWHILE		   20
#define KWIF		   21
#define KWTHEN		   22
#define KWELSE		   23
#define KWRETURNVAL	   24
#define RELOP		   25
#define LBRACKET	   26
#define RBRACKET	   27
#define KWLOCAL		   28
#endif
%}

/* This option is useful for printing out a syntax error */
/* message and printing out the line # it occurred on */
%option yylineno

/****** Token Patterns (regular expressions) ******/
%%
[ \t\n\r]+ { /* skip white space and do not return a token */ }
program  {
            if (debug) printf("lex: program\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWPROGRAM);
         }
function {
			if (debug) printf("lex: function\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWFUNCTION);
		 }
call     {
            if (debug) printf("lex: call\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWCALL);
         }
int      {
            if (debug) printf("lex: int\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWINT);
         }
string   {
            if (debug) printf("lex: string\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWSTRING);
         }       
global   {
		  	if (debug) printf("lex: global\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWGLOBAL);
         }
local   {
		  	if (debug) printf("lex: local\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWLOCAL);
         }
while    {
		  	if (debug) printf("lex: while\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWWHILE);
         }
do       {
		  	if (debug) printf("lex: do\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWDO);
         }
if       {
		  	if (debug) printf("lex: if\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWIF);
         }
then     {
		  	if (debug) printf("lex: then\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWTHEN);
         }
else     {
		  	if (debug) printf("lex: else\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWELSE);
         }
returnvalue      {
		  	if (debug) printf("lex: returnvalue\n");
            yylval.str = strdup(yytext);
            free(yylval.str);
            return(KWRETURNVAL);
         }
\<       {
            if (debug) printf("lex: less than\n");
            yylval.ival = yytext[0];
            return(RELOP);
         }
\>       {
            if (debug) printf("lex: greater than\n");
            yylval.ival = yytext[0];
            return(RELOP);
         }
\=\=     {
            if (debug) printf("lex: equal cond\n");
            yylval.ival = yytext[0];
            return(RELOP);
         }
\!\=     {
            if (debug) printf("lex: not equal\n");
            yylval.ival = yytext[0];
            return(RELOP);
         }
\{       {
            if (debug) printf("lex: left brace\n");
            yylval.ival = yytext[0];
            return(LBRACE);
         }
\}       {
            if (debug) printf("lex: right brace\n");
            yylval.ival = yytext[0];
            return(RBRACE);
         }
\(       {
            if (debug) printf("lex: left paren\n");
            yylval.ival = yytext[0];
            return(LPAREN);
         }
\)       {
            if (debug) printf("lex: right paren\n");
            yylval.ival = yytext[0];
            return(RPAREN);
         }
\;       {
            if (debug) printf("lex: semicolon\n");
            yylval.ival = yytext[0];
            return(SEMICOLON);
         }
\,       {
            if (debug) printf("lex: comma\n");
            yylval.ival = yytext[0];
            return(COMMA);
         }
\+ 	     {
            if (debug) printf("lex: plus\n");
            yylval.ival = yytext[0];
            return(ADDOP);
         }
\-       {
			if (debug) printf("lex: minus\n");
            yylval.ival = yytext[0];
            return(ADDOP);
         }
\=		 {
			if (debug) printf("lex: equals\n");
            yylval.ival = yytext[0];
            return(EQUALS);
		 }
\[		 {
			if (debug) printf("lex: left bracket\n");
            yylval.ival = yytext[0];
            return(LBRACKET);
		 }
\]		 {
			if (debug) printf("lex: right bracket\n");
            yylval.ival = yytext[0];
            return(RBRACKET);
		 }
[a-zA-Z_][a-zA-Z0-9_]* {
            if (debug) printf("lex: identifier (%s)\n", yytext);
            yylval.str = strdup(yytext);
            return(ID);
         }
[0-9]+   {
            if (debug) printf("lex: number\n");
            yylval.ival = strtol(yytext,0,10);
            return(NUMBER);
         }
\"[^"]*\" {
            if (debug) printf("lex: string (%s)\n", yytext);
            yylval.str = strdup(yytext);
            return(STRING);
         }
.        {
            // this rule matches any single char not matched above
            fprintf(stderr, "lex: unknown char (%c)\n", yytext[0]);
         }

%%
/****** Functions (not used when used with parser) *******/

//
// Code in the ifdef block below is only for compiling the
// scanner all by itself, for testing purposes. The 
// Makefile shows how to compile it under the "ltest" rule
// (do "make ltest" to build it)
//
#ifdef LEXONLY

// A main for standalone testing (uses just stdin as input)
int main(int argc, char **argv) 
{
   do {
      yylex();
   } while (1);
   // while (!feof(stdin)); doesn't work if redirecting a file
   // in because the file is read in and buffered, and eof is
   // true too early, causing lex to stop; rather, use while(1)
   // and then do a hard exit in yywrap(); ugly, but works!
   return 0;
}

int yywrap()
{
   exit(0); // hard exit!
   //return(1);
}

#endif // LEXONLY




/****
* Cassandra Palmer | 800908441
* CS 466 | Spring 2025 | 4/14/25
* Compiler 5: Loops and conditionals
*
* Yacc parser for basic compiler
*
* Grammar:
* wholeprogram -> globals functions program
* program -> KWPROGRAM LBRACE statements RBRACE
* functions -> function functions | empty
* function -> KWFUNCTION ID LPAREN parameters RPAREN LBRACE localvars statements RBRACE
* statements -> statement statements | empty
* statement -> funcall | assignment | ifthenelse | whileloop | returnstmt
* funcall -> KWCALL ID LPAREN arguments RPAREN SEMICOLON
* assignment -> ID EQUALS expression SEMICOLON | ID LBRACKET expression RBRACKET EQUALS expression SEMICOLON
* arguments -> empty | argument | argument COMMA arguments
* argument -> expression
* expression -> NUMBER | ID | ID LBRACKET expression RBRACKET | STRING | KWRETURNVAL | expression ADDOP expression
* globals -> empty | KWGLOBAL vardecl SEMICOLON globals
* vardecl -> KWINT ID | KWSTRING ID | KWINT ID LBRACKET NUMBER RBRACKET
* parameters -> empty | paramdecl | paramdecl COMMA parameters
* paramdecl -> KWINT ID | KWSTRING ID
* localvars -> empty | KWLOCAL localdecl SEMICOLON localvars
* localdecl -> KWINT ID | KWSTRING ID
* ifthenelse -> KWIF LPAREN boolexpr RPAREN KWTHEN LBRACE statements RBRACE KWELSE LBRACE statements RBRACE
* whileloop -> KWWHILE LPAREN boolexpr RPAREN KWDO LBRACE statements RBRACE
* boolexpr -> expression RELOP expression
* returnstmt -> KWRETURN expression SEMICOLON
****/



/****** Header definitions ******/
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astree.h"
// function prototypes from lex
int yyerror(char *s);
int yylex(void);
int yylex_destroy(void);
int debug=0; // set to 1 to turn on extra printing
int doAssembly=1;
int filename=0;
Symbol** table;
ASTNode* astRoot;
int argNum=0;
int scope=0;
char *argRegStr[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
char *paramStr[6];
int paramNum=2;
int sid=0;
int scopeParser=0;
int addString(char* str)
{
  if (lastStringIndex < 100)
    savedStrings[lastStringIndex] = str;
  lastStringIndex++;
  return (lastStringIndex - 1);
}

%}
/* token value data types */
%union { 
   int ival;  // for most scanner tokens
   char* str; // tokens that need a string, like ID and STRING
   struct astnode_s * astnode; // for all grammar nonterminals
}

/* Starting non-terminal */
%start wholeprogram
/* All nonterminal actions generate an AST node or subtree */
%type <astnode> wholeprogram program statements statement funcall function functions argument arguments expression globals vardecl parameters paramdecl assignment ifthenelse whileloop boolexpr returnstmt localvars localdecl

/* Token types */
%token <ival> KWPROGRAM KWCALL KWFUNCTION KWGLOBAL KWINT KWSTRING SEMICOLON LPAREN RPAREN LBRACE RBRACE NUMBER ADDOP COMMA EQUALS KWWHILE KWDO KWIF KWTHEN KWELSE KWRETURNVAL RELOP LBRACKET RBRACKET KWLOCAL
%token <str>  ID STRING 
%left ADDOP RELOP
%%
/******* Rules *******/

wholeprogram: globals functions program 
     {
        if (debug) fprintf(stderr,"wholeprogram def\n");
        $$ = astRoot;
        $$->child[0] = $1;
        scopeParser=1;
        $$->child[1] = $2;
        $$->child[2] = $3;
     }

program: KWPROGRAM LBRACE statements RBRACE
    {
        if (debug) fprintf(stderr,"program def\n");
        $$ = $3;
    }
    
functions: /* empty */ {$$ = 0; }
     | function functions
     {
        if (debug) fprintf(stderr,"functions def\n");
        $1->next = $2;
        $$ = $1;
     }

function: KWFUNCTION ID LPAREN parameters RPAREN LBRACE localvars statements RBRACE
     {
        if (debug) fprintf(stderr,"function def\n");
        $$ = (ASTNode*) newASTNode(AST_FUNCTION);
        $$->strval = $2;
        $$->strNeedsFreed = 1;
        $$->child[0] = $4;
        $$->child[1] = $8;
        $$->child[2] = $7;
        delScopeLevel(table, S_LOCAL);
        paramNum=2;
     }
	
statements: {$$ = 0;}
     | statement statements
    {
        if (debug) fprintf(stderr,"statements def\n");
        $1->next = $2;
        $$ = $1;
    }

statement: funcall
    {
        if (debug) fprintf(stderr,"statement def\n");
        $$ = $1;
    }
     | assignment
    {
    	if (debug) fprintf(stderr,"statement def\n");
        $$ = $1;
    }
     | ifthenelse
    {
    	if (debug) fprintf(stderr,"statement def\n");
        $$ = $1;
    }
     | whileloop
    {
    	if (debug) fprintf(stderr,"statement def\n");
        $$ = $1;
    }
     | returnstmt
    {
    	if (debug) fprintf(stderr,"statement def\n");
        $$ = $1;
    }

funcall: KWCALL ID LPAREN arguments RPAREN SEMICOLON
       {
        if (debug) fprintf(stderr,"funcall def\n");
        $$ = (ASTNode*) newASTNode(AST_FUNCALL);
        $$->strval = $2;
        $$->strNeedsFreed = 1;
        $$->child[0] = $4;
       }
       
assignment: ID EQUALS expression SEMICOLON
	   {
	   	if (debug) fprintf(stderr,"assignment def\n");
	   	if ( findSymbol(table, $1) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	$$ = (ASTNode*) newASTNode(AST_ASSIGNMENT);
       	$$->strval = $1;
        $$->strNeedsFreed = 1;
        $$->child[0] = $3;
        $$->varKind = findSymbol(table, $1)->kind;
        $$->ival = findSymbol(table, $1)->offset;
	   }
	   | ID LBRACKET expression RBRACKET EQUALS expression SEMICOLON
	   {
	    if (debug) fprintf(stderr,"assignment def\n");
	   	if ( findSymbol(table, $1) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	$$ = (ASTNode*) newASTNode(AST_ASSIGNMENT);
       	$$->strval = $1;
        $$->strNeedsFreed = 1;
        $$->child[0] = $6;
        $$->child[1] = $3;
        $$->varKind = findSymbol(table, $1)->kind;
        $$->ival = findSymbol(table, $1)->offset;
	   }

arguments: {$$ = 0;}
     | argument
    {
    	if (debug) fprintf(stderr,"arguments def\n");
    	$$ = (ASTNode*) newASTNode(AST_ARGUMENT);
       	$$->child[0] = $1;
    } 
     | argument COMMA arguments
	{
		if (debug) fprintf(stderr,"arguments def\n");
    	$$ = (ASTNode*) newASTNode(AST_ARGUMENT);
        $$->next = $3;
        $$->child[0] = $1;
	}
	
argument: expression 
	{
		if (debug) fprintf(stderr,"argument def\n");
		$$ = $1;
	}
	
expression: NUMBER 
	{
		if (debug) fprintf(stderr,"expression def\n");
       	$$ = (ASTNode*) newASTNode(AST_CONSTANT);
       	$$->valType = T_INT;
        $$->ival = $1;
	}
	| ID
	{
		if (debug) fprintf(stderr,"expression def\n");
		if ( findSymbol(table, $1) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	$$ = (ASTNode*) newASTNode(AST_VARREF);
       	$$->strval = $1;
       	$$->valType = T_STRING;
        $$->strNeedsFreed = 1;
        $$->varKind = findSymbol(table, $1)->kind;
        $$->ival = findSymbol(table, $1)->offset;
	}
	| ID LBRACKET expression RBRACKET
	{
		if (debug) fprintf(stderr,"expression def\n");
		if ( findSymbol(table, $1) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	$$ = (ASTNode*) newASTNode(AST_VARREF);
       	$$->strval = $1;
        $$->child[0] = $3;
       	$$->valType = T_INT;
        $$->strNeedsFreed = 1;
        $$->varKind = findSymbol(table, $1)->kind;
        $$->ival = findSymbol(table, $1)->offset;
	}
	| STRING
	{
		if (debug) fprintf(stderr,"expression def\n");
       	$$ = (ASTNode*) newASTNode(AST_CONSTANT);
       	$$->valType = T_STRING;
       	$$->strval = $1;
        $$->strNeedsFreed = 1;
        sid = addString($1);
	}
	| KWRETURNVAL
	{
		if (debug) fprintf(stderr,"expression def\n");
       	$$ = (ASTNode*) newASTNode(AST_CONSTANT);
       	$$->valType = T_RETURNVAL;
	}
	| expression ADDOP expression
	{
		if (debug) fprintf(stderr,"expression def\n");
       	$$ = (ASTNode*) newASTNode(AST_EXPRESSION);
       	$$->child[0] = $1;
       	$$->ival = $2;
       	$$->child[1] = $3;
	}	
 
globals: {$$ = 0;}
     | KWGLOBAL vardecl SEMICOLON globals
     {
      scopeParser=0;
      if (debug) fprintf(stderr,"expression def\n");
      $2->next = $4;
      $$ = $2;
      scopeParser=1;
     }

vardecl: KWINT ID
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, (scopeParser==1 ? S_LOCAL : S_GLOBAL), T_INT, 4, paramNum, (scopeParser==1 ? K_LOCAL : K_GLOBAL) );
              
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_INT;
      $$->varKind = (scopeParser==1 ? K_LOCAL : K_GLOBAL);
      $$->ival = (scopeParser==1 ? paramNum++ : 0);
      }
      
       | KWSTRING ID
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, (scopeParser==1 ? S_LOCAL : S_GLOBAL), T_STRING, 52, paramNum, (scopeParser==1 ? K_LOCAL : K_GLOBAL));
              
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_STRING;
      $$->varKind = (scopeParser==1 ? K_LOCAL : K_GLOBAL);
      $$->ival = (scopeParser==1 ? paramNum++ : 0);
      }
      | KWINT ID LBRACKET NUMBER RBRACKET
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, S_GLOBAL, T_INT, 8 * $4, 0, K_GLOBALARRAY);
              
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_INT;
      $$->varKind = K_GLOBALARRAY;
      $$->ival = $4;
      }
      
parameters: {$$ = 0;}
      | paramdecl
      {
      if (debug) fprintf(stderr,"parameters def\n");
      $$ = $1;
       }
       | paramdecl COMMA parameters 
       {
      if (debug) fprintf(stderr,"parameters def\n");
      $$->next = $3;
      $$ = $1;
       }
       
paramdecl: KWINT ID
      {
      if (debug) fprintf(stderr,"paramdecl def\n");
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, S_LOCAL, T_INT, 4, paramNum, K_PARAM);
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_INT;
      $$->varKind = K_PARAM;
      $$->ival = paramNum++;
      }
       | KWSTRING ID
      {
      if (debug) fprintf(stderr,"paramdecl def\n");
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, S_LOCAL, T_STRING, 52, paramNum, K_PARAM);
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_STRING;
      $$->varKind = K_PARAM;
      $$->ival = paramNum++;
      }
     
localvars: {$$ = 0;}
      | KWLOCAL localdecl SEMICOLON localvars
      {
      if (debug) fprintf(stderr,"localvars def\n");
      $2->next = $4;
      $$ = $2;
      }

localdecl: KWINT ID
      {
      if (debug) fprintf(stderr,"localdecl def\n");
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, S_LOCAL, T_INT, 4, paramNum, K_LOCAL);
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_INT;
      $$->varKind = K_LOCAL;
      $$->ival = paramNum++;
      }
       | KWSTRING ID
      {
      if (debug) fprintf(stderr,"localdecl def\n");
      if ( findSymbol(table, $2) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, $2, S_LOCAL, T_STRING, 52, paramNum, K_LOCAL);
      $$ = (ASTNode*) newASTNode(AST_VARDECL);
      $$->strval = $2;
      $$->strNeedsFreed = 1;
      $$->valType = T_STRING;
      $$->ival = paramNum++;
      $$->varKind = K_LOCAL;
      }
      
ifthenelse: KWIF LPAREN boolexpr RPAREN KWTHEN LBRACE statements RBRACE KWELSE LBRACE statements RBRACE
      {
      if (debug) fprintf(stderr,"ifthenelse def\n");
      $$ = (ASTNode*) newASTNode(AST_IFTHEN);
      $$->child[0] = $3;
      $$->child[1] = $7;
      $$->child[2] = $11;
      }
      
whileloop: KWWHILE LPAREN boolexpr RPAREN KWDO LBRACE statements RBRACE
      {
      if (debug) fprintf(stderr,"whileloop def\n");
      $$ = (ASTNode*) newASTNode(AST_WHILE);
      $$->child[0] = $3;
      $$->child[1] = $7;
      }
      
boolexpr: expression RELOP expression
      {
      if (debug) fprintf(stderr,"boolexpr def\n");
      $$ = (ASTNode*) newASTNode(AST_RELEXPR);
      $$->child[0] = $1;
      $$->ival = $2;
      $$->child[1] = $3;
      }
      
returnstmt: KWRETURNVAL expression SEMICOLON
      {
      if (debug) fprintf(stderr,"returnstmt def\n");
      $$ = $2;
      }
     ;
%%
/******* Functions *******/
extern FILE *yyin; // from lex

int main(int argc, char **argv)
{
  int parse = 0;
  table = newSymbolTable();
  astRoot = newASTNode(AST_PROGRAM);
  FILE *outputFile;
  for (int arguments = 1; arguments < argc; arguments++) {
    if (argv[arguments][0] == '-' && strlen(argv[arguments]) == 2) {
    	 if (argv[arguments][1] == 't') debug=1;
    	 if (argv[arguments][1] == 'd') doAssembly=0;
    } else {
    yyin = fopen(argv[arguments], "r");
      if (!yyin || (argv[arguments][strlen(argv[arguments])-1] != 'j' || argv[arguments][strlen(argv[arguments])-2] != '.')) {fprintf(stderr, "Error: not a valid filename.\nUsage: ./jc [options] [filename].j\n");
       exit(1);
        } else {
        char outputFileName[strlen(argv[arguments])]; // alter filename to end in a .s and set as output file
        strcpy(outputFileName, argv[arguments]);
        outputFileName[strlen(argv[arguments]) - 1] = 's';
        filename = 1;
        outputFile = fopen(outputFileName, "w");
        parse = yyparse();
        fclose(yyin);
        }
        break;
   	}
   }
   if (filename == 0) parse = yyparse();
   

  sid=0;
  argNum=0;
  if (doAssembly && !parse) 
     genCodeFromASTree(astRoot, 0, (filename == 1) ? outputFile : stdout);
  else
     printASTree(astRoot, 0, (filename == 1) ? outputFile : stdout);
  fclose(outputFile);
  freeAllSymbols(table);
  free(table);
  freeASTree(astRoot);
  yylex_destroy();
  return parse;  
}

extern int yylineno; // from lex

int yyerror(char *s)
{
   fprintf(stderr, "Error: line %d: %s\n",yylineno,s);
   return 0;
}

int yywrap()
{
   return(1);
}

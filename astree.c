//
// Abstract Syntax Tree Implementation
// - see "astree.h" for type definitions
// - the tree is made up of nodes of type ASTNode
// - the root node must be of type AST_PROGRAM
// - child nodes are linked by the "child[]" array, and
//   each type of node has its own children types
// - a special "child" node (the AST is a tree) uses
//   the "next" pointer to point to a "sibling"-type
//   node that is the next in a list (such as statements)
//
// Copyright (C) 2025 Jonathan Cook
//
#include <stdlib.h>
#include <stdio.h>
#include "astree.h"


// Create a new AST node 
// - allocates space and initializes node type, zeros other stuff out
// - returns pointer to new node
ASTNode* newASTNode(ASTNodeType type)
{
   int i;
   ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
   if (node == NULL)
      return NULL;
   node->type = type;
   node->valType = T_INT;
   node->varKind = K_GLOBAL;
   node->ival = 0;
   node->strval = 0;
   node->strNeedsFreed = 0;
   node->next = 0;
   for (i=0; i < ASTNUMCHILDREN; i++)
      node->child[i] = 0;
   return node;
}

static int getUniqueLabelID()
{
   static int lid = 100; // you can start at 0, it really doesn't matter
   return lid++;
}

// Generate an indentation string prefix
// - this is a helper function for use in printing the abstract
//   syntax tree with indentation used to indicate tree depth.
// - NOT thread safe! (uses a static char array to hold prefix)
#define INDENTAMT 3
static char* levelPrefix(int level)
{
   static char prefix[128]; // static so that it can be returned safely
   int i;
   for (i=0; i < level*INDENTAMT && i < 126; i++)
      prefix[i] = ' ';
   prefix[i] = '\0';
   return prefix;
}

// Free an entire ASTree, along with string data it has
// - a node must have strNeedsFreed to non-zero in order 
//   for its strval to be freed
void freeASTree(ASTNode* node)
{
   if (!node)
      return;
   freeASTree(node->child[0]);
   freeASTree(node->child[1]);
   freeASTree(node->child[2]);
   freeASTree(node->next);
   if (node->strNeedsFreed && node->strval) 
      free(node->strval);
   free(node);
}

// Print the abstract syntax tree starting at the given node
// - this is a recursive function, your initial call should 
//   pass 0 in for the level parameter
// - comments in code indicate types of nodes and where they
//   are expected; this helps you understand what the AST looks like
// - "out" is the file to output to, can be "stdout" or other file handle
void printASTree(ASTNode* node, int level, FILE *out)
{
   if (!node)
      return;
   fprintf(out,"%s",levelPrefix(level)); // note: no newline printed here!
   switch (node->type) {
    case AST_PROGRAM:
       fprintf(out,"Whole Program AST:\n");
       fprintf(out,"%s--globalvars--\n",levelPrefix(level+1));
       printASTree(node->child[0],level+1,out);  // child 0 is gobal var decls
       fprintf(out,"%s--functions--\n",levelPrefix(level+1));
       printASTree(node->child[1],level+1,out);  // child 1 is function defs
       fprintf(out,"%s--program--\n",levelPrefix(level+1));
       printASTree(node->child[2],level+1,out);  // child 2 is program
       break;
    case AST_VARDECL:
       fprintf(out,"Variable declaration (%s)",node->strval); // var name
       if (node->valType == T_INT)
          if (node->varKind != K_GLOBALARRAY)
             fprintf(out," type int\n");
          else
             fprintf(out," type int array size %d\n",node->ival);
       else if (node->valType == T_LONG)
          fprintf(out," type long\n");
       else if (node->valType == T_STRING)
          fprintf(out," type string\n");
       else
          fprintf(out," type unknown (%d)\n", node->valType);
       break;
    case AST_FUNCTION:
       fprintf(out,"Function def (%s)\n",node->strval); // function name
       fprintf(out,"%s--params--\n",levelPrefix(level+1));
       printASTree(node->child[0],level+1,out); // child 0 is param list
       fprintf(out,"%s--locals--\n",levelPrefix(level+1));
       printASTree(node->child[2],level+1,out); // child 2 is local vars
       fprintf(out,"%s--body--\n",levelPrefix(level+1));
       printASTree(node->child[1],level+1,out); // child 1 is body (stmt list)
       break;
    case AST_SBLOCK: // we don't use this node type
       fprintf(out,"Statement block\n"); 
       printASTree(node->child[0],level+1,out);  // child 0 is statement list
       break;
    case AST_FUNCALL:
       fprintf(out,"Function call (%s)\n",node->strval); // func name
       printASTree(node->child[0],level+1,out);  // child 0 is argument list
       break;
    case AST_ARGUMENT:
       fprintf(out,"Funcall argument\n");
       printASTree(node->child[0],level+1,out);  // child 0 is argument expr
       break;
    case AST_ASSIGNMENT:
       fprintf(out,"Assignment to (%s) ", node->strval);
       if (node->varKind == K_GLOBALARRAY) { //child[1]) {
          fprintf(out,"array var\n");
          fprintf(out,"%s--index--\n",levelPrefix(level+1));
          printASTree(node->child[1],level+1,out);
       } else  
          fprintf(out,"simple var\n");
       fprintf(out,"%s--right hand side--\n",levelPrefix(level+1));
       printASTree(node->child[0],level+1,out);  // child 1 is right hand side
       break;
    case AST_WHILE:
       fprintf(out,"While loop\n");
       printASTree(node->child[0],level+1,out);  // child 0 is condition expr
       fprintf(out,"%s--body--\n",levelPrefix(level+1));
       printASTree(node->child[1],level+1,out);  // child 1 is loop body
       break;
    case AST_IFTHEN:
       fprintf(out,"If then\n");
       printASTree(node->child[0],level+1,out);  // child 0 is condition expr
       fprintf(out,"%s--ifpart--\n",levelPrefix(level+1));
       printASTree(node->child[1],level+1,out);  // child 1 is if body
       fprintf(out,"%s--elsepart--\n",levelPrefix(level+1));
       printASTree(node->child[2],level+1,out);  // child 2 is else body
       break;
    case AST_EXPRESSION: // only for binary op expression
       fprintf(out,"Expression (op %d,%c)\n",node->ival,node->ival);
       printASTree(node->child[0],level+1,out);  // child 0 is left side
       printASTree(node->child[1],level+1,out);  // child 1 is right side
       break;
    case AST_RELEXPR: // only for relational op expression
       fprintf(out,"Relational Expression (op %d,%c)\n",node->ival,node->ival);
       printASTree(node->child[0],level+1,out);  // child 0 is left side
       printASTree(node->child[1],level+1,out);  // child 1 is right side
       break;
    case AST_VARREF:
       fprintf(out,"Variable ref (%s)",node->strval); // var name
       if (node->varKind == K_GLOBALARRAY) { //child[0]) {
          fprintf(out," array ref\n");
          printASTree(node->child[0],level+1,out);
       } else 
          fprintf(out,"\n");
       break;
    case AST_CONSTANT: // for both int and string constants
       if (node->valType == T_INT)
          fprintf(out,"Int Constant = %d\n",node->ival);
       else if (node->valType == T_STRING)
          fprintf(out,"String Constant = (%s)\n",node->strval);
       else if (node->valType == T_RETURNVAL) // NEW
          fprintf(out,"Return Value\n");
       else 
          fprintf(out,"Unknown Constant\n");
       break;
    default:
       fprintf(out,"Unknown AST node!\n");
   }
   // IMPORTANT: walks down sibling list (for nodes that form lists, like
   // declarations, functions, parameters, arguments, and statements)
   printASTree(node->next,level,out);
}

//
// Below here is code for generating our output assembly code from
// an AST. You will probably want to move some things from the
// grammar file (.y file) over here, since you will no longer be 
// generating code in the grammar file. You may have some global 
// stuff that needs accessed from both, in which case declare it in
// one and then use "extern" to reference it in the other.

// Generate assembly code from AST
// - this function should look _alot_ like the print function;
//   indeed, the best way to start would be to copy over the 
//   code from printASTree() and change all the recursive calls
//   to this function; then, instead of printing info, we are 
//   going to print assembly code. Easy!
// - @param node is the current node being processed
// - @param hval is a helper value parameter that can be used to keep
//   track of value for you -- I use it only in two places, to keep
//   track of arguments (position) and then to use the correct argument register
//   and to keep a label ID for conditional jumps on AST_RELEXPR 
//   nodes; otherwise this helper value can just be 0
// - param out is the output file handle. Use "fprintf(out,..." 
//   instead of printf(...); call it with "stdout" for terminal output
//   (see printASTree() code for how it uses the output file handle)
//
void genCodeFromASTree(ASTNode* node, int hval, FILE *out)
{
   char* instr;
   int ifJump;
   int continueJump;
   int loopTop;
   int loopBottom;
   int arrIndex = 1;
   if (!node)
      return;
   fprintf(out,""); // note: no newline printed here!
   switch (node->type) {
    case AST_PROGRAM:
       fprintf(out,"#\n# Data section\n#\n\t.section\t.rodata\n");
       for (int ix = 0; ix < lastStringIndex; ix++)
        {
          fprintf(out, ".SC%d:\n\t.string\t%s\n", ix, savedStrings[ix]);
        }
       genCodeFromASTree(node->child[0],hval,out);  // child 0 is gobal var decls
       fprintf(out,"\n#\n# Code section\n#\n\t.text\n");
       genCodeFromASTree(node->child[1],hval,out);  // child 1 is function defs
       fprintf(out,"\t.globl\tmain\nmain:\n\tpushq\t%%rbp\n\tmovq\t%%rsp, %%rbp\n");
       genCodeFromASTree(node->child[2],hval,out);  // child 2 is program
       fprintf(out,"\tmovl\t$0, %%eax\n\tleave\n\tret\n\t.section\t.note.GNU-stack,\"\",@progbits\n");
       fprintf(out,"#\n# Library function readInt()\n");
       fprintf(out, "\t.section\t.rodata\n.LC0:\t.string\t\"%%d\"\n\t.text\n\t.globl\treadInt\n\t.type\treadInt, @function\nreadInt:\n\tpushq\t%%rbp\n\tmovq\t%%rsp, %%rbp\n\tsubq\t$16, %%rsp\n\tleaq\t-12(%%rbp), %%rsi\n\tleaq\t.LC0(%%rip), %%rdi\n\tmovl\t$0, %%eax\n\tcall\tscanf@PLT\n\tmovl\t-12(%%rbp), %%eax\n\tleave\n\tret\n\n");
       break;
    case AST_VARDECL:
       if (node->varKind == K_GLOBAL || node->varKind == K_GLOBALARRAY) fprintf(out,"\t.comm\t%s", node->strval);
       if (node->valType == T_INT)
          if (node->varKind == K_GLOBALARRAY)
       		 fprintf(out,", %d, 32\n", node->ival*8);
          else if (node->varKind == K_GLOBAL)
             fprintf(out,", 4, 4\n");
       else if (node->varKind == K_GLOBAL && node->valType == T_LONG)
          fprintf(out,", 8, 8\n");
       else if (node->varKind == K_GLOBAL && node->valType == T_STRING)
          fprintf(out,", 52, 32\n");
       
       break;
    case AST_FUNCTION:
       fprintf(out,"\t.globl\t%s\n%s:\n\tpushq\t%%rbp\n\tmovq\t%%rsp, %%rbp\n\tsubq\t$128, %%rsp\n\tmovq\t%rbx, -8(%rbp)\n\tmovq\t%rdi, -16(%rbp)\n\tmovq\t%rsi, -24(%rbp)\n\tmovq\t%rdx, -32(%rbp)\n\tmovq\t%rcx, -40(%rbp)\n", node->strval,node->strval);
       genCodeFromASTree(node->child[0],hval,out); // child 0 is param list
       fprintf(out,"");
       genCodeFromASTree(node->child[2],hval,out); // child 2 is local vars
       fprintf(out,"");
       genCodeFromASTree(node->child[1],hval,out); // child 1 is body (stmt list)
       fprintf(out,"\tmovq\t-8(%%rbp), %%rbx\n\tleave\n\tret\n\n");
       break;
    case AST_SBLOCK: // we don't use this node type
       fprintf(out,"");
       genCodeFromASTree(node->child[0],hval+1,out);  // child 0 is statement list
       break;
    case AST_FUNCALL:
       genCodeFromASTree(node->child[0],argNum,out);  // child 0 is argument list
       fprintf(out,"\tcall\t%s@PLT\n", node->strval);
       fprintf(out,"\tmovq\t%%rax, %%rdx\n");
       argNum = 0;
       break;
    case AST_ARGUMENT:
       fprintf(out,"");
       genCodeFromASTree(node->child[0],argNum+1,out);  // child 0 is argument expr
       fprintf(out,"\tmov\t\t%%rax, %s\n", argRegStr[argNum++]);
       break;
    case AST_ASSIGNMENT:
       if (node->varKind == K_GLOBALARRAY) { //child[1]
          genCodeFromASTree(node->child[1],hval,out);
          fprintf(out,"\tpushq\t%%rbx\n");
          fprintf(out,"\tpushq\t%%rax\n");          
          genCodeFromASTree(node->child[0],hval,out);  // child 0 is right hand side
          fprintf(out,"\tcltq\n");          
          fprintf(out,"\tleaq\t%s(%%rip), %%rcx\n",node->strval);
          fprintf(out,"\tpopq\t%%rbx\n");          
          fprintf(out,"\tmovl\t%%ebx, 0(%%rcx,%%rax,4)\n");
       } else {
         genCodeFromASTree(node->child[0],hval,out);  // child 0 is right hand side
         if (node->varKind == K_GLOBAL) fprintf(out,"\tmovl\t%%eax, %s(%%rip)\n", node->strval);
         else fprintf(out,"\tmovl\t%%eax, %d(%%rbp)\n", node->ival * -8); 
       }
       break;
    case AST_WHILE:
       loopTop = getUniqueLabelID();
       loopBottom = getUniqueLabelID();
       fprintf(out,"LL%d:\n", loopTop);
       genCodeFromASTree(node->child[0],loopBottom,out); // child 0 is condition expr
       genCodeFromASTree(node->child[1],hval,out); // child 1 is loop body
       fprintf(out,"\tjmp\t\tLL%d\nLL%d:\n", loopTop, loopBottom);
       break;
    case AST_IFTHEN:
       ifJump = getUniqueLabelID();
       continueJump = getUniqueLabelID();
       genCodeFromASTree(node->child[0],ifJump,out);  // child 0 is condition expr
       genCodeFromASTree(node->child[1],ifJump,out);  // child 1 is if body
       fprintf(out,"\tjmp\t\tLL%d\nLL%d:\n", continueJump, ifJump);
       genCodeFromASTree(node->child[2],continueJump,out);  // child 2 is else body
       fprintf(out,"LL%d:\n", continueJump);
       break;
    case AST_EXPRESSION: // only for binary op expression
       fprintf(out,"");
       if (node->ival == '+') {
       	genCodeFromASTree(node->child[0],hval,out);  // child 0 is left side
       	fprintf(out,"\tpushq\t%%rax\n");
       	genCodeFromASTree(node->child[1],hval,out);  // child 1 is right side
       	fprintf(out,"\tpopq\t%%rcx\n\taddl\t%%ecx, %%eax\n");
       } else {
       	genCodeFromASTree(node->child[1],hval,out);  // child 1 is right side
       	fprintf(out,"\tpushq\t%%rax\n");
       	genCodeFromASTree(node->child[0],hval,out);  // child 0 is left side
       	fprintf(out,"\tpopq\t%%rcx\n\tsubl\t%%ecx, %%eax\n");
       	}
       break;
    case AST_RELEXPR: // only for relational op expression
       genCodeFromASTree(node->child[0],0,out);  // child 0 is left side
       fprintf(out,"\tpushq\t%%rax\n");
       genCodeFromASTree(node->child[1],0,out);  // child 1 is right side
       fprintf(out,"\tpopq\t%%rcx\n");
       fprintf(out,"\tcmpl\t%%eax, %%ecx\n");
       switch (node->ival) { // inverted instructions
         case '>': instr = "jle"; break;
         case '<': instr = "jge"; break;
         case '=': instr = "jne"; break;
         case '!': instr = "je"; break;
         default: instr = "unknown relop";
       }
       fprintf(out,"\t%s\t\tLL%d\n",instr,hval);        break;
    case AST_VARREF:
       if (node->varKind == K_GLOBAL) {
       	  fprintf(out,"\tmovl\t%s(%%rip), %%eax\n",node->strval);
       } else if (node->varKind == K_GLOBALARRAY) { //child[0])
          genCodeFromASTree(node->child[0],hval,out);
          fprintf(out,"\tcltq\n");
          fprintf(out,"\tleaq\t%s(%%rip), %%rcx\n", node->strval);
          fprintf(out,"\tmovl\t0(%%rcx,%%rax,4), %%eax\n");
       } else 
          fprintf(out,"\tmovl\t%d(%%rbp), %%eax\n",-8 * node->ival);
       break;
    case AST_CONSTANT: // for both int and string constants
       if (node->valType == T_INT)
          fprintf(out,"\tmovl\t$%d, %%eax\n",node->ival);
       else if (node->valType == T_STRING)
          fprintf(out,"\tleaq\t.SC%d(%%rip), %%rax\n", sid++ );
       else if (node->valType == T_RETURNVAL) // NEW
          fprintf(out,"\tmovq\t%%rdx, %%rax\n");
       else 
          fprintf(out,"");
       break;
    default:
       fprintf(out,"");
   }
   // IMPORTANT: walks down sibling list (for nodes that form lists, like
   // declarations, functions, parameters, arguments, and statements)
   genCodeFromASTree(node->next,hval,out);
}



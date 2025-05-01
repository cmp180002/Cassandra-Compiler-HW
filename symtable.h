//
// Symbol Table Module Interface
//
#ifndef SYMTABLE_H
#define SYMTABLE_H

typedef enum { T_STRING, T_INT, T_LONG, T_RETURNVAL } DataType;
typedef enum { K_GLOBAL, K_PARAM, K_LOCAL, 
               K_GLOBALARRAY, K_FUNCTION } SymbolKind;
typedef enum { S_GLOBAL, S_LOCAL, S_BLOCK } ScopeLevel; // order is important

// Symbol structure
typedef struct symbol_s {
   ScopeLevel scopeLevel;
   DataType type;
   SymbolKind kind;
   unsigned int size;  // 0 if simple var, N if array (N is num elems)
   int offset;         // stack offset for local vars and params
   char* name;         // private string copy, no other pointers to it
   struct symbol_s* next;
} Symbol;

// helper structure to iterate through table
typedef struct {
   int index;
   Symbol* lastsym;
} SymbolTableIter;

Symbol** newSymbolTable();
int addSymbol(Symbol** table, char* name, ScopeLevel scopeLevel, DataType type,
              unsigned int size, int offset, SymbolKind kind);
Symbol* findSymbol(Symbol** table, char* name);
Symbol* iterSymbolTable(Symbol** table, SymbolTableIter* iter);
void freeAllSymbols(Symbol** table);
int delScopeLevel(Symbol** table, ScopeLevel scopeLevel);

#endif


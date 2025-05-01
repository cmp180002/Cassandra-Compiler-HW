/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 35 "parser.y"


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


#line 103 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KWPROGRAM = 3,                  /* KWPROGRAM  */
  YYSYMBOL_KWCALL = 4,                     /* KWCALL  */
  YYSYMBOL_KWFUNCTION = 5,                 /* KWFUNCTION  */
  YYSYMBOL_KWGLOBAL = 6,                   /* KWGLOBAL  */
  YYSYMBOL_KWINT = 7,                      /* KWINT  */
  YYSYMBOL_KWSTRING = 8,                   /* KWSTRING  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 10,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 11,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 12,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_NUMBER = 14,                    /* NUMBER  */
  YYSYMBOL_ADDOP = 15,                     /* ADDOP  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_EQUALS = 17,                    /* EQUALS  */
  YYSYMBOL_KWWHILE = 18,                   /* KWWHILE  */
  YYSYMBOL_KWDO = 19,                      /* KWDO  */
  YYSYMBOL_KWIF = 20,                      /* KWIF  */
  YYSYMBOL_KWTHEN = 21,                    /* KWTHEN  */
  YYSYMBOL_KWELSE = 22,                    /* KWELSE  */
  YYSYMBOL_KWRETURNVAL = 23,               /* KWRETURNVAL  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_LBRACKET = 25,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 26,                  /* RBRACKET  */
  YYSYMBOL_KWLOCAL = 27,                   /* KWLOCAL  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_wholeprogram = 31,              /* wholeprogram  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_functions = 33,                 /* functions  */
  YYSYMBOL_function = 34,                  /* function  */
  YYSYMBOL_statements = 35,                /* statements  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_funcall = 37,                   /* funcall  */
  YYSYMBOL_assignment = 38,                /* assignment  */
  YYSYMBOL_arguments = 39,                 /* arguments  */
  YYSYMBOL_argument = 40,                  /* argument  */
  YYSYMBOL_expression = 41,                /* expression  */
  YYSYMBOL_globals = 42,                   /* globals  */
  YYSYMBOL_vardecl = 43,                   /* vardecl  */
  YYSYMBOL_parameters = 44,                /* parameters  */
  YYSYMBOL_paramdecl = 45,                 /* paramdecl  */
  YYSYMBOL_localvars = 46,                 /* localvars  */
  YYSYMBOL_localdecl = 47,                 /* localdecl  */
  YYSYMBOL_ifthenelse = 48,                /* ifthenelse  */
  YYSYMBOL_whileloop = 49,                 /* whileloop  */
  YYSYMBOL_boolexpr = 50,                  /* boolexpr  */
  YYSYMBOL_returnstmt = 51                 /* returnstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    95,   101,   102,   109,   122,   123,   130,
     135,   140,   145,   150,   156,   165,   179,   195,   196,   202,
     210,   216,   223,   237,   252,   261,   267,   276,   277,   286,
     304,   321,   339,   340,   345,   352,   367,   383,   384,   391,
     406,   422,   431,   439,   448
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KWPROGRAM", "KWCALL",
  "KWFUNCTION", "KWGLOBAL", "KWINT", "KWSTRING", "SEMICOLON", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "NUMBER", "ADDOP", "COMMA", "EQUALS",
  "KWWHILE", "KWDO", "KWIF", "KWTHEN", "KWELSE", "KWRETURNVAL", "RELOP",
  "LBRACKET", "RBRACKET", "KWLOCAL", "ID", "STRING", "$accept",
  "wholeprogram", "program", "functions", "function", "statements",
  "statement", "funcall", "assignment", "arguments", "argument",
  "expression", "globals", "vardecl", "parameters", "paramdecl",
  "localvars", "localdecl", "ifthenelse", "whileloop", "boolexpr",
  "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,    30,    14,    18,     0,     3,    24,   -34,    15,    42,
      18,    21,   -34,     2,    37,    36,   -34,   -34,    35,   -34,
      32,    -1,    25,    22,    26,    41,    39,    29,    43,    48,
     -13,     4,    46,    -1,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,    50,    32,    55,   -13,   -13,   -34,   -34,    44,
     -34,    -4,   -13,   -13,   -34,   -34,    33,   -34,   -13,   -11,
      56,    57,   -13,   -34,   -13,    -3,    -8,    34,    -1,    59,
      58,    51,   -13,    52,    54,    -6,   -34,   -34,    60,    53,
      61,    63,    65,    67,   -13,    51,    68,    70,   -34,   -13,
     -34,   -34,    33,   -34,   -34,   -34,    -1,    -1,    17,   -34,
      66,    71,   -34,   -34,    64,    73,    -1,    74,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      27,     0,     0,     4,     0,     0,     0,     1,     0,     0,
       4,    29,    30,    27,     0,     0,     2,     5,     0,    28,
      32,     7,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     7,     9,    10,    11,    12,    13,    31,
      35,    36,     0,    32,     0,     0,     0,    21,    25,    22,
      24,     0,     0,     0,     3,     8,    37,    34,    17,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     7,     0,
      18,    20,     0,     0,     0,     0,    26,    15,     0,     0,
       0,     0,     0,     0,    17,    43,     0,     0,    23,     0,
      39,    40,    37,     6,    14,    19,     7,     7,     0,    38,
       0,     0,    16,    42,     0,     0,     7,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,    78,   -34,   -33,   -34,   -34,   -34,     6,
     -34,   -28,    79,   -34,    40,   -34,     1,   -34,   -34,   -34,
      45,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    16,     9,    10,    32,    33,    34,    35,    69,
      70,    59,     3,     6,    25,    26,    68,    81,    36,    37,
      60,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    47,    51,    27,    64,    63,    77,    64,     1,    64,
      48,    64,    64,    72,     7,    49,    50,    28,    78,    29,
      88,    52,    30,     8,    65,    66,   102,    31,    11,    53,
      71,    12,    64,    13,    75,    82,    76,     4,     5,    23,
      24,    79,    80,    14,    85,    15,    18,    20,    21,    22,
      40,    39,    42,    45,    41,    43,    71,    44,    46,    54,
      67,    98,    56,   100,   101,    58,    64,    73,    74,    62,
      83,    86,    92,   107,    84,    87,    94,    89,    93,   103,
      96,    90,    97,    57,   104,   106,   105,   108,    17,    91,
      95,    61,    19,    99
};

static const yytype_int8 yycheck[] =
{
      33,    14,    30,     4,    15,     9,     9,    15,     6,    15,
      23,    15,    15,    24,     0,    28,    29,    18,    26,    20,
      26,    17,    23,     5,    52,    53,     9,    28,    28,    25,
      58,    28,    15,     9,    62,    68,    64,     7,     8,     7,
       8,     7,     8,    28,    72,     3,    25,    10,    12,    14,
      28,    26,    11,    10,    28,    16,    84,    28,    10,    13,
      27,    89,    12,    96,    97,    10,    15,    11,    11,    25,
      11,    19,     9,   106,    16,    21,     9,    17,    13,    13,
      12,    28,    12,    43,    13,    12,    22,    13,    10,    28,
      84,    46,    13,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    31,    42,     7,     8,    43,     0,     5,    33,
      34,    28,    28,     9,    28,     3,    32,    33,    25,    42,
      10,    12,    14,     7,     8,    44,    45,     4,    18,    20,
      23,    28,    35,    36,    37,    38,    48,    49,    51,    26,
      28,    28,    11,    16,    28,    10,    10,    14,    23,    28,
      29,    41,    17,    25,    13,    35,    12,    44,    10,    41,
      50,    50,    25,     9,    15,    41,    41,    27,    46,    39,
      40,    41,    24,    11,    11,    41,    41,     9,    26,     7,
       8,    47,    35,    11,    16,    41,    19,    21,    26,    17,
      28,    28,     9,    13,     9,    39,    12,    12,    41,    46,
      35,    35,     9,    13,    13,    22,    12,    35,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    33,    33,    34,    35,    35,    36,
      36,    36,    36,    36,    37,    38,    38,    39,    39,    39,
      40,    41,    41,    41,    41,    41,    41,    42,    42,    43,
      43,    43,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    49,    50,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     4,     0,     2,     9,     0,     2,     1,
       1,     1,     1,     1,     6,     4,     7,     0,     1,     3,
       1,     1,     1,     4,     1,     1,     3,     0,     4,     2,
       2,     5,     0,     1,     3,     2,     2,     0,     4,     2,
       2,    12,     8,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* wholeprogram: globals functions program  */
#line 86 "parser.y"
     {
        if (debug) fprintf(stderr,"wholeprogram def\n");
        (yyval.astnode) = astRoot;
        (yyval.astnode)->child[0] = (yyvsp[-2].astnode);
        scopeParser=1;
        (yyval.astnode)->child[1] = (yyvsp[-1].astnode);
        (yyval.astnode)->child[2] = (yyvsp[0].astnode);
     }
#line 1318 "y.tab.c"
    break;

  case 3: /* program: KWPROGRAM LBRACE statements RBRACE  */
#line 96 "parser.y"
    {
        if (debug) fprintf(stderr,"program def\n");
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 1327 "y.tab.c"
    break;

  case 4: /* functions: %empty  */
#line 101 "parser.y"
                       {(yyval.astnode) = 0; }
#line 1333 "y.tab.c"
    break;

  case 5: /* functions: function functions  */
#line 103 "parser.y"
     {
        if (debug) fprintf(stderr,"functions def\n");
        (yyvsp[-1].astnode)->next = (yyvsp[0].astnode);
        (yyval.astnode) = (yyvsp[-1].astnode);
     }
#line 1343 "y.tab.c"
    break;

  case 6: /* function: KWFUNCTION ID LPAREN parameters RPAREN LBRACE localvars statements RBRACE  */
#line 110 "parser.y"
     {
        if (debug) fprintf(stderr,"function def\n");
        (yyval.astnode) = (ASTNode*) newASTNode(AST_FUNCTION);
        (yyval.astnode)->strval = (yyvsp[-7].str);
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->child[0] = (yyvsp[-5].astnode);
        (yyval.astnode)->child[1] = (yyvsp[-1].astnode);
        (yyval.astnode)->child[2] = (yyvsp[-2].astnode);
        delScopeLevel(table, S_LOCAL);
        paramNum=2;
     }
#line 1359 "y.tab.c"
    break;

  case 7: /* statements: %empty  */
#line 122 "parser.y"
            {(yyval.astnode) = 0;}
#line 1365 "y.tab.c"
    break;

  case 8: /* statements: statement statements  */
#line 124 "parser.y"
    {
        if (debug) fprintf(stderr,"statements def\n");
        (yyvsp[-1].astnode)->next = (yyvsp[0].astnode);
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 1375 "y.tab.c"
    break;

  case 9: /* statement: funcall  */
#line 131 "parser.y"
    {
        if (debug) fprintf(stderr,"statement def\n");
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 1384 "y.tab.c"
    break;

  case 10: /* statement: assignment  */
#line 136 "parser.y"
    {
    	if (debug) fprintf(stderr,"statement def\n");
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 1393 "y.tab.c"
    break;

  case 11: /* statement: ifthenelse  */
#line 141 "parser.y"
    {
    	if (debug) fprintf(stderr,"statement def\n");
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 1402 "y.tab.c"
    break;

  case 12: /* statement: whileloop  */
#line 146 "parser.y"
    {
    	if (debug) fprintf(stderr,"statement def\n");
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 1411 "y.tab.c"
    break;

  case 13: /* statement: returnstmt  */
#line 151 "parser.y"
    {
    	if (debug) fprintf(stderr,"statement def\n");
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 1420 "y.tab.c"
    break;

  case 14: /* funcall: KWCALL ID LPAREN arguments RPAREN SEMICOLON  */
#line 157 "parser.y"
       {
        if (debug) fprintf(stderr,"funcall def\n");
        (yyval.astnode) = (ASTNode*) newASTNode(AST_FUNCALL);
        (yyval.astnode)->strval = (yyvsp[-4].str);
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->child[0] = (yyvsp[-2].astnode);
       }
#line 1432 "y.tab.c"
    break;

  case 15: /* assignment: ID EQUALS expression SEMICOLON  */
#line 166 "parser.y"
           {
	   	if (debug) fprintf(stderr,"assignment def\n");
	   	if ( findSymbol(table, (yyvsp[-3].str)) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_ASSIGNMENT);
       	(yyval.astnode)->strval = (yyvsp[-3].str);
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->child[0] = (yyvsp[-1].astnode);
        (yyval.astnode)->varKind = findSymbol(table, (yyvsp[-3].str))->kind;
        (yyval.astnode)->ival = findSymbol(table, (yyvsp[-3].str))->offset;
	   }
#line 1450 "y.tab.c"
    break;

  case 16: /* assignment: ID LBRACKET expression RBRACKET EQUALS expression SEMICOLON  */
#line 180 "parser.y"
           {
	    if (debug) fprintf(stderr,"assignment def\n");
	   	if ( findSymbol(table, (yyvsp[-6].str)) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_ASSIGNMENT);
       	(yyval.astnode)->strval = (yyvsp[-6].str);
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->child[0] = (yyvsp[-1].astnode);
        (yyval.astnode)->child[1] = (yyvsp[-4].astnode);
        (yyval.astnode)->varKind = findSymbol(table, (yyvsp[-6].str))->kind;
        (yyval.astnode)->ival = findSymbol(table, (yyvsp[-6].str))->offset;
	   }
#line 1469 "y.tab.c"
    break;

  case 17: /* arguments: %empty  */
#line 195 "parser.y"
           {(yyval.astnode) = 0;}
#line 1475 "y.tab.c"
    break;

  case 18: /* arguments: argument  */
#line 197 "parser.y"
    {
    	if (debug) fprintf(stderr,"arguments def\n");
    	(yyval.astnode) = (ASTNode*) newASTNode(AST_ARGUMENT);
       	(yyval.astnode)->child[0] = (yyvsp[0].astnode);
    }
#line 1485 "y.tab.c"
    break;

  case 19: /* arguments: argument COMMA arguments  */
#line 203 "parser.y"
        {
		if (debug) fprintf(stderr,"arguments def\n");
    	(yyval.astnode) = (ASTNode*) newASTNode(AST_ARGUMENT);
        (yyval.astnode)->next = (yyvsp[0].astnode);
        (yyval.astnode)->child[0] = (yyvsp[-2].astnode);
	}
#line 1496 "y.tab.c"
    break;

  case 20: /* argument: expression  */
#line 211 "parser.y"
        {
		if (debug) fprintf(stderr,"argument def\n");
		(yyval.astnode) = (yyvsp[0].astnode);
	}
#line 1505 "y.tab.c"
    break;

  case 21: /* expression: NUMBER  */
#line 217 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_CONSTANT);
       	(yyval.astnode)->valType = T_INT;
        (yyval.astnode)->ival = (yyvsp[0].ival);
	}
#line 1516 "y.tab.c"
    break;

  case 22: /* expression: ID  */
#line 224 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
		if ( findSymbol(table, (yyvsp[0].str)) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_VARREF);
       	(yyval.astnode)->strval = (yyvsp[0].str);
       	(yyval.astnode)->valType = T_STRING;
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->varKind = findSymbol(table, (yyvsp[0].str))->kind;
        (yyval.astnode)->ival = findSymbol(table, (yyvsp[0].str))->offset;
	}
#line 1534 "y.tab.c"
    break;

  case 23: /* expression: ID LBRACKET expression RBRACKET  */
#line 238 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
		if ( findSymbol(table, (yyvsp[-3].str)) == NULL) {
          fprintf(stderr, "Error: variable undefined.\n");
          exit(1);
    	  }
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_VARREF);
       	(yyval.astnode)->strval = (yyvsp[-3].str);
        (yyval.astnode)->child[0] = (yyvsp[-1].astnode);
       	(yyval.astnode)->valType = T_INT;
        (yyval.astnode)->strNeedsFreed = 1;
        (yyval.astnode)->varKind = findSymbol(table, (yyvsp[-3].str))->kind;
        (yyval.astnode)->ival = findSymbol(table, (yyvsp[-3].str))->offset;
	}
#line 1553 "y.tab.c"
    break;

  case 24: /* expression: STRING  */
#line 253 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_CONSTANT);
       	(yyval.astnode)->valType = T_STRING;
       	(yyval.astnode)->strval = (yyvsp[0].str);
        (yyval.astnode)->strNeedsFreed = 1;
        sid = addString((yyvsp[0].str));
	}
#line 1566 "y.tab.c"
    break;

  case 25: /* expression: KWRETURNVAL  */
#line 262 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_CONSTANT);
       	(yyval.astnode)->valType = T_RETURNVAL;
	}
#line 1576 "y.tab.c"
    break;

  case 26: /* expression: expression ADDOP expression  */
#line 268 "parser.y"
        {
		if (debug) fprintf(stderr,"expression def\n");
       	(yyval.astnode) = (ASTNode*) newASTNode(AST_EXPRESSION);
       	(yyval.astnode)->child[0] = (yyvsp[-2].astnode);
       	(yyval.astnode)->ival = (yyvsp[-1].ival);
       	(yyval.astnode)->child[1] = (yyvsp[0].astnode);
	}
#line 1588 "y.tab.c"
    break;

  case 27: /* globals: %empty  */
#line 276 "parser.y"
         {(yyval.astnode) = 0;}
#line 1594 "y.tab.c"
    break;

  case 28: /* globals: KWGLOBAL vardecl SEMICOLON globals  */
#line 278 "parser.y"
     {
      scopeParser=0;
      if (debug) fprintf(stderr,"expression def\n");
      (yyvsp[-2].astnode)->next = (yyvsp[0].astnode);
      (yyval.astnode) = (yyvsp[-2].astnode);
      scopeParser=1;
     }
#line 1606 "y.tab.c"
    break;

  case 29: /* vardecl: KWINT ID  */
#line 287 "parser.y"
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), (scopeParser==1 ? S_LOCAL : S_GLOBAL), T_INT, 4, paramNum, (scopeParser==1 ? K_LOCAL : K_GLOBAL) );
              
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_INT;
      (yyval.astnode)->varKind = (scopeParser==1 ? K_LOCAL : K_GLOBAL);
      (yyval.astnode)->ival = (scopeParser==1 ? paramNum++ : 0);
      }
#line 1627 "y.tab.c"
    break;

  case 30: /* vardecl: KWSTRING ID  */
#line 305 "parser.y"
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), (scopeParser==1 ? S_LOCAL : S_GLOBAL), T_STRING, 52, paramNum, (scopeParser==1 ? K_LOCAL : K_GLOBAL));
              
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_STRING;
      (yyval.astnode)->varKind = (scopeParser==1 ? K_LOCAL : K_GLOBAL);
      (yyval.astnode)->ival = (scopeParser==1 ? paramNum++ : 0);
      }
#line 1648 "y.tab.c"
    break;

  case 31: /* vardecl: KWINT ID LBRACKET NUMBER RBRACKET  */
#line 322 "parser.y"
      {
      if (debug) fprintf(stderr,"vardecl def\n");
      
      if ( findSymbol(table, (yyvsp[-3].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[-3].str), S_GLOBAL, T_INT, 8 * (yyvsp[-1].ival), 0, K_GLOBALARRAY);
              
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[-3].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_INT;
      (yyval.astnode)->varKind = K_GLOBALARRAY;
      (yyval.astnode)->ival = (yyvsp[-1].ival);
      }
#line 1669 "y.tab.c"
    break;

  case 32: /* parameters: %empty  */
#line 339 "parser.y"
            {(yyval.astnode) = 0;}
#line 1675 "y.tab.c"
    break;

  case 33: /* parameters: paramdecl  */
#line 341 "parser.y"
      {
      if (debug) fprintf(stderr,"parameters def\n");
      (yyval.astnode) = (yyvsp[0].astnode);
       }
#line 1684 "y.tab.c"
    break;

  case 34: /* parameters: paramdecl COMMA parameters  */
#line 346 "parser.y"
       {
      if (debug) fprintf(stderr,"parameters def\n");
      (yyval.astnode)->next = (yyvsp[0].astnode);
      (yyval.astnode) = (yyvsp[-2].astnode);
       }
#line 1694 "y.tab.c"
    break;

  case 35: /* paramdecl: KWINT ID  */
#line 353 "parser.y"
      {
      if (debug) fprintf(stderr,"paramdecl def\n");
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), S_LOCAL, T_INT, 4, paramNum, K_PARAM);
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_INT;
      (yyval.astnode)->varKind = K_PARAM;
      (yyval.astnode)->ival = paramNum++;
      }
#line 1713 "y.tab.c"
    break;

  case 36: /* paramdecl: KWSTRING ID  */
#line 368 "parser.y"
      {
      if (debug) fprintf(stderr,"paramdecl def\n");
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), S_LOCAL, T_STRING, 52, paramNum, K_PARAM);
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_STRING;
      (yyval.astnode)->varKind = K_PARAM;
      (yyval.astnode)->ival = paramNum++;
      }
#line 1732 "y.tab.c"
    break;

  case 37: /* localvars: %empty  */
#line 383 "parser.y"
           {(yyval.astnode) = 0;}
#line 1738 "y.tab.c"
    break;

  case 38: /* localvars: KWLOCAL localdecl SEMICOLON localvars  */
#line 385 "parser.y"
      {
      if (debug) fprintf(stderr,"localvars def\n");
      (yyvsp[-2].astnode)->next = (yyvsp[0].astnode);
      (yyval.astnode) = (yyvsp[-2].astnode);
      }
#line 1748 "y.tab.c"
    break;

  case 39: /* localdecl: KWINT ID  */
#line 392 "parser.y"
      {
      if (debug) fprintf(stderr,"localdecl def\n");
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), S_LOCAL, T_INT, 4, paramNum, K_LOCAL);
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_INT;
      (yyval.astnode)->varKind = K_LOCAL;
      (yyval.astnode)->ival = paramNum++;
      }
#line 1767 "y.tab.c"
    break;

  case 40: /* localdecl: KWSTRING ID  */
#line 407 "parser.y"
      {
      if (debug) fprintf(stderr,"localdecl def\n");
      if ( findSymbol(table, (yyvsp[0].str)) != NULL) {
          fprintf(stderr, "Error: variable already defined.\n");
          exit(1);
      }
      addSymbol(table, (yyvsp[0].str), S_LOCAL, T_STRING, 52, paramNum, K_LOCAL);
      (yyval.astnode) = (ASTNode*) newASTNode(AST_VARDECL);
      (yyval.astnode)->strval = (yyvsp[0].str);
      (yyval.astnode)->strNeedsFreed = 1;
      (yyval.astnode)->valType = T_STRING;
      (yyval.astnode)->ival = paramNum++;
      (yyval.astnode)->varKind = K_LOCAL;
      }
#line 1786 "y.tab.c"
    break;

  case 41: /* ifthenelse: KWIF LPAREN boolexpr RPAREN KWTHEN LBRACE statements RBRACE KWELSE LBRACE statements RBRACE  */
#line 423 "parser.y"
      {
      if (debug) fprintf(stderr,"ifthenelse def\n");
      (yyval.astnode) = (ASTNode*) newASTNode(AST_IFTHEN);
      (yyval.astnode)->child[0] = (yyvsp[-9].astnode);
      (yyval.astnode)->child[1] = (yyvsp[-5].astnode);
      (yyval.astnode)->child[2] = (yyvsp[-1].astnode);
      }
#line 1798 "y.tab.c"
    break;

  case 42: /* whileloop: KWWHILE LPAREN boolexpr RPAREN KWDO LBRACE statements RBRACE  */
#line 432 "parser.y"
      {
      if (debug) fprintf(stderr,"whileloop def\n");
      (yyval.astnode) = (ASTNode*) newASTNode(AST_WHILE);
      (yyval.astnode)->child[0] = (yyvsp[-5].astnode);
      (yyval.astnode)->child[1] = (yyvsp[-1].astnode);
      }
#line 1809 "y.tab.c"
    break;

  case 43: /* boolexpr: expression RELOP expression  */
#line 440 "parser.y"
      {
      if (debug) fprintf(stderr,"boolexpr def\n");
      (yyval.astnode) = (ASTNode*) newASTNode(AST_RELEXPR);
      (yyval.astnode)->child[0] = (yyvsp[-2].astnode);
      (yyval.astnode)->ival = (yyvsp[-1].ival);
      (yyval.astnode)->child[1] = (yyvsp[0].astnode);
      }
#line 1821 "y.tab.c"
    break;

  case 44: /* returnstmt: KWRETURNVAL expression SEMICOLON  */
#line 449 "parser.y"
      {
      if (debug) fprintf(stderr,"returnstmt def\n");
      (yyval.astnode) = (yyvsp[-1].astnode);
      }
#line 1830 "y.tab.c"
    break;


#line 1834 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 454 "parser.y"

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

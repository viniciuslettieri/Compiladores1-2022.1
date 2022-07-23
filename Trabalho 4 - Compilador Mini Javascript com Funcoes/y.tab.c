/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilador.y"


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Atributos {
    vector<string> v;
    int contador = 0;
};


#define YYSTYPE Atributos

void erro( string msg );
void Print( vector<string> st );
int retorna( int tk );
string nome_token( int token );
inline string trim( string s, const char* t );
vector<string> tokeniza( string text, char delim );

string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );
bool trata_declaracoes( string id, string tipo );
void trata_uso( string id );
void trata_atribuicao( string id );

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

int linha = 1;
int coluna = 1;

// Controle de Variaveis Declaradas
vector< unordered_map<string, pair<string, int>> > declarations = {{}};
void abre_escopo();
void fecha_escopo();

// Tratamento de Funcoes
vector<string> default_return = { "undefined", "@", "'&retorno'", "@", "~" };
vector<string> function_area;


#line 125 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    ID = 258,
    NUM = 259,
    MAIG = 260,
    MEIG = 261,
    IG = 262,
    DIF = 263,
    MAATR = 264,
    MEATR = 265,
    INCREM = 266,
    DECREM = 267,
    STRING = 268,
    COMENTARIO = 269,
    LET = 270,
    CONST = 271,
    VAR = 272,
    IF = 273,
    ELSE = 274,
    WHILE = 275,
    FOR = 276,
    FUNCTION = 277,
    RETURN = 278,
    ASM = 279,
    TRUE = 280,
    FALSE = 281
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define MAIG 260
#define MEIG 261
#define IG 262
#define DIF 263
#define MAATR 264
#define MEATR 265
#define INCREM 266
#define DECREM 267
#define STRING 268
#define COMENTARIO 269
#define LET 270
#define CONST 271
#define VAR 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define FOR 276
#define FUNCTION 277
#define RETURN 278
#define ASM 279
#define TRUE 280
#define FALSE 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      39,    40,    32,    30,    43,    31,    36,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    44,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    73,    76,    77,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    93,    95,
      95,    95,   101,   101,   101,   108,   113,   120,   127,   136,
     146,   155,   166,   169,   170,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   198,   199,   200,
     203,   206,   207,   208,   209,   212,   215,   216,   217,   218,
     221,   224,   225,   226,   227,   230,   231,   232,   233,   234,
     235,   238,   239,   240,   241,   242,   243,   244,   245,   248,
     250,   253,   253,   253,   254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "MAIG", "MEIG", "IG", "DIF",
  "MAATR", "MEATR", "INCREM", "DECREM", "STRING", "COMENTARIO", "LET",
  "CONST", "VAR", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN",
  "ASM", "TRUE", "FALSE", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "'.'", "'['", "';'", "'('", "')'", "'{'", "'}'", "','",
  "']'", "$accept", "S", "CMDz", "CMDs", "CMD", "CMD_RETURN",
  "CMD_FUNCTION", "$@1", "$@2", "$@3", "$@4", "PARAMS", "CMD_IF",
  "CMD_WHILE", "CMD_FOR", "LVALUE", "LVALUEPROP", "RVALUE", "EXPR",
  "CMD_DECL", "CMD_LET", "MULTI_LET", "CMD_VAR", "MULTI_VAR", "CMD_CONST",
  "MULTI_CONST", "ATRIB", "FINAL", "ARGS", "BLOCO", "$@5", "$@6", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    60,    62,
      43,    45,    42,    47,    37,    94,    46,    91,    59,    40,
      41,   123,   125,    44,    93
};
# endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     208,   -91,   -91,   -91,    14,    20,    26,   -34,    -3,    10,
      28,   237,   -91,   -91,    17,    17,     7,   -91,   237,    -1,
      52,   -91,   208,   -91,   -91,   -91,   -91,   -91,     1,    -2,
     275,    15,   -91,   -91,   -91,    19,    23,   -91,   -11,   -91,
      -9,   -91,    -8,   -91,   237,   237,   240,    25,    27,    30,
     286,   -91,    33,   -91,    64,    64,   -91,    34,   -91,   208,
     -91,   -91,   237,   237,   -91,   -91,   237,   237,   237,   237,
      17,    17,    17,    17,    45,    17,    17,    17,    17,    17,
      17,    17,    17,    62,   237,   -91,   -91,   -91,    91,   237,
      14,   237,    20,   237,    26,    53,    63,   286,    54,    69,
      99,   -91,   -91,   -91,   -91,   208,   -91,   -91,   -91,   -91,
     -91,   -91,   319,   319,   319,   319,   -91,   319,   319,    64,
      64,     2,     2,     2,     2,   -91,    66,   -91,    65,    74,
      75,   -91,    76,   -91,    77,   -91,   208,   208,   237,   237,
      83,   126,    92,   -91,   -91,   237,   -91,    14,    20,    26,
     114,   -91,    97,   100,    98,   -91,   -16,   -91,   -91,   -91,
     -91,   -91,   208,    17,    17,   208,   104,   143,   -91,   107,
     108,   110,   208,   -91,   208,   208,   -91,   111,   -91,   -91,
     -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    32,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,     0,     0,     0,    13,     0,    91,
       0,     2,     4,    12,    11,     8,    10,     9,    85,    86,
       0,     0,    57,    58,    59,     0,    54,    17,    64,    60,
      74,    70,    69,    65,     0,     0,     0,     0,     0,     0,
      36,    35,    85,    86,    52,    53,    83,     0,    94,     0,
       1,     3,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     7,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    37,    18,    84,    92,     6,    76,    77,    75,    79,
      80,    78,    39,    38,    40,    41,    15,    43,    44,    46,
      47,    45,    48,    49,    42,    33,     0,    55,    90,     0,
      62,    63,    72,    73,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     5,    34,     0,    56,     0,     0,     0,
      27,    29,     0,     0,     0,    26,     0,    93,    89,    61,
      71,    66,     0,     0,     0,     4,     0,     0,    28,     0,
       0,     0,     4,    25,     0,     0,    20,     0,    30,    31,
      21,    23,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -21,    44,   -50,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   112,   128,    22,     0,   109,
     -91,   -87,   -91,   -88,   -91,   -90,     4,   -91,     5,   -91,
     -91,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,   104,    22,    23,    24,   140,   180,   141,
     182,   156,    25,    26,    27,    28,    29,   128,    50,    31,
      32,    39,    33,    43,    34,    41,    51,    36,   129,    37,
      59,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    61,   133,   131,    35,    44,   135,    67,    68,   105,
      62,    63,    64,    65,    54,    55,    89,    38,    91,    93,
       1,     2,    30,    40,   166,    69,    35,   167,    66,    42,
       3,    47,    90,    49,    92,    94,    45,    82,    83,    84,
      57,    58,    12,    13,    64,    65,    97,    14,    15,    46,
      99,    56,    60,    86,    16,   105,    18,    87,   160,    30,
     159,   161,    88,    35,   100,   125,    95,    96,   102,   101,
     112,   113,   114,   115,   103,   117,   118,   119,   120,   121,
     122,   123,   124,   116,   106,   107,   150,   151,   108,   109,
     110,   111,   138,   136,     1,     2,    79,    80,    81,    82,
      83,    84,   -22,   137,     3,    30,   126,   139,   145,    35,
     144,   130,   168,   132,   146,   134,    12,    13,   147,   148,
     149,    14,    15,   154,   178,   179,    52,    52,    16,   155,
      18,   127,    48,   162,   157,   163,    30,    30,   164,   165,
      35,    35,    53,    53,   171,   172,   173,   174,   175,   143,
     158,   177,   176,   181,     0,    98,     0,     0,     0,     0,
     152,   153,    30,    97,    97,    30,    35,   169,   170,    35,
       0,     0,    30,     0,    30,    30,    35,     0,    35,    35,
       0,     0,    52,    52,    52,    52,     0,    52,    52,    52,
      52,    52,    52,    52,    52,     0,     0,     0,    53,    53,
      53,    53,     0,    53,    53,    53,    53,    53,    53,    53,
      53,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     4,     5,     6,     7,     0,     8,     9,
      10,    11,     0,    12,    13,     0,     0,     0,    14,    15,
       1,     2,     0,     1,     2,    16,    17,    18,     0,    19,
       3,     0,     0,     3,     0,     4,     5,     6,     0,     0,
       0,     0,    12,    13,     0,    12,    13,    14,    15,     0,
      14,    15,     0,     0,    16,     0,    18,    16,    48,    18,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,     0,     0,     0,     0,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   -23,   -23,   -23,   -23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -23,   -23,    77,
      78,    79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       0,    22,    92,    90,     0,    39,    94,     9,    10,    59,
       9,    10,    11,    12,    14,    15,    27,     3,    27,    27,
       3,     4,    22,     3,    40,    27,    22,    43,    27,     3,
      13,     3,    43,    11,    43,    43,    39,    35,    36,    37,
      18,    42,    25,    26,    11,    12,    46,    30,    31,    39,
      46,    44,     0,    38,    37,   105,    39,    38,   148,    59,
     147,   149,    39,    59,    39,     3,    44,    45,    38,    42,
      70,    71,    72,    73,    40,    75,    76,    77,    78,    79,
      80,    81,    82,    38,    62,    63,   136,   137,    66,    67,
      68,    69,    38,    40,     3,     4,    32,    33,    34,    35,
      36,    37,     3,    40,    13,   105,    84,    38,    43,   105,
      44,    89,   162,    91,    40,    93,    25,    26,    43,    43,
      43,    30,    31,    40,   174,   175,    14,    15,    37,     3,
      39,    40,    41,    19,    42,    38,   136,   137,    38,    41,
     136,   137,    14,    15,   165,    41,     3,    40,    40,   105,
     145,   172,    42,    42,    -1,    46,    -1,    -1,    -1,    -1,
     138,   139,   162,   163,   164,   165,   162,   163,   164,   165,
      -1,    -1,   172,    -1,   174,   175,   172,    -1,   174,   175,
      -1,    -1,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    -1,    30,    31,
       3,     4,    -1,     3,     4,    37,    38,    39,    -1,    41,
      13,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    25,    26,    -1,    25,    26,    30,    31,    -1,
      30,    31,    -1,    -1,    37,    -1,    39,    37,    41,    39,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    13,    15,    16,    17,    18,    20,    21,
      22,    23,    25,    26,    30,    31,    37,    38,    39,    41,
      46,    47,    49,    50,    51,    57,    58,    59,    60,    61,
      63,    64,    65,    67,    69,    71,    72,    74,     3,    66,
       3,    70,     3,    68,    39,    39,    39,     3,    41,    62,
      63,    71,    60,    61,    63,    63,    44,    62,    42,    75,
       0,    47,     9,    10,    11,    12,    27,     9,    10,    27,
       5,     6,     7,     8,    24,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    38,    38,    39,    27,
      43,    27,    43,    27,    43,    62,    62,    63,    64,    71,
      39,    42,    38,    40,    48,    49,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    38,    63,    63,    63,
      63,    63,    63,    63,    63,     3,    62,    40,    62,    73,
      62,    66,    62,    70,    62,    68,    40,    40,    38,    38,
      52,    54,    76,    48,    44,    43,    40,    43,    43,    43,
      49,    49,    62,    62,    40,     3,    56,    42,    73,    66,
      70,    68,    19,    38,    38,    41,    40,    43,    49,    71,
      71,    47,    41,     3,    40,    40,    42,    47,    49,    49,
      53,    42,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    52,
      53,    51,    54,    55,    51,    56,    56,    57,    57,    58,
      59,    59,    60,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      65,    66,    66,    66,    66,    67,    68,    68,    68,    68,
      69,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    75,    76,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     1,     3,     0,
       0,     9,     0,     0,    10,     3,     1,     5,     7,     5,
       9,     9,     1,     3,     4,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     3,     4,     1,     1,     1,
       2,     5,     3,     3,     1,     2,     5,     3,     3,     1,
       2,     5,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     3,     1,     1,     1,     1,     3,
       1,     0,     0,     5,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 69 "compilador.y"
                                            { Print(yyvsp[0].v + "." + function_area); }
#line 1555 "y.tab.c"
    break;

  case 3:
#line 72 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + yyvsp[0].v; }
#line 1561 "y.tab.c"
    break;

  case 4:
#line 73 "compilador.y"
                                            { yyval.v = {}; }
#line 1567 "y.tab.c"
    break;

  case 5:
#line 76 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + yyvsp[0].v; }
#line 1573 "y.tab.c"
    break;

  case 6:
#line 77 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1579 "y.tab.c"
    break;

  case 7:
#line 80 "compilador.y"
                                            { yyval.v = yyvsp[-1].v; }
#line 1585 "y.tab.c"
    break;

  case 8:
#line 81 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1591 "y.tab.c"
    break;

  case 9:
#line 82 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1597 "y.tab.c"
    break;

  case 10:
#line 83 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1603 "y.tab.c"
    break;

  case 11:
#line 84 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1609 "y.tab.c"
    break;

  case 12:
#line 85 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1615 "y.tab.c"
    break;

  case 13:
#line 86 "compilador.y"
                                            { yyval.v = {}; }
#line 1621 "y.tab.c"
    break;

  case 14:
#line 87 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "^"; }
#line 1627 "y.tab.c"
    break;

  case 15:
#line 88 "compilador.y"
                                                { yyval.v = yyvsp[-2].v + yyvsp[-1].v + "^"; }
#line 1633 "y.tab.c"
    break;

  case 16:
#line 89 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "^"; }
#line 1639 "y.tab.c"
    break;

  case 17:
#line 90 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1645 "y.tab.c"
    break;

  case 18:
#line 93 "compilador.y"
                                                        {   yyval.v = yyvsp[-1].v + "'&retorno'" + "@" + "~"; }
#line 1651 "y.tab.c"
    break;

  case 19:
#line 95 "compilador.y"
                              { trata_declaracoes(yyvsp[-1].v[0], "function"); abre_escopo();  }
#line 1657 "y.tab.c"
    break;

  case 20:
#line 95 "compilador.y"
                                                                                                           { fecha_escopo(); }
#line 1663 "y.tab.c"
    break;

  case 21:
#line 96 "compilador.y"
                                                        {   
                                                            string funcao_label = gera_label("funcao" + yyvsp[-7].v[0]); 
                                                            function_area = function_area + (":" + funcao_label) + 
                                                                            yyvsp[-2].v + default_return; 
                                                            yyval.v = yyvsp[-7].v + "&" + yyvsp[-7].v + "{}" + "=" + "'&funcao'" + funcao_label + "[=]" + "^"; }
#line 1673 "y.tab.c"
    break;

  case 22:
#line 101 "compilador.y"
                              { trata_declaracoes(yyvsp[-1].v[0], "function"); abre_escopo(); }
#line 1679 "y.tab.c"
    break;

  case 23:
#line 101 "compilador.y"
                                                                                                                  { fecha_escopo(); }
#line 1685 "y.tab.c"
    break;

  case 24:
#line 102 "compilador.y"
                                                        {   
                                                            string funcao_label = gera_label("funcao" + yyvsp[-8].v[0]); 
                                                            function_area = function_area + (":" + funcao_label) + 
                                                                            yyvsp[-5].v + yyvsp[-2].v + default_return; 
                                                            yyval.v = yyvsp[-8].v + "&" + yyvsp[-8].v + "{}" + "=" + "'&funcao'" + funcao_label + "[=]" + "^"; }
#line 1695 "y.tab.c"
    break;

  case 25:
#line 108 "compilador.y"
                                                        {   yyval.contador = 1 + yyvsp[-2].contador;
                                                            vector<string> decl = {yyvsp[0].v[0], "&"}; if(!trata_declaracoes(yyvsp[0].v[0], "var")) decl = {};
                                                            yyval.v = yyvsp[-2].v + decl + yyvsp[0].v + "arguments" + "@" + 
                                                                   to_string(yyval.contador) + "[@]" + "=" + "^"; 
                                                        }
#line 1705 "y.tab.c"
    break;

  case 26:
#line 113 "compilador.y"
                                                        {   yyval.contador = 0;
                                                            vector<string> decl = {yyvsp[0].v[0], "&"}; if(!trata_declaracoes(yyvsp[0].v[0], "var")) decl = {}; 
                                                            yyval.v = decl + yyvsp[0].v + "arguments" + "@" + 
                                                                   to_string(yyval.contador) + "[@]" + "=" + "^"; 
                                                        }
#line 1715 "y.tab.c"
    break;

  case 27:
#line 120 "compilador.y"
                                                {   string ifok_label = gera_label("ifok");
                                                    string ifend_label = gera_label("ifend");
                                                    yyval.v = yyvsp[-2].v + (ifok_label) + "?" + 
                                                           (ifend_label) + "#" + 
                                                           (":" + ifok_label) + yyvsp[0].v + 
                                                           (":" + ifend_label);   }
#line 1726 "y.tab.c"
    break;

  case 28:
#line 127 "compilador.y"
                                                {   string ifok_label = gera_label("ifok");
                                                    string ifelse_label = gera_label("ifelse");
                                                    string ifend_label = gera_label("ifend");
                                                    yyval.v = yyvsp[-4].v + (ifok_label) + "?" + 
                                                           (ifelse_label) + "#" + 
                                                           (":" + ifok_label) + yyvsp[-2].v + (ifend_label) + "#" + 
                                                           (":" + ifelse_label) + yyvsp[0].v + (":" + ifend_label);   }
#line 1738 "y.tab.c"
    break;

  case 29:
#line 136 "compilador.y"
                                                {   string whileexpr_label = gera_label("whileexpr");
                                                    string whileend_label = gera_label("whileend");
                                                    string whileok_label = gera_label("whileok");
                                                    yyval.v =  (":" + whileexpr_label) + yyvsp[-2].v + (whileok_label) + "?" + 
                                                            (whileend_label) + "#" + 
                                                            (":" + whileok_label) + yyvsp[0].v + 
                                                            (whileexpr_label) + "#" + 
                                                            (":" + whileend_label);   }
#line 1751 "y.tab.c"
    break;

  case 30:
#line 146 "compilador.y"
                                                                {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    yyval.v = yyvsp[-6].v + 
                                                                           (":" + forexpr_label) + yyvsp[-4].v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + yyvsp[0].v + 
                                                                           yyvsp[-2].v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
#line 1765 "y.tab.c"
    break;

  case 31:
#line 155 "compilador.y"
                                                                {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    yyval.v = yyvsp[-6].v + "^" + 
                                                                           (":" + forexpr_label) + yyvsp[-4].v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + yyvsp[0].v + 
                                                                           yyvsp[-2].v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
#line 1779 "y.tab.c"
    break;

  case 32:
#line 166 "compilador.y"
                                          { /*trata_uso( $1.v[0] );*/ yyval.v = yyvsp[0].v; }
#line 1785 "y.tab.c"
    break;

  case 33:
#line 169 "compilador.y"
                                          { yyval.v = yyvsp[-2].v + yyvsp[0].v; }
#line 1791 "y.tab.c"
    break;

  case 34:
#line 170 "compilador.y"
                                          { yyval.v = yyvsp[-3].v + yyvsp[-1].v; }
#line 1797 "y.tab.c"
    break;

  case 35:
#line 173 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1803 "y.tab.c"
    break;

  case 36:
#line 174 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1809 "y.tab.c"
    break;

  case 37:
#line 175 "compilador.y"
                                            { yyval.v = {string("{}")}; }
#line 1815 "y.tab.c"
    break;

  case 38:
#line 177 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "<="; }
#line 1821 "y.tab.c"
    break;

  case 39:
#line 178 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + ">="; }
#line 1827 "y.tab.c"
    break;

  case 40:
#line 179 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "=="; }
#line 1833 "y.tab.c"
    break;

  case 41:
#line 180 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "!="; }
#line 1839 "y.tab.c"
    break;

  case 42:
#line 181 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "^"; }
#line 1845 "y.tab.c"
    break;

  case 43:
#line 182 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "<"; }
#line 1851 "y.tab.c"
    break;

  case 44:
#line 183 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + ">"; }
#line 1857 "y.tab.c"
    break;

  case 45:
#line 184 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "*"; }
#line 1863 "y.tab.c"
    break;

  case 46:
#line 185 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "+"; }
#line 1869 "y.tab.c"
    break;

  case 47:
#line 186 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "-"; }
#line 1875 "y.tab.c"
    break;

  case 48:
#line 187 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "/"; }
#line 1881 "y.tab.c"
    break;

  case 49:
#line 188 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "%"; }
#line 1887 "y.tab.c"
    break;

  case 50:
#line 189 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "@" + yyvsp[-1].v + yyvsp[-1].v + "@" + "1" + "+" + "=" + "^"; }
#line 1893 "y.tab.c"
    break;

  case 51:
#line 190 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "@" + yyvsp[-1].v + yyvsp[-1].v + "@" + "1" + "-" + "=" + "^"; }
#line 1899 "y.tab.c"
    break;

  case 52:
#line 191 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1905 "y.tab.c"
    break;

  case 53:
#line 192 "compilador.y"
                                            { yyval.v = "0" + yyvsp[0].v + "-"; }
#line 1911 "y.tab.c"
    break;

  case 54:
#line 193 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1917 "y.tab.c"
    break;

  case 55:
#line 194 "compilador.y"
                                            { yyval.v = "0" + yyvsp[-2].v + "$"; }
#line 1923 "y.tab.c"
    break;

  case 56:
#line 195 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + to_string(yyvsp[-1].contador) + yyvsp[-3].v + "$"; }
#line 1929 "y.tab.c"
    break;

  case 57:
#line 198 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1935 "y.tab.c"
    break;

  case 58:
#line 199 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1941 "y.tab.c"
    break;

  case 59:
#line 200 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1947 "y.tab.c"
    break;

  case 60:
#line 203 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1953 "y.tab.c"
    break;

  case 61:
#line 206 "compilador.y"
                                                { vector<string> decl = {yyvsp[-4].v[0], "&"}; if(!trata_declaracoes(yyvsp[-4].v[0], "let")) decl = {}; yyval.v = decl + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 1959 "y.tab.c"
    break;

  case 62:
#line 207 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "let")) decl = {}; yyval.v = decl + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 1965 "y.tab.c"
    break;

  case 63:
#line 208 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "let")) decl = {}; yyval.v = decl + yyvsp[0].v; }
#line 1971 "y.tab.c"
    break;

  case 64:
#line 209 "compilador.y"
                                                { vector<string> decl = {yyvsp[0].v[0], "&"}; if(!trata_declaracoes(yyvsp[0].v[0], "let")) decl = {}; yyval.v = decl; }
#line 1977 "y.tab.c"
    break;

  case 65:
#line 212 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1983 "y.tab.c"
    break;

  case 66:
#line 215 "compilador.y"
                                                { vector<string> decl = {yyvsp[-4].v[0], "&"}; if(!trata_declaracoes(yyvsp[-4].v[0], "var")) decl = {}; yyval.v = decl + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 1989 "y.tab.c"
    break;

  case 67:
#line 216 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "var")) decl = {}; yyval.v = decl + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 1995 "y.tab.c"
    break;

  case 68:
#line 217 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "var")) decl = {}; yyval.v = decl + yyvsp[0].v; }
#line 2001 "y.tab.c"
    break;

  case 69:
#line 218 "compilador.y"
                                                { vector<string> decl = {yyvsp[0].v[0], "&"}; if(!trata_declaracoes(yyvsp[0].v[0], "var")) decl = {}; yyval.v = decl; }
#line 2007 "y.tab.c"
    break;

  case 70:
#line 221 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 2013 "y.tab.c"
    break;

  case 71:
#line 224 "compilador.y"
                                                { vector<string> decl = {yyvsp[-4].v[0], "&"}; if(!trata_declaracoes(yyvsp[-4].v[0], "const")) decl = {}; yyval.v = decl + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 2019 "y.tab.c"
    break;

  case 72:
#line 225 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "const")) decl = {}; yyval.v = decl + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 2025 "y.tab.c"
    break;

  case 73:
#line 226 "compilador.y"
                                                { vector<string> decl = {yyvsp[-2].v[0], "&"}; if(!trata_declaracoes(yyvsp[-2].v[0], "const")) decl = {}; yyval.v = decl + yyvsp[0].v; }
#line 2031 "y.tab.c"
    break;

  case 74:
#line 227 "compilador.y"
                                                { vector<string> decl = {yyvsp[0].v[0], "&"}; if(!trata_declaracoes(yyvsp[0].v[0], "const")) decl = {}; yyval.v = decl; }
#line 2037 "y.tab.c"
    break;

  case 75:
#line 230 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[0].v + "="; }
#line 2043 "y.tab.c"
    break;

  case 76:
#line 231 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "@" + yyvsp[0].v + "+" + "="; }
#line 2049 "y.tab.c"
    break;

  case 77:
#line 232 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "@" + yyvsp[0].v + "-" + "="; }
#line 2055 "y.tab.c"
    break;

  case 78:
#line 233 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[0].v + "[=]"; }
#line 2061 "y.tab.c"
    break;

  case 79:
#line 234 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "[@]" + yyvsp[0].v + "+" + "[=]"; }
#line 2067 "y.tab.c"
    break;

  case 80:
#line 235 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "[@]" + yyvsp[0].v + "-" + "[=]"; }
#line 2073 "y.tab.c"
    break;

  case 81:
#line 238 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 2079 "y.tab.c"
    break;

  case 82:
#line 239 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 2085 "y.tab.c"
    break;

  case 83:
#line 240 "compilador.y"
                                            { yyval.v = { string("[]") }; }
#line 2091 "y.tab.c"
    break;

  case 84:
#line 241 "compilador.y"
                                            { yyval.v = yyvsp[-1].v; }
#line 2097 "y.tab.c"
    break;

  case 85:
#line 242 "compilador.y"
                                            { yyval.v = yyvsp[0].v + "@"; }
#line 2103 "y.tab.c"
    break;

  case 86:
#line 243 "compilador.y"
                                            { yyval.v = yyvsp[0].v + "[@]"; }
#line 2109 "y.tab.c"
    break;

  case 87:
#line 244 "compilador.y"
                                            { yyval.v = {"true"}; }
#line 2115 "y.tab.c"
    break;

  case 88:
#line 245 "compilador.y"
                                            { yyval.v = {"false"}; }
#line 2121 "y.tab.c"
    break;

  case 89:
#line 248 "compilador.y"
                                                        {   yyval.v = yyvsp[-2].v + yyvsp[0].v;
                                                            yyval.contador = 1 + yyvsp[0].contador;  }
#line 2128 "y.tab.c"
    break;

  case 90:
#line 250 "compilador.y"
                                                        {   yyval.v = yyvsp[0].v;
                                                            yyval.contador = 1;   }
#line 2135 "y.tab.c"
    break;

  case 91:
#line 253 "compilador.y"
                  { abre_escopo(); }
#line 2141 "y.tab.c"
    break;

  case 92:
#line 253 "compilador.y"
                                          { fecha_escopo(); }
#line 2147 "y.tab.c"
    break;

  case 93:
#line 253 "compilador.y"
                                                                            { yyval.v = "<{" + yyvsp[-2].v + "}>"; }
#line 2153 "y.tab.c"
    break;

  case 94:
#line 254 "compilador.y"
                                                                            { yyval.v = {}; }
#line 2159 "y.tab.c"
    break;


#line 2163 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 257 "compilador.y"


#include "lex.yy.c"

map<int, string> nome_tokens = {
    { STRING, "string" },
    { ID, "nome de identificador" },
    { NUM, "número" }
};

string nome_token( int token ) {
    if( nome_tokens.find( token ) != nome_tokens.end() )
        return nome_tokens[token];
    else {
        string r;
        r = token;
        return r;
    }
}

int retorna( int tk ) {  
    yylval.v = {yytext}; 
    coluna += strlen( yytext ); 
    return tk;
}

string gera_label( string prefixo ) {
    static int n_label = 0;
    return prefixo + "_" + to_string( ++n_label ) + ":";
}

inline string trim( string s, const char* t = " \t\n\r\f\v" ) {
    s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// https://stackoverflow.com/a/65075284
vector<string> tokeniza( string text, char delim ) {
    string line;
    vector<string> vec;
    stringstream ss(text);
    while(getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
    map<string,int> label;
    vector<string> saida;
    for( int i = 0; i < entrada.size(); i++ )
        if( entrada[i][0] == ':' ) 
            label[entrada[i].substr(1)] = saida.size();
        else
            saida.push_back( entrada[i] );

    for( int i = 0; i < saida.size(); i++ ) 
        if( label.count( saida[i] ) > 0 )
            saida[i] = to_string(label[saida[i]]);

    return saida;
}

vector<string> concatena( vector<string> a, vector<string> b ) {
    a.insert( a.end(), b.begin(), b.end() );
    return a;
}
vector<string> operator+( vector<string> a, vector<string> b ) {
    return concatena( a, b );
}
vector<string> operator+( vector<string> a, string b ) {
    a.push_back( b );
    return a;
}
vector<string> operator+( string a, vector<string> b ) {
    b.insert(b.begin(), a);
    return b;
}

void yyerror( const char* msg ) {
    cout << msg << endl;
    exit(1);
}

bool trata_declaracoes( string id, string tipo ){
    int i=1;
    for(auto decl = declarations.rbegin(); decl != declarations.rend(); decl++){
        auto decl_type = (*decl).find(id);
        if(decl_type == (*decl).end()){
            continue;
        }else if(tipo == "let"){
            if(decl == declarations.rbegin()){
                string linha_decl = to_string(decl_type->second.second);
                string msg = "Erro: a variável '" + id + "' já foi declarada na linha " + linha_decl + ".";
                yyerror(msg.c_str());
                return false;
            }
        }else if(tipo == "var"){
            if(decl_type->second.first == "var" && decl == declarations.rbegin()){
                return false;
            }
            if(decl_type->second.first != "var" && decl == declarations.rbegin()){
                string linha_decl = to_string(decl_type->second.second);
                string msg = "Erro: a variável '" + id + "' já foi declarada na linha " + linha_decl + ".";
                yyerror(msg.c_str());
                return false;
            }
        }else if(tipo == "const"){
            if(decl == declarations.rbegin()){
                string linha_decl = to_string(decl_type->second.second);
                string msg = "Erro: a variável '" + id + "' já foi declarada na linha " + linha_decl + ".";
                yyerror(msg.c_str());
                return false;
            }
        }
    }

    // O id ainda nao foi declarado
    // cout << "id " << id << " declarado no escopo " << declarations.size() << endl;
    declarations[declarations.size()-1][id] = {tipo, linha};
    return true;
}

void trata_uso( string id ){
    int i=1;
    for(auto decl = declarations.rbegin(); decl != declarations.rend(); decl++){
        auto decl_type = (*decl).find(id);
        if(decl_type != (*decl).end()){
            return;
        }
    }
    
    // O id ainda nao foi declarado
    string msg = "Erro: a variável '" + id + "' não foi declarada.";
    yyerror(msg.c_str());
}

void trata_atribuicao( string id ){
    int i=1;
    for(auto decl = declarations.rbegin(); decl != declarations.rend(); decl++){
        auto decl_type = (*decl).find(id);
        if(decl_type == (*decl).end()){
            continue;
        }else if(decl_type->second.first == "const"){
            string msg = "Erro: tentativa de modificar uma variável constante ('" + id + "').";
            yyerror(msg.c_str());
            return;
        }
    }
}

void Print( vector<string> st ) {
    int linha = 0;
    vector<string> enderecos_resolvidos = resolve_enderecos(st);
    for( auto x: enderecos_resolvidos )
        cout << x << "\n";
}

void abre_escopo(){
    declarations.push_back({});
}
void fecha_escopo(){
    declarations.pop_back();
}

int main( int argc, char* argv[] ) {
    yyparse();
    return 0;
}

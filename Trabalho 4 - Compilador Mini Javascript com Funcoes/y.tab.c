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

using namespace std;

struct Atributos {
    vector<string> v;
};


#define YYSTYPE Atributos

void erro( string msg );
void Print( vector<string> st );
int retorna( int tk );
string nome_token( int token );

string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );
void trata_declaracoes( string id, string tipo );
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


#line 121 "y.tab.c"

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
    PRINT = 258,
    ID = 259,
    NUM = 260,
    MAIG = 261,
    MEIG = 262,
    IG = 263,
    DIF = 264,
    MAATR = 265,
    MEATR = 266,
    INCREM = 267,
    DECREM = 268,
    STRING = 269,
    COMENTARIO = 270,
    LET = 271,
    CONST = 272,
    VAR = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    FOR = 277,
    NEWARRAY = 278,
    FUNCTION = 279,
    RETURN = 280
  };
#endif
/* Tokens.  */
#define PRINT 258
#define ID 259
#define NUM 260
#define MAIG 261
#define MEIG 262
#define IG 263
#define DIF 264
#define MAATR 265
#define MEATR 266
#define INCREM 267
#define DECREM 268
#define STRING 269
#define COMENTARIO 270
#define LET 271
#define CONST 272
#define VAR 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define FOR 277
#define NEWARRAY 278
#define FUNCTION 279
#define RETURN 280

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

#define YYUNDEFTOK  2
#define YYMAXUTOK   280


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
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      38,    39,    31,    29,    43,    30,    35,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      27,    26,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    42,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    68,    69,    72,    73,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    88,    90,    95,
     102,   111,   121,   130,   141,   144,   145,   148,   149,   150,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   171,   172,   173,
     176,   179,   180,   181,   182,   185,   188,   189,   190,   191,
     194,   197,   198,   199,   200,   203,   204,   205,   206,   207,
     208,   211,   212,   213,   214,   215,   216,   217,   221,   221,
     221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "ID", "NUM", "MAIG", "MEIG",
  "IG", "DIF", "MAATR", "MEATR", "INCREM", "DECREM", "STRING",
  "COMENTARIO", "LET", "CONST", "VAR", "IF", "ELSE", "WHILE", "FOR",
  "NEWARRAY", "FUNCTION", "RETURN", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "'.'", "'['", "';'", "'('", "')'", "'{'",
  "'}'", "']'", "','", "$accept", "S", "CMDz", "CMDs", "CMD", "CMD_RETURN",
  "CMD_FUNCTION", "CMD_IF", "CMD_WHILE", "CMD_FOR", "LVALUE", "LVALUEPROP",
  "RVALUE", "EXPR", "CMD_DECL", "CMD_LET", "MULTI_LET", "CMD_VAR",
  "MULTI_VAR", "CMD_CONST", "MULTI_CONST", "ATRIB", "FINAL", "BLOCO", "@1",
  "$@2", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    61,    60,    62,    43,
      45,    42,    47,    37,    94,    46,    91,    59,    40,    41,
     123,   125,    93,    44
};
# endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,   -26,   -86,   -86,    11,    15,    18,   -14,   -11,    -9,
     -86,    26,     2,   241,   241,   -86,     2,    -4,    38,   -86,
     197,   -86,   -86,   -86,   -86,   -86,    23,    33,    55,     4,
     -86,   -86,   -86,     9,   -86,   -86,     8,   -22,   -86,   -17,
     -86,   -15,   -86,     2,     2,   224,     1,    10,    13,   259,
     -86,     5,   -86,    87,    87,    16,   -86,   197,   -86,   -86,
       2,     2,   -86,   -86,     2,     2,     2,     2,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
      52,     2,   -86,   -86,   -86,   -86,     2,    11,     2,    15,
       2,    18,    28,    59,   259,    62,    64,    65,   -86,   -86,
     -86,   -86,   197,   -86,   -86,   -86,   -86,   -86,   -86,   269,
     269,   269,   269,   269,   269,    87,    87,    61,    61,    61,
      61,   -86,    82,    22,   -86,    60,   -86,    63,   -86,   197,
     197,     2,     2,    67,    85,   -86,   -86,    11,    15,    18,
     107,   -86,    91,   100,   197,   -86,   -86,   -86,   -86,   197,
     241,   241,    98,   -86,   102,   103,   -86,   197,   197,   -86,
     -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    24,    71,    72,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,    13,     0,    78,     0,     2,
       4,    12,    11,     8,    10,     9,    75,    76,     0,     0,
      47,    48,    49,     0,    46,    16,     0,    54,    50,    64,
      60,    59,    55,     0,     0,     0,     0,     0,     0,    28,
      27,    75,    76,    44,    45,     0,    81,     0,     1,     3,
       0,     0,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     7,    15,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    17,
      74,    79,     6,    66,    67,    65,    69,    70,    68,    31,
      30,    32,    33,    35,    36,    38,    39,    37,    40,    41,
      34,    25,     0,    52,    53,    62,    63,    57,    58,     0,
       0,     0,     0,     0,     0,     5,    26,     0,     0,     0,
      19,    21,     0,     0,     4,    80,    51,    61,    56,     0,
       0,     0,     0,    20,     0,     0,    18,     0,     0,    22,
      23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -19,    41,   -49,   -86,   -86,   -86,   -86,   -86,
      99,   121,    50,     0,   101,   -86,   -85,   -86,   -81,   -86,
     -84,     3,   -86,   -86,   -86,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,   101,    20,    21,    22,    23,    24,    25,
      26,    27,    48,    49,    29,    30,    38,    31,    42,    32,
      40,    50,    34,    35,    57,   134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    59,   124,    33,    86,   126,     1,     2,   102,    88,
     128,    90,    36,    53,    54,    37,     3,    62,    63,    39,
      28,    87,    41,    33,    43,    10,    89,    44,    91,    45,
      46,    13,    14,    60,    61,    62,    63,    56,    58,    97,
      16,    83,    47,    65,    66,    94,    84,    85,    96,    64,
      99,    98,   146,   102,   147,   100,   121,    28,   148,    67,
      33,    68,    69,    70,    71,   137,    55,   129,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     140,   141,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    92,    93,    79,    80,    81,   130,   131,
     153,   132,    28,   138,   133,    33,   139,   144,   159,   160,
     103,   104,    51,    51,   105,   106,   107,   108,    76,    77,
      78,    79,    80,    81,   136,   152,   145,   149,   150,    28,
      28,   122,    33,    33,    52,    52,   123,   151,   125,   156,
     127,   157,   158,   135,    28,     0,    95,    33,     0,    28,
      94,    94,    33,   154,   155,     0,     0,    28,    28,     0,
      33,    33,     0,     0,     0,     0,     0,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,     0,
       0,   142,   143,     0,     0,     0,     0,     0,     0,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     4,     5,     6,     7,     0,     8,     9,
      10,    11,    12,     0,     0,     0,    13,    14,     1,     2,
       0,     0,     0,     0,    15,    16,     0,    17,     3,     0,
       4,     5,     6,     0,     0,     1,     2,    10,     0,     0,
       0,     0,     0,    13,    14,     3,     0,     0,     0,     0,
       0,     0,    16,     0,    10,    68,    69,    70,    71,     0,
      13,    14,     0,     0,     0,    -1,    -1,    -1,    -1,    16,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       0,    20,    87,     0,    26,    89,     4,     5,    57,    26,
      91,    26,    38,    13,    14,     4,    14,    12,    13,     4,
      20,    43,     4,    20,    38,    23,    43,    38,    43,    38,
       4,    29,    30,    10,    11,    12,    13,    41,     0,    38,
      38,    37,    40,    10,    11,    45,    37,    39,    45,    26,
      37,    41,   137,   102,   138,    39,     4,    57,   139,    26,
      57,     6,     7,     8,     9,    43,    16,    39,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
     129,   130,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    43,    44,    34,    35,    36,    39,    37,
     149,    37,   102,    43,    39,   102,    43,    40,   157,   158,
      60,    61,    13,    14,    64,    65,    66,    67,    31,    32,
      33,    34,    35,    36,    42,   144,    41,    20,    37,   129,
     130,    81,   129,   130,    13,    14,    86,    37,    88,    41,
      90,    39,    39,   102,   144,    -1,    45,   144,    -1,   149,
     150,   151,   149,   150,   151,    -1,    -1,   157,   158,    -1,
     157,   158,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    30,     4,     5,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    14,    -1,
      16,    17,    18,    -1,    -1,     4,     5,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    23,     6,     7,     8,     9,    -1,
      29,    30,    -1,    -1,    -1,     6,     7,     8,     9,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    14,    16,    17,    18,    19,    21,    22,
      23,    24,    25,    29,    30,    37,    38,    40,    45,    46,
      48,    49,    50,    51,    52,    53,    54,    55,    57,    58,
      59,    61,    63,    65,    66,    67,    38,     4,    60,     4,
      64,     4,    62,    38,    38,    38,     4,    40,    56,    57,
      65,    54,    55,    57,    57,    56,    41,    68,     0,    46,
      10,    11,    12,    13,    26,    10,    11,    26,     6,     7,
       8,     9,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    37,    37,    39,    26,    43,    26,    43,
      26,    43,    56,    56,    57,    58,    65,    38,    41,    37,
      39,    47,    48,    56,    56,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,     4,    56,    56,    60,    56,    64,    56,    62,    39,
      39,    37,    37,    39,    69,    47,    42,    43,    43,    43,
      48,    48,    56,    56,    40,    41,    60,    64,    62,    20,
      37,    37,    46,    48,    65,    65,    41,    39,    39,    48,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    50,    51,
      51,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      59,    60,    60,    60,    60,    61,    62,    62,    62,    62,
      63,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    68,    69,
      67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     7,     5,
       7,     5,     9,     9,     1,     3,     4,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     5,     3,     3,     1,     2,     5,     3,     3,     1,
       2,     5,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     1,     1,     3,     0,     0,
       5,     2
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
#line 65 "compilador.y"
                                            { Print(yyvsp[0].v + "." + function_area); }
#line 1528 "y.tab.c"
    break;

  case 3:
#line 68 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + yyvsp[0].v; }
#line 1534 "y.tab.c"
    break;

  case 4:
#line 69 "compilador.y"
                                            { yyval.v = {}; }
#line 1540 "y.tab.c"
    break;

  case 5:
#line 72 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + yyvsp[0].v; }
#line 1546 "y.tab.c"
    break;

  case 6:
#line 73 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1552 "y.tab.c"
    break;

  case 7:
#line 76 "compilador.y"
                                            { yyval.v = yyvsp[-1].v; }
#line 1558 "y.tab.c"
    break;

  case 8:
#line 77 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1564 "y.tab.c"
    break;

  case 9:
#line 78 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1570 "y.tab.c"
    break;

  case 10:
#line 79 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1576 "y.tab.c"
    break;

  case 11:
#line 80 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1582 "y.tab.c"
    break;

  case 12:
#line 81 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1588 "y.tab.c"
    break;

  case 13:
#line 82 "compilador.y"
                                            { yyval.v = {}; }
#line 1594 "y.tab.c"
    break;

  case 14:
#line 83 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "^"; }
#line 1600 "y.tab.c"
    break;

  case 15:
#line 84 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "^"; }
#line 1606 "y.tab.c"
    break;

  case 16:
#line 85 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1612 "y.tab.c"
    break;

  case 17:
#line 88 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "'&retorno'" + "@" + "~"; }
#line 1618 "y.tab.c"
    break;

  case 18:
#line 90 "compilador.y"
                                                {   string funcao_label = gera_label("funcao" + yyvsp[-5].v[0]); 
                                                    function_area = function_area + (":" + funcao_label) + 
                                                                    yyvsp[-1].v + default_return; 
                                                    yyval.v = yyvsp[-5].v + "&" + yyvsp[-5].v + "{}" + "=" + "'&funcao'" + funcao_label + "[=]" + "^"; }
#line 1627 "y.tab.c"
    break;

  case 19:
#line 95 "compilador.y"
                                                {   string ifok_label = gera_label("ifok");
                                                    string ifend_label = gera_label("ifend");
                                                    yyval.v = yyvsp[-2].v + (ifok_label) + "?" + 
                                                           (ifend_label) + "#" + 
                                                           (":" + ifok_label) + yyvsp[0].v + 
                                                           (":" + ifend_label);   }
#line 1638 "y.tab.c"
    break;

  case 20:
#line 102 "compilador.y"
                                                {   string ifok_label = gera_label("ifok");
                                                    string ifelse_label = gera_label("ifelse");
                                                    string ifend_label = gera_label("ifend");
                                                    yyval.v = yyvsp[-4].v + (ifok_label) + "?" + 
                                                           (ifelse_label) + "#" + 
                                                           (":" + ifok_label) + yyvsp[-2].v + (ifend_label) + "#" + 
                                                           (":" + ifelse_label) + yyvsp[0].v + (":" + ifend_label);   }
#line 1650 "y.tab.c"
    break;

  case 21:
#line 111 "compilador.y"
                                                {   string whileexpr_label = gera_label("whileexpr");
                                                    string whileend_label = gera_label("whileend");
                                                    string whileok_label = gera_label("whileok");
                                                    yyval.v =  (":" + whileexpr_label) + yyvsp[-2].v + (whileok_label) + "?" + 
                                                            (whileend_label) + "#" + 
                                                            (":" + whileok_label) + yyvsp[0].v + 
                                                            (whileexpr_label) + "#" + 
                                                            (":" + whileend_label);   }
#line 1663 "y.tab.c"
    break;

  case 22:
#line 121 "compilador.y"
                                                                {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    yyval.v = yyvsp[-6].v + 
                                                                           (":" + forexpr_label) + yyvsp[-4].v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + yyvsp[0].v + 
                                                                           yyvsp[-2].v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
#line 1677 "y.tab.c"
    break;

  case 23:
#line 130 "compilador.y"
                                                                {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    yyval.v = yyvsp[-6].v + "^" + 
                                                                           (":" + forexpr_label) + yyvsp[-4].v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + yyvsp[0].v + 
                                                                           yyvsp[-2].v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
#line 1691 "y.tab.c"
    break;

  case 24:
#line 141 "compilador.y"
                                            { trata_uso( yyvsp[0].v[0] ); yyval.v = yyvsp[0].v; }
#line 1697 "y.tab.c"
    break;

  case 25:
#line 144 "compilador.y"
                                          { yyval.v = yyvsp[-2].v + yyvsp[0].v; }
#line 1703 "y.tab.c"
    break;

  case 26:
#line 145 "compilador.y"
                                          { yyval.v = yyvsp[-3].v + yyvsp[-1].v; }
#line 1709 "y.tab.c"
    break;

  case 27:
#line 148 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1715 "y.tab.c"
    break;

  case 28:
#line 149 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1721 "y.tab.c"
    break;

  case 29:
#line 150 "compilador.y"
                                            { yyval.v = {string("{}")}; }
#line 1727 "y.tab.c"
    break;

  case 30:
#line 152 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "<="; }
#line 1733 "y.tab.c"
    break;

  case 31:
#line 153 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + ">="; }
#line 1739 "y.tab.c"
    break;

  case 32:
#line 154 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "=="; }
#line 1745 "y.tab.c"
    break;

  case 33:
#line 155 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "!="; }
#line 1751 "y.tab.c"
    break;

  case 34:
#line 156 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "^"; }
#line 1757 "y.tab.c"
    break;

  case 35:
#line 157 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "<"; }
#line 1763 "y.tab.c"
    break;

  case 36:
#line 158 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + ">"; }
#line 1769 "y.tab.c"
    break;

  case 37:
#line 159 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "*"; }
#line 1775 "y.tab.c"
    break;

  case 38:
#line 160 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "+"; }
#line 1781 "y.tab.c"
    break;

  case 39:
#line 161 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "-"; }
#line 1787 "y.tab.c"
    break;

  case 40:
#line 162 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "/"; }
#line 1793 "y.tab.c"
    break;

  case 41:
#line 163 "compilador.y"
                                            { yyval.v = yyvsp[-2].v + yyvsp[0].v + "%"; }
#line 1799 "y.tab.c"
    break;

  case 42:
#line 164 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "@" + yyvsp[-1].v + yyvsp[-1].v + "@" + "1" + "+" + "=" + "^"; }
#line 1805 "y.tab.c"
    break;

  case 43:
#line 165 "compilador.y"
                                            { yyval.v = yyvsp[-1].v + "@" + yyvsp[-1].v + yyvsp[-1].v + "@" + "1" + "-" + "=" + "^"; }
#line 1811 "y.tab.c"
    break;

  case 44:
#line 166 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1817 "y.tab.c"
    break;

  case 45:
#line 167 "compilador.y"
                                            { yyval.v = "0" + yyvsp[0].v + "-"; }
#line 1823 "y.tab.c"
    break;

  case 46:
#line 168 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1829 "y.tab.c"
    break;

  case 47:
#line 171 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1835 "y.tab.c"
    break;

  case 48:
#line 172 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1841 "y.tab.c"
    break;

  case 49:
#line 173 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1847 "y.tab.c"
    break;

  case 50:
#line 176 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1853 "y.tab.c"
    break;

  case 51:
#line 179 "compilador.y"
                                                { trata_declaracoes(yyvsp[-4].v[0], "let"); yyval.v = yyvsp[-4].v + "&" + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 1859 "y.tab.c"
    break;

  case 52:
#line 180 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "let"); yyval.v = yyvsp[-2].v + "&" + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 1865 "y.tab.c"
    break;

  case 53:
#line 181 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "let"); yyval.v = yyvsp[-2].v + "&" + yyvsp[0].v; }
#line 1871 "y.tab.c"
    break;

  case 54:
#line 182 "compilador.y"
                                                { trata_declaracoes(yyvsp[0].v[0], "let"); yyval.v = yyvsp[0].v + "&"; }
#line 1877 "y.tab.c"
    break;

  case 55:
#line 185 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1883 "y.tab.c"
    break;

  case 56:
#line 188 "compilador.y"
                                                { trata_declaracoes(yyvsp[-4].v[0], "var"); yyval.v = yyvsp[-4].v + "&" + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 1889 "y.tab.c"
    break;

  case 57:
#line 189 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "var"); yyval.v = yyvsp[-2].v + "&" + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 1895 "y.tab.c"
    break;

  case 58:
#line 190 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "var"); yyval.v = yyvsp[-2].v + "&" + yyvsp[0].v; }
#line 1901 "y.tab.c"
    break;

  case 59:
#line 191 "compilador.y"
                                                { trata_declaracoes(yyvsp[0].v[0], "var"); yyval.v = yyvsp[0].v + "&"; }
#line 1907 "y.tab.c"
    break;

  case 60:
#line 194 "compilador.y"
                                                { yyval.v = yyvsp[0].v; }
#line 1913 "y.tab.c"
    break;

  case 61:
#line 197 "compilador.y"
                                                { trata_declaracoes(yyvsp[-4].v[0], "const"); yyval.v = yyvsp[-4].v + "&" + yyvsp[-4].v + yyvsp[-2].v + "=" + "^" + yyvsp[0].v; }
#line 1919 "y.tab.c"
    break;

  case 62:
#line 198 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "const"); yyval.v = yyvsp[-2].v + "&" + yyvsp[-2].v + yyvsp[0].v + "=" + "^"; }
#line 1925 "y.tab.c"
    break;

  case 63:
#line 199 "compilador.y"
                                                { trata_declaracoes(yyvsp[-2].v[0], "const"); yyval.v = yyvsp[-2].v + "&" + yyvsp[0].v; }
#line 1931 "y.tab.c"
    break;

  case 64:
#line 200 "compilador.y"
                                                { trata_declaracoes(yyvsp[0].v[0], "const"); yyval.v = yyvsp[0].v + "&"; }
#line 1937 "y.tab.c"
    break;

  case 65:
#line 203 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[0].v + "="; }
#line 1943 "y.tab.c"
    break;

  case 66:
#line 204 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "@" + yyvsp[0].v + "+" + "="; }
#line 1949 "y.tab.c"
    break;

  case 67:
#line 205 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "@" + yyvsp[0].v + "-" + "="; }
#line 1955 "y.tab.c"
    break;

  case 68:
#line 206 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[0].v + "[=]"; }
#line 1961 "y.tab.c"
    break;

  case 69:
#line 207 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "[@]" + yyvsp[0].v + "+" + "[=]"; }
#line 1967 "y.tab.c"
    break;

  case 70:
#line 208 "compilador.y"
                                                { trata_atribuicao(yyvsp[-2].v[0]); yyval.v = yyvsp[-2].v + yyvsp[-2].v + "[@]" + yyvsp[0].v + "-" + "[=]"; }
#line 1973 "y.tab.c"
    break;

  case 71:
#line 211 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1979 "y.tab.c"
    break;

  case 72:
#line 212 "compilador.y"
                                            { yyval.v = yyvsp[0].v; }
#line 1985 "y.tab.c"
    break;

  case 73:
#line 213 "compilador.y"
                                            { yyval.v = { string("[]") }; }
#line 1991 "y.tab.c"
    break;

  case 74:
#line 214 "compilador.y"
                                            { yyval.v = yyvsp[-1].v; }
#line 1997 "y.tab.c"
    break;

  case 75:
#line 215 "compilador.y"
                                            { yyval.v = yyvsp[0].v + "@"; }
#line 2003 "y.tab.c"
    break;

  case 76:
#line 216 "compilador.y"
                                            { yyval.v = yyvsp[0].v + "[@]"; }
#line 2009 "y.tab.c"
    break;

  case 77:
#line 217 "compilador.y"
                                            { yyval.v = "0" + yyvsp[-2].v + "@" + "$"; }
#line 2015 "y.tab.c"
    break;

  case 78:
#line 221 "compilador.y"
                  { abre_escopo(); }
#line 2021 "y.tab.c"
    break;

  case 79:
#line 221 "compilador.y"
                                          { fecha_escopo(); }
#line 2027 "y.tab.c"
    break;

  case 80:
#line 221 "compilador.y"
                                                                            { yyval.v = "<{" + yyvsp[-3].v + "}>"; }
#line 2033 "y.tab.c"
    break;

  case 81:
#line 222 "compilador.y"
                                                                            { yyval.v = {}; }
#line 2039 "y.tab.c"
    break;


#line 2043 "y.tab.c"

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
#line 225 "compilador.y"


#include "lex.yy.c"

map<int, string> nome_tokens = {
    { PRINT, "print" },
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

void trata_declaracoes( string id, string tipo ){
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
                return;
            }
        }else if(tipo == "var"){
            if(decl_type->second.first != "var" && decl == declarations.rbegin()){
                string linha_decl = to_string(decl_type->second.second);
                string msg = "Erro: a variável '" + id + "' já foi declarada na linha " + linha_decl + ".";
                yyerror(msg.c_str());
            }
            return;
        }else if(tipo == "const"){
            string linha_decl = to_string(decl_type->second.second);
            string msg = "Erro: a variável '" + id + "' já foi declarada na linha " + linha_decl + ".";
            yyerror(msg.c_str());
            return;
        }
    }

    // O id ainda nao foi declarado
    // cout << "id " << id << " declarado no escopo " << declarations.size() << endl;
    declarations[declarations.size()-1][id] = {tipo, linha};
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

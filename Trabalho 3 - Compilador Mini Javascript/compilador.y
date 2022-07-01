%{

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
    vector<string> v;
};

#define YYSTYPE Atributos

void erro( string msg );
void Print( vector<string> st );
int retorna( int tk );
string nome_token( int token );

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

int linha = 1;
int coluna = 1;

%}

%token PRINT ID NUM MAIG MEIG IG DIF MAATR MEATR STRING COMENTARIO LET CONST VAR IF WHILE FOR NEWOBJECT NEWARRAY

%right '=' MAATR MEATR 
%nonassoc '<' '>' IG MEIG MAIG DIF '[' 
%left '.'
%left '+' '-'
%left '*' '/' '%'
%right '^'

%start S

%%

S           : CMDs                          { Print($1.v + "."); }
            ;

CMDs        : CMD CMDs                      { $$.v =  $1.v + "\n" + $2.v; }
            |                               { $$.v = {}; }
            ;

// CMD         : CMD_FOR ';'
//             | RVALUE ';'
//             ;
CMD         : RVALUE ';'                    { $$.v =  $1.v + "^"; }
            | CMD_DECL ';'                  { $$.v =  $1.v; }
            // | CMD_IF ';'                    { $$.v =  $1.v + "\n"; }
            // | BLOCO                         { $$.v =  $1.v; }
            // | RVALUE                          { $$.v =  $1.v + "\n"; }
            ;

// CMD_FOR     : FOR '(' CMD_DECL ';' RVALUE ';' ATRIB ')' CMD
//             | FOR '(' ATRIB ';' RVALUE ';' ATRIB ')' CMD
//             | FOR '(' RVALUE ';' RVALUE ';' ATRIB ')' CMD
//             ;

// CMD_IF      : IF '(' RVALUE ')' CMD           { $$.v = $; }
//             ;

LVALUE      : ID                            { $$.v =  $1.v; }
            ;

LVALUEPROP  : RVALUE '.' ID                 { $$.v =  $1.v + $3.v; }
            | RVALUE '[' RVALUE ']'         { $$.v =  $1.v + $3.v; } 
            ;

RVALUE      : ATRIB                         { $$.v =  $1.v; }
            | RVALUE MEIG RVALUE            { $$.v =  $1.v + $3.v + "<="; }
            | RVALUE MAIG RVALUE            { $$.v =  $1.v + $3.v + ">="; }
            | RVALUE IG RVALUE              { $$.v =  $1.v + $3.v + "=="; }
            | RVALUE DIF RVALUE             { $$.v =  $1.v + $3.v + "!="; }
            | RVALUE '^' RVALUE             { $$.v =  $1.v + $3.v + "^"; }
            | RVALUE '<' RVALUE             { $$.v =  $1.v + $3.v + "<"; }
            | RVALUE '>' RVALUE             { $$.v =  $1.v + $3.v + ">"; }
            | RVALUE '*' RVALUE             { $$.v =  $1.v + $3.v + "*"; }
            | RVALUE '+' RVALUE             { $$.v =  $1.v + $3.v + "+"; }
            | RVALUE '-' RVALUE             { $$.v =  $1.v + $3.v + "-"; }
            | RVALUE '/' RVALUE             { $$.v =  $1.v + $3.v + "/"; }
            | RVALUE '%' RVALUE             { $$.v =  $1.v + $3.v + "%"; }
            | '+' RVALUE                    { $$.v =  $2.v; }
            | '-' RVALUE                    { $$.v =  "0" + $2.v + "-"; }
            | FINAL                         { $$.v =  $1.v; }
            ;

CMD_DECL    : LET MULTI_DECL                { $$.v =  $2.v; }
            | VAR MULTI_DECL                { $$.v =  $2.v; }
            | CONST MULTI_DECL              { $$.v =  $2.v; }
            ;

MULTI_DECL  : LVALUE '=' RVALUE ',' MULTI_DECL      { $$.v =  $1.v + "&" + $1.v + $3.v + "=" + "^" + $5.v; }
            | LVALUE '=' RVALUE                     { $$.v =  $1.v + "&" + $1.v + $3.v + "=" + "^"; }
            | ID ',' MULTI_DECL                     { $$.v =  $1.v + "&" + $3.v; }
            | ID                                    { $$.v =  $1.v + "&" ; }
            ;

ATRIB       : LVALUE '=' RVALUE               { $$.v =  $1.v + $3.v + "="; }
            | LVALUE MAATR RVALUE             { $$.v =  $1.v + $1.v + "@" + $3.v + "+" + "="; }
            | LVALUEPROP '=' RVALUE           { $$.v =  $1.v + $3.v + "[=]"; }
            | LVALUEPROP MEATR RVALUE         { $$.v =  $1.v + $1.v + "[@]" + $3.v + "+" + "[=]"; }
            ;

FINAL       : NUM                           { $$.v =  $1.v; }
            | STRING                        { $$.v =  $1.v; }
            | NEWOBJECT                     { $$.v =  { string("{}") }; }
            | NEWARRAY                      { $$.v =  { string("[]") }; }
            | '(' RVALUE ')'                { $$.v =  $2.v; }
            // | FUNCAO
            | LVALUE                        { $$.v =  $1.v + "@"; }
            | LVALUEPROP                    { $$.v =  $1.v + "[@]"; }
            ; 

            // | ID '(' ')'
            // | ID '(' RVALUES ')'
// RVALUES       : RVALUE ',' RVALUES
//             | RVALUE 
//             ;


// BLOCO       : '{' CMDs '}'                  { $$.v =  $1.v; }
//             ;
  
%%

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
    b.push_back( a );
    return b;
}

void yyerror( const char* msg ) {
    cout << "erro" << endl;
    // cout << endl << "Erro: " << msg << endl << "Perto de : '" << yylval.v << "'" <<endl;
    exit( 0 );
}

void Print( vector<string> st ) {
    for( auto x: st )
        cout << x << " ";
}

int main( int argc, char* argv[] ) {
    yyparse();
    return 0;
}
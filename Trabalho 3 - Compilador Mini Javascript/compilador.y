%{

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Atributos {
    string v;
};

#define YYSTYPE Atributos

void erro( string msg );
void Print( string st );
int retorna( int tk );
string nome_token( int token );
string logging( string id, string s );

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

int linha = 1;
int coluna = 1;

%}

%token PRINT ID NUM MAIG MEIG IG DIF STRING COMENTARIO LET CONST VAR IF WHILE FOR NEWOBJECT NEWARRAY NEWLINE

%right '=' ','
%nonassoc '<' '>' IG MEIG MAIG DIF
%left '+' '-'
%left '*' '/' '%'
%right '^'

%start S

%%

S           : CMDs                          { Print($1.v + '.'); }
            ;

CMDs        : CMD CMDs                      { $$.v = logging("a", $1.v + $2.v); }
            |                               { $$.v = logging("a0", ""); }
            ;

// CMD         : CMD_FOR ';'
//             // | CMD_IF ';'
//             | EXPR ';'
//             ;
CMD         : EXPR ';'                      { $$.v = logging("b",  $1.v + "\n"); }
            | EXPR ';' NEWLINE              { $$.v = logging("b",  $1.v + "\n"); }
            | EXPR NEWLINE                  { $$.v = logging("b",  $1.v + "\n"); }
            | BLOCO                         { $$.v = logging("c",  $1.v); }
            | EXPR                          { $$.v = logging("b",  $1.v + "\n"); }
            ;

// CMD_FOR     : FOR '(' CMD_DECL ';' EXPR ';' ATRIB ')' CMD
//             | FOR '(' ATRIB ';' EXPR ';' ATRIB ')' CMD
//             | FOR '(' EXPR ';' EXPR ';' ATRIB ')' CMD
//             ;

LVALUE      : ID                            { $$.v = logging("d",  $1.v + " "); }
            ;

LVALUEPROP  : FINALID                       { $$.v = logging("d",  $1.v + " "); }
            ;

EXPR        : ATRIB                         { $$.v = logging("e",  $1.v); }
            | CMD_DECL                      { $$.v = logging("f",  $1.v); }
            | EXPR MEIG EXPR                { $$.v = logging("g",  $1.v + $3.v + " <= "); }
            | EXPR MAIG EXPR                { $$.v = logging("g",  $1.v + $3.v + " >= "); }
            | EXPR IG EXPR                  { $$.v = logging("g",  $1.v + $3.v + " == "); }
            | EXPR DIF EXPR                 { $$.v = logging("g",  $1.v + $3.v + " != "); }
            | EXPR '^' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " ^ "); }
            | EXPR '<' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " < "); }
            | EXPR '>' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " > "); }
            | EXPR '*' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " * "); }
            | EXPR '+' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " + "); }
            | EXPR '-' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " - "); }
            | EXPR '/' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " / "); }
            | EXPR '%' EXPR                 { $$.v = logging("g",  $1.v + $3.v + " % "); }
            | FINAL                         { $$.v = logging("g1",  $1.v); }
            ;

CMD_DECL    : LET MULTI_DECL                { $$.v = logging("h",  $2.v); }
            | VAR MULTI_DECL                { $$.v = logging("h",  $2.v); }
            | CONST MULTI_DECL              { $$.v = logging("h",  $2.v); }
            ;

MULTI_DECL  : LVALUE '=' EXPR ',' MULTI_DECL    { $$.v = logging("i",  $1.v + " & " + $1.v + $3.v + " = " + " ^ " + $5.v); }
            | LVALUE '=' EXPR                   { $$.v = logging("j",  $1.v + " & " + $1.v + $3.v + " = " + " ^ "); }
            | ID ',' MULTI_DECL                 { $$.v = logging("k",  $1.v + " & " + $3.v); }
            | ID                                { $$.v = logging("l",  $1.v + " & " ); }
            ;

ATRIB       : LVALUE '=' EXPR               { $$.v = logging("m",  $1.v + $3.v + " = " + " ^ "); }
            | LVALUEPROP '=' EXPR           { $$.v = logging("m",  $1.v + $3.v + " [=] " + " ^ "); }
            ;

FINAL       : NUM                           { $$.v = logging("n",  $1.v + " "); }
            | STRING                        { $$.v = logging("n",  $1.v + " "); }
            | NEWOBJECT                     { $$.v = logging("n",  string("{}") + " "); }
            | NEWARRAY                      { $$.v = logging("n",  string("[]") + " "); }
            | '(' EXPR ')'                  { $$.v = logging("n",  $2.v + " "); }
            // | FUNCAO
            | FINALID                       { $$.v = logging("n",  $1.v + " "); }
            ; 

            // | ID '(' ')'
            // | ID '(' EXPRS ')'
// EXPRS       : EXPR ',' EXPRS
//             | EXPR 
//             ;

FINALID     : ID FINALIDPROP                { $$.v = logging("o",  $1.v + " @ " + $2.v); }
            ;

FINALIDPROP : '.' ID FINALIDPROP            { $$.v = logging("p",  $2.v + " [@] " + $3.v); }
            | '[' EXPR ']' FINALIDPROP      { $$.v = logging("p",  $2.v + " [@] " + $4.v); } 
            |                               { $$.v = logging("q", ""); }
            ;

BLOCO       : '{' CMDs '}'                  { $$.v = logging("q",  $1.v); }
            ;
  
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
    yylval.v = yytext; 
    coluna += strlen( yytext ); 
    return tk;
}

void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl << "Perto de : '" << yylval.v << "'" <<endl;
    exit( 0 );
}

void Print( string st ) {
    cout << st << " ";
}

bool active_log = false;
string logging( string id, string s ) {
    if(active_log) return "[" + id + " ~ " + s + "]";
    else return s;
}

int main( int argc, char* argv[] ) {
    yyparse();
    return 0;
}
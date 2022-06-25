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

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

int linha = 1;
int coluna = 1;

%}

%token PRINT ID NUM MAIG MEIG IG DIF STRING COMENTARIO LET CONST VAR IF WHILE FOR NEWOBJECT NEWARRAY



%start S

%%

S           : CMDs { Print($1.v); }
            ;

CMDs        : CMD CMDs
            |
            ;

// CMD         : CMD_FOR ';'
//             // | CMD_IF ';'
//             | EXPR ';'
//             ;
CMD         : EXPR ';'
            | BLOCO
            ;

// CMD_FOR     : FOR '(' CMD_DECL ';' EXPR ';' ATRIB ')' CMD
//             | FOR '(' ATRIB ';' EXPR ';' ATRIB ')' CMD
//             | FOR '(' EXPR ';' EXPR ';' ATRIB ')' CMD
//             ;

LVALUE      : ID    
            ;

EXPR        : ATRIB
            | CMD_DECL
            | EXPR MEIG EXPR
            | EXPR MAIG EXPR
            | EXPR IG EXPR
            | EXPR DIF EXPR
            | EXPR '^' EXPR
            | EXPR '<' EXPR
            | EXPR '*' EXPR
            | EXPR '+' EXPR
            | EXPR '-' EXPR
            | EXPR '/' EXPR
            | EXPR '>' EXPR
            | EXPR '%' EXPR
            | FINAL
            ;

CMD_DECL    : LET MULTI_DECL
            | VAR MULTI_DECL
            | CONST MULTI_DECL
            ;

MULTI_DECL  : ATRIB ',' MULTI_DECL
            | ATRIB
            | ID ',' MULTI_DECL
            | ID
            ;

ATRIB       : LVALUE '=' EXPR
            // | LVALUEPROP '=' EXPR
            ;

FINAL       : NUM
            | STRING
            | NEWOBJECT
            | NEWARRAY
            | '(' EXPR ')'
            | ID '(' ')'
            | ID '(' EXPRS ')'
            ; 

EXPRS       : EXPR ',' EXPRS
            | EXPR 
            ;

BLOCO       : '{' CMDs '}'
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

int main( int argc, char* argv[] ) {
    yyparse();
    return 0;
}
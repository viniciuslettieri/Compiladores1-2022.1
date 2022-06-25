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

%token PRINT ID NUM MAIG MEIG IG DIF STRING COMENTARIO LET CONST VAR IF WHILE FOR

%%

P : A ';' P
  | A ';'
  ;

A : LET ID '=' E 
  | CONST ID 
  | VAR ID 
  | PRINT E 
  ;
  
E : E '+' E { Print( "+" ); }
  | E '-' E { Print( "-" ); }
  | E '*' E { Print( "*" ); }
  | E '/' E { Print( "/" ); }
  | F
  ;
  
F : ID { Print( $1.v + " @" ); }
  | NUM { Print(  $1.v ); }
  | STRING { Print(  $1.v ); }
  | '(' E ')'
  | ID '(' PARAM ')' { Print( $1.v + " #" ); }
  ;
  
PARAM : ARGs
      |
      ;
  
ARGs : E ',' ARGs
     | E
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
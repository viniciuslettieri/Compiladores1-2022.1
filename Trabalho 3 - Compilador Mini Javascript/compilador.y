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

string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

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

%token PRINT ID NUM MAIG MEIG IG DIF MAATR MEATR INCREM DECREM STRING COMENTARIO LET CONST VAR IF ELSE WHILE FOR NEWOBJECT NEWARRAY 

%right '=' MAATR MEATR 
%nonassoc '<' '>' IG MEIG MAIG DIF INCREM DECREM
%left '+' '-'
%left '*' '/' '%'
%right '^'
%nonassoc '.' '['

%start S

%%

S           : CMDs                          { Print($1.v + "."); }
            ;

CMDs        : CMD CMDs                      { $$.v = $1.v + $2.v; }
            |                               { $$.v = {}; }
            ;

// CMD         : CMD_FOR ';'
//             | RVALUE ';'
//             ;
CMD         : RVALUE ';'                    { $$.v = $1.v + "^"; }
            | CMD_DECL ';'                  { $$.v = $1.v; }
            | CMD_IF                        { $$.v = $1.v; }
            | CMD_FOR                       { $$.v = $1.v; }
            | CMD_WHILE                     { $$.v = $1.v; }
            | BLOCO                         { $$.v = $1.v; }
            | ';'                           { $$.v = {}; }
            ;

CMD_IF      : IF '(' RVALUE ')' CMD             {   string ifok_label = gera_label("ifok");
                                                    string ifend_label = gera_label("ifend");
                                                    $$.v = $3.v + (ifok_label) + "?" + 
                                                           (ifend_label) + "#" + 
                                                           (":" + ifok_label) + $5.v + 
                                                           (":" + ifend_label);   }

            | IF '(' RVALUE ')' CMD ELSE CMD    {   string ifok_label = gera_label("ifok");
                                                    string ifelse_label = gera_label("ifelse");
                                                    string ifend_label = gera_label("ifend");
                                                    $$.v = $3.v + (ifok_label) + "?" + 
                                                           (ifelse_label) + "#" + 
                                                           (":" + ifok_label) + $5.v + (ifend_label) + "#" + 
                                                           (":" + ifelse_label) + $7.v + (":" + ifend_label);   }
            ;

CMD_WHILE   : WHILE '(' RVALUE ')' CMD          {   string whileexpr_label = gera_label("whileexpr");
                                                    string whileend_label = gera_label("whileend");
                                                    string whileok_label = gera_label("whileok");
                                                    $$.v =  (":" + whileexpr_label) + $3.v + (whileok_label) + "?" + 
                                                            (whileend_label) + "#" + 
                                                            (":" + whileok_label) + $5.v + 
                                                            (whileexpr_label) + "#" + 
                                                            (":" + whileend_label);   }
            ;

CMD_FOR     : FOR '(' CMD_DECL ';' RVALUE ';' ATRIB ')' CMD     {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    $$.v = $3.v + 
                                                                           (":" + forexpr_label) + $5.v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + $9.v + 
                                                                           $7.v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
            | FOR '(' ATRIB ';' RVALUE ';' ATRIB ')' CMD        {   string forexpr_label = gera_label("forexpr");
                                                                    string forend_label = gera_label("forend");
                                                                    string forok_label = gera_label("forok");
                                                                    $$.v = $3.v + "^" + 
                                                                           (":" + forexpr_label) + $5.v + (forok_label) + "?" + 
                                                                           (forend_label) + "#" + 
                                                                           (":" + forok_label) + $9.v + 
                                                                           $7.v + "^" + (forexpr_label) + "#" + 
                                                                           (":" + forend_label);   }
            ;

LVALUE      : ID                            { $$.v = $1.v; }
            ;

LVALUEPROP  : RVALUE '.' ID                 { $$.v = $1.v + $3.v; }
            | RVALUE '[' RVALUE ']'         { $$.v = $1.v + $3.v; } 
            ;

RVALUE      : ATRIB                         { $$.v = $1.v; }
            | RVALUE MEIG RVALUE            { $$.v = $1.v + $3.v + "<="; }
            | RVALUE MAIG RVALUE            { $$.v = $1.v + $3.v + ">="; }
            | RVALUE IG RVALUE              { $$.v = $1.v + $3.v + "=="; }
            | RVALUE DIF RVALUE             { $$.v = $1.v + $3.v + "!="; }
            | RVALUE '^' RVALUE             { $$.v = $1.v + $3.v + "^"; }
            | RVALUE '<' RVALUE             { $$.v = $1.v + $3.v + "<"; }
            | RVALUE '>' RVALUE             { $$.v = $1.v + $3.v + ">"; }
            | RVALUE '*' RVALUE             { $$.v = $1.v + $3.v + "*"; }
            | RVALUE '+' RVALUE             { $$.v = $1.v + $3.v + "+"; }
            | RVALUE '-' RVALUE             { $$.v = $1.v + $3.v + "-"; }
            | RVALUE '/' RVALUE             { $$.v = $1.v + $3.v + "/"; }
            | RVALUE '%' RVALUE             { $$.v = $1.v + $3.v + "%"; }
            | LVALUE INCREM                 { $$.v = $1.v + "@" + $1.v + $1.v + "@" + "1" + "+" + "=" + "^"; }
            | LVALUE DECREM                 { $$.v = $1.v + "@" + $1.v + $1.v + "@" + "1" + "-" + "=" + "^"; }
            | '+' RVALUE                    { $$.v = $2.v; }
            | '-' RVALUE                    { $$.v = "0" + $2.v + "-"; }
            | FINAL                         { $$.v = $1.v; }
            ;

CMD_DECL    : LET MULTI_DECL                { $$.v = $2.v; }
            | VAR MULTI_DECL                { $$.v = $2.v; }
            | CONST MULTI_DECL              { $$.v = $2.v; }
            ;

MULTI_DECL  : LVALUE '=' RVALUE ',' MULTI_DECL      { $$.v = $1.v + "&" + $1.v + $3.v + "=" + "^" + $5.v; }
            | LVALUE '=' RVALUE                     { $$.v = $1.v + "&" + $1.v + $3.v + "=" + "^"; }
            | ID ',' MULTI_DECL                     { $$.v = $1.v + "&" + $3.v; }
            | ID                                    { $$.v = $1.v + "&" ; }
            ;

ATRIB       : LVALUE '=' RVALUE               { $$.v = $1.v + $3.v + "="; }
            | LVALUE MAATR RVALUE             { $$.v = $1.v + $1.v + "@" + $3.v + "+" + "="; }
            | LVALUE MEATR RVALUE             { $$.v = $1.v + $1.v + "@" + $3.v + "-" + "="; }
            | LVALUEPROP '=' RVALUE           { $$.v = $1.v + $3.v + "[=]"; }
            | LVALUEPROP MAATR RVALUE         { $$.v = $1.v + $1.v + "[@]" + $3.v + "+" + "[=]"; }
            | LVALUEPROP MEATR RVALUE         { $$.v = $1.v + $1.v + "[@]" + $3.v + "-" + "[=]"; }
            ;

FINAL       : NUM                           { $$.v = $1.v; }
            | STRING                        { $$.v = $1.v; }
            | NEWOBJECT                     { $$.v = { string("{}") }; }
            | NEWARRAY                      { $$.v = { string("[]") }; }
            | '(' RVALUE ')'                { $$.v = $2.v; }
            // | FUNCAO
            | LVALUE                        { $$.v = $1.v + "@"; }
            | LVALUEPROP                    { $$.v = $1.v + "[@]"; }
            ; 

            // | ID '(' ')'
            // | ID '(' RVALUES ')'
// RVALUES       : RVALUE ',' RVALUES
//             | RVALUE 
//             ;


BLOCO       : '{' CMDs '}'                  { $$.v = $2.v; }
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
    // cout << "erro" << yytext << endl;
    cout << endl << "Erro: " << msg << endl << "Perto de : '" << yylval.v[0] << "'" <<endl;
    exit( 0 );
}

void Print( vector<string> st ) {
    int linha = 0;
    vector<string> enderecos_resolvidos = resolve_enderecos(st);
    // vector<string> enderecos_resolvidos = st;
    for( auto x: enderecos_resolvidos )
        // cout << linha++ << ": ";
        cout << x << "\n";
}

int main( int argc, char* argv[] ) {
    yyparse();
    return 0;
}
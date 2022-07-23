%{

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

%}

%token PRINT ID NUM MAIG MEIG IG DIF MAATR MEATR INCREM DECREM STRING COMENTARIO LET CONST VAR IF ELSE WHILE FOR FUNCTION RETURN ASM

%right '=' MAATR MEATR 
%nonassoc '<' '>' IG MEIG MAIG DIF INCREM DECREM
%left '+' '-'
%left '*' '/' '%'
%right '^'
%nonassoc '.' '['

%start S

%%

S           : CMDz                          { Print($1.v + "." + function_area); }
            ;

CMDz        : CMD CMDz                      { $$.v = $1.v + $2.v; }
            |                               { $$.v = {}; }
            ;

CMDs        : CMD CMDs                      { $$.v = $1.v + $2.v; }
            | CMD                           { $$.v = $1.v; }
            ;

CMD         : CMD_DECL ';'                  { $$.v = $1.v; }
            | CMD_IF                        { $$.v = $1.v; }
            | CMD_FOR                       { $$.v = $1.v; }
            | CMD_WHILE                     { $$.v = $1.v; }
            | CMD_FUNCTION                  { $$.v = $1.v; }
            | CMD_RETURN                    { $$.v = $1.v; }
            | ';'                           { $$.v = {}; }
            | EXPR ';'                      { $$.v = $1.v + "^"; }
            | EXPR ASM ';' 	                { $$.v = $1.v + $2.v + "^"; }
            | ATRIB ';'                     { $$.v = $1.v + "^"; }
            | BLOCO                         { $$.v = $1.v; }
            ;

CMD_RETURN  : RETURN RVALUE ';'                         {   $$.v = $2.v + "'&retorno'" + "@" + "~"; } 

CMD_FUNCTION: FUNCTION ID '(' { trata_declaracoes($2.v[0], "function"); abre_escopo();  } ')' '{' CMDz '}' { fecha_escopo(); }          
                                                        {   
                                                            string funcao_label = gera_label("funcao" + $2.v[0]); 
                                                            function_area = function_area + (":" + funcao_label) + 
                                                                            $7.v + default_return; 
                                                            $$.v = $2.v + "&" + $2.v + "{}" + "=" + "'&funcao'" + funcao_label + "[=]" + "^"; }
            | FUNCTION ID '(' { trata_declaracoes($2.v[0], "function"); abre_escopo(); } PARAMS ')' '{'  CMDz '}' { fecha_escopo(); }
                                                        {   
                                                            string funcao_label = gera_label("funcao" + $2.v[0]); 
                                                            function_area = function_area + (":" + funcao_label) + 
                                                                            $5.v + $8.v + default_return; 
                                                            $$.v = $2.v + "&" + $2.v + "{}" + "=" + "'&funcao'" + funcao_label + "[=]" + "^"; }

PARAMS      : PARAMS ',' ID                             {   $$.contador = 1 + $1.contador;
                                                            vector<string> decl = {$3.v[0], "&"}; if(!trata_declaracoes($3.v[0], "var")) decl = {};
                                                            $$.v = $1.v + decl + $3.v + "arguments" + "@" + 
                                                                   to_string($$.contador) + "[@]" + "=" + "^"; 
                                                        }
            | ID                                        {   $$.contador = 0;
                                                            vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "var")) decl = {}; 
                                                            $$.v = decl + $1.v + "arguments" + "@" + 
                                                                   to_string($$.contador) + "[@]" + "=" + "^"; 
                                                        }
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

LVALUE      : ID                          { trata_uso( $1.v[0] ); $$.v = $1.v; }
            ;

LVALUEPROP  : EXPR '.' ID                 { $$.v = $1.v + $3.v; }
            | EXPR '[' RVALUE ']'         { $$.v = $1.v + $3.v; } 
            ;

RVALUE      : ATRIB                         { $$.v = $1.v; }
            | EXPR                          { $$.v = $1.v; }
            | '{''}'                        { $$.v = {string("{}")}; }

EXPR        : EXPR MEIG EXPR                { $$.v = $1.v + $3.v + "<="; }
            | EXPR MAIG EXPR                { $$.v = $1.v + $3.v + ">="; }
            | EXPR IG EXPR                  { $$.v = $1.v + $3.v + "=="; }
            | EXPR DIF EXPR                 { $$.v = $1.v + $3.v + "!="; }
            | EXPR '^' EXPR                 { $$.v = $1.v + $3.v + "^"; }
            | EXPR '<' EXPR                 { $$.v = $1.v + $3.v + "<"; }
            | EXPR '>' EXPR                 { $$.v = $1.v + $3.v + ">"; }
            | EXPR '*' EXPR                 { $$.v = $1.v + $3.v + "*"; }
            | EXPR '+' EXPR                 { $$.v = $1.v + $3.v + "+"; }
            | EXPR '-' EXPR                 { $$.v = $1.v + $3.v + "-"; }
            | EXPR '/' EXPR                 { $$.v = $1.v + $3.v + "/"; }
            | EXPR '%' EXPR                 { $$.v = $1.v + $3.v + "%"; }
            | LVALUE INCREM                 { $$.v = $1.v + "@" + $1.v + $1.v + "@" + "1" + "+" + "=" + "^"; }
            | LVALUE DECREM                 { $$.v = $1.v + "@" + $1.v + $1.v + "@" + "1" + "-" + "=" + "^"; }
            | '+' EXPR                      { $$.v = $2.v; }
            | '-' EXPR                      { $$.v = "0" + $2.v + "-"; }
            | FINAL                         { $$.v = $1.v; }
            | FINAL '('')'                  { $$.v = "0" + $1.v + "$"; }
            | FINAL '(' ARGS ')'            { $$.v = $3.v + to_string($3.contador) + $1.v + "$"; }
            ;

CMD_DECL    : CMD_LET                           { $$.v = $1.v; }
            | CMD_VAR                           { $$.v = $1.v; }
            | CMD_CONST                         { $$.v = $1.v; }
            ;

CMD_LET     : LET MULTI_LET                     { $$.v = $2.v; }
            ;

MULTI_LET   : ID '=' RVALUE ',' MULTI_LET       { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "let")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^" + $5.v; }
            | ID '=' RVALUE                     { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "let")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^"; }
            | ID ',' MULTI_LET                  { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "let")) decl = {}; $$.v = decl + $3.v; }
            | ID                                { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "let")) decl = {}; $$.v = decl; }
            ;

CMD_VAR     : VAR MULTI_VAR                     { $$.v = $2.v; }
            ;

MULTI_VAR   : ID '=' RVALUE ',' MULTI_VAR       { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "var")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^" + $5.v; }
            | ID '=' RVALUE                     { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "var")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^"; }
            | ID ',' MULTI_VAR                  { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "var")) decl = {}; $$.v = decl + $3.v; }
            | ID                                { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "var")) decl = {}; $$.v = decl; }
            ;

CMD_CONST   : CONST MULTI_CONST                 { $$.v = $2.v; }
            ;

MULTI_CONST : ID '=' RVALUE ',' MULTI_CONST     { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "const")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^" + $5.v; }
            | ID '=' RVALUE                     { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "const")) decl = {}; $$.v = decl + $1.v + $3.v + "=" + "^"; }
            | ID ',' MULTI_CONST                { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "const")) decl = {}; $$.v = decl + $3.v; }
            | ID                                { vector<string> decl = {$1.v[0], "&"}; if(!trata_declaracoes($1.v[0], "const")) decl = {}; $$.v = decl; }
            ;

ATRIB       : LVALUE '=' RVALUE                 { trata_atribuicao($1.v[0]); $$.v = $1.v + $3.v + "="; }
            | LVALUE MAATR RVALUE               { trata_atribuicao($1.v[0]); $$.v = $1.v + $1.v + "@" + $3.v + "+" + "="; }
            | LVALUE MEATR RVALUE               { trata_atribuicao($1.v[0]); $$.v = $1.v + $1.v + "@" + $3.v + "-" + "="; }
            | LVALUEPROP '=' RVALUE             { trata_atribuicao($1.v[0]); $$.v = $1.v + $3.v + "[=]"; }
            | LVALUEPROP MAATR RVALUE           { trata_atribuicao($1.v[0]); $$.v = $1.v + $1.v + "[@]" + $3.v + "+" + "[=]"; }
            | LVALUEPROP MEATR RVALUE           { trata_atribuicao($1.v[0]); $$.v = $1.v + $1.v + "[@]" + $3.v + "-" + "[=]"; }
            ;

FINAL       : NUM                           { $$.v = $1.v; }
            | STRING                        { $$.v = $1.v; }
            | '['']'                        { $$.v = { string("[]") }; }
            | '(' RVALUE ')'                { $$.v = $2.v; }
            | LVALUE                        { $$.v = $1.v + "@"; }
            | LVALUEPROP                    { $$.v = $1.v + "[@]"; }
            ; 

ARGS        : RVALUE ',' ARGS                           {   $$.v = $1.v + $3.v;
                                                            $$.contador = 1 + $3.contador;  }
            | RVALUE                                    {   $$.v = $1.v;
                                                            $$.contador = 1;   }

BLOCO       : '{' { abre_escopo(); } CMDs { fecha_escopo(); } '}'           { $$.v = "<{" + $3.v + "}>"; }
            | '{''}'                                                        { $$.v = {}; }
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

/* Definicoes em C++ */

%{

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;

enum TOKEN { _ID = 256, _INT, _FLOAT, _STRING, _STRING2, _FUNCAO, _FUNCAO_POS};  

// Tratamento de variaveis
map<string, double> var;

// Tratamento do nome dos tokens
map<int, string> nome_tokens = {
    { _INT, "int" },
    { _STRING, "string" },
    { _FLOAT, "float" },
    { _ID, "nome de identificador" },
    { _FUNCAO, "funcao" },
    { _FUNCAO_POS, "funcao pos fixada" }
};

void casa( int esperado );
int tk( int token );

%}


/* Definições Regulares */

DIGITO                  [0-9]
LETRA                   [a-zA-Z]
ID                      ([$_]|{LETRA})([$_]|{DIGITO}|{LETRA})*
INT 	                {DIGITO}+
FLOAT 	                {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
STRING_SIMPLES          \'([^\'\n\\]|(\\\')|\'\'|'\\\\')+\'
STRING_DUPLA            \"([^\"\n\\]|(\\\")|\"\"|"\\\\")+\"
STRING_ACENTO           `[^`]*`

%%

    /* Padrões e ações */

"print"                 { return tk(_FUNCAO); }
"max"                   { return tk(_FUNCAO); }
"dtos"                  { return tk(_FUNCAO); }
"mdc"                   { return tk(_FUNCAO); }
"!"                     { return tk(_FUNCAO_POS); }

" "	                    { coluna_anterior = coluna_atual++; }
"\t"		            { coluna_anterior = coluna_atual; coluna_atual += 2; }
"\n"                    { linha++; coluna_anterior = coluna_atual; coluna_atual = 1; }
{INT}	                { return tk(_INT); }
{FLOAT}                 { return tk(_FLOAT); }	
{ID}	                { return tk(_ID); }
{STRING_SIMPLES}        { return tk(_STRING); }
{STRING_DUPLA}          { return tk(_STRING); }
{STRING_ACENTO}         { return tk(_STRING2); }

.                       { return tk(*yytext); }

%%

void erro( string msg ) {
    cout << "*** Erro: ***" << endl << "Linha: " << linha << ", coluna: " << coluna_anterior << endl << msg << endl;
    exit( 1 );
}

int tk( int token ) {
    coluna_anterior = coluna_atual;
    coluna_atual += strlen( yytext ); 
    return token;
}

string nome_token( int token ) {
    if( nome_tokens.find( token ) != nome_tokens.end() ) {
        return nome_tokens[token];
    } else {
        string r;
        r = (char) token;
        return "'" + r + "'";
    }
}

int next_token(){
    token = yylex();
    return token;
}

void casa( int esperado ) {
    if( token == esperado ){
        token = next_token();
    }else{
        erro( "Esperado " + nome_token( esperado ) + ", encontrado: " + nome_token( token ) );
    }
}

bool logging = false;
string offset = "";


// Declaracao dos Estados
void A( );
void E1( );
void E2( );
void T1( );
void T2( );
void PT1( );
void PT2( );
void U( );
void F( );
void P( );
void FN2( );


// CMDs   ->  A CMDs | e             [funciona como loop]
void CMDs(){
    A();
    // cout << endl;
    if( token != 0 )
        CMDs();
}

// A   ->  id { Print( id ); } = E1 ; { Print( "=" ); }
//     |   E1 ;
void A( ) {
    if(logging) cout << endl << offset << "[+A]" << endl;
    offset += ">";

    string temp = yytext; 
    switch( token ) {
        case _ID:
            casa( _ID );
            cout << temp << " ";
            casa( '=' );
            E1();
            casa( ';' );
            cout << '=' << " ";
            break;
        
        default:
            E1();
            casa( ';' );
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-A]" << endl;
}

// E1  ->  T1 E2
void E1( ) {
    if(logging) cout << endl << offset << "[+E1]" << endl;
    offset += ">";
    
    T1( );
    E2( );

    offset.pop_back();
    if(logging) cout << endl << offset << "[-E1]" << endl;
}

// E2  ->  + T1 { Print( "+" ); } E2
//     |   - T1 { Print( "-" ); } E2
void E2( ) {
    if(logging) cout << endl << offset << "[+E2]" << endl;
    offset += ">";
    
    string temp = yytext; 
    switch( token ) {
        case '+':
            casa( '+' );
            T1();
            cout << "+ ";
            E2();
            break;

        case '-':
            casa( '-' );
            T1();
            cout << "- ";
            E2();
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-E2]" << endl;
}

// T1  ->  U T2
void T1( ) {
    if(logging) cout << endl << offset << "[+T1]" << endl;
    offset += ">";

    U( );
    T2( );

    offset.pop_back();
    if(logging) cout << endl << offset << "[-T1]" << endl;
}

// T2  ->  * U { Print( "*" ); } T2
//     |   / U { Print( "/" ); } T2
void T2( ) {
    if(logging) cout << endl << offset << "[+T2]" << endl;
    offset += ">";
    
    string temp = yytext; 
    switch( token ) {
        case '*':
            casa( '*' );
            U();
            cout << "* ";
            T2();
            break;

        case '/':
            casa( '/' );
            U();
            cout << "/ ";
            T2();
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-E2]" << endl;
}

// U   ->  + U 
//     |   - { Print( "0" ); } U { Print( "-" ); }
//     |   PT1
void U( ) {
    if(logging) cout << endl << offset << "[+U]" << endl;
    offset += ">";
    
    string temp = yytext; 
    switch( token ) {
        case '+':
            casa( '+' );
            U();
            break;

        case '-':
            casa( '-' );
            cout << "0 ";
            U();
            cout << "- ";
            break;
        
        default:
            PT1();
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-U]" << endl;
}

// PT1 ->  F PT2
void PT1( ) {
    if(logging) cout << endl << offset << "[+PT1]" << endl;
    offset += ">";

    F( );
    PT2( );

    offset.pop_back();
    if(logging) cout << endl << offset << "[-PT1]" << endl;
}

// PT2 ->  ^ F { Print( "^" ); } PT2
//     |   ε
void PT2( ) {
    if(logging) cout << endl << offset << "[+PT2]" << endl;
    offset += ">";
    
    string temp = yytext; 
    switch( token ) {
        case '^':
            casa( '^' );
            F();
            PT2();
            cout << "^ ";
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-PT2]" << endl;
}

// F   ->  funcao E1 { Print( funcao ) }
//     |   id { Print( id + "@" ); } FN2
//     |   int { Print( int ); } FN2
//     |   float { Print( float ); } FN2
//     |   string { Print( string ); } FN2
//     |   ( P FN2

void F( ) {
    if(logging) cout << endl << offset << "[+F]" << endl;
    offset += ">";

    string temp = yytext;
    switch( token ) {
        case _FUNCAO: 
            casa( _FUNCAO ); 
            E1();
            cout << temp << " # "; 
            break;

        case _ID: 
            casa( _ID ); 
            cout << temp << " @ "; 
            break;

        case _INT:
            casa( _INT ); 
            cout << temp << " ";
            break;

        case _FLOAT:
            casa( _FLOAT ); 
            cout << temp << " ";
            break;

        case _STRING:
            casa( _STRING ); 
            cout << temp << " ";
            break;

        case _STRING2:
            casa( _STRING2 ); 
            cout << temp << " ";
            break;

        case '(': 
            casa( '(' ); 
            P(); 
            break;

        default:
            erro( string("Operando esperado, encontrado ") + yytext );
    }

    FN2( );

    offset.pop_back();
    if(logging) cout << endl << offset << "[-F]" << endl;
}

// P -> ',' | ')' | E1 P
void P( ) {
    if(logging) cout << endl << offset << "[+P]" << endl;
    offset += ">";

    string temp = yytext;
    switch( token ) {
        case ',': 
            casa( ',' ); 
            P();
            break;
            
        case ')':
            casa( ')' );
            break;

        default:
            E1();
            P();
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-P]" << endl;
}

// FN2 ->  ! { Print( "fat #" ) }
//     |   ε
void FN2( ) {
    if(logging) cout << endl << offset << "[+FN2]" << endl;
    offset += ">";

    string temp = yytext;
    switch( token ) {
        case _FUNCAO_POS: 
            if( temp == "!" ){
                casa( _FUNCAO_POS ); 
                cout << "fat # ";
            }
            break;
    }

    offset.pop_back();
    if(logging) cout << endl << offset << "[-FN2]" << endl;
}

auto f = &yyunput;

int main() {
    token = next_token();

    CMDs();

    // while( (token = next_token()) != 0 ){
    //     cout << yytext << " : " << nome_token(token) << endl;
    //     A();
    // }

    return 0;
}
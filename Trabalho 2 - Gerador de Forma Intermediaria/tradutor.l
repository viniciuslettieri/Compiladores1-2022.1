
/* Definicoes em C++ */

%{

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;

enum TOKEN { _ID = 256, _INT, _FLOAT, _STRING, _STRING2, _FUNCAO};  

// Tratamento de variaveis
map<string, double> var;

// Tratamento do nome dos tokens
map<int,string> nome_tokens = {
    { _INT, "int" },
    { _STRING, "string" },
    { _FLOAT, "float" },
    { _ID, "nome de identificador" },
    { _FUNCAO, "funcao" }
};

// Declaracao dos Estados
void A( );
void E1( );
void E2( );
void T1( );
void T2( );
void T3( );
void F1( );
void F2( );
void P( );
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
    // cout << endl << "(" << nome_token(token) << " - " << yytext << ")" << endl;
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


// CMDs -> A CMDs | e             [funciona como loop]

void CMDs(){
    A();
    cout << endl;
    if( token != 0 )
        CMDs();
}

// A -> id { Print( id ); } = E1 ; { Print( "=" ); }
//    | print E1 ; { Print( "print #" ); }

void A( ) {
    if(logging) cout << "[+A]" << endl;
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
        
        case _FUNCAO:
            casa( _FUNCAO );
            E1();
            casa( ';' );
            cout << temp << " # ";
            break;
    }
    if(logging) cout << "[-A]" << endl;
}

// E1 -> T1 E2
//    | max E1 ; { Print( "max #" ); }

void E1( ) {
    if(logging) cout << "[+E1]" << endl;
    string temp = yytext; 
    switch( token ) {
        case _FUNCAO:
            casa( _FUNCAO );
            E1();
            cout << temp << " # ";
            break; 

        default:
            T1();
            E2();
            break;
    }
    if(logging) cout << "[-E1]" << endl;
}

// E2 -> + T1 { Print( "+" ) E1; }
//    | - T1 { Print( "-" ) E1; }
//    | ^ T1 { Print( "^" ) E1; }
//    | ε

void E2( ) {
    if(logging) cout << "[+E2]" << endl;
    switch( token ) {
        case '+':
            casa( '+' );
            T1();
            cout << "+" << " ";
            E2();
            break;

        case '-':
            casa( '-' );
            T1();
            cout << "-" << " ";
            E2();
            break;
    }
    if(logging) cout << "[-E2]" << endl;
}

// T1 -> F T2

void T1( ) {
    if(logging) cout << "[+T1]" << endl;
    F1();
    T2();
    if(logging) cout << "[-T1]" << endl;
}

// T2 -> * F1 { Print( "*" ); }
//    | / F1 { Print( "/" ); }
//    | T3

void T2( ) {
    if(logging) cout << "[+T2]" << endl;
    switch( token ) {
        case '*':
            casa( '*' );
            F1();
            cout << "*" << " ";
            T2();
            break;

        case '/':
            casa( '/' );
            F1();
            cout << "/" << " ";
            T2();
            break;
        
        default:
            T3();
            break;
    }    
    if(logging) cout << "[-T2]" << endl;
}

void T3( ) {
    if(logging) cout << "[+T2]" << endl;
    switch( token ) {
        case '^':
            casa( '^' );
            F1();
            cout << "^" << " ";
            T2();
            break;
    }    
    if(logging) cout << "[-T2]" << endl;
}

// F1 -> + { Print( "0" ); } F2 { Print( "+" ); }; 
//    | - { Print( "0" ); } F2 { Print( "-" ); }; 
//    | F2

void F1( ) {
    switch( token ){
        case '+':
            casa( '+' );
            cout << "0 ";
            F2();    
            cout << "+ ";
            break;

        case '-':
            casa( '-' );
            cout << "0 ";
            F2();    
            cout << "- ";
            break; 

        default:
            F2();
            break;
    }
}

// F -> id { Print( id + "@" ); }
//    | int { Print( int ); }
//    | float { Print( float ); }
//    | string { Print( string ); }
//    | ( E1 )

void F2( ) {
    if(logging) cout << "[+F1]" << endl;
    string temp = yytext;
    switch( token ) {
        case _ID: 
            casa( _ID ); 
            cout << temp << " @" << " "; 
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

    if( token == '!' ){
        casa( '!' );
        cout << "fat # ";
    }

    if(logging) cout << "[-F1]" << endl;
}

// P -> ',' | ')' | E1

void P( ) {
    if(logging) cout << "[+P]" << endl;
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
    if(logging) cout << "[-P]" << endl;
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
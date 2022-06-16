# Roteiro

## Sugestão do Professor

1. Modificar a gramática de expressões original (Ações Semânticas para Gerar NPR) para incluir funções, print e mais de uma expressão separadas por ';' ;
2. Acrescentar as ações semânticas necessárias para gerar a forma intermediária;
3. Remover o início comum e a recursividade à esquerda;
4. Criar um arquivo lex para lidar com os novos tokens: num, id e string;
5. Escrever o analisador recursivo descendente no arquivo do lex, após o '%%';
6. Para submeter, copie o arquivo todo do lex incluindo a função main.

## Definindo as Ações Semânticas

versao 1

```
A   ->  id { Print( id ); } = FN { Print( "=" ); }

// Funcoes Pre-fixadas
FN  ->  funcao E1 { Print( funcao ) }
    |   E1

// Expressao
E1  ->  EU E2

E2  ->  + EU { Print( "+" ); } E2
    |   - EU { Print( "-" ); } E2

// Operadores Unários
EU ->   + EU 
    |   - { Print( "0" ); } EU { Print( "-" ); }
    |   T1

T1  ->  F T2

T2  ->  * F { Print( "*" ); } T2
    |   / F { Print( "/" ); } T2

F   ->  id { Print( id + "@" ); } FN2
    |   int { Print( int ); } FN2
    |   float { Print( float ); } FN2
    |   string { Print( string ); } FN2
    |   ( P FN2

P   ->  ,
    |   )
    |   FN

// Funcoes Pos-fixadas
FN2 ->  ! { Print( "fat" ) }
    |   ε

```

versao 2

```
A   ->  id { Print( id ); } = FN ; { Print( "="); }
    |   FN ;

// Funcoes Pre-fixadas
FN  ->  funcao E1 { Print( funcao ) }
    |   E1

E1  ->  T1 E2

E2  ->  + T1 { Print( "+" ); } E2
    |   - T1 { Print( "-" ); } E2

T1  ->  PT T2

T2  ->  * PT1 { Print( "*" ); } T2
    |   / PT1 { Print( "/" ); } T2

// Exponenciacao
PT1 ->  U PT2

PT2 ->  ^ U { Print( "^" ); } PT2
    |   ε

// Operadores Unários
U   ->  + U 
    |   - { Print( "0" ); } U { Print( "-" ); }
    |   F

F   ->  id { Print( id + "@" ); } FN2
    |   int { Print( int ); } FN2
    |   float { Print( float ); } FN2
    |   string { Print( string ); } FN2
    |   ( P FN2

P   ->  ,
    |   )
    |   FN

// Funcoes Pos-fixadas
FN2 ->  ! { Print( "fat" ) }
    |   ε

```

versao 3
precedencia do ^ maior que do unario

```
A   ->  id { Print( id ); } = FN ; { Print( "="); }
    |   FN ;

// Funcoes Pre-fixadas
FN  ->  funcao E1 { Print( funcao ) }
    |   E1

E1  ->  T1 E2

E2  ->  + T1 { Print( "+" ); } E2
    |   - T1 { Print( "-" ); } E2

T1  ->  U T2

T2  ->  * U { Print( "*" ); } T2
    |   / U { Print( "/" ); } T2

// Operadores Unários
U   ->  + U 
    |   - { Print( "0" ); } U { Print( "-" ); }
    |   PT1

// Exponenciacao
PT1 ->  F PT2

PT2 ->  ^ F { Print( "^" ); } PT2
    |   ε

F   ->  id { Print( id + "@" ); } FN2
    |   int { Print( int ); } FN2
    |   float { Print( float ); } FN2
    |   string { Print( string ); } FN2
    |   ( P FN2

P   ->  ,
    |   )
    |   FN

// Funcoes Pos-fixadas
FN2 ->  ! { Print( "fat" ) }
    |   ε

```

antigo

```
A -> id { Print( id ); } = E1 ; { Print( "=" ); }
   | print E1 ; { Print( "print #" ); }
   
E1 -> T1 E2
   | max E1 ; { Print( "max #" ); }
   | + { Print( "0" ); } E1 ; { Print( "+" ); }
   | - { Print( "0" ); } E1 ; { Print( "-" ); }

E2 -> + T1 { Print( "+" ); }
   | - T1 { Print( "-" ); }
   | ε

T1 -> F T2

T2 -> * F { Print( "*" ); }
   | / F { Print( "/" ); }
   | F

F -> id { Print( id + "@" ); }
   | int { Print( int ); }
   | float { Print( float ); }
   | string { Print( string ); }
   | ( E1 )
```

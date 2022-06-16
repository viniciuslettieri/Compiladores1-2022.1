# Roteiro

## Sugestão do Professor

1. Modificar a gramática de expressões original (Ações Semânticas para Gerar NPR) para incluir funções, print e mais de uma expressão separadas por ';' ;
2. Acrescentar as ações semânticas necessárias para gerar a forma intermediária;
3. Remover o início comum e a recursividade à esquerda;
4. Criar um arquivo lex para lidar com os novos tokens: num, id e string;
5. Escrever o analisador recursivo descendente no arquivo do lex, após o '%%';
6. Para submeter, copie o arquivo todo do lex incluindo a função main.

## Definindo as Ações Semânticas

```
A   ->  id { Print( id ); } = E1 ; { Print( "=" ); }
    |   E1 ;

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

F   ->  funcao E1 { Print( funcao + "#" ) } FN2
    |   id { Print( id + "@" ); } FN2
    |   int { Print( int ); } FN2
    |   float { Print( float ); } FN2
    |   string { Print( string ); } FN2
    |   ( P FN2

P   ->  ,
    |   )
    |   E1 P

// Funcoes Pos-fixadas
FN2 ->  ! { Print( "fat #" ) }
    |   ε

```

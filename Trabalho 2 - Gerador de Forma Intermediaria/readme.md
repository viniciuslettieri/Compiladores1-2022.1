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

A -> id { Print( id ); } = FN { Print( "="); }

FN  ->  funcao E1 { Print( funcao ) }

// Expressao
E1  ->  EU + E2 { Print( "+" ); }
    |   EU - E2 { Print( "-" ); }
    |   E2

E2  ->  EU + E2 { Print( "+" ); }
    |   EU - E2 { Print( "-" ); }
    |   EU

// Operadores Unários
EU ->   + E2
    |   - E2
    |   T2

T   ->  T * F { Print( "*" ); }
    |   T / F { Print( "/" ); }
    |   F

F   ->  id { Print(id + "@"); } FN2
    |   num { Print( num ); } FN2
    |   ( E ) FN2

FN2 ->  ! { Print( "fat" ) }

```

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

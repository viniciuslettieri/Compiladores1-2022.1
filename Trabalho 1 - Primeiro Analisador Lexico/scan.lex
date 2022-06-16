/* Coloque aqui definições regulares */

DIGITO                  [0-9]
LETRA                   [a-zA-Z]
ID                      ([$_]|{LETRA})([$_]|{DIGITO}|{LETRA})*
INT 	                {DIGITO}+
FLOAT 	                {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
FOR 	                [fF][oO][rR]
IF	                    [iI][fF]
COMENTARIO_BLOCO        \/\*([^*]|([*][^\/]))*\*\/
COMENTARIO_LINHA        \/\/[^(\n)]*
STRING_SIMPLES          \'([^\'\n\\]|(\\\')|\'\'|'\\\\')+\'
STRING_DUPLA            \"([^\"\n\\]|(\\\")|\"\"|"\\\\")+\"
STRING_ACENTO           `[^`]*`
WS	                    [ \t\n]

%%

    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	                { /* ignora espaços, tabs e '\n' */ } 
{INT}	                { return _INT; }
{FLOAT}                 { return _FLOAT; }	
{FOR}	                { return _FOR; }
{IF}	                { return _IF; }
{ID}	                { return _ID; }
">="	                { return _MAIG; }  
"<="	                { return _MEIG; }  
"=="                    { return _IG; }
"<>"	                { return _DIF; }  
{COMENTARIO_BLOCO}      { return _COMENTARIO; }
{COMENTARIO_LINHA}      { return _COMENTARIO; }
{STRING_SIMPLES}        { return _STRING; }
{STRING_DUPLA}          { return _STRING; }
{STRING_ACENTO}         { return _STRING2; }

.                       { return *yytext; }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */
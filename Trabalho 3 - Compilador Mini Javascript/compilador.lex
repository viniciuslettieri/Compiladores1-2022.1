DIGITO                  [0-9]
LETRA                   [a-zA-Z]
ID                      ([$_]|{LETRA})([$_]|{DIGITO}|{LETRA})*
INT 	                {DIGITO}+
NUM 	                {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
COMENTARIO_BLOCO        \/\*([^*]|([*][^\/]))*\*\/
COMENTARIO_LINHA        \/\/[^(\n)]*
STRING_SIMPLES          \'([^\'\n\\]|(\\\')|\'\'|'\\\\')+\'
STRING_DUPLA            \"([^\"\n\\]|(\\\")|\"\"|"\\\\")+\"
STRING_ACENTO           `[^`]*`
WS	                    [ \t\n]

%%

"\t"                    { coluna += 4; }
" "                     { coluna++; }
"\n"	                { linha++; coluna = 1; }

{NUM}	                { return retorna(NUM); }

"print"                 { return retorna(PRINT); }
"let"                   { return retorna(LET); }
"const"                 { return retorna(CONST); }
"var"                   { return retorna(VAR); }
"if"                    { return retorna(IF); }
"while"                 { return retorna(WHILE); }
"for"                   { return retorna(FOR); }

{ID}	                { return retorna(ID); }

">="	                { return retorna(MAIG); }  
"<="	                { return retorna(MEIG); }  
"=="                    { return retorna(IG); }
"<>"	                { return retorna(DIF); }  

{COMENTARIO_BLOCO}      { return retorna(COMENTARIO); }
{COMENTARIO_LINHA}      { return retorna(COMENTARIO); }
{STRING_SIMPLES}        { return retorna(STRING); }
{STRING_DUPLA}          { return retorna(STRING); }
{STRING_ACENTO}         { return retorna(STRING); }

.                       { return retorna(*yytext); }

%%
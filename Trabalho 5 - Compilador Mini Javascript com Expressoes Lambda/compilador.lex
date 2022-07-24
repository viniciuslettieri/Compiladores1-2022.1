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
WS	                    [ \t\n]*
ARGS                    {WS}{ID}{WS}(","{WS}{ID}{WS})*

%%

"\t"                    { coluna += 4; }
" "                     { coluna++; }
"\n"	                { linha++; coluna = 1;  }

"("/{ARGS}")"{WS}"=>"   { return retorna(ABRE_PAR_SETA); }

{NUM}	                { return retorna(NUM); }

"let"                   { return retorna(LET); }
"const"                 { return retorna(CONST); }
"var"                   { return retorna(VAR); }
"if"                    { return retorna(IF); }
"else"                  { return retorna(ELSE); }
"while"                 { return retorna(WHILE); }
"for"                   { return retorna(FOR); }
"function"              { return retorna(FUNCTION); }
"return"                { return retorna(RETURN); }

"true"                  { return retorna(TRUE); }
"false"                 { return retorna(FALSE); }

"asm{".*"}"             { string lexema = trim( yytext + 3, "{}" ); 
                          yylval.v = tokeniza( lexema, ' ' );
                          coluna += strlen( yytext ); 
                          return ASM; }
"=>"                    { return retorna(SETA); }

{ID}	                { return retorna(ID); }

">="	                { return retorna(MAIG); }  
"<="	                { return retorna(MEIG); }  
"=="                    { return retorna(IG); }
"<>"	                { return retorna(DIF); }  
"+="                    { return retorna(MAATR); }  
"-="                    { return retorna(MEATR); }  
"++"                    { return retorna(INCREM); }
"--"                    { return retorna(DECREM); }

{COMENTARIO_BLOCO}      { return retorna(COMENTARIO); }
{COMENTARIO_LINHA}      { return retorna(COMENTARIO); }
{STRING_SIMPLES}        { return retorna(STRING); }
{STRING_DUPLA}          { return retorna(STRING); }
{STRING_ACENTO}         { return retorna(STRING); }

.                       { return retorna(*yytext); }

%%
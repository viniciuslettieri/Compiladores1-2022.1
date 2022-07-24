all: compilador entrada.txt
	@./compilador < entrada.txt

interpretador: compilador entrada.txt
	@./compilador < entrada.txt > Maquina\ de\ Pilha/entrada.txt
	@./Maquina\ de\ Pilha/interpretador < ./Maquina\ de\ Pilha/entrada.txt

compilador: lex.yy.c y.tab.c
	@g++ y.tab.c -o compilador -lfl

lex.yy.c: compilador.lex
	@lex compilador.lex

y.tab.c: compilador.y
	@yacc -v compilador.y

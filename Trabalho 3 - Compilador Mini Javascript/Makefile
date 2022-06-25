all: compilador entrada.txt
	./compilador < entrada.txt

compilador: lex.yy.c y.tab.c
	g++ y.tab.c -o compilador -lfl	

lex.yy.c: compilador.lex
	lex compilador.lex

y.tab.c: compilador.y
	yacc compilador.y

derivada: lex.yy.c y.tab.c
	g++ -o compilador y.tab.c -lfl
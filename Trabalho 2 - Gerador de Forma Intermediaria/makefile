all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: tradutor.l
	lex tradutor.l

saida: lex.yy.c 
	g++ -Wall -std=c++17 lex.yy.c -ll -o saida
	
clean:
	rm saida lex.yy.c
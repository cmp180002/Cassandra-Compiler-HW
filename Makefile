
# default rule, build the parser into a 'jc' executable
all: jc

# yacc "-d" flag creates y.tab.h header
y.tab.c: parser.y
	yacc -d parser.y

# lex rule includes y.tab.c to force yacc to run first
# lex "-d" flag turns on debugging output, if you want it
lex.yy.c: scanner.l y.tab.c
	lex scanner.l

# jc executable needs scanner and parser object files
jc: lex.yy.o y.tab.o symtable.o astree.o
	gcc -Wall -o jc y.tab.o lex.yy.o symtable.o astree.o

# example test run of the program using file input redirection
test: jc
	./jc hello.j > hello.s
	gcc -Wall -o hello hello.s
	./hello

# ltest is a standalone lexer (scanner)
# build this by doing "make ltest"
# -ll for compiling lexer as standalone
ltest: scanner.l
	lex scanner.l
	gcc -Wall -DLEXONLY lex.yy.c -o ltest 
	
# checks for memory leaks
memcheck: jc
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./jc hello.j

# clean the directory for a pure rebuild (do "make clean")
clean: 
	rm -f lex.yy.c a.out y.tab.c y.tab.h *.o jc ltest hello.s hello vgcore.*


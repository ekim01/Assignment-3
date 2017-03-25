# Assignment-3
COMP2160 A3 Q1 and Q2
@@ -0,0 +1,40 @@

git repository:
git clone https://github.com/ekim01/Assignment-3.git

//Q1:
to compile:
make

to run:
./A3Q1

//Q2:
//suggest
to compile:
make
to run:
./suggest filedirectory
for example:
./suggest /usr/share/dict/words


//test
go into make and change 

PROG = suggest into PROG = test

and 

OBJS = $(OBJDIR)/suggest.o $(OBJDIR)/table.o $(OBJDIR)/engine.o $(OBJDIR)/levenshtein.o   

into 

OBJS = $(OBJDIR)/test.o $(OBJDIR)/table.o $(OBJDIR)/engine.o $(OBJDIR)/levenshtein.o

then compile it with make

to run:
./test filedirectory

example:
./test /usr/share/dict/words
\ No newline at end of file

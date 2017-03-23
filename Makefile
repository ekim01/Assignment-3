CC = clang
CFLAGS = -g -Wall

PROG = question1

OBJS = table.o main.o

$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)


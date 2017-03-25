CC = clang
CFLAGS = -g -Wall -DNDEBUG

PROG = suggest
PROG2 = test

OBJDIR = objects
OBJS = $(OBJDIR)/suggest.o $(OBJDIR)/table.o $(OBJDIR)/engine.o $(OBJDIR)/levenshtein.o
OBJS2 = $(OBJDIR)/test.o $(OBJDIR)/table.o $(OBJDIR)/engine.o $(OBJDIR)/levenshtein.o

# ... and in the darkness bind them (er, link them)
$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(PROG2): $(OBJS2) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS2) -o $(PROG2)

# One rule to build them all...
$(OBJDIR)/%.o: %.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# $@ is a variable with the name of the file that caused the rule
# to run. We've got multiple .c files, and thus multiple .o files,
# so each one of the .c files will create a separate .o file.
# $< is the name of the first prerequisite (in this case the .c)
# file. So our recipe will expand to something like:
# 	$(CC) $(CFLAGS) -c -o myfile.o myfile.c

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROG)
	rm -rf $(OBJDIR) $(PROG2)

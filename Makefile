#compiler flags:
CC = g++

#compiler flags:
# -g    adds debugging info to exe
# -Wall turns on most compiler warnings
CFLAGS = -g -Wall

#executable name and dependencies
palindrome: main.o palindrome.o; $(CC) $(CFLAGS) -o palindrome main.o palindrome.o

main.o: main.cpp palindrome.h ; $(CC) $(CFLAGS) -c main.cpp

palindrome.o: palindrome.cpp palindrome.h; $(CC) $(CFLAGS) -c palindrome.cpp

#to clean things up
clean: ; $(RM) count *.o *~

main: main.cpp palindromeNode.o stack.o
	g++ -g -static palindromeNode.o stack.o main.cpp -o main

palindromeNode.o: palindromeNode.cpp palindromeNode.h
	g++ -c -static palindromeNode.cpp

stack.o: stack.cpp stack.h palindromeNode.h
	g++ -c -static stack.cpp
run:
	./main

clean:
	rm -f *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main
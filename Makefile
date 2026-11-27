CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11

test: test_bitvec8.c bitvec8.c bitvec8.h
	gcc $(CFLAGS) test_bitvec8.c bitvec8.c -o test_bitvec8 

clean: 
	rm test_bitvec8

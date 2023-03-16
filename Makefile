connectn.out: board.o connectn.o input_val.o play.o win.o
	gcc -g -Wall -Werror -o connectn.out board.o connectn.o input_val.o play.o win.o
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
connectn.o: connectn.c play.h
	gcc -g -Wall -Werror -c connectn.c
input_val.o: input_val.c input_val.h
	gcc -g -Wall -Werror -c input_val.c
play.o: play.c play.h input_val.h board.h win.h
	gcc -g -Wall -Werror -c play.c
win.o: win.c win.h board.h
	gcc -g -Wall -Werror -c win.c
clean:
	rm -f *.o *.out
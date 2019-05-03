OBJ = main.o screen.o
APPNAME = screen.out

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) 

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(APPNAME) $(OBJ) wlist.txt


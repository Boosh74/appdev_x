#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int main(){
	char text[1500];
	int i=0;
/*
 * Check if a file exist using fopen() function
 * return 1 if the file exist otherwise return 0
 */
/* try to open file to read */
	FILE *file;
	if (file = fopen("wlist.txt", "r")){
		fclose(file);
    } else {
	    system("wget http://www.cc.puv.fi/~gc/wlist.txt");
	}

	clearScreen();
	fileintoarray(i);
	getchar();
	resetColors();
	clearScreen();
}

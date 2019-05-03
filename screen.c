#include <stdio.h>
#include "screen.h"
#include <stdlib.h>

void barChart(int db[], int tab, int scale){
	int i, j;
	for(i=0;i<COL;i++){
		for(j=1;j<=(db[i]/scale);j++){
			printf("\033[%d;%dH", 35-j, i*2+1+tab);

#ifdef UNICODE
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif

			printf("\033[%d;%dH", 35-j, (i+1)*2+tab);
#ifdef UNICODE
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
		printf("\33[35;%dH", (i+1)*2+tab);
		printf("%c", 65+i);
		if(db[i]!=0){
			printf("\33[%d;%dH", 35-j ,i*2+1+tab);
			printf("%d", db[i]);
		}
	}
	fflush(stdout);
}



char fileintoarray(int i){
	FILE* file;
	int ls[26]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int lfs[26]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char words[1311];
	int c, l, fl, wc=0;
	if((file = fopen("wlist.txt","r"))==NULL){
		printf("Problem with opening the file.");
		exit(1);
	}
	fscanf(file, "%[^\n]", words);
	fclose(file);

	if(words[0]!=' ')
		wc++;
	for(c=0;c<1311;c++){
		if((words[c]==' ') &&(words[c+1]>64)&&(words[c+1]<91))
			wc++;
	}
	printf("\033[62;1H");
//	printf("Number of words: %d\n", wc);

	for(c=0;c<1311;c++){
		if(words[c]=='A')
			ls[0]++;
		else if(words[c]=='B')
			ls[1]++;
		else if(words[c]=='C')
			ls[2]++;
		else if(words[c]=='D')
			ls[3]++;
		else if(words[c]=='E')
			ls[4]++;
		else if(words[c]=='F')
			ls[5]++;
		else if(words[c]=='G')
			ls[6]++;
		else if(words[c]=='H')
			ls[7]++;
		else if(words[c]=='I')
			ls[8]++;
		else if(words[c]=='J')
			ls[9]++;
		else if(words[c]=='K')
			ls[10]++;
		else if(words[c]=='L')
			ls[11]++;
		else if(words[c]=='M')
			ls[12]++;
		else if(words[c]=='N')
			ls[13]++;
		else if(words[c]=='O')
			ls[14]++;
		else if(words[c]=='P')
			ls[15]++;
		else if(words[c]=='Q')
			ls[16]++;
		else if(words[c]=='R')
			ls[17]++;
		else if(words[c]=='S')
			ls[18]++;
		else if(words[c]=='T')
			ls[19]++;
		else if(words[c]=='U')
			ls[20]++;
		else if(words[c]=='V')
			ls[21]++;
		else if(words[c]=='W')
			ls[22]++;
		else if(words[c]=='X')
			ls[23]++;
		else if(words[c]=='Y')
			ls[24]++;
		else if(words[c]=='Z')
			ls[25]++;
	}

	for(c=0;c<1311;c++){
		if(words[c]==' '){
			if(words[c+1]=='A')
				lfs[0]++;
			else if(words[c+1]=='B')
				lfs[1]++;
			else if(words[c+1]=='C')
				lfs[2]++;
			else if(words[c+1]=='D')
				lfs[3]++;
			else if(words[c+1]=='E')
				lfs[4]++;
			else if(words[c+1]=='F')
				lfs[5]++;
			else if(words[c+1]=='G')
				lfs[6]++;
			else if(words[c+1]=='H')
				lfs[7]++;
			else if(words[c+1]=='I')
				lfs[8]++;
			else if(words[c+1]=='J')
				lfs[9]++;
			else if(words[c+1]=='K')
				lfs[10]++;
			else if(words[c+1]=='L')
				lfs[11]++;
			else if(words[c+1]=='M')
				lfs[12]++;
			else if(words[c+1]=='N')
				lfs[13]++;
			else if(words[c+1]=='O')
				lfs[14]++;
			else if(words[c+1]=='P')
				lfs[15]++;
			else if(words[c+1]=='Q')
				lfs[16]++;
			else if(words[c+1]=='R')
				lfs[17]++;
			else if(words[c+1]=='S')
				lfs[18]++;
			else if(words[c+1]=='T')
				lfs[19]++;
			else if(words[c+1]=='U')
				lfs[20]++;
			else if(words[c+1]=='V')
				lfs[21]++;
			else if(words[c+1]=='W')
				lfs[22]++;
			else if(words[c+1]=='X')
				lfs[23]++;
			else if(words[c+1]=='Y')
				lfs[24]++;
			else if(words[c+1]=='Z')
				lfs[25]++;
		}
	}
/*
	for(int j=0; j<26; j++)
		printf("Num: %d", ls[j]);

	for(int j=0; j<26; j++)
		printf("Num:\n%d\n", lfs[j]);
*/
//	return words[i];

	setColors(CYAN, bg(BLACK));
	barChart(lfs, 0, 2);
	setColors(GREEN, bg(BLACK));
	barChart(ls, 62, 5);

}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}


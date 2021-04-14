// Tommy's BSD Custom shell.
// Calls commands with SH and system().
//
// (c) 2021-2021 Tommy Wilson

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define TRUE	1
#define FALSE	0

int promptret;
int shmode = FALSE;
int shutup = FALSE;
int debug = FALSE;
char promptlook[32] = "[TSH] $ ";
char command[500];
char defaultprompt[32] = "[TSH] $ ";

int init()
{
	if (shutup == TRUE) {
		return 1;
	}

	color(2);
	printf("TSH (tommy's shell)\n");
	printf("Did you know that if you specify a string in quotes as a command line parameter, that becomes your shell? It can be easy to get lost on if you are in TSH or SH, so make sure your prompts are diffrentiatable.\n\n");
	if (shmode == TRUE) {
		funprintf("Classic SH mode is activated right now\n");
	}
	else {
		funprintf("Class SH mode is NOT activated right now\n");
	}
	color(7);
	return 0;
}

int prompt()
{
	if (shmode == FALSE) {
		printf("%s",promptlook);
	}
	else {
		printf("$ ");
	}
	
	fgets(command,500,stdin);
	
	if (strcmp(command,"exit") == 0) {
		return 128;
	}

	if (strcmp(command,"quit") == 0) {
		return 128;
	}

	if (strcmp(command,"info") == 0) {
		return 192;
	}

	if (debug == TRUE) { printf("[debug] command=%s\n",command); }

	system(command);

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		if (strcmp(argv[1],"--defaultprompt") != 0) 
		{
			strcpy(promptlook, argv[1]);
		}
		else {
			strcpy(promptlook, defaultprompt);
		}
	}
	if (argc > 2) {
		if (strcmp(argv[2],"--shutup") == 0) {
			shutup = TRUE;
		}
	}
	if (argc > 3) {
		if (strcmp(argv[3],"--debug") == 0) {
			debug = TRUE;
		}
	}
	init();

	if (debug == TRUE) {
		printf("[debug] init() called\n");
		printf("[debug] argc=%i\n",argc);
		printf("[debug] flags=%i %i %i (sh, quiet, debug)\n", shmode, shutup, debug);
	}

	// ITS DOWN THERE NOT UP HERE
	// HERE IS FOR COOL PEOPLE ONLY DOWN THERE IS DUMB IDIOT SHELL STUFF
	// PROMPT MESS IS BELOW HERE!!!!
	
	while(1<2) {
		promptret = prompt();

		if (promptret == 128) {
			printf("Use ^C\n");
		}
		if (promptret == 192) {
			funprintf("TommySH (tsh) Info!\n");
			printf("This my custom shell written in C using color.h.\n");
			printf("(I also wrote color.h by the way.) :)\n");	
		}
	}
}

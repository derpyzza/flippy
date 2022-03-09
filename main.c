#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUF 1024


void error(char* error) {
	fprintf(stderr, "\033[31m%s\033[m\n", error);
	exit(1);
}

char* readLine() {
	int bufsize = BUF; 
	char* buffer = malloc(sizeof (char) * bufsize);
	int position 	= 0, c;

	if (!buffer){
		error("error reading line");
	}

	while ( 1 ) 
	{
		c = getchar();

		if ( c == EOF || c == '\n' ) 
		{
			buffer[position] = '\0';
			return buffer;
		} 
		else 
		{
			buffer[position] = c;
		}
		position++;

		if ( position >= bufsize ) 
		{
			bufsize += BUF;
			buffer = realloc(buffer, bufsize);
			
			if (!buffer)
			{
				error("error reading line");
			}
		}
	}
}

void flip(char* input) {
	size_t len = strlen(input);
	
	for ( size_t i = 0; i <= len - 1; i++ ) {
		if ( input [i] >= 65 && input [i] <= 90){
			input[i] = (27 - (input[i] - 64)) + 64;
		}
		else if ( input[i] <= 122 && input[i] >= 96 ) input[i] = (27 - (input[i] - 96)) + 96;
	}
}

int main
( int argc, char* argv[])
{ 
 if ( argc > 1) {
		for(int i = 1; i < argc; i++){
			flip(argv[i]);
			printf("\033[32m%s \033[m", argv[i]);
		}
		printf("\n");
	} else { 
		printf(">>> ");
		printf("\033[32m");
		char* input = readLine();
		printf("\033[m");
		flip(input);
		printf("%s\n",input);
	}
}

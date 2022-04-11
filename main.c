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

		if ( c == EOF || c == '\n')
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
	int lowerKey = 96
		,	upperKey = 64
		,	numKey	 = 27;
	
	for ( size_t i = 0; i <= len - 1; i++ ) {
		
		// For every character, if it's a letter of the alphabet, subract the caseKey ( 64 for upper 
		// case, 96 for lower ) from the character to get the index of the character in the alphabet 
		// ( index starts at a = 1, ends at z = 26 ).
		// once you have the index of the character, subtract the index from the total number of characters in the
		// alphabet plus one ( so, 27 ). that will give you the opposite, or the mirror of the selected character.
		// once you have the mirror, add the caseKey back to the character, to get the ascii code of the character back.
		if ( input [i] >= 65 && input [i] <= 90){
			input[i] = (numKey - (input[i] - upperKey)) + upperKey;
		}
		else if ( input[i] <= 122 && input[i] >= 96 ) 
		input[i] = (numKey - (input[i] - lowerKey)) + lowerKey;
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

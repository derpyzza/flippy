#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUF 1024

char* readLine() {
	int bufsize = BUF; 
	char* buffer = malloc(sizeof (char) * bufsize);
	int position 	= 0
		,	c;

	if (!buffer){
		// print buffer error message
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
				//print error and exit
			}
		}
	}
}

void flip(char* input) {
	size_t len = strlen(input);
	//printf("len:%ld\n", len);
	
	for ( size_t i = 0; i <= len - 1; i++ ) {
		//printf("i:%d\n", i);
		if ( input [i] >= 65 && input [i] <= 90){
			input[i] = (27 - (input[i] - 64)) + 64;
		}
		else if ( input[i] <= 122 && input[i] >= 96 ) input[i] = (27 - (input[i] - 96)) + 96;
	}
}

int main() 
{ 
	char* input = readLine();
	flip(input);
	printf("\033[32m%s\033[m\n",input);
	//printf("\033[31m%c\033[m\n", (27 - (98 - 'a')) + 96);
	
	//for (char c = 'a'; c <= 'z'; c++) {
	//	printf("c: %c, id: %i, #: %i, f: %c\n", c, c, c - 96, (27 - (c - 96)) + 96);
	//}
}

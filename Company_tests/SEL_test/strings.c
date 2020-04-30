#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define WORD_NUMBER	(4)

// returns zero on success, returns -1 on error.
char* char_escape(char* input) 
{
	size_t length = strlen(input);
	size_t retLen=0;
	char* retStr = (char*)malloc(sizeof(char)*2*length);
	while(*input != 0)
	{
		if((*input == 60) || (*input == 62) || (*input == 92))
		{
			*retStr = 92;
			retStr++;
			retLen++;
		}
		*retStr = *input;
		
		retStr++;
		input++;
		retLen++;

//		printf("%c", *retStr);
	}
	*retStr = 0;
	retStr-=retLen;
	return retStr;
}


int main() 
{
	char* s1 = "<hello> world";

	printf("\nEscaped string is %s\n", char_escape(s1));
	return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WORD_NUMBER	(2)
#define CLOSE_OF(x)	((x==40) ? x+1 : x+2)

// returns zero on success, returns -1 on error.
int str_copy(char *dest, const char *src) 
{
	int index = 0;
	while(src[index] != '\0') 
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	if(index != strlen(src)) 
	{
		return 1;
	}
	return 0;
}


/**
 * @brief 
 *
 * @param haystack string
 * @param needle string
 *
 * @return index of first occurence of needle in haystack, or -1 if needle is not part of haystack
 */
int stringString(char* haystack, char* needle)
{
	int itr_h = 0, itr_n = 0;
	int length = strlen(needle);
	if(needle == NULL)
	{
		return 0;
	}

	while((needle[itr_n] != '\0') && (haystack[itr_h] != '\0'))
	{
		if(needle[itr_n] == haystack[itr_h])
		{
			itr_n++;
			itr_h++;
		}
		else 
		{
			itr_h = itr_h - itr_n + 1;
			itr_n = 0;
		}
	}

	if(itr_n == length)
	{
		return itr_h - length;
	}
	else
	{
		return -1;
	}
}


void parse_parm(const char* arguments, int argument_number, char** output)
{
	char* ptr = (char*)arguments;
	int word_count = 0;
	char* tmp;
	while(*ptr != 0)
	{
		if(argument_number != 0)
		{
			if(*ptr == 44)
			{
				argument_number--;
			}
			ptr++;
		}
		else 
		{
			tmp = ptr;
			while((*tmp != 44) && (*tmp != 0))
			{
				word_count++;
				tmp++;
			}
			break;
		}
	}
	*output = (char*)malloc(sizeof(char)*(word_count+1));
	memcpy((void*)*output, (const void*)ptr, word_count);
	(*output)[word_count] = 0;
}


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


/**
 * @brief checks if a string of brackets is properly nested. Eg. - {[()<>]} is correct
 * {[(<>])} is wrong
 *
 * @param brackets string of brackets
 * @param size length of string of brackets
 *
 * @return true is properly nested, false otherwise
 */
bool verify_nesting(char* brackets, int size)
{
	char arr[size];
	int index=-1;
	while(*brackets != 0)
	{
		if((*brackets != 40) && (*brackets != 41)
		&& (*brackets != 60) && (*brackets != 62)
		&& (*brackets != 91) && (*brackets != 93)
		&& (*brackets != 123) && (*brackets != 125))
		{
			printf("\n***Character not recognized*** as %d\n", *brackets);
			return false;
		}
		else
		{
			if((*brackets == 40) || (*brackets == 60)
			|| (*brackets == 91) || (*brackets == 123))
			{
				arr[++index] = *brackets;
			}
			else
			{
				if(*brackets == CLOSE_OF(arr[index]))
				{
					index--;
				}
				else
				{
					return false;
				}
			}
		}
		brackets++;
	}

	if(index == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() 
{
	char s1[] = "hello";
	char s2[32], s3[6];

	if (str_copy(s2, s1) == 0)
		printf("s2: %s\n", s2);

	if (str_copy(s3, s1) == 0)
		printf("s3: %s\n", s3);

	printf("\nIndex of repeating string is %d\n", stringString("mississippi", "ssis"));

	const char* s4 = (const char*)malloc(100);
	s4 = "one,two,three,four,five";
	char* word;
	parse_parm(s4, WORD_NUMBER, &word);
	printf("\nWord no. %d is %s\n", WORD_NUMBER+1, word);

	char* s5 = "<hello> world";
	printf("\nEscaped string is %s\n", char_escape(s5));

	char* brackets = "<{[()<>]}>";
	verify_nesting(brackets, sizeof(brackets)) ? printf("\nGiven string is properly nested\n") : printf("\nGiven string is improperly nested\n");

	return 0;
}

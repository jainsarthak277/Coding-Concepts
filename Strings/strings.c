#include <string.h>
#include <stdio.h>


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


int main() 
{
	char s1[] = "hello";
	char s2[32], s3[6];

	if (str_copy(s2, s1) == 0)
		printf("s2: %s\n", s2);

	if (str_copy(s3, s1) == 0)
		printf("s3: %s\n", s3);

	printf("Index of repeating string is %d\n", stringString("mississippi", "ssis"));

	return 0;
}

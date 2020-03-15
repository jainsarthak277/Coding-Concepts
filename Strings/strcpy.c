/*

Implement strcpy function

*/

#include <string.h>
#include <stdio.h>


// returns zero on success, returns -1 on error.
int str_copy(char *dest, const char *src) {
  int index = 0;
  while(src[index] != '\0') {
    dest[index] = src[index];
    index++;
  }
  dest[index] = '\0';
  if(index != strlen(src)) {
   return 1;
  }
  return 0;
}


int main() {
    char s1[] = "hello";
    char s2[32], s3[6];
   
    if (str_copy(s2, s1) == 0)
        printf("s2: %s\n", s2);
   
    if (str_copy(s3, s1) == 0)
        printf("s3: %s\n", s3);
   
    printf("OK\n");
    return 0;
}

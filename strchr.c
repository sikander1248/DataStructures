#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[] = "CRANES VARSITY";

    char key;

    printf("The string is : %s \n",str);
 //   printf("Enter the character to search : ");
//    scanf(" %c", &key);

    char *ptr = strchr(str , 65);//strrchr(str , key);
    if( ptr == NULL)
        printf("Key character not found \n");
    else
    {
	printf("Key character found \n");
	printf("ptr = %p \n",ptr);
	printf("str = %p \n",str);


    }
    return 0;
}

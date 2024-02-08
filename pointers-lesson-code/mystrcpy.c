#include <stdio.h>
#include <string.h>

void mystrcpyArr(char *source, char *dest){
    int len = strlen(source);
    int i;
    for (i=0; i<len; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    
}

void mystrcpyPtr(char *source, char *dest){
    while (*source){
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    
}


int main(){
    char s1[20] = "This is a string";
    char s2[20];
    char s3[20];
    
    mystrcpyArr(s1, s2);
    printf("String copied using array: %s\n", s2);
    
    mystrcpyPtr(s1, s3);
    printf("String copied using pointer: %s\n", s3);
    

}
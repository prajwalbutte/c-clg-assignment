#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    strrev(str);
    printf("Reversed: %s\n", str);
}

void palindrome(char str[]) {
    char temp[100];
    strcpy(temp, str);
    strrev(temp);
    if(strcmp(str, temp)==0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

void concat(char a[], char b[]) {
    strcat(a, b);
    printf("Concatenated: %s\n", a);
}

void wordCount(char str[]) {
    int count = 1;
    for(int i=0; str[i]!='\0'; i++)
        if(str[i] == ' ') count++;
    printf("Word Count: %d\n", count);
}

int main() {
    char s1[100], s2[100];
    printf("Enter a string: ");
    gets(s1);
    reverse(s1);
    palindrome(s1);
    printf("Enter another string: ");
    gets(s2);
    concat(s1, s2);
    wordCount(s1);
    return 0;
}

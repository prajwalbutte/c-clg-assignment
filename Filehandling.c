#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook() {
    FILE *fp = fopen("books.txt", "a");
    struct Book b;
    printf("Enter Book ID, Title, Author: ");
    scanf("%d %s %s", &b.id, b.title, b.author);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("Book Added!\n");
}

void displayBooks() {
    FILE *fp = fopen("books.txt", "r");
    struct Book b;
    printf("\n--- Book Records ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("%d\t%s\t%s\n", b.id, b.title, b.author);
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("books.txt", "r");
    struct Book b;
    int id, found=0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("Found: %d %s %s\n", b.id, b.title, b.author);
            found = 1;
        }
    }
    if(!found) printf("Not Found!\n");
    fclose(fp);
}

int main() {
    int ch;
    while(1) {
        printf("\n1.Add  2.Display  3.Search  4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if(ch == 1) addBook();
        else if(ch == 2) displayBooks();
        else if(ch == 3) searchBook();
        else break;
    }
    return 0;
}

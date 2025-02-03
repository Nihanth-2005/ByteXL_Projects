#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    char book_name[50];  // Increased size for longer book names
    char author[50];     // Increased size for longer author names
    int pages;
    float price;
};

int main() {
    struct library lib[100];
    char ar_nm[50];  // Increased size for longer author names
    int i, input, count;
    i = input = count = 0;

    while (1) {
        printf("\n\n****** WELCOME TO E-LIBRARY *******\n");
        printf("1. Add book information\n");
        printf("2. Display all books\n");
        printf("3. List all books of a given author\n");
        printf("4. Display the total count of books\n");
        printf("5. Exit\n");
        printf("***********************************\n");

        printf("\nEnter your choice: ");
        scanf("%d", &input);
        getchar(); // To clear newline left in the buffer

        switch (input) {
            case 1:
                printf("\n----- Adding a new book -----\n");
                if (count < 100) {
                    printf("Enter book name: ");
                    fgets(lib[count].book_name, sizeof(lib[count].book_name), stdin);
                    lib[count].book_name[strcspn(lib[count].book_name, "\n")] = '\0'; // Remove newline

                    printf("Enter author name: ");
                    fgets(lib[count].author, sizeof(lib[count].author), stdin);
                    lib[count].author[strcspn(lib[count].author, "\n")] = '\0'; // Remove newline

                    printf("Enter number of pages: ");
                    scanf("%d", &lib[count].pages);

                    printf("Enter price: ");
                    scanf("%f", &lib[count].price);

                    printf("\nBook added successfully!\n");
                    count++;
                } else {
                    printf("\nLibrary is full! Cannot add more books.\n");
                }
                break;

            case 2:
                printf("\n----- List of Books in Library -----\n");
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("\nBook %d:\n", i + 1);
                        printf("Book Name  : %s\n", lib[i].book_name);
                        printf("Author     : %s\n", lib[i].author);
                        printf("Pages      : %d\n", lib[i].pages);
                        printf("Price      : ₹%.2f\n", lib[i].price);
                    }
                }
                break;

            case 3:
                printf("\nEnter author name to search: ");
                fgets(ar_nm, sizeof(ar_nm), stdin);
                ar_nm[strcspn(ar_nm, "\n")] = '\0'; // Remove newline

                printf("\n----- Books by %s -----\n", ar_nm);
                int found = 0;
                for (i = 0; i < count; i++) {
                    if (strcmp(ar_nm, lib[i].author) == 0) {
                        printf("\nBook Name  : %s\n", lib[i].book_name);
                        printf("Pages      : %d\n", lib[i].pages);
                        printf("Price      : ₹%.2f\n", lib[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No books found by this author.\n");
                }
                break;

            case 4:
                printf("\nTotal number of books in the library: %d\n", count);
                break;

            case 5:
                printf("\nExiting the program... Thank you for using E-Library!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

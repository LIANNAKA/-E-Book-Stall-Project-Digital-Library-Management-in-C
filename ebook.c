#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int available;
};

struct Book library[MAX_BOOKS] = {
    {"Book1", "Author1", 1},
    {"Book2", "Author2", 1},
    {"Book3", "Author3", 1},
    // Add more books as needed
};

int numBooks = 3;  // Number of initially stored books

void displayMenu();
void borrowBook();
void returnBook();
void displayAvailableBooks();
void addNewBook();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                borrowBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                displayAvailableBooks();
                break;
            case 4:
                addNewBook();
                break;
            case 5:
                printf("Exiting the e-library. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nE-Library Management System\n");
    printf("1. Borrow Book\n");
    printf("2. Return Book\n");
    printf("3. Display Available Books\n");
    printf("4. Add New Book\n");
    printf("5. Exit\n");
}

void borrowBook() {
    char title[50];
    printf("Enter the title of the book you want to borrow: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove the newline character

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].available) {
                library[i].available = 0;
                printf("Book '%s' borrowed successfully!\n", title);
            } else {
                printf("Book '%s' is not available for borrowing.\n", title);
            }
            return;
        }
    }

    printf("Book '%s' not found in the library.\n", title);
}

void returnBook() {
    char title[50];
    printf("Enter the title of the book you want to return: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove the newline character

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("Book '%s' returned successfully!\n", title);
            } else {
                printf("Book '%s' is already available in the library.\n", title);
            }
            return;
        }
    }

    printf("Book '%s' not found in the library.\n", title);
}

void displayAvailableBooks() {
    printf("\nAvailable Books in the Library:\n");

    for (int i = 0; i < numBooks; i++) {
        if (library[i].available) {
            printf("Title: %s, Author: %s\n", library[i].title, library[i].author);
        }
    }
}

void addNewBook() {
    if (numBooks < MAX_BOOKS) {
        printf("Enter details for the new book:\n");

        printf("Title: ");
        fgets(library[numBooks].title, sizeof(library[numBooks].title), stdin);
        library[numBooks].title[strcspn(library[numBooks].title, "\n")] = 0; // Remove the newline character

        printf("Author: ");
        fgets(library[numBooks].author, sizeof(library[numBooks].author), stdin);
        library[numBooks].author[strcspn(library[numBooks].author, "\n")] = 0; // Remove the newline character

        library[numBooks].available = 1;  // Newly added book is available
        numBooks++;

        printf("New book added successfully!\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}